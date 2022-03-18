#pragma once

#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>
#include<float.h>
#include<iso646.h>
#include<limits.h>
#include<stdarg.h>
#include<Sauce/Memory/efiMemory.hpp>

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
    PSF1_FONT* Font;
    Sauce::EFI_MEMORY_DESCRIPTOR* mMap;
    uint64_t mMapSize;
    uint64_t mDescriptorSize;
}DataStructure;

static const GOP_PixelStructure GOP_RED={0x00,0x00,0xff,0xff};
static const GOP_PixelStructure GOP_GREEN={0x00,0xff,0x00,0xff};
static const GOP_PixelStructure GOP_BLUE={0xff,0x00,0x00,0xff};
static const GOP_PixelStructure GOP_YELLOW={0x00,0xff,0xff,0xff};
static const GOP_PixelStructure GOP_PURPLE={0xff,0x00,0xff,0xff};
static const GOP_PixelStructure GOP_CYAN={0xff,0xff,0x00,0xff};
static const GOP_PixelStructure GOP_WHITE={0xff,0xff,0xff,0xff};
static const GOP_PixelStructure GOP_BLACK={0x00,0x00,0x00,0xff};
