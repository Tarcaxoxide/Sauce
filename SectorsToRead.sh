#!/bin/bash

echo $(echo $(du -b --block-size=512 build/*|grep kernel.bin)|cut -d' ' -f1)
