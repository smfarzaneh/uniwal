#!/bin/bash

cmake -S . -B build/
cmake --build build/
ctest --test-dir build/ --output-on-failure
./build/UniwalApp
