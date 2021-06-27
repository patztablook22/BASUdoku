#!/usr/bin/env bash

cd $(dirname $0)
mkdir -p build
cmake -S src -B build

cd build
make
