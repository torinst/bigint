#!/usr/bin/env bash

set -e

HEADER_FILE="bigint"
SOURCE_DIR="$(cd "$(dirname "$0")" && pwd)"
DEST_DIR="/usr/local/include"

# uninstall
if [ "$1" == "uninstall" ]; then
    echo "Uninstalling $HEADER_FILE from $DEST_DIR ..."
    if [ -f "$DEST_DIR/$HEADER_FILE" ]; then
        sudo rm -f "$DEST_DIR/$HEADER_FILE"
        echo "Uninstallation successful!"
    else
        echo "File $HEADER_FILE does not exist in $DEST_DIR"
    fi
    exit 0
fi

# install
if [ ! -f "$SOURCE_DIR/$HEADER_FILE" ]; then
    echo "Error: $HEADER_FILE not found in $SOURCE_DIR"
    exit 1
fi

echo "Installing $HEADER_FILE to $DEST_DIR ..."
sudo cp "$SOURCE_DIR/$HEADER_FILE" "$DEST_DIR/"

if [ -f "$DEST_DIR/$HEADER_FILE" ]; then
    echo "Installation successful!"
else
    echo "Installation failed!"
    exit 1
fi
