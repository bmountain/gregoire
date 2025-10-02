#!/bin/bash

if [ ! -d build ]; then
  mkdir build
fi
cmake -S . -B build -G "Ninja Multi-Config" -D CMAKE_CXX_COMPILER=g++