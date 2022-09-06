# UEFI_Master - so i decided to try and convert my OS to uefi

- Requirements
    - mtools
        - mcopy
        - mmd
    - nasm
    - gcc
        - g++
    - qemu
        - qemu-system-x86_64
    - dosfstools
        - mkfs.fat
    - cdrtools
        - mkisofs

# notes
- idk how to do filesystems XD documentation is confusing as hell cause they got variables that they don't tell you how to get, than i search for the variable and i find documentation on what the variable is but not how to obtain it. so i will be slowly working on that as information become apparent to me.
- i've added strlen and split.
- started implementation of a neural network thingy just for funs, not sure what i'll use it for.
- i've made the dynamic array into a single class instead of 2.
- AHCI driver now has the ability to read single bytes at a time.