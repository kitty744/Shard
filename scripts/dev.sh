#!/bin/bash

echo "Building and running Shard Engine..."
echo ""

make -j$(nproc)

if [ $? -eq 0 ]; then
    echo ""
    echo "Build successful! Launching Sandbox..."
    echo "========================================"
    echo ""
    LD_LIBRARY_PATH=./bin/Debug-linux-x86_64/Shard:$LD_LIBRARY_PATH ./bin/Debug-linux-x86_64/Sandbox/Sandbox
else
    echo ""
    echo "Build failed!"
    exit 1
fi