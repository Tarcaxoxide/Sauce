.PHONY:


clean:
	cd kernel &&\
	make clean

purge: clean
	cd gnu-efi &&\
	make clean &&\
	make &&\
	make  bootloader

compile: clean
	cd gnu-efi &&\
	make bootloader
	cd kernel &&\
	make

restore:
	git restore .

commit: compile
	make clean
	git add .
	git commit -am "$(shell date)" 

push:
	git push "https://loganer%40vivaldi.net:$(shell cat ../git_token.txt)@github.com/Tarcaxoxide/Sauce.git"

run: compile
	cd kernel &&\
	make run