X86_64_asm_source_files := $(shell find src/impl/x86_64 -name *.asm)
X86_64_asm_object_files := $(patsubst src/impl/x86_64/%.asm, build/x86_64/%.o, $(X86_64_asm_source_files))

X86_64_cpp_source_files := $(shell find src/impl/x86_64 -name *.cpp)
X86_64_cpp_object_files := $(patsubst src/impl/x86_64/%.cpp, build/x86_64/%.o, $(X86_64_cpp_source_files))

kernel_source_files := $(shell find src/impl/kernel -name *.cpp)
kernel_object_files := $(patsubst src/impl/kernel/%.cpp, build/kernel/%.o, $(kernel_source_files))


X86_64_object_files :=$(X86_64_cpp_object_files) $(X86_64_asm_object_files) 

Target :=dist/x86_64/build-x86_64.iso

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

.PHONY: run-nogui run clean do

default: $(Target)

clean:
	rm -frv build targets/x86_64/iso/boot/kernel.bin dist

run: default
	qemu-system-x86_64 ${vm_args} -sdl -cdrom $(Target)

run-nogui: default
	qemu-system-x86_64 ${vm_args} -curses -cdrom ${Target}

do:
	make clean;clear;clear;reset;make default && make run

dist/x86_64/build-x86_64.iso: $(kernel_object_files) $(X86_64_object_files)
	mkdir -p dist/x86_64
	$(compilerPath)-ld $(LINK_ARGS) -o dist/x86_64/kernel.bin -T targets/x86_64/linker.ld $^
	cp dist/x86_64/kernel.bin targets/x86_64/iso/boot/kernel.bin
	grub-mkrescue /usr/lib/grub/i386-pc -o dist/x86_64/build-x86_64.iso targets/x86_64/iso
