#include<Sauce/Graphics/Shell/Language/Types.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace Sauce{
	namespace Graphics{
		namespace Shell{
			namespace Language{
				namespace Types{
					std::string Value::inspect(){
						Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Value::inspect()",_NAMESPACE_,_ALLOW_PRINT_);
						return "?";
					}
					std::string ListValue::inspect(){
						Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ListValue::inspect()",_NAMESPACE_,_ALLOW_PRINT_);
						std::string Result="(";
						for(size_t i=0;i<m_list.Size();i++){
							Result+=m_list[i]->inspect();
							Result+=",";
						}
						Result[Result.Size()-1]=')';
						return Result;
					}
					std::string SymbolValue::inspect(){
						Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"SymbolValue::inspect()",_NAMESPACE_,_ALLOW_PRINT_);
						return m_str;
					}
					Value::~Value(){}
					SymbolValue::~SymbolValue(){m_str="";}
					ListValue::~ListValue(){m_list.Clear();}
				};
			};
		};
	};
};