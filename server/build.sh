#!/bin/bash

export MY_INSTALL_DIR=$HOME/.local
cmake -S . -B ../build/server -DCMAKE_PREFIX_PATH=$MY_INSTALL_DIR
cd ../build/server
make -j 4
./server