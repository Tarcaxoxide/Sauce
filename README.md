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

# working on...
- partial implementation
	- Filesystem
		- FAT32
		- VFS
- Currently
	- trying out creating a Lisp (if successfull i might use this instead of wasm)
- Planned
    - fix the timer (not really urgent since nothing i do is really time sensitive, but i suppose it would be nice to have a sane relative time XD).
	- Userland (can't really do this without the filesystem in place first)
		- do research on (~wasm?)
		- (~wasm?) interpreter
		- desktop GUI in (~wasm?)
	- DAVAS (much much later)
		- Natural langauge processing
		- Generic hook function for DAVAS to execute different features.
			- probing functions for gathering information about the hardware
			- probing functions for gathering information about the software
			- disk read and write functions
			- math functions to perform redumentary calculations
			- Graphics functions to draw images such as graphs and diagrams
			- Ethernet functions for querying data from various places (maybe? implement an optional crawler but that wont be untill quite far into the future indeed). 
		- DAVAS (the AI itself needs to be created, obviously)
	
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

# notes/quirks
- 'terminal' in this context is basically an object that manages a framebuffer, it holds the framebuffer and data about the framebuffer such as it's size and offset and were it's pixel cursor and it's responsible for actually putting the framebuffer onto the screen which is also a framebuffer and this process is done through copying the data over to the screen (using memcpy of course).
- 'cursor' there are 3 distinct types of cursor, you have the mouse cursor which is the one you click with, you have the text cursor which shell object has for placing text, and you have the pixel cursor for graphics drawing.
- 'shell' inherits from 'terminal' and is responsible for drawing text to the framebuffer housed by the 'terminal' object class.
- 'window' inherits from 'shell' and is responsible for graphical things such as mouse clicks and later on it will deal with drawing shapes to the framebuffer.
- 'mouse'(cursor) the visible cursor on the screen that you click with inherites from 'terminal' , it draws itself to it's own small framebuffer which than later gets copied to the screen at the the mouse cursor's offset which is set when we recieve a mouse interrupt.
- 'Global' is just a collection of globally available objects such as the ahci driver and the kernel object.
- 'kernel' in this context it sort of has a double meaning, it can refer to the object with is kind of the central control of the kernel and the larger kernel as a whole. the reason for this is if i switch out my bootloader all i have to do is take the data the new bootload gives me and recreate the original data structure from it and pass it to the kernel object during initialization, effectively i can change bootloaders and the majority of the kernel doesn't need to know about it.
- there is/will be a std library but effectively it will just be proxy functions to the implementations inside the Sauce namespace except 'std::cin' which i don't know if that is even possible currently.