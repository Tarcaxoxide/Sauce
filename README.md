# Sauce

# requirements
you need 
- gcc
- nasm
- ld
- make
- binutils (i think, for objcopy command)
- qemu to run the iso if your doing `make do`
- if your not using qemu then this command will "fail" but don't worry, the iso can be found at `build/build/sys.iso`


# Build
>- `make do`
>> this will clear the terminal, then it will clean the build directory, then it will build sys.bin and boot it with qemu-system-x86_64.


# codes/
 specified in hdr/Misc.hpp as enum