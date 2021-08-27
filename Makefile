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

PREFIX=Compiler/opt/cross
TARGET=x86_64-elf
Cross=$(PREFIX)/bin/$(TARGET)
CompilerHome=Compiler
Target_gcc=gcc-9.4.0
Target_binutils=binutils-2.37
Linker=$(Cross)-ld
Cpp_Compiler=$(Cross)-g++
CPP_ARGS= -Ihdr -ffreestanding -mcmodel=large -mno-red-zone -mno-mmx -mno-sse -mno-sse2 -O2 -Wall -Wextra -fno-exceptions -fno-rtti -nostdlib



build/sys.img: build/Bootloader_First.bin build/kernel.bin
	mkdir -p $(dir $@)
	cat $^ > build/sys.img 

build/sys.iso: build/sys.img
	mkdir -p build/build
	cp $< build/$<
	truncate build/$< -s 1200k
	mkisofs -o build/$@ -b $< ./build/

build/kernel.bin: $(Objs)
	mkdir -p $(dir $@)
	$(Linker) -Tsrc/linker.ld $(Objs) -o build/kernel.tmp
	$(Cross)-objcopy -O binary build/kernel.tmp build/kernel.bin


build/Bootloader_First.bin:src/Bootloader_First.asm build/kernel.bin
	mkdir -p $(dir $@)
	cat res/Templates/A_ReadDisk.inc > hdr/ReadDisk.inc
	echo "        mov al, $(shell ./SectorCount.sh build/kernel.bin)">>hdr/ReadDisk.inc
	cat res/Templates/B_ReadDisk.inc >> hdr/ReadDisk.inc
	nasm -Ihdr -f bin $< -o $@
	echo "#$( $@)"

build/%.o:src/%.asm
	mkdir -p $(dir $@)
	nasm -Ihdr -f elf64 $< -o $@


build/%.o:src/%.cpp
	mkdir -p $(dir $@)
	$(Cpp_Compiler) ${CPP_ARGS} -c $< -o $@


.PHONY: clean run default do setup push

clean:
	rm -frv build/*

default: build/sys.img

run: build/sys.iso
	qemu-system-x86_64 -serial stdio -no-reboot -no-shutdown -cdrom build/$< -m 10G -smp 6

do:
	clear
	clear
	reset
	make clean run

push:
	./push.sh
	

$(CompilerHome)/src/$(Target_binutils).tar.xz:
	mkdir -p $(dir $@)
	wget --continue "https://ftp.gnu.org/gnu/binutils/$(Target_binutils).tar.xz" -O $@

$(CompilerHome)/src/$(Target_gcc).tar.xz:
	mkdir -p $(dir $@)
	wget --continue "https://ftp.gnu.org/gnu/gcc/$(Target_gcc)/$(Target_gcc).tar.xz" -O $@


setup: $(CompilerHome)/src/$(Target_binutils).tar.xz $(CompilerHome)/src/$(Target_gcc).tar.xz
	./setup.sh "$(CompilerHome)" "$(Target_gcc)" "$(Target_binutils)" "$(TARGET)" "$(PREFIX)"

