#include<Sauce/Graphics/Shell/Lisp/Tokenizer.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
	namespace Graphics{
		namespace Shell{
			namespace Lisp{
				std::list<std::string> Tokenizer(const std::string input){
					Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Tokenizer",_NAMESPACE_,_ALLOW_PRINT_);
					Debugger.Print(input);
					std::list<std::string> Result;
					Result.Clear();
					std::string Buffer="";
					for(size_t i=0;i<input.Size();i++){
						switch(input[i]){
							case ' ':case '\t':case '\n':{
								if(Buffer.Size()){Result.AddLast(Buffer);Debugger.Print(Buffer);Buffer="";}
							}break;
							case '[':case ']':case '(':case ')':case '{':case '}':{
								if(Buffer.Size()){Result.AddLast(Buffer);Debugger.Print(Buffer);Buffer="";}
								Debugger.Print(input.Substr(i,1));
								Result.AddLast(input.Substr(i,1));
							}break;
							case '"':{
								if(Buffer.Size()){Result.AddLast(Buffer);Debugger.Print(Buffer);Buffer="";}
								size_t start=i;
								while(i+1<input.Size()&&input[i+1]!='"')i++;
								if(i+1<input.Size()&&input[i+1]=='"')i++;
								size_t length=i-start;
								Debugger.Print(input.Substr(start,length+1));
								Result.AddLast(input.Substr(start,length+1));
							}break;
							default:{
								Buffer+=input[i];
							}break;
						}
					}
					return Result;
				}
			};
		};
	};
};