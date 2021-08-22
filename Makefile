CPP_ARGS= -Ihdr -ffreestanding -mcmodel=large -mno-red-zone -mno-mmx -mno-sse -mno-sse2 -O2 -Wall -Wextra -fno-exceptions -fno-rtti -nostdlib
Objs = build/Bootstrap.o
Objs += build/Convert.o
Objs += build/IDT.o
Objs += build/Interrupts.o
Objs += build/IO.o
Objs += build/Keyboard.o
Objs += build/Terminal.o
Objs += build/Binaries.o
Objs += build/Memory.o
Objs += build/Kernel.o
Objs += build/PreKernel.o


build/sys.bin: build/Bootloader_First.bin build/kernel.bin
	mkdir -p $(dir $@)
	cat $^ > build/sys.bin 

build/kernel.bin: $(Objs)
	mkdir -p $(dir $@)
	x86_64-elf-ld -Tsrc/linker.ld $(Objs) -o build/kernel.tmp
	x86_64-elf-objcopy -O binary build/kernel.tmp build/kernel.bin


build/Bootloader_First.bin:src/Bootloader_First.asm build/kernel.bin
	mkdir -p $(dir $@)
	cat hdr/A_ReadDisk.inc > hdr/ReadDisk.inc
	echo "        mov al, $(shell ./SectorsToRead.sh)">>hdr/ReadDisk.inc
	cat hdr/B_ReadDisk.inc >> hdr/ReadDisk.inc
	nasm -Ihdr -f bin $< -o $@
	echo "#$( $@)"

build/%.o:src/%.asm
	mkdir -p $(dir $@)
	nasm -Ihdr -f elf64 $< -o $@


build/%.o:src/%.cpp
	mkdir -p $(dir $@)
	x86_64-elf-g++ ${CPP_ARGS} -c $< -o $@


.PHONY: clean CheckSizes run default do

clean:
	rm -frv build/*

CheckSizes:
	du -b --block-size=512 build/*
	@./SizeCheck.sh

default: build/sys.bin

run: build/sys.bin
	qemu-system-x86_64 -no-reboot -no-shutdown -drive file=$<,format=raw -m 4G

do:
	clear
	clear
	reset
	make clean run