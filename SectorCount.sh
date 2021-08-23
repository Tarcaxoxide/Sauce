#!/bin/bash

let Size=$(echo $(du -b --block-size=512 build/*|grep $1)|cut -d' ' -f1)
echo "$Size"
