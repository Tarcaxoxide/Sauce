#pragma once

#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>
#include<float.h>
#include<iso646.h>
#include<limits.h>
#include<stdarg.h>

typedef struct{
    void* BaseAddress;
    size_t BufferSize;
    unsigned int Width;
    unsigned int Height;
    unsigned int PixelsPerScanLine;
}FrameBufferStructure;

typedef struct{
    uint64_t TestNumber;
    FrameBufferStructure* FrameBuffer;
}DataStructure;


typedef struct {
    uint8_t Red;
    uint8_t Green;
    uint8_t Blue;
    uint8_t Alpha;
}GOP_PixelStructure;