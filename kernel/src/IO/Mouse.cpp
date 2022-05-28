#include<Sauce/IO/Mouse.hpp>
#include<Sauce/Kernel.hpp>
#include<Sauce/IO/IO.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utilities/Conversion.hpp>

namespace Sauce{
    namespace IO{
        Point64_t MousePosition {0,0,0};
        void MouseWait(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MOUSE)Sauce::IO::Debug::COM1_Console.Write((char*)"[MouseWait]\n\0");
            uint64_t timeout=100000;
            while(timeout--){
                if((inb(0x64) & 0b10) == 0){
                    return;
                }
            }
            if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::MOUSE)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(void)\n\0");
        }
        void MouseWaitInput(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MOUSE)Sauce::IO::Debug::COM1_Console.Write((char*)"[MouseWaitInput]\n\0");
            uint64_t timeout=100000;
            while(timeout--){
                if(inb(0x64) & 0b1){
                    return;
                }
            }
            if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::MOUSE)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(void)\n\0");
        }
        void MouseWrite(uint8_t value){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MOUSE)Sauce::IO::Debug::COM1_Console.Write((char*)"[MouseWrite]\n\0");
            MouseWait();
            outb(0x64,0xD4);
            MouseWait();
            outb(0x60,value);
            if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::MOUSE)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(void)\n\0");
        }
        uint8_t MouseRead(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MOUSE)Sauce::IO::Debug::COM1_Console.Write((char*)"[MouseRead]\n\0");
            MouseWaitInput();
            return inb(0x60);
            if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::MOUSE)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(void)\n\0");
        }
        uint8_t MouseCycle=0;
        uint8_t MousePacket[4];
        bool MousePacketReady=false;
        void HandlePS2Mouse(uint8_t data){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[HandlePS2Mouse]\n\0");
            switch(MouseCycle){
                case 0:{
                    if(MousePacketReady)break;
                    if((data & 0b00001000) == 0)break;
                    MousePacket[0]=data;
                    MouseCycle++;
                }break;
                case 1:{
                    if(MousePacketReady)break;
                    MousePacket[1] = data;
                    MouseCycle++;
                }break;
                case 2:{
                    if(MousePacketReady)break;
                    MousePacket[2] = data;
                    MousePacketReady=true;
                    MouseCycle=0;
                }break;
            }
            if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::MOUSE)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(void)\n\0");
        }
        Sauce::IO::Mouse_st nMouseData;
        Sauce::IO::Mouse_st* ProcessMousePacket(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[ProcessMousePacket]\n\0");
            nMouseData.Good=false;
            if(!MousePacketReady){
                if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::SPAMMY){
                    Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(\0");
                    nMouseData.RightButton ? Sauce::IO::Debug::COM1_Console.Write((char*)"RightButton:True,\0") : Sauce::IO::Debug::COM1_Console.Write((char*)"RightButton:False,\0");
                    nMouseData.LeftButton ? Sauce::IO::Debug::COM1_Console.Write((char*)"LeftButton:True,\0") : Sauce::IO::Debug::COM1_Console.Write((char*)"LeftButton:False,\0");
                    nMouseData.CenterButton ? Sauce::IO::Debug::COM1_Console.Write((char*)"CenterButton:True,\0") : Sauce::IO::Debug::COM1_Console.Write((char*)"CenterButton:False,\0");
                    Sauce::IO::Debug::COM1_Console.Write((char*)"Position:{X:\0");
                    Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::ToString(nMouseData.Position->X));
                    Sauce::IO::Debug::COM1_Console.Write((char*)",Y:\0");
                    Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::ToString(nMouseData.Position->Y));
                    Sauce::IO::Debug::COM1_Console.Write((char*)"},\0");
                    Sauce::IO::Debug::COM1_Console.Write((char*)"},Not Good\0");
                    Sauce::IO::Debug::COM1_Console.Write((char*)")\n\0");
                }
                return &nMouseData;
            }
            nMouseData.Good=true;

            bool xNegative,yNegative,xOverflow,yOverflow;
            
            xNegative=(bool)(MousePacket[0] & PS2XSign);
            yNegative=(bool)(MousePacket[0] & PS2YSign);
            xOverflow=(bool)(MousePacket[0] & PS2XOverflow);
            yOverflow=(bool)(MousePacket[0] & PS2YOverflow);

            if(!xNegative){
                MousePosition.X+=MousePacket[1];
                if(xOverflow){
                    MousePosition.X+=255;
                }
            }else{
                MousePacket[1]= 256 - MousePacket[1];
                MousePosition.X-=MousePacket[1];
                if(xOverflow){
                    MousePosition.X-=255;
                }
            }

            if(!yNegative){
                MousePosition.Y-=MousePacket[2];
                if(yOverflow){
                    MousePosition.Y-=255;
                }
            }else{
                MousePacket[2]= 256 - MousePacket[2];
                MousePosition.Y+=MousePacket[2];
                if(yOverflow){
                    MousePosition.Y+=255;
                }
            }
            MousePosition.Z=0;
            MousePacketReady=false;

            nMouseData.LeftButton=(MousePacket[0] & PS2LeftButton);
            nMouseData.CenterButton=(MousePacket[0] & PS2MiddleButton);
            nMouseData.RightButton=(MousePacket[0] & PS2RightButton);
            
            if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::SPAMMY){
                Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(\0");
                nMouseData.RightButton ? Sauce::IO::Debug::COM1_Console.Write((char*)"RightButton:True,\0") : Sauce::IO::Debug::COM1_Console.Write((char*)"RightButton:False,\0");
                nMouseData.LeftButton ? Sauce::IO::Debug::COM1_Console.Write((char*)"LeftButton:True,\0") : Sauce::IO::Debug::COM1_Console.Write((char*)"LeftButton:False,\0");
                nMouseData.CenterButton ? Sauce::IO::Debug::COM1_Console.Write((char*)"CenterButton:True,\0") : Sauce::IO::Debug::COM1_Console.Write((char*)"CenterButton:False,\0");
                Sauce::IO::Debug::COM1_Console.Write((char*)"Position:{X:\0");
                Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::ToString(nMouseData.Position->X));
                Sauce::IO::Debug::COM1_Console.Write((char*)",Y:\0");
                Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::ToString(nMouseData.Position->Y));
                Sauce::IO::Debug::COM1_Console.Write((char*)"},\0");
                Sauce::IO::Debug::COM1_Console.Write((char*)"},Good\0");
                Sauce::IO::Debug::COM1_Console.Write((char*)")\n\0");
            }
            return &nMouseData;
        }
        void PS2MouseInitialize(Point64_t InitMousePosition){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MOUSE)Sauce::IO::Debug::COM1_Console.Write((char*)"[PS2MouseInitialize]\n\0");
            MousePosition.X=InitMousePosition.X;
            MousePosition.Y=InitMousePosition.Y;
            MousePosition.Z=InitMousePosition.Z;
            nMouseData.Position=&MousePosition;
            outb(0x64,0xA8); // enable auxiliary device - mouse
            MouseWait();
            outb(0x64,0x20); // tell keyboard controller that we want to send a command to the mouse
            MouseWaitInput();
            uint8_t status = inb(0x60);
            status |= 0b10;
            MouseWait();
            outb(0x64,0x60);
            MouseWait();
            outb(0x60,status); // setting the correct bit , the "compaq" status byte.

            MouseWrite(0xF6);// 0xF6 , use default settings.
            MouseRead();

            MouseWrite(0xF4); // enable mouse
            MouseRead();
            if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::MOUSE)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(void)\n\0");
        }
    };
};