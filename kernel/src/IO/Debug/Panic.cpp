namespace Sauce{
    namespace IO{
        void Panic(const char* msg){
            asm volatile("cli;hlt");
        }
    };
};