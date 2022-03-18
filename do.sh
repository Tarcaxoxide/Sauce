#!/bin/bash

let test=0
pushd gnu-efi
    make bootloader || let test=1
popd

if [ "!$test" == "!1" ]
then
	exit
fi

pushd kernel
    make clean
    make
    make run
popd
