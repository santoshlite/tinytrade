#!/bin/bash

export MY_INSTALL_DIR=$HOME/.local
cmake -S . -B ../build/client -DCMAKE_PREFIX_PATH=$MY_INSTALL_DIR
cd ../build/client
make -j 4
./client

