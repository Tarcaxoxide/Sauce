# Sauce

# Build
>- `make setup`
>> this will setup a cross compiler inside the projects directory, this is so i know the compiler and binutils versions are known good.
>> your system's compiler might introduce some unexpected bugs, even if it's the same architecture.
>- `make do`
>> this will clear the terminal, then it will clean the build directory, then it will build sys.bin and boot it with qemu-system-x86_64.


# codes/
- 0 : nothing wrong.
- 1 : trying to retrieve from index bugger then DynamicArray.
- 2 : shape error for matrix.
- 3 : out of memory.
- FFFFFFFFFFFFFFFF : stop called by shell.