#!/bin/bash

echo "Building Shard Engine..."
make -j$(nproc)

if [ $? -eq 0 ]; then
    echo ""
    echo "Build successful! Run './run.sh' to launch Sandbox."
else
    echo ""
    echo "Build failed!"
    exit 1
fi