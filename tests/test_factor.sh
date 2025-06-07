#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

# Compile Source.cpp
if ! g++ "$SCRIPT_DIR/../Source.cpp" -o "$SCRIPT_DIR/factor"; then
  echo "Compilation failed" >&2
  exit 1
fi

# Run the binary with sample input 15 followed by 0 to exit
output=$(printf "15\n0\n" | "$SCRIPT_DIR/factor")

# Check that both factors 3 and 5 appear in the output
if ! echo "$output" | grep -q "3 ,"; then
  echo "Expected factor 3 not found" >&2
  exit 1
fi

if ! echo "$output" | grep -q "5 ,"; then
  echo "Expected factor 5 not found" >&2
  exit 1
fi

echo "All tests passed"

