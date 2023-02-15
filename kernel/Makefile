
OSNAME = Sauce

GNUEFI = ../gnu-efi
OVMFDIR = ../OVMFbin
LDS = kernel.ld
ASMC=nasm
CC = g++

INCDIR=inc
CFLAGS = -I$(INCDIR) -O0 -Werror -ffreestanding -fshort-wchar -mno-red-zone -fmax-errors=1 -fno-exceptions
ASMFLAGS = -I$(INCDIR)
LDFLAGS = -T $(LDS) -static -Bsymbolic -nostdlib

SRCDIR := src
OBJDIR := lib
BUILDDIR = bin
BOOTEFI := $(GNUEFI)/x86_64/bootloader/main.efi

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC = $(call rwildcard,$(SRCDIR),*.cpp)
ASMSRC = $(call rwildcard,$(SRCDIR),*.asm)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%_cpp.o, $(SRC))
OBJS += $(patsubst $(SRCDIR)/%.asm, $(OBJDIR)/%_asm.o, $(ASMSRC))
DIRS = $(wildcard $(SRCDIR)/*)

$(BUILDDIR)/$(OSNAME).img: $(BUILDDIR)/kernel.elf
	dd if=/dev/zero of=$(BUILDDIR)/$(OSNAME).img bs=512 count=93750
	mkfs.fat -F32 $(BUILDDIR)/$(OSNAME).img
	mmd -i $(BUILDDIR)/$(OSNAME).img ::/EFI
	mmd -i $(BUILDDIR)/$(OSNAME).img ::/EFI/BOOT
	mcopy -i $(BUILDDIR)/$(OSNAME).img $(BOOTEFI) ::/EFI/BOOT
	mcopy -i $(BUILDDIR)/$(OSNAME).img startup.nsh ::/
	mcopy -i $(BUILDDIR)/$(OSNAME).img $(BUILDDIR)/kernel.elf ::/
	mcopy -i $(BUILDDIR)/$(OSNAME).img $(INCDIR)/Sauce/Fonts/zap-light16.psf ::/
	mcopy -i $(BUILDDIR)/$(OSNAME).img $(INCDIR)/Sauce/TESTFILE.txt ::/

$(BUILDDIR)/$(OSNAME).iso: $(BUILDDIR)/$(OSNAME).img
	mkisofs -d -D -J -l -r -U -relaxed-filenames -o $@ $<


$(OBJDIR)/Interrupts/Interrupts_cpp.o:$(SRCDIR)/Interrupts/Interrupts.cpp
	mkdir -p $(@D)
	$(CC) -I$(INCDIR) -mno-red-zone -mgeneral-regs-only -ffreestanding -c $^ -o $@

$(OBJDIR)/%_cpp.o:$(SRCDIR)/%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJDIR)/%_asm.o:$(SRCDIR)/%.asm
	mkdir -p $(@D)
	$(ASMC) $(ASMFLAGS) $^ -f elf64 -o $@

$(BUILDDIR)/kernel.elf: $(OBJS)
	mkdir -p $(@D)
	ld $(LDFLAGS) -o $(BUILDDIR)/kernel.elf $^

setup:
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(SRCDIR)
	@mkdir -p $(OBJDIR)

.PHONY: clean run 
clean:
	make setup
	@rm -frv bin/* lib/*

run: $(BUILDDIR)/$(OSNAME).img
	@qemu-system-x86_64 -no-reboot -display gtk,zoom-to-fit=on -smp 2 -serial file:$(BUILDDIR)/log.txt -machine q35 -s -drive format=raw,file=$< -m 2G -cpu qemu64 -drive if=pflash,format=raw,unit=0,file="$(OVMFDIR)/OVMF_CODE-pure-efi.fd",readonly=on -drive if=pflash,format=raw,unit=1,file="$(OVMFDIR)/OVMF_VARS-pure-efi.fd"
	@read -p "press enter to continue..."
	@reset

