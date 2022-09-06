namespace Sauce{
    namespace IO{
        namespace Debug{ // General overall settings
            static const bool FUNCTION_CALLS=true; // the first print of every function, this just tells us what function we are currently executing.
            static const bool FUNCTION_DETAILS=true; // anything after the FUNCTION_CALLS and before the FUNCTION_RETURNS.
            static const bool FUNCTION_RETURNS=true; // the value or values if a structure, we are returning to the calling function.
            static const bool SPAMMY=false; // prints i consider to be particularly spammy.
        };
        namespace Debug{ // specific settings
            static const bool CONVERSIONS=true;
            static const bool INTERRUPT_DONE=true;
            static const bool INTERRUPT_MOUSE=true;
            static const bool INTERRUPT_KEYBOARD=true;
            static const bool INTERRUPTS=true;
            static const bool INTERRUPT_PIT=true;
            static const bool INTERRUPT_FAULTS=true;
            static const bool BITMAP=true;
            static const bool MOUSE=true;
            static const bool KEYBOARD=true;
            static const bool SHELL=true;
            static const bool TERMINAL=true;
            static const bool WINDOW=true;
            static const bool INTERRUPT_DESCRIPTOR_TABLE=true;
            static const bool AHCI=true;
            static const bool PCI=true;
            static const bool MEMORY=true;
            static const bool HEAP=true;
            static const bool ALLOCATOR=true;
            static const bool INDEXER=true;
            static const bool TableManager=true;
            static const bool VirtualMachine=true;
            static const bool PAGING=true;
            static const bool STORAGE=true;
            static const bool KERNEL=true;
            static const bool NEUROL=true;
            static const bool MATH=false;
        };
    };
};

//#include<Sauce/IO/Debug/Console.hpp>


//function call      `[function]`

//function detail    `{detail values}`

//function return    `(return value)`


/*
Sauce::IO::Debug::Print_Call("",Sauce::IO::Debug::);
Sauce::IO::Debug::Print_Return("<void>",Sauce::IO::Debug::);
*/