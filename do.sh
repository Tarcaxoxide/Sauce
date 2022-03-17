#!/bin/bash

pushd gnu-efi
    make bootloader
popd
pushd kernel
    make clean
    make
    make run
popd