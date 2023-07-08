# UEFI_Master - so i decided to try and convert my OS to uefi

- Requirements
	- sudo
		- create the disk image.
		- we create the image and make the partition table, then mount it to `/mnt/img` as a loopback device, then we just copy the files over and umount it.
	- kpartx
		- tool used to create the loopback device from the file in order to mount the partition the image contains.
	
	- nasm
		- for compiling the assembly files
	- gcc/clang
		- g++/clang++ for compiling the cpp files
	- qemu
		- qemu-system-x86_64 to run the produced .img file
	- dosfstools
		- mkfs.fat for generating the fat32 filesystem on the .img file
	- gnu make
		- to run the Makefiles ;)


# About the architecture

Firstly the kernel architecture is what is known as a megalithic kernel which means there is no task switching or user-mode.
you may refer to https://wiki.osdev.org/Megalithic_Kernel this page for more details.
there will however still be a "userland" however it will be a virtual machine, think like if you compile linux's userland to target KVM instead of the actual hardware.
for the virtual machine i am thinking of possibly using wasm for the binaries like...


```
[kernel]{
	[wasm interpreter]{
		[userland binary]{...binary...}
	}
}
```

this will allow me to have the simplicity of a megalithic kernel with the flexibility of a monolithic kernel while also keeping the speed of the megalithic kernel. and if i do indeed do wasm instead of something else than my "userland" will be pretty portable as well,  it could run on any platform with a browser basically.
