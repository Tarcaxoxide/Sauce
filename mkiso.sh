#!/bin/bash


pushd kernel/bin
mkdir -vp mnt
sudo mount Sauce.img mnt
mkisofs -o Sauce.iso -T -D -R mnt
sudo umount mnt
popd