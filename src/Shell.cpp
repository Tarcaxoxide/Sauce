#include <Shell.hpp>


namespace Sauce{
    namespace Shell{
        const size_t ShellBufferSize=512;
        char ShellBuffer[ShellBufferSize]={0};
        uint64_t CshellIndex=0;
        uint64_t Counter=0;


        void ClearBuffer(){
            

            for(;CshellIndex > 0;){
                ShellBuffer[CshellIndex--]=0;
            }
        }


        void split(const char* str, const char d, char** into)
        {
            if(str != NULL && into != NULL)
            {
                int n = 0;
                int c = 0;
                for(int i = 0; str[c] != '\0'; i++,c++)
                {
                    
                    into[n][i] = str[c];
                    if(str[c] == d)
                    {
                        into[n][i] = '\0';
                        i = -1;
                        ++n;
                        for(size_t I=0;I<c;I++){
                            into[n][I]='\0';
                        }
                    }
                }
            }
        }

        
        void Command(){
            char* tmstr[ShellBufferSize];
            char tmcmd[ShellBufferSize];
         
            for(size_t I=0;I < ShellBufferSize;I++){
                tmcmd[I]=ShellBuffer[I];
            }
            
            split((const char*)tmcmd,';',(char**)tmstr);
            
            if(Sauce::Utils::StringCompare(tmstr[0],"clear")){
                Sauce::Terminal::Clear();
            }else{
                Sauce::Terminal::String("Uknown:");
                Sauce::Terminal::String(tmstr[0]);
                Sauce::Terminal::String("\n\r");
            }
        }

        void KeyPress(Sauce::Keyboard::KeyboardKey _Key){
            if(_Key.visible && _Key.Press){
                ShellBuffer[CshellIndex++]=_Key.Display;
                Sauce::Terminal::Character(_Key.Display);
            }else if((!_Key.visible) && _Key.Press){
                switch(_Key.Key){
                    case 0x1C:{
                        Sauce::Terminal::BackSpace();
                        CshellIndex--;
                        }break;
                    case 0xD6:{//Enter
                        Sauce::Terminal::NewLine();
                        Sauce::Terminal::ReturnCaret();
                        ShellBuffer[CshellIndex++]=0;
                        Command();
                        ClearBuffer();
                        }break;
                    case 0xBE:{//up arrow
                        //Sauce::Terminal::RelativeSetCursor(true,0,-1); 
                        }break;
                    case 0xCA:{//right arrow
                        //Sauce::Terminal::RelativeSetCursor(true,1,0); 
                        }break;
                    case 0xC2:{//down arrow
                        //Sauce::Terminal::RelativeSetCursor(true,0,1); 
                        }break;
                    case 0xB6:{//left arrow
                        //Sauce::Terminal::RelativeSetCursor(true,-1,0); 
                        }break;
                }
            }
            
        }
        void ClockTick(){}
    };
};




/*
if(_Key.Press){ // we just have some testing code here I guess; a prototype key handler.
        char D=_Key.Display;
        if(D != NULL && _Key.visible){
            Sauce::Terminal::Character(D);
        }else if(_Key.visible){ // unhandled key.
            Sauce::Terminal::String("0x");
            Sauce::Terminal::String(Sauce::Convert::To_String::From_uint8(_Key.Key));
        }else{
            switch(_Key.Key){
                case 0x1C:{
                    Sauce::Terminal::BackSpace();
                    }break;
                case 0xD6:{
                    Sauce::Terminal::NewLine();
                    Sauce::Terminal::ReturnCaret();
                    }break;
                case 0xBE:{
                    Sauce::Terminal::RelativeSetCursor(true,0,-1); //up arrow
                    }break;
                case 0xCA:{
                    Sauce::Terminal::RelativeSetCursor(true,1,0); //right arrow
                    }break;
                case 0xC2:{
                    Sauce::Terminal::RelativeSetCursor(true,0,1); //down arrow
                    }break;
                case 0xB6:{
                    Sauce::Terminal::RelativeSetCursor(true,-1,0); //left arrow
                    }break;
            }
        }
    }
*/
