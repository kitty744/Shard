#!/bin/bash

echo "Generating Makefiles with Premake5..."
premake5 gmake2

echo "Done! Run './build.sh' to compile."