#!/usr/bin/env bash

set -e

if [ -d "build" ]; then
    rm -rf build
fi

mkdir build
cd build

cmake .. && make

exe_file=$(find . -maxdepth 1 -type f -perm -111 | head -n 1)
$exe_file
