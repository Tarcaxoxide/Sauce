X86_64_asm_source_files := $(shell find src/impl/x86_64 -name *.asm)
X86_64_asm_object_files := $(patsubst src/impl/x86_64/%.asm, build/x86_64/%.o, $(X86_64_asm_source_files))

X86_64_cpp_source_files := $(shell find src/impl/x86_64 -name *.cpp)
X86_64_cpp_object_files := $(patsubst src/impl/x86_64/%.cpp, build/x86_64/%.o, $(X86_64_cpp_source_files))

kernel_source_files := $(shell find src/impl/kernel -name *.cpp)
kernel_object_files := $(patsubst src/impl/kernel/%.cpp, build/kernel/%.o, $(kernel_source_files))


X86_64_object_files :=$(X86_64_cpp_object_files) $(X86_64_asm_object_files) 

Target :=dist/x86_64/build-x86_64.iso

compilerPath=~/opt/cross/bin/x86_64-elf


$(X86_64_asm_object_files): build/x86_64/%.o : src/impl/x86_64/%.asm
	mkdir -p $(dir $@)
	nasm -f elf64 $(patsubst build/x86_64/%.o, src/impl/x86_64/%.asm, $@) -o $@

$(kernel_object_files): build/kernel/%.o : src/impl/kernel/%.cpp
	mkdir -p $(dir $@)
	$(compilerPath)-g++ -I src/intf -ffreestanding -c $(patsubst build/kernel/%.o, src/impl/kernel/%.cpp, $@) -o $@


$(X86_64_cpp_object_files): build/x86_64/%.o : src/impl/x86_64/%.cpp
	mkdir -p $(dir $@)
	$(compilerPath)-g++ -I src/intf -ffreestanding -c $(patsubst build/x86_64/%.o, src/impl/x86_64/%.cpp, $@) -o $@

.PHONY: run clean

default: $(Target)

clean:
	rm -frv build targets/x86_64/iso/boot/kernel.bin dist

run: default
	qemu-system-x86_64 -cdrom $(Target)

dist/x86_64/build-x86_64.iso: $(kernel_object_files) $(X86_64_object_files)
	mkdir -p dist/x86_64
	$(compilerPath)-ld -n -o dist/x86_64/kernel.bin -T targets/x86_64/linker.ld $^
	cp dist/x86_64/kernel.bin targets/x86_64/iso/boot/kernel.bin
	grub-mkrescue /usr/lib/grub/i386-pc -o dist/x86_64/build-x86_64.iso targets/x86_64/iso
