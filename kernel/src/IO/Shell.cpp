#include<Sauce/IO/Shell.hpp>
#include<Sauce/Memory/PageFrameAllocator.hpp>
#include<Sauce/Memory/PageTableManager.hpp>
#include<Sauce/Convert/To_String.hpp>

namespace Sauce{
    namespace Shell{
        Kshell::Kshell(DataStructure* DFBL)
        :Term(DFBL){
            this->DFBL=DFBL;
            Sauce::IO::GlobalTerminal=&Term;
            
        }
        void Kshell::Input(Sauce::IO::InputData_st Data){
            if(Data.NewKeyboard){
                if(Data.Keyboard.Press){
                    switch(Data.Keyboard.Key){
                        case 0x1C:{
                            Sauce::IO::GlobalTerminal->BackSpace();
                        }break;
                        case 0x56:{/*Left Shift*/}break;
                        case 0x70:{/*Right Shift*/}break;
                        case 0x3A:{/*caps lock*/}break;
                        case 0xD6:{Term.PutString("\n\r");}break;
                        case 0xF8:{/*scr lk*/}break;
                        case 0x7E:{/*pause break*/}break;
                        case 0xC4:{/*ins*/}break;
                        case 0xB4:{/*home*/}break;
                        case 0xC8:{/*page up*/}break;
                        case 0xCE:{/*del*/}break;
                        case 0xB8:{/*end*/}break;
                        case 0xCC:{/*page down*/}break;
                        case 0xDA:{Sauce::IO::GlobalTerminal->Clear();}break;
                        case 0x7A:{/*alt*/}break;
                        default:{
                            if(Data.Keyboard.visible){
                                Term.PutChar(Data.Keyboard.Display);
                            }else{
                                Sauce::IO::GlobalTerminal->PutChar('[');
                                Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString(Data.Keyboard.Key));
                                Sauce::IO::GlobalTerminal->PutChar(']');
                            }
                        }break;
                    }
                }
            }
            if(Data.NewMouse && Data.Mouse.Good){
                if(Data.Mouse.RightButton){
                    Sauce::IO::GlobalTerminal->SetCursor(Data.Mouse.Position.X+DFBL->Font->psf1_header->char_width,Data.Mouse.Position.Y);
                }
                Term.Mouse(&Data.Mouse.Position);
            }
        }
        
    };
};