#include<Sauce/IO/Mouse.hpp>
#include<Sauce/Kernel.hpp>
#include<Sauce/IO/IO.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utilities/Conversion.hpp>

namespace Sauce{
    namespace IO{
        Point64_t MousePosition {0,0,0};
        void MouseWait(){
            Sauce::IO::Debug::Print_Call("MouseWait",Sauce::IO::Debug::MOUSE);
            uint64_t timeout=100000;
            while(timeout--){
                if((inb(0x64) & 0b10) == 0){
                    return;
                }
            }
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::MOUSE);
        }
        void MouseWaitInput(){
            Sauce::IO::Debug::Print_Call("MouseWaitInput",Sauce::IO::Debug::MOUSE);
            uint64_t timeout=100000;
            while(timeout--){
                if(inb(0x64) & 0b1){
                    return;
                }
            }
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::MOUSE);
        }
        void MouseWrite(uint8_t value){
            Sauce::IO::Debug::Print_Call("MouseWrite",Sauce::IO::Debug::MOUSE);
            MouseWait();
            outb(0x64,0xD4);
            MouseWait();
            outb(0x60,value);
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::MOUSE);
        }
        uint8_t MouseRead(){
            Sauce::IO::Debug::Print_Call("MouseRead",Sauce::IO::Debug::MOUSE);
            MouseWaitInput();
            return inb(0x60);
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::MOUSE);
        }
        uint8_t MouseCycle=0;
        uint8_t MousePacket[4];
        bool MousePacketReady=false;
        void HandlePS2Mouse(uint8_t data){
            Sauce::IO::Debug::Print_Call("HandlePS2Mouse",Sauce::IO::Debug::MOUSE);
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
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::MOUSE);
        }
        Sauce::IO::Mouse_st nMouseData;
        Sauce::IO::Mouse_st* ProcessMousePacket(){
            Sauce::IO::Debug::Print_Call("ProcessMousePacket",Sauce::IO::Debug::MOUSE);
            nMouseData.Good=false;
            if(!MousePacketReady){
                nMouseData.RightButton ? Sauce::IO::Debug::Print_Return("RightButton:True",Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Start) : Sauce::IO::Debug::Print_Return("RightButton:False",Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Start);
                nMouseData.LeftButton ? Sauce::IO::Debug::Print_Return("LeftButton:True",Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Middle) : Sauce::IO::Debug::Print_Return("LeftButton:False",Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Middle);
                nMouseData.CenterButton ? Sauce::IO::Debug::Print_Return("CenterButton:True",Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Middle) : Sauce::IO::Debug::Print_Return("CenterButton:False",Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Return("{X:",Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Return(Sauce::Convert::ToString(nMouseData.Position->X),Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Return(",Y:",Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Return(Sauce::Convert::ToString(nMouseData.Position->Y),Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Return("},Not Good",Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::End);
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
            
            nMouseData.RightButton ? Sauce::IO::Debug::Print_Return("RightButton:True,",Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Start) : Sauce::IO::Debug::Print_Return("RightButton:False,",Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Start);
            nMouseData.LeftButton ? Sauce::IO::Debug::Print_Return("LeftButton:True,",Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Middle) : Sauce::IO::Debug::Print_Return("LeftButton:False,",Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Middle);
            nMouseData.CenterButton ? Sauce::IO::Debug::Print_Return("CenterButton:True,",Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Middle) : Sauce::IO::Debug::Print_Return("CenterButton:False,",Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Middle);
            Sauce::IO::Debug::Print_Return("{X:",Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Middle);
            Sauce::IO::Debug::Print_Return(Sauce::Convert::ToString(nMouseData.Position->X),Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Middle);
            Sauce::IO::Debug::Print_Return(",Y:",Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Middle);
            Sauce::IO::Debug::Print_Return(Sauce::Convert::ToString(nMouseData.Position->Y),Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::Middle);
            Sauce::IO::Debug::Print_Return("},Good",Sauce::IO::Debug::MOUSE,Sauce::IO::Debug::StartOfPrint::End);
            return &nMouseData;
        }
        void PS2MouseInitialize(Point64_t InitMousePosition){
            Sauce::IO::Debug::Print_Call("PS2MouseInitialize",Sauce::IO::Debug::MOUSE);
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
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::MOUSE);
        }
    };
};