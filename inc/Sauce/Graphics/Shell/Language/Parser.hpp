#ifndef __Sauce_Graphics_Shell_Language_Parser
#define __Sauce_Graphics_Shell_Language_Parser
#include<std/string.hpp>
#include<stddef.h>
#include<stdint.h>
namespace Sauce{
    namespace Graphics{
        namespace Shell{
            namespace Language{
                class Parser_cl{
                    Parser_cl* ParentParser{nullptr};
                    public:
                        Parser_cl(Parser_cl* OtherParser=nullptr):ParentParser(OtherParser){}
                };
            };
        };
    };
};
#endif