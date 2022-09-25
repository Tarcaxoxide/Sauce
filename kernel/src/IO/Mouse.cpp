#include<Sauce/IO/Mouse.hpp>
#include<Sauce/Kernel.hpp>
#include<Sauce/IO/IO.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>

namespace Sauce{
    namespace IO{
		Sauce::Point64_st MousePosition {0,0,0};
        void MouseWait(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"MouseWait",_NAMESPACE_);
            uint64_t timeout=100000;
            while(timeout--){
                if((inb(0x64) & 0b10) == 0){
                    return;
                }
            }
        }
        void MouseWaitInput(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"MouseWaitInput",_NAMESPACE_);
            uint64_t timeout=100000;
            while(timeout--){
                if(inb(0x64) & 0b1){
                    return;
                }
            }
        }
        void MouseWrite(Sauce::IO::Debug::Debugger_st* pDebugger,uint8_t value){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"MouseWrite",_NAMESPACE_);
            MouseWait(&Debugger);
            outb(0x64,0xD4);
            MouseWait(&Debugger);
            outb(0x60,value);
        }
        uint8_t MouseRead(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"MouseRead",_NAMESPACE_);
            MouseWaitInput(&Debugger);
            return inb(0x60);
        }
        uint8_t MouseCycle=0;
        uint8_t MousePacket[4];
        bool MousePacketReady=false;
        void HandlePS2Mouse(Sauce::IO::Debug::Debugger_st* pDebugger,uint8_t data){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"HandlePS2Mouse",_NAMESPACE_);
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
        }
        Sauce::Mouse_st nMouseData;
        Sauce::Mouse_st* ProcessMousePacket(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"ProcessMousePacket",_NAMESPACE_);
            nMouseData.Good=false;
            if(!MousePacketReady){
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
            
            return &nMouseData;
        }
        void PS2MouseInitialize(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st InitMousePosition){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PS2MouseInitialize",_NAMESPACE_);
            MousePosition.X=InitMousePosition.X;
            MousePosition.Y=InitMousePosition.Y;
            MousePosition.Z=InitMousePosition.Z;
            nMouseData.Position=&MousePosition;
            outb(0x64,0xA8); // enable auxiliary device - mouse
            MouseWait(&Debugger);
            outb(0x64,0x20); // tell keyboard controller that we want to send a command to the mouse
            MouseWaitInput(&Debugger);
            uint8_t status = inb(0x60);
            status |= 0b10;
            MouseWait(&Debugger);
            outb(0x64,0x60);
            MouseWait(&Debugger);
            outb(0x60,status); // setting the correct bit , the "compaq" status byte.

            MouseWrite(&Debugger,0xF6);// 0xF6 , use default settings.
            MouseRead(&Debugger);

            MouseWrite(&Debugger,0xF4); // enable mouse
            MouseRead(&Debugger);
        }
    };
};
