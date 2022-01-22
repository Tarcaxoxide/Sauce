Objs = build/Bootstrap.o
Objs += build/IDT.o
Objs += build/VirtualFileSystem.o
Objs += build/Misc.o
Objs += build/Math.o
Objs += build/Utils.o
Objs += build/Convert.o
Objs += build/Interrupts.o
Objs += build/IO.o
Objs += build/Keyboard.o
Objs += build/Terminal.o
Objs += build/Binaries.o
Objs += build/Memory.o
Objs += build/Graphics.o
Objs += build/Shell.o
Objs += build/Kernel.o
Objs += build/PreKernel.o


Linker=ld
Cpp_Compiler=g++
CPP_ARGS= -Ihdr -ffreestanding -mcmodel=large -mno-red-zone -mno-mmx -O0 -fno-elide-constructors -Wall -Wextra -fno-exceptions -fno-rtti -nostdlib -Wno-unused-parameter -Wno-unused

# TODO:: Add stack protection.
CPP_ARGS += -fno-stack-protector


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
	objcopy -O binary build/kernel.tmp build/kernel.bin


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

default: build/sys.iso

run: build/sys.iso
	qemu-img resize -f raw build/$< +15G
	qemu-system-x86_64 -display sdl -cpu host -enable-kvm -m 20G -smp 6 -serial stdio -no-reboot -no-shutdown -cdrom build/$<

do:
	clear
	clear
	reset
	make clean run 

push:
	./push.sh
	

