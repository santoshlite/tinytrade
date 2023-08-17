#!/bin/bash

cmake -S . -B ../build/client
cmake --build ../build/client
cd ../build/client
./client
cd ..
cd ..

