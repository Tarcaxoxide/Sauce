#pragma once

#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>
#include<float.h>
#include<iso646.h>
#include<limits.h>
#include<stdarg.h>

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

typedef struct{
    uint64_t TestNumber;
    FrameBufferStructure* FrameBuffer;
}DataStructure;


const static GOP_PixelStructure GOP_RED={0x00,0x00,0xff,0xff};
const static GOP_PixelStructure GOP_GREEN={0x00,0xff,0x00,0xff};
const static GOP_PixelStructure GOP_BLUE={0xff,0x00,0x00,0xff};
const static GOP_PixelStructure GOP_YELLOW={0x00,0xff,0xff,0xff};
const static GOP_PixelStructure GOP_PURPLE={0xff,0x00,0xff,0xff};
const static GOP_PixelStructure GOP_CYAN={0xff,0xff,0x00,0xff};
const static GOP_PixelStructure GOP_WHITE={0xff,0xff,0xff,0xff};
const static GOP_PixelStructure GOP_BLACK={0x00,0x00,0x00,0xff};
