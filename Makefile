
.PHONY: default compile setup clean run

default: clean setup compile run

compile:
	###compile
	cd kernel && make
	cd gnu-efi && make bootloader

setup:
	###setup
	cd kernel && make setup
	cd gnu-efi && make 

clean:
	###clean
	cd kernel && make clean

run:
	###run
	cd kernel && make run