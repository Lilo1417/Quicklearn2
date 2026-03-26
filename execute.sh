#!/bin/bash

rm -r build/
cmake -B build -S src -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

cmake --build build/

build/quicklearn
