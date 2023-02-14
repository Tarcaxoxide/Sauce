#include<Sauce/Graphics/Terminal.hpp>
#pragma once
namespace Sauce{
    namespace Graphics{
        class Shell_cl : public Basic::Terminal_cl {
			Sauce::Point64_st Cursor{0,0,0};
            _std::string CharBuffer;
            public:
                Shell_cl(Sauce::Point64_st Size,Sauce::Point64_st Offset={0,0,0});
                void PutChar(char chr,bool AddToBuffer);
                void PutString(_std::string str,bool AddToBuffer);
                bool GoDown(size_t amount=1);
                bool GoUp(size_t amount=1);
                bool GoRight(size_t amount=1);
                bool GoLeft(size_t amount=1);
                void GoFarDown();
                void GoFarUp();
                void GoFarRight();
                void GoFarLeft();
                void ParseAndRunCommand();
                void ShellClear(bool ClearScreen);
        };
    };
};
