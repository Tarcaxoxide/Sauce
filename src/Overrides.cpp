#include <Overrides.hpp>


void* operator new[](size_t size){
    return Sauce::Memory::alloc(size);
}
void operator delete[](void* pointer){
    Sauce::Memory::free(pointer);
}