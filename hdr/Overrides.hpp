#pragma once

#include <stdint.h>
#include <stddef.h>
#include <Memory.hpp>

void* operator new[](size_t);
void operator delete[](void*, size_t);
