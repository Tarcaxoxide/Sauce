#pragma once

#include<Sauce/Terminal.hpp>

namespace Sauce{
    struct interrupt_frame;
    __attribute__((interrupt)) void PageFault_handler(struct interrupt_frame* frame);
};