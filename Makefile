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


run: compile
	cd kernel &&\
	make run