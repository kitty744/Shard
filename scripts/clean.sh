#!/bin/bash

echo "Cleaning build artifacts..."
make clean
rm -rf bin/
rm -rf bin-int/
rm -f Makefile
rm -f Shard/Makefile
rm -f Sandbox/Makefile
rm -f *.make

echo "Clean complete!"