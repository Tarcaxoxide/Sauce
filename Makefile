X86_64_asm_source_files := $(shell find src/impl/x86_64 -name *.asm)
X86_64_asm_object_files := $(patsubst src/impl/x86_64/%.asm, build/x86_64/%.o, $(X86_64_asm_source_files))

Target :=dist/x86_64/build-x86_64.iso

compilerPath=~/opt/cross/bin/x86_64-elf

$(X86_64_asm_object_files): build/x86_64/%.o : src/impl/x86_64/%.asm
	mkdir -p $(dir $@)
	nasm -f elf64 $(patsubst build/x86_64/%.o, src/impl/x86_64/%.asm, $@) -o $@

.PHONY: run clean

default: $(Target)

clean:
	rm -frv build targets/iso/kernel.bin dist
run: default
	qemu-system-x86_64 -cdrom $(Target)

dist/x86_64/build-x86_64.iso: $(X86_64_asm_object_files)
	mkdir -p dist/x86_64
	$(compilerPath)-ld -n -o dist/x86_64/kernel.bin -T targets/x86_64/linker.ld $(X86_64_asm_object_files)
	cp dist/x86_64/kernel.bin targets/x86_64/iso/boot/kernel.bin
	grub-mkrescue /usr/lib/grub/i386-pc -o dist/x86_64/build-x86_64.iso targets/x86_64/iso
