#!/bin/bash

echo "Building Shard Engine..."
make -j$(nproc)

if [ $? -eq 0 ]; then
    echo ""
else
    echo ""
    echo "Build failed!"
    exit 1
fi