#include<Sauce/IO/Debug/Serial.hpp>
#include<Sauce/IO/Debug/Console.hpp>

#define DoNotCare(X,Y) extern "C" void X(){Sauce::IO::Debug::COM1_Console.Write((char*)"[\0");Sauce::IO::Debug::COM1_Console.Write((char*)Y);Sauce::IO::Debug::COM1_Console.Write((char*)"]\n\0");}




DoNotCare(__stack_chk_fail,"__stack_chk_fail\0");
DoNotCare(_Unwind_Resume,"_Unwind_Resume\0");
DoNotCare(__gxx_personality_v0,"__gxx_personality_v0\0");
DoNotCare(__dso_handle,"__dso_handle\0");
DoNotCare(__cxa_atexit,"__cxa_atexit\0");
DoNotCare(__cxa_throw_bad_array_new_length,"__cxa_throw_bad_array_new_length\0");
DoNotCare(__cxa_guard_acquire,"__cxa_guard_acquire\0");
DoNotCare(__cxa_guard_release,"__cxa_guard_release\0");
