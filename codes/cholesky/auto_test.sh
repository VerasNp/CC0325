#!/bin/bash

if [ -d "out" ]; then
    echo "Cleaning up the previous build..."
    rm -rf out
fi

echo "Configuring the project with CMake..."
cmake -S . -B out -DENABLE_TESTS=ON

echo "Building the project..."
cmake --build out

echo "Build completed."

echo "Running tests..."
cd out
ctest -VV
