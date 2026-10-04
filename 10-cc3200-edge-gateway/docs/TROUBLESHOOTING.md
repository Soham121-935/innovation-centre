# P10 — Troubleshooting

| Symptom | Check | Safe action |
|---|---|---|
| Temperature channel missing | Physical U6 population; newer builds may omit TMP008 | Mark unavailable; do not replace sensor |
| Accelerometer not found | Board revision, sensor presence, I²C jumper state | Use exact TI guide; do not change jumpers by trial |
| USB/debug not available | Matching cable, board power and existing driver/tool | Stop; no download or cable purchase |
| Board resets on Wi-Fi | Power path/current/configuration in matching guide | Disconnect; do not add an unlisted supply |
| AP/station fails | Existing supported SDK and local settings | Stop; no external router/internet assumption |
| Invalid sensor data shown as healthy | Range/freshness/fault logic | Mark unknown; never reuse stale values |
| Proposed browser/cloud dashboard | No client/cloud in stock scope | Defer; no claim of a web interface |

No remedy has been bench-verified.