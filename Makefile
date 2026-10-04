PYTHON ?= python3
CC ?= cc
HOST_CFLAGS ?= -std=c11 -Wall -Wextra -Werror -pedantic
BUILD_DIR ?= build/host-tests
P03_TEST_BIN := $(BUILD_DIR)/p03-sensor-fusion-tests
P03_CORE := 03-rslk-sensor-fusion/firmware/core/sensor_fusion.c
P03_TEST := 03-rslk-sensor-fusion/firmware/tests/test_sensor_fusion.c
P03_INCLUDE := 03-rslk-sensor-fusion/firmware/core

.PHONY: all validate test test-p03 test-p03-sanitized clean

all: test

validate:
	$(PYTHON) scripts/validate_repo.py

test: validate test-p03

test-p03:
	mkdir -p "$(BUILD_DIR)"
	$(CC) $(HOST_CFLAGS) -I$(P03_INCLUDE) $(P03_CORE) $(P03_TEST) -lm -o "$(P03_TEST_BIN)"
	"$(P03_TEST_BIN)"

test-p03-sanitized:
	mkdir -p "$(BUILD_DIR)"
	$(CC) $(HOST_CFLAGS) -fsanitize=address,undefined -fno-omit-frame-pointer -g \
		-I$(P03_INCLUDE) $(P03_CORE) $(P03_TEST) -lm -o "$(BUILD_DIR)/p03-sensor-fusion-tests-sanitized"
	"$(BUILD_DIR)/p03-sensor-fusion-tests-sanitized"

clean:
	rm -rf "$(BUILD_DIR)"
