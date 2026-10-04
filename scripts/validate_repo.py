#!/usr/bin/env python3
"""Dependency-free structure and Markdown checks for the Innovation Centre repo."""

from __future__ import annotations

import re
import sys
from pathlib import Path
from urllib.parse import unquote, urlsplit

ROOT = Path(__file__).resolve().parents[1]
EXPECTED_PROJECT_IDS = list(range(1, 15))
PROJECT_DIRECTORIES = sorted(
    (path for path in ROOT.iterdir() if path.is_dir() and re.match(r"^\d{2}-", path.name)),
    key=lambda path: path.name,
)
ROOT_FILES = (
    "README.md",
    "PROJECT_STATUS.md",
    "HARDWARE_INVENTORY.md",
    "DEVELOPMENT_STANDARDS.md",
    "CONTRIBUTING.md",
    "SAFETY.md",
    "LICENSE",
    "docs/FINAL_REPORT_TEMPLATE.md",
)
PROJECT_DIRECTORIES_REQUIRED = (
    "BOM",
    "data",
    "diagrams",
    "docs",
    "firmware",
    "hardware",
    "media",
    "results",
    "software",
    "tests",
    "web",
)
PROJECT_FILES_REQUIRED = (
    "README.md",
    "BOM/bom.md",
    "CHANGELOG.md",
    "data/README.md",
    "diagrams/01-system-block-diagram.md",
    "diagrams/02-hardware-connection.md",
    "diagrams/03-data-flow.md",
    "diagrams/04-software-architecture.md",
    "diagrams/README.md",
    "docs/RESEARCH.md",
    "docs/TROUBLESHOOTING.md",
    "docs/TUTORIAL.md",
    "firmware/README.md",
    "hardware/README.md",
    "hardware/VERIFICATION.md",
    "hardware/pin-map.md",
    "media/README.md",
    "results/README.md",
    "software/README.md",
    "tests/README.md",
    "web/README.md",
)
MARKDOWN_LINK = re.compile(r"!?\[[^\]]*\]\(([^)]+)\)")
FENCE_START = re.compile(r"^\s*(`{3,}|~{3,})(.*)$")
TEXT_SUFFIXES = {".md", ".py", ".c", ".h", ".yml", ".yaml", ".txt"}


def report(errors: list[str]) -> int:
    if errors:
        print("Repository validation failed:")
        for error in errors:
            print(f"- {error}")
        return 1

    markdown_count = sum(1 for path in ROOT.rglob("*.md") if ".git" not in path.parts)
    print(f"Repository validation passed: {len(PROJECT_DIRECTORIES)} projects, {markdown_count} Markdown files.")
    print("Project structure, required docs, README section counts, local links, code fences, and whitespace are OK.")
    return 0


def strip_fenced_code(text: str) -> str:
    """Return Markdown outside fenced code blocks for inline-link checking."""
    output: list[str] = []
    active_char: str | None = None
    active_length = 0

    for line in text.splitlines():
        match = FENCE_START.match(line)
        if match is None:
            output.append(line if active_char is None else "")
            continue

        fence, trailing = match.groups()
        char = fence[0]
        if active_char is None:
            active_char = char
            active_length = len(fence)
            output.append("")
            continue

        if char == active_char and len(fence) >= active_length and not trailing.strip():
            active_char = None
            active_length = 0
        output.append("")

    return "\n".join(output)


def check_markdown(path: Path, errors: list[str]) -> None:
    text = path.read_text(encoding="utf-8")
    relative = path.relative_to(ROOT)
    active_char: str | None = None
    active_length = 0
    active_line = 0

    for line_number, line in enumerate(text.splitlines(), start=1):
        if line.endswith((" ", "\t")):
            errors.append(f"{relative}:{line_number}: trailing whitespace")

        match = FENCE_START.match(line)
        if match is None:
            continue
        fence, trailing = match.groups()
        char = fence[0]
        if active_char is None:
            active_char = char
            active_length = len(fence)
            active_line = line_number
        elif char == active_char and len(fence) >= active_length and not trailing.strip():
            active_char = None
            active_length = 0
            active_line = 0

    if active_char is not None:
        errors.append(f"{relative}:{active_line}: unclosed fenced code block")

    prose = strip_fenced_code(text)
    for match in MARKDOWN_LINK.finditer(prose):
        raw_target = match.group(1).strip()
        if not raw_target:
            errors.append(f"{relative}: empty Markdown link")
            continue
        if raw_target.startswith("<") and ">" in raw_target:
            raw_target = raw_target[1 : raw_target.index(">")]
        else:
            raw_target = raw_target.split(maxsplit=1)[0]

        parsed = urlsplit(raw_target)
        if parsed.scheme or parsed.netloc or raw_target.startswith("#"):
            continue
        if not parsed.path:
            continue

        target = (path.parent / unquote(parsed.path)).resolve()
        try:
            target.relative_to(ROOT)
        except ValueError:
            errors.append(f"{relative}: local link escapes repository: {raw_target}")
            continue
        if not target.exists():
            errors.append(f"{relative}: broken local link: {raw_target}")


def main() -> int:
    errors: list[str] = []

    project_ids = []
    for directory in PROJECT_DIRECTORIES:
        match = re.match(r"^(\d{2})-", directory.name)
        if match:
            project_ids.append(int(match.group(1)))
    if project_ids != EXPECTED_PROJECT_IDS:
        errors.append(
            f"expected project directories numbered 01 through 14 in order; found {project_ids}"
        )

    for relative in ROOT_FILES:
        if not (ROOT / relative).is_file():
            errors.append(f"missing root file: {relative}")

    for project in PROJECT_DIRECTORIES:
        for relative in PROJECT_DIRECTORIES_REQUIRED:
            if not (project / relative).is_dir():
                errors.append(f"{project.name}: missing directory {relative}/")
        for relative in PROJECT_FILES_REQUIRED:
            if not (project / relative).is_file():
                errors.append(f"{project.name}: missing file {relative}")

        readme = project / "README.md"
        if readme.is_file():
            numbered_sections = re.findall(r"^##\s+\d+\.", readme.read_text(encoding="utf-8"), re.MULTILINE)
            if len(numbered_sections) != 29:
                errors.append(
                    f"{project.name}/README.md: expected 29 numbered sections, found {len(numbered_sections)}"
                )

    for path in ROOT.rglob("*.md"):
        if ".git" not in path.parts:
            check_markdown(path, errors)

    for path in ROOT.rglob("*"):
        is_project_text = path.suffix in TEXT_SUFFIXES or path.name in {"Makefile", ".gitignore"}
        if not path.is_file() or ".git" in path.parts or not is_project_text or path.suffix == ".md":
            continue
        try:
            lines = path.read_text(encoding="utf-8").splitlines()
        except UnicodeDecodeError:
            continue
        for line_number, line in enumerate(lines, start=1):
            if line.endswith((" ", "\t")):
                errors.append(f"{path.relative_to(ROOT)}:{line_number}: trailing whitespace")

    return report(errors)


if __name__ == "__main__":
    sys.exit(main())
