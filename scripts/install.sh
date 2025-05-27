#!/bin/bash

# exit on error
set -e

BINARY_NAME = "c-hot-reloader"
BUILD_DIR   = "build"
DEST_DIR    = "/usr/local/bin"

echo "Build started"
make

if [ ! -f "$BUILD_DIR/$BINARY_NAME" ]; then
    echo "Build failed: $BUILD_DIR/$BINARY_NAME not found"
    exit 1
fi

echo "Installing Binary"
sudo cp "$BUILD_DIR/$BINARY_NAME" "$DEST_DIR/"
sudo chmod +x "$BUILD_DIR/$BINARY_NAME"

echo "Install Finnished"
