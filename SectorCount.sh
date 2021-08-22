#!/bin/bash

echo $(echo $(du -b --block-size=512 build/*|grep $1)|cut -d' ' -f1)
