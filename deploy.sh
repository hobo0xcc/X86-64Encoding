#!/bin/bash
mdbook build --dest-dir docs
git add .
git commit -m "$1"
git push origin master
