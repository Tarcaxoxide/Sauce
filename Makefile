.PHONY:

compile:
	cd gnu-efi &&\
	make bootloader
	cd kernel &&\
	make clean &&\
	make


purge:
	cd gnu-efi &&\
	make clean &&\
	make &&\
	make bootloader
	cd kernel &&\
	make clean&&\
	make

git_Push: compile
	git add .
	git commit -am "$(shell date)" 
	git push "https://loganer%40vivaldi.net:$(shell cat ../git_token.txt)@github.com/Tarcaxoxide/Sauce.git"

git_SwitchTo_Breakable:
	git checkout Breakable

git_SwitchTo_Master:
	git checkout UEFI_Master


run:
	cd kernel &&\
	make run

usb: compile
	@rm -frv USBdir
	@mkdir -p USBdir/efi/boot
	@cp gnu-efi/x86_64/bootloader/main.efi USBdir/efi/boot/bootx64.efi
	@cp kernel/bin/kernel.elf USBdir/kernel.elf
	@cp inc/Sauce/Fonts/zap-light16.psf USBdir/zap-light16.psf
	@sudo mkdir -p /mnt/usb
	@sudo mount ${USBdev} /mnt/usb
	@sudo rm -frv /mnt/usb/*
	@sudo cp -r USBdir/* /mnt/usb/
	@sudo umount /mnt/usb

iso: compile #doesn't work
	@rm -frv ISOdir Sauce.iso
	@mkdir -p ISOdir/efi/boot
	@cp gnu-efi/x86_64/bootloader/main.efi ISOdir/efi/boot/bootx64.efi
	@cp kernel/bin/kernel.elf ISOdir/kernel.elf
	@cp inc/Sauce/Fonts/zap-light16.psf ISOdir/zap-light16.psf
	@mkisofs -d -D -J -l -r -U -relaxed-filenames -o Sauce.iso ISOdir