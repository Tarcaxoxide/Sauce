# UEFI_Master - so i decided to try and convert my OS to uefi

- Requirements
    - mtools
        - mcopy copying files over to the .img file
        - mmd for creating directories in the .img file
    - nasm
        - for compiling the assembly files
    - gcc/clang
        - g++/clang++ for compiling the cpp files
    - qemu
        - qemu-system-x86_64 to run the produced .img file
    - dosfstools
        - mkfs.fat for generating the fat32 filesystem on the .img file
    - cdrtools
        - mkisofs for producing the final .img file.
    - gnu make
        - to run the Makefiles ;)
