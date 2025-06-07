#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
TEST_BIN="$SCRIPT_DIR/mlkem_test"

if ! g++ "$SCRIPT_DIR/test_mlkem.cpp" -o "$TEST_BIN" $(pkg-config --cflags --libs liboqs 2>/dev/null); then
  echo "Failed to compile ML-KEM test" >&2
  exit 1
fi

if ! "$TEST_BIN"; then
  echo "ML-KEM test failed" >&2
  exit 1
fi

echo "ML-KEM test passed"
