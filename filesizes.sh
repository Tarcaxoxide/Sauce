#!/bin/bash
echo "File Sizes in 512 sectors..."
for file in build/*
do
    du -b --block-size=512 $file
done