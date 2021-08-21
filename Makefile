CPP_ARGS= -Ihdr -ffreestanding -mcmodel=large -mno-red-zone -mno-mmx -mno-sse -mno-sse2 -O2 -Wall -Wextra -fno-exceptions -fno-rtti -nostdlib
Objs = build/Bootstrap.o

Objs += build/Convert.o
Objs += build/IDT.o
Objs += build/Interrupts.o
Objs += build/IO.o
Objs += build/Keyboard.o
Objs += build/Terminal.o
Objs += build/Kernel.o


build/sys.bin: build/Bootloader_First.bin build/kernel.bin
	mkdir -p $(dir $@)
	cat $^ > build/sys.bin 

build/kernel.bin: $(Objs)
	mkdir -p $(dir $@)
	x86_64-elf-ld -Tsrc/linker.ld $(Objs) -o build/kernel.tmp
	x86_64-elf-objcopy -O binary build/kernel.tmp build/kernel.bin


build/Bootloader_First.bin:src/Bootloader_First.asm
	mkdir -p $(dir $@)
	nasm -Ihdr -f bin $< -o $@
	echo "#$( $@)"

build/%.o:src/%.asm
	mkdir -p $(dir $@)
	nasm -Ihdr -f elf64 $< -o $@


build/%.o:src/%.cpp
	mkdir -p $(dir $@)
	x86_64-elf-g++ ${CPP_ARGS} -c $< -o $@


.PHONY: clean filesizes run

clean:
	rm -frv build/*

filesizes:
	du -b --block-size=512 build/*

run: build/sys.bin
	qemu-system-x86_64 -drive file=$<,format=raw -m 4G -smp 4 
