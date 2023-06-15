#include<Sauce/IO/Debug/Serial.hpp>
#include<std/terminate.hpp>

#define DoNotCare(X,Y) extern "C" void X(){/*print Y*/asm volatile("cli;hlt");}


DoNotCare(__stack_chk_fail,"__stack_chk_fail\0");
DoNotCare(_Unwind_Resume,"_Unwind_Resume\0");
DoNotCare(__gxx_personality_v0,"__gxx_personality_v0\0");
DoNotCare(__dso_handle,"__dso_handle\0");
DoNotCare(__cxa_atexit,"__cxa_atexit\0");
DoNotCare(__cxa_throw_bad_array_new_length,"__cxa_throw_bad_array_new_length\0");
DoNotCare(__cxa_guard_acquire,"__cxa_guard_acquire\0");
DoNotCare(__cxa_guard_release,"__cxa_guard_release\0");
DoNotCare(__cxa_begin_catch,"__cxa_begin_catch\0");
DoNotCare(__clang_call_terminate,"__clang_call_terminate\0");
