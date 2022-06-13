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

# plans
> -
- things done.
    - Text output "printf"
    - Dynamic Memory
    - strings "std::string" <- `Sauce::Memory::List_cl<char> StringVariableName`
> -
- Not yet done.
    - Userland Virtual Machines
    - UserLand Binary Compiler
    - UserLand binaries
    - disk access
    - loading of UserLand binaries
    - Multi-processing (not multi-threading)
    - graphics
    - hardware accelerated graphics

# current working on
- disk access (with addition confusion XD).
- debugging (making it easy to turn off/on certain things for printing to serial)