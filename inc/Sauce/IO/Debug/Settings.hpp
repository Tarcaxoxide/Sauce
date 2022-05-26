namespace Sauce{
    namespace IO{
        namespace Debug{
            static const bool FUNCTION_CALLS=true;
            static const bool FUNCTION_DETAILS=false;
            static const bool FUNCTION_RETURNS=true;
            static const bool CONVERSIONS=false;
            static const bool INTERRUPT_MOUSE=false;
            static const bool INTERRUPT_KEYBOARD=false;
            static const bool INTERRUPT_PIT=false;
            static const bool INTERRUPT_FAULTS=true;
            static const bool INTERRUPT_DONE=false;
        };
    };
};

//#include<Sauce/IO/Debug/Console.hpp>


//function call      `[function]`
//if(Sauce::IO::Debug::FUNCTION_CALLS)Sauce::IO::Debug::COM1_Console.Write((char*)"[]\n\0");


//function detail    `->(detail values)`
//if(Sauce::IO::Debug::FUNCTION_DETAILS)Sauce::IO::Debug::COM1_Console.Write((char*)"\t->(\0");
    //details?
//if(Sauce::IO::Debug::FUNCTION_DETAILS)Sauce::IO::Debug::COM1_Console.Write((char*)")\n\0");


//function return    `<-(return value)`
//if(Sauce::IO::Debug::FUNCTION_RETURNS)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(\0");
    //return?
//if(Sauce::IO::Debug::FUNCTION_RETURNS)Sauce::IO::Debug::COM1_Console.Write((char*)")\n\0");