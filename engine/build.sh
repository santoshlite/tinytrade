#!/bin/bash

cmake -S . -B ../build/engine
cmake --build ../build/engine
cd ../build/engine
./engine
cd ..
cd ..

