#include<Sauce/IO/Shell.hpp>

namespace Sauce{
    namespace Shell{
        Kshell::Kshell(DataStructure* DFBL)
        :Term(DFBL){
            this->DFBL=DFBL;
            Sauce::IO::GlobalTerminal=&Term;
        }
        void Kshell::InputKeyboard(Sauce::IO::Keyboard_st xKeyboard){
            if(xKeyboard.Press){
                switch(xKeyboard.Key){
                    case 0x1C:{
                        Sauce::IO::GlobalTerminal->BackSpace();
                    }break;
                    case 0x56:{/*Left Shift*/}break;
                    case 0x70:{/*Right Shift*/}break;
                    case 0x3A:{/*caps lock*/}break;
                    case 0xD6:{/*enter*/}break;
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
                        if(xKeyboard.visible){
                            Term.PutChar(xKeyboard.Display);
                        }else{
                            Sauce::IO::GlobalTerminal->PutChar('[');
                            Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString(xKeyboard.Key));
                            Sauce::IO::GlobalTerminal->PutChar(']');
                        }
                    }break;
                }
            }
        }
        void Kshell::InputMouse(Sauce::IO::Mouse_st* xMouse){
            Term.Mouse(xMouse->Position);
        }
    };
};