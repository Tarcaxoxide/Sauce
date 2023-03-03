# UEFI_Master - so i decided to try and convert my OS to uefi

- Requirements
	- mtools
		- mcopy copying files over to the .img file
		- mmd for creating directories in the .img file
	- nasm
		- for compiling the assembly files
	- gcc/clang
		- g++/clang++ for compiling the cpp files
	- qemu
		- qemu-system-x86_64 to run the produced .img file
	- dosfstools
		- mkfs.fat for generating the fat32 filesystem on the .img file
	- cdrtools
		- mkisofs for producing the final .img file.
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

# notes/quirks
- 'terminal' in this context is basically an object that manages a framebuffer, it holds the framebuffer and data about the framebuffer such as it's size and offset and were it's pixel cursor and it's responsible for actually putting the framebuffer onto the screen which is also a framebuffer and this process is done through copying the data over to the screen (using memcpy of course).
- 'cursor' there are 3 distinct types of cursor, you have the mouse cursor which is the one you click with, you have the text cursor which shell object has for placing text, and you have the pixel cursor for graphics drawing.
- 'shell' inherits from 'terminal' and is responsible for drawing text to the framebuffer housed by the 'terminal' object class.
- 'window' inherits from 'shell' and is responsible for graphical things such as mouse clicks and later on it will deal with drawing shapes to the framebuffer.
- 'mouse'(cursor) the visible cursor on the screen that you click with inherites from 'terminal' , it draws itself to it's own small framebuffer which than later gets copied to the screen at the the mouse cursor's offset which is set when we recieve a mouse interrupt.
- 'Global' is just a collection of globally available objects such as the ahci driver and the kernel object.
- 'kernel' in this context it sort of has a double meaning, it can refer to the object with is kind of the central control of the kernel and the larger kernel as a whole. the reason for this is if i switch out my bootloader all i have to do is take the data the new bootload gives me and recreate the original data structure from it and pass it to the kernel object during initialization, effectively i can change bootloaders and the majority of the kernel doesn't need to know about it.
- there is/will be a std library but effectively it will just be proxy functions to the implementations inside the Sauce namespace except 'std::cin' which i don't know if that is even possible currently.