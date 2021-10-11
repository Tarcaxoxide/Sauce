#include <Shell.hpp>

namespace Sauce{
    namespace Shell{

        Sauce::Container::String LineBuffer;
        Sauce::Container::DynamicArray<Sauce::Container::String> Words;
        Sauce::Container::String NewString;
        
        void Command(){
            LineBuffer.Push(' ');
            Words.Clear();
            size_t WordCount=0;
            size_t j=0;
            for(size_t i=0;i<LineBuffer.Size();i++){
                if(*LineBuffer[i] != ' '){
                    NewString.Push(*LineBuffer[i]);
                }else{
                    Words.Push(NewString);
                    WordCount++;
                    NewString.Clear();
                }
            }

            if(Sauce::Utils::String_Compare_ReturnBool((*Words[0]).Raw(),(char*)"clear")){
                 Sauce::Terminal::Clear();
            }else if(Sauce::Utils::String_Compare_ReturnBool((*Words[0]).Raw(),(char*)"test")){
                 Sauce::Terminal::String("It worked!\n\r");
            }else if(Sauce::Utils::String_Compare_ReturnBool((*Words[0]).Raw(),(char*)"stop")){
                 STOP(User_Executed);
            }else{
                Sauce::Terminal::String("Unknown:\'");
                Sauce::Terminal::String( (*Words[0]).Raw() );
                Sauce::Terminal::String("\'\n\r");
            }
        }

        void KeyPress(Sauce::Keyboard::KeyboardKey _Key){
            if(_Key.Press){ 
                    char D=_Key.Display;
                    if(_Key.visible){
                        LineBuffer.Push(_Key.Display);
                        Sauce::Terminal::Character(_Key.Display);
                    }else{
                        switch(_Key.Key){
                            case 0x1C:{
                                Sauce::Terminal::BackSpace();
                                //LineBuffer[LineBufferCounter--]=0;
                                LineBuffer.Pop();
                                }break;
                            case 0xD6:{
                                Sauce::Terminal::NewLine();
                                Sauce::Terminal::ReturnCaret();
                                Command();
                                LineBuffer.Clear();
                                }break;
                            case 0xBE:{
                                //Sauce::Terminal::RelativeSetCursor(true,0,-1); //up arrow
                                }break;
                            case 0xCA:{
                                //Sauce::Terminal::RelativeSetCursor(true,1,0); //right arrow
                                }break;
                            case 0xC2:{
                                //Sauce::Terminal::RelativeSetCursor(true,0,1); //down arrow
                                }break;
                            case 0xB6:{
                                //Sauce::Terminal::RelativeSetCursor(true,-1,0); //left arrow
                                }break;
                        }
                    }
                }
            }
    };
};