X86_64_asm_source_files := $(shell find src/impl/x86_64 -name *.asm)
X86_64_asm_object_files := $(patsubst src/impl/x86_64/%.asm, build/x86_64/%.o, $(X86_64_asm_source_files))

X86_64_cpp_source_files := $(shell find src/impl/x86_64 -name *.cpp)
X86_64_cpp_object_files := $(patsubst src/impl/x86_64/%.cpp, build/x86_64/%.o, $(X86_64_cpp_source_files))

kernel_source_files := $(shell find src/impl/kernel -name *.cpp)
kernel_object_files := $(patsubst src/impl/kernel/%.cpp, build/kernel/%.o, $(kernel_source_files))


X86_64_object_files :=$(X86_64_cpp_object_files) $(X86_64_asm_object_files) 

Target :=dist/x86_64/grub-build-x86_64.iso

compilerPath=~/opt/cross/bin/x86_64-elf

vm_args= -m 4G -smp 4

CPP_ARGS=-I src/intf -ffreestanding -mcmodel=large -mno-red-zone -mno-mmx -mno-sse -mno-sse2 -O2 -Wall -Wextra -fno-exceptions -fno-rtti -nostdlib 
LINK_ARGS= -n -z max-page-size=0x1000

$(X86_64_asm_object_files): build/x86_64/%.o : src/impl/x86_64/%.asm
	mkdir -p $(dir $@)
	nasm -f elf64 $(patsubst build/x86_64/%.o, src/impl/x86_64/%.asm, $@) -o $@

$(kernel_object_files): build/kernel/%.o : src/impl/kernel/%.cpp
	mkdir -p $(dir $@)
	$(compilerPath)-g++  $(CPP_ARGS) -c $(patsubst build/kernel/%.o, src/impl/kernel/%.cpp, $@) -o $@


$(X86_64_cpp_object_files): build/x86_64/%.o : src/impl/x86_64/%.cpp
	mkdir -p $(dir $@)
	$(compilerPath)-g++ $(CPP_ARGS) -c $(patsubst build/x86_64/%.o, src/impl/x86_64/%.cpp, $@) -o $@

.PHONY: run-nogui run clean do-grub do-mine-bin

build/BootLoader.bin:
	mkdir -p $(dir $@)
	nasm -I src/impl/Bootloader -f bin src/impl/Bootloader/BootLoader.asm -o $@
build/Extended_Bootloader.bin:
	mkdir -p $(dir $@)
	nasm -I src/impl/Bootloader -f bin src/impl/Bootloader/Extended_BootLoader.asm -o $@

clean:
	rm -frv build targets/x86_64/iso/boot/kernel.bin dist

run: $(Target)
	# $(Target)
	qemu-system-x86_64 ${vm_args} -sdl -cdrom $(Target)

run-bin: $(Target)
	# $(Target)
	qemu-system-x86_64 ${vm_args} -sdl -drive  format=raw,file=$(Target)

run-nogui: default
	qemu-system-x86_64 ${vm_args} -curses -cdrom ${Target}

do-grub:
	clear;clear;reset;make clean run

do-mine-bin:
	clear;clear;reset;make clean run-bin Target="dist/x86_64/mine-build-x86_64.bin"


dist/x86_64/kernel.bin: $(kernel_object_files) $(X86_64_object_files)
	mkdir -p dist/x86_64
	$(compilerPath)-ld $(LINK_ARGS) -o dist/x86_64/kernel.bin -T targets/x86_64/linker.ld $^

dist/x86_64/grub-build-x86_64.iso: dist/x86_64/kernel.bin
	cp dist/x86_64/kernel.bin targets/x86_64/iso/boot/kernel.bin
	grub-mkrescue /usr/lib/grub/i386-pc -o $@ targets/x86_64/iso

dist/x86_64/Bootloader.bin: build/BootLoader.bin build/Extended_Bootloader.bin
	mkdir -p $(dir $@)
	# i think? the kernel should be at the 1M location.
	cat $^ > $@

dist/x86_64/mine-build-x86_64.bin: dist/x86_64/Bootloader.bin dist/x86_64/kernel.bin
	#cat $^ > $@
	cat dist/x86_64/Bootloader.bin > $@