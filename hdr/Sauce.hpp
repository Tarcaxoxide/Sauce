#pragma once
// this file is so i don't have to include the includes all Individually. it's basically an include <everything> .
// this is only really to be used for the kernel itself. using it for the other compile units might cause some issues. 
#include <stdint.h>
#include <stddef.h>
#include <KeyboardMaps.hpp>
#include <IO.hpp>
#include <Interrupts.hpp>
#include <Keyboard.hpp>
#include <Terminal.hpp>
#include <Convert.hpp>
#include <Memory.hpp>
#include <Graphics.hpp>
#include <Filesystem.hpp>
