#pragma once

#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>
#include<float.h>
#include<iso646.h>
#include<limits.h>
#include<stdarg.h>


#include<Sauce/Memory/efiMemory.hpp>
#include<Sauce/IO/ACPI.hpp>

typedef struct {
    uint8_t Blue;
    uint8_t Green;
    uint8_t Red;
    uint8_t Alpha;
}GOP_PixelStructure;

typedef struct{
    GOP_PixelStructure* BaseAddress;
    size_t BufferSize;
    unsigned int Width;
    unsigned int Height;
    unsigned int PixelsPerScanLine;
    unsigned int BytesPerPixel;
}FrameBufferStructure;

#define PSF1_MAGIC0 0x36
#define PSF1_MAGIC1 0x04

typedef struct{
    unsigned char magic[2];
    unsigned char mode;
    unsigned char char_size;
    unsigned char char_width;
    unsigned char char_height;
}PSF1_HEADER;

typedef struct{
    PSF1_HEADER* psf1_header;
    void* glyphBuffer;
}PSF1_FONT;


typedef struct{
    uint64_t TestNumber;
    FrameBufferStructure* FrameBuffer;
    uint64_t fbBase;
    uint64_t fbSize;
    PSF1_FONT* Font;
    Sauce::Memory::EFI_MEMORY_DESCRIPTOR* mMap;
    uint64_t mMapSize;
    uint64_t mDescriptorSize;
    Sauce::IO::ACPI::RSDP2* rsdp;
}DataStructure;
