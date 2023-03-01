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
	make  bootloader
	cd kernel &&\
	make clean

commit: compile
	git add .
	git commit -am "$(shell date)" 

push: commit
	git push "https://loganer%40vivaldi.net:$(shell cat ../git_token.txt)@github.com/Tarcaxoxide/Sauce.git"

run: compile
	cd kernel &&\
	make run