# UEFI_Master - so i decided to try and convert my OS to uefi

- Requirements
    - mtools
        - mcopy
        - mmd
    - nasm
    - gcc
        - g++
    - qemu
        - qemu-system-x86_64
    - dosfstools
        - mkfs.fat
    - cdrtools
        - mkisofs

# documentation of functions and variable types that I think might be of interest.
- `Sauce::Memory::DynamicArray_cl`
    - base class for dynamic arrays, it acts sort of like a deque
- `Sauce::Memory::List_cl`
    - this is my answer to `std::string` except better because it can contain any type instead of just `char`
- `Sauce::IO::outb(Port,Value)`
    - it calls the assembly version.
    - also has a slow version `Sauce::IO::outb_w(Port,Value)`, _w for wait
- `Sauce::IO::inb(Port)`
    - it calls the assembly version.
    - also has a slow version `Sauce::IO::inb_w(Port)`, _w for wait
- `Sauce::IO::GlobalTerminal`
    - `->PutString(VALUE)`
        - places the string `VALUE`
    - `->PutChar(VALUE)`
        - places the char `VALUE`
    - `->PutCharAt(VALUE,X,Y)`
        - places the char `VALUE` at `X`x`Y`
    - `->NewLine()`
        - calls `DownwardChar()` , it will scroll when i actually get around to implement that
    - `->ForwardChar()`
        - goes +1 char in the X direction, returns false if it could not
    - `->BackwardChar()`
        - goes -1 char in the X direction, returns false if it could not
    - `->UpwardChar()`
        - goes -1 char in the Y direction, returns false if it could not
    - `->DownwardChar()`
        - goes +1 char in the Y direction, returns false if it could not
    - `->TopChar()`
        - goes to the top of the screen, stays in the same column
    - `->BottomChar()`
        - goes to the bottom of the screen, stays in the same column
    - `->FrontChar()`
        - goes to the far left of the screen, stays in the same row
    - `->BackChar()`
        - goes to the far right of the screen, stays in the same row
    - `->ReturnCaret()`
        - calls `FrontChar()`
    - `->BackSapce()`
        - it goes back 1 char. just like you would think
    - `->Clear()`
        - it clears the screen and sets the cursor to the top left
    - `->Fill(VALUE)`
        - fills the entire screen with char `VALUE`
    - `->FillColumn(VALUE,NUM)`
        - fills column `NUM` with char `VALUE`
    - `->FillRow(VALUE,NUM)`
        - fills row `NUM` with char `VALUE`
    - `->SetColor(VALUE1,VALUE2)`
        - takes 1 or 2 BGRA structs and sets the foreground to `VALUE1` and the background to `VALUE2`, `VALUE2` is optional
    - `->MaxY(NUM)`
        - returns the Maximum value you can set for something on the screen, takes into account `NUM` which is the something size in the Y direction
    - `->MaxX(NUM)`
        - returns the Maximum value you can set for something on the screen, takes into account `NUM` which is the something size in the X direction
    - `->CharX()`
        - returns the size of a char in the X direction
    - `->CharY()`
        - returns the size of a char in the Y direction
    - `->SetCursor(X,Y)`
        - sets the cursor to `X`x`Y` (not the mouse cursor, the text one)

# plans
- things done.
    - Text output "printf"
    - Dynamic Memory
    - strings "std::string" <- `Sauce::Memory::List_cl<char> StringVariableName`
- Not yet done.
    - Userland Virtual Machines
    - UserLand Binary Compiler
    - UserLand binaries
    - disk access
    - loading of UserLand binaries
    - Multi-processing (not multi-threading)
    - graphics
    - hardware accelerated graphics









not exactly my dream keyboard however i would classify it under 'pretty damn decent'