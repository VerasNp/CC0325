#!/bin/bash

if [ -d "out" ]; then
    echo "Cleaning up the previous build..."
    rm -rf out
fi

echo "Configuring the project with CMake..."
cmake -S . -B out -DENABLE_MAIN=ON

echo "Building the project..."
cmake --build out

echo "Build completed."

./out/build/bin/CholeskyExecutable