#!/bin/sh

if [ "$1" == "serve" ]; then
    mdbook serve --dest-dir docs
    exit
else
    mdbook build --dest-dir docs
fi
