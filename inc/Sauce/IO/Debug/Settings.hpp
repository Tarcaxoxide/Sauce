namespace Sauce{
    namespace IO{
        namespace Debug{ // General overall settings
            static const bool FUNCTION_CALLS=true; // the first print of every function, this just tells us what function we are currently executing.
            static const bool FUNCTION_DETAILS=false; // anything after the FUNCTION_CALLS and before the FUNCTION_RETURNS.
            static const bool FUNCTION_RETURNS=false; // the value or values if a structure, we are returning to the calling function.
            static const bool SPAMMY=false; // prints i consider to be particularly spammy.
        };
        namespace Debug{ // specific settings
            static const bool CONVERSIONS=false;
            static const bool INTERRUPT_DONE=false;
            static const bool INTERRUPT_MOUSE=false;
            static const bool INTERRUPT_KEYBOARD=false;
            static const bool INTERRUPTS=false;
            static const bool INTERRUPT_PIT=false;
            static const bool INTERRUPT_FAULTS=false;
            static const bool BITMAP=false;
            static const bool MOUSE=true;
            static const bool KEYBOARD=true;
            static const bool SHELL=false;
            static const bool TERMINAL=true;
            static const bool INTERRUPT_DESCRIPTOR_TABLE=false;
            static const bool AHCI=false;
            static const bool PCI=false;
            static const bool MEMORY=false;
            static const bool KERNEL=true;
        };
    };
};

//#include<Sauce/IO/Debug/Console.hpp>


//function call      `[function]`

//function detail    `->(detail values)`

//function return    `<-(return value)`
