#include<Sauce/IO/Mouse.hpp>


namespace Sauce{
    namespace IO{
        Point64_t MousePosition {0,0,0};
        Point64_t OldMousePosition {0,0,0};
        void MouseWait(){
            uint64_t timeout=100000;
            while(timeout--){
                if((inb(0x64) & 0b10) == 0){
                    return;
                }
            }
        }
        void MouseWaitInput(){
            uint64_t timeout=100000;
            while(timeout--){
                if(inb(0x64) & 0b1){
                    return;
                }
            }
        }
        void MouseWrite(uint8_t value){
            MouseWait();
            outb(0x64,0xD4);
            MouseWait();
            outb(0x60,value);
        }
        uint8_t MouseRead(){
            MouseWaitInput();
            return inb(0x60);
        }
        uint8_t MouseCycle=0;
        uint8_t MousePacket[4];
        bool MousePacketReady=false;
        void HandlePS2Mouse(uint8_t data){
            switch(MouseCycle){
                case 0:{
                    if(MousePacketReady)break;
                    if(data & 0b00001000 == 0)break;
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
        void ProcessMousePacket(){
            if(!MousePacketReady)return;

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
            MousePacketReady=false;

            Sauce::IO::GlobalTerminal->Mouse(MousePosition);
        }
        void PS2MouseInitialize(){
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
            
        }
    };
};