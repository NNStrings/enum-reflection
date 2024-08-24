#!/bin/bash

set -e

cmake -B build || { echo "cmake configuration failed"; exit 1; }

make -C build || { echo "make build failed"; exit 1; }

echo "-------------Result-------------"

./build/enum-reflection