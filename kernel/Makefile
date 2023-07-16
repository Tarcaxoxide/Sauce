
OSNAME = Sauce

GNUEFI = ../gnu-efi
OVMFDIR = ../OVMFbin
LDS = kernel.ld
ASMC=nasm


INCDIR=inc
OPTIMIZATION_FLAGS=-O0 -fno-elide-constructors -fno-aggressive-loop-optimizations -fno-allocation-dce -fno-asynchronous-unwind-tables -fno-auto-inc-dec -fno-bit-tests -fno-dce -fno-delete-null-pointer-checks -fno-early-inlining -fno-fp-int-builtin-inexact -fno-function-cse -fno-gcse-lm -fno-handle-exceptions -fno-inline-atomics -fno-ipa-stack-alignment -fno-ipa-strict-aliasing -fno-ira-hoist-pressure -fno-ira-share-save-slots -fno-ira-share-spill-slots -fno-ivopts -fno-jump-tables
WARNING_FLAGS=-Werror -Wall -Wno-unused-variable
PLATFORM_FLAGS=-ffreestanding -fshort-wchar -mno-red-zone -fno-exceptions -fno-rtti
CFLAGS = -I$(INCDIR) $(OPTIMIZATION_FLAGS) $(WARNING_FLAGS) $(PLATFORM_FLAGS) 
ASMFLAGS = -I$(INCDIR)
LDFLAGS = -T $(LDS) -static -Bsymbolic -nostdlib

SRCDIR := src
OBJDIR := lib
BUILDDIR = bin
BOOTEFI := $(GNUEFI)/x86_64/bootloader/main.efi

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC = $(call rwildcard,$(SRCDIR),*.cpp)
ASMSRC = $(call rwildcard,$(SRCDIR),*.asm)
OBJS = $(patsubst $(SRCDIR)/%.asm, $(OBJDIR)/%_asm.o, $(ASMSRC))
OBJS += $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%_cpp.o, $(SRC))
DIRS = $(wildcard $(SRCDIR)/*)

$(BUILDDIR)/$(OSNAME).img: $(BUILDDIR)/kernel.elf
	sudo umount /mnt/img || true
	sudo kpartx -d -v $(BUILDDIR)/$(OSNAME).img || true
	dd if=/dev/zero of=$(BUILDDIR)/$(OSNAME).img bs=512 count=400000
	echo "type=83" | sudo sfdisk $(BUILDDIR)/$(OSNAME).img
	sudo sfdisk -A $(BUILDDIR)/$(OSNAME).img 1
	sudo kpartx -v -a $(BUILDDIR)/$(OSNAME).img
	sudo mkdir -p /mnt/img
	sudo mkfs.fat -F32 /dev/mapper/loop0p1
	sudo mount /dev/mapper/loop0p1 /mnt/img
	sudo mkdir -p /mnt/img/EFI/BOOT
	sudo cp $(BOOTEFI) /mnt/img/EFI/BOOT/
	sudo cp startup.nsh /mnt/img/
	sudo cp $(BUILDDIR)/kernel.elf /mnt/img/
	sudo cp -r $(INCDIR)/Resources/* /mnt/img/
	sudo umount /mnt/img
	sudo kpartx -d -v $(BUILDDIR)/$(OSNAME).img


$(OBJDIR)/Interrupts/Interrupts_cpp.o:$(SRCDIR)/Interrupts/Interrupts.cpp
	mkdir -p $(@D)
	$(CC) -I$(INCDIR) -mno-red-zone -mgeneral-regs-only -ffreestanding -c $^ -o $@

$(OBJDIR)/%_cpp.o:$(SRCDIR)/%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -S -c $^ -o $@.asm
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJDIR)/%_asm.o:$(SRCDIR)/%.asm
	mkdir -p $(@D)
	$(ASMC) $(ASMFLAGS) $^ -f elf64 -o $@

$(BUILDDIR)/kernel.elf: $(OBJS)
	mkdir -p $(@D)
	$(CC) $(LDFLAGS) -o $(BUILDDIR)/kernel.elf $^

setup:
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(SRCDIR)
	@mkdir -p $(OBJDIR)

.PHONY: clean run 
clean:
	make setup
	@rm -frv bin/* lib/*

run: $(BUILDDIR)/$(OSNAME).img
	@echo "log can be found at ./kernel/$(BUILDDIR)/log.txt"
	@qemu-system-x86_64 -no-reboot -display gtk,zoom-to-fit=on -smp 2 -serial file:$(BUILDDIR)/log.txt -machine q35 -s -drive format=raw,file=$< -m 1G -cpu qemu64 -drive if=pflash,format=raw,unit=0,file="$(OVMFDIR)/OVMF_CODE-pure-efi.fd",readonly=on -drive if=pflash,format=raw,unit=1,file="$(OVMFDIR)/OVMF_VARS-pure-efi.fd"
	@read -p "press enter to continue..."
	@reset

