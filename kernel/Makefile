
OSNAME = Sauce

GNUEFI = ../gnu-efi
OVMFDIR = ../OVMFbin
LDS = kernel.ld
ASMC=nasm
CC = g++

INCDIR=inc
CFLAGS = -I$(INCDIR) -ffreestanding -fshort-wchar -mno-red-zone -fmax-errors=1 -fno-exceptions
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
	@#mformat -i $(BUILDDIR)/$(OSNAME).img -f 1440 ::
	mkfs.fat -F32 $(BUILDDIR)/$(OSNAME).img
	mmd -i $(BUILDDIR)/$(OSNAME).img ::/EFI
	mmd -i $(BUILDDIR)/$(OSNAME).img ::/EFI/BOOT
	mcopy -i $(BUILDDIR)/$(OSNAME).img $(BOOTEFI) ::/EFI/BOOT
	mcopy -i $(BUILDDIR)/$(OSNAME).img startup.nsh ::
	mcopy -i $(BUILDDIR)/$(OSNAME).img $(BUILDDIR)/kernel.elf ::
	mcopy -i $(BUILDDIR)/$(OSNAME).img $(INCDIR)/Sauce/Fonts/zap-light16.psf ::


$(OBJDIR)/Interrupts/Interrupts_cpp.o:$(SRCDIR)/Interrupts/Interrupts.cpp
	@echo ##$^ -> $@
	@mkdir -p $(@D)
	$(CC) -I$(INCDIR) -mno-red-zone -mgeneral-regs-only -ffreestanding -c $^ -o $@

$(OBJDIR)/%_cpp.o:$(SRCDIR)/%.cpp
	@echo ##$^ -> $@
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJDIR)/%_asm.o:$(SRCDIR)/%.asm
	@echo ##$^ -> $@
	@mkdir -p $(@D)
	$(ASMC) $(ASMFLAGS) $^ -f elf64 -o $@

$(BUILDDIR)/kernel.elf: $(OBJS)
	@echo ##$^ -> $@
	@mkdir -p $(@D)
	ld $(LDFLAGS) -o $(BUILDDIR)/kernel.elf $^

setup:
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(SRCDIR)
	@mkdir -p $(OBJDIR)


.PHONY: clean
clean:
	rm -frv bin/* lib/*

run: $(BUILDDIR)/$(OSNAME).img
	touch $(BUILDDIR)/$(OSNAME)_BlankDrive.img
	qemu-system-x86_64 -smp 2 -serial stdio -machine q35 -s -drive format=raw,file=$(BUILDDIR)/$(OSNAME).img -drive format=raw,file=$(BUILDDIR)/$(OSNAME)_BlankDrive.img -m 2G -cpu qemu64 -drive if=pflash,format=raw,unit=0,file="$(OVMFDIR)/OVMF_CODE-pure-efi.fd",readonly=on -drive if=pflash,format=raw,unit=1,file="$(OVMFDIR)/OVMF_VARS-pure-efi.fd" -net none
