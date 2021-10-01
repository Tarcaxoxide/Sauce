#pragma once
#include <Misc.hpp>
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
#include <Utils.hpp>
#include <Container.hpp>

namespace Sauce{
    namespace Shell{
        void KeyPress(Sauce::Keyboard::KeyboardKey _Key);
    };
};