#pragma once

enum StandardMessageState : uint64_t{
    STATE__NULL=0,
    STATE__GOOD,
    STATE__BAD,
    STATE__TIME_SCALE_MILLISECONDS,
    STATE__TIME_SCALE_SECONDS,
    STATE__TIME_SCALE_MINUTES,
    STATE__TIME_SCALE_HOURS,
    STATE__TIME_SCALE_CUSTOM_DIVIDED,
    STATE__TIME_SCALE_CUSTOM_MULTIPLIED,
    STATE__ITC_MOUSE,
    STATE__ITC_KEYBOARD,
    STATE__ITC_TIME,
    STATE__GET_INFO
};

typedef struct {
    StandardMessageState State{StandardMessageState::STATE__NULL}; // 64 bytes
    void* ptr{nullptr}; // 128 bytes
    union{ // 256 bytes
        uint64_t code64[2]{0x0000000000000000};
        uint32_t code32[4];
        uint16_t code16[8];
        uint8_t code8[16];
        uint64_t* ptrs[2];
    };
} StandardMessage_st; // the StandardMessage is exactly 1 (256 byte) sector in size.


/* "structure" of the code union, horizontal takes up the same space.
    [00]    code8[0]    code16[0]   code32[0]   code64[0]
    [01]    code8[1]    code16[0]   code32[0]   code64[0]
    [03]    code8[2]    code16[1]   code32[0]   code64[0]
    [04]    code8[3]    code16[1]   code32[0]   code64[0]
    [05]    code8[4]    code16[2]   code32[1]   code64[0]
    [06]    code8[5]    code16[2]   code32[1]   code64[0]
    [07]    code8[6]    code16[3]   code32[1]   code64[0]
    [08]    code8[7]    code16[3]   code32[1]   code64[0]
    [09]    code8[8]    code16[4]   code32[2]   code64[1]
    [10]    code8[9]    code16[4]   code32[2]   code64[1]
    [11]    code8[10]   code16[5]   code32[2]   code64[1]
    [12]    code8[11]   code16[5]   code32[2]   code64[1]
    [13]    code8[12]   code16[6]   code32[3]   code64[1]
    [14]    code8[13]   code16[6]   code32[3]   code64[1]
    [15]    code8[14]   code16[7]   code32[3]   code64[1]
    [16]    code8[15]   code16[7]   code32[3]   code64[1]
*/