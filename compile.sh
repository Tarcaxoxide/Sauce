#Clean and setup variables
    rm -frv build/*
    CPP_ARGS="-Ihdr -ffreestanding -mcmodel=large -mno-red-zone -mno-mmx -mno-sse -mno-sse2 -O2 -Wall -Wextra -fno-exceptions -fno-rtti -nostdlib"

#Compile
    nasm -Ihdr -f bin src/Bootloader_First.asm -o build/Bootloader_First.bin || exit

    nasm -Ihdr -f elf64  src/Bootloader_Extended.asm -o build/Bootloader_Extended.elf64 || exit

    x86_64-elf-g++ ${CPP_ARGS} -c src/Kernel.cpp -o build/kernel.o || exit

    

    x86_64-elf-ld -Ttext 0x7e00 build/Bootloader_Extended.elf64 build/kernel.o -o build/kernel.tmp || exit
    x86_64-elf-objcopy -O binary build/kernel.tmp build/kernel.bin || exit

#finish up
    cat build/Bootloader_First.bin build/kernel.bin > build/sys.bin 

#Display File Sizes
    echo "File Sizes in 512 sectors..."
    for file in build/*
    do
        du -b --block-size=512 $file
    done


qemu-system-x86_64 -m 4G -smp 4 -drive file=build/sys.bin,format=raw