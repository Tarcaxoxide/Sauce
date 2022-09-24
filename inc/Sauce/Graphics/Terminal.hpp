#pragma once

#include<Sauce/Common.hpp>
#include<Sauce/Types.hpp>
#include<Sauce/Math/Functions.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Graphics{
        class Terminal_cl{
            protected:
                GOP_PixelStructure* PixelBuffer=nullptr;
                size_t PixelBufferTotalSize,PixelsPerLine,PixelsBufferHeight;
                GOP_PixelStructure ForegroundColor{0xFF,0xFF,0xFF,0xFF},BackgroundColor{0x00,0x00,0x00,0x00};
				Sauce::Point64_st PixelPointer{0,0,0};
				Sauce::Point64_st MyOffset{0,0,0};
            public:
                char ID[64]{'\0'};
                Terminal_cl(Sauce::IO::Debug::Debugger_st* pDebugger,size_t PixelBufferTotalSize,size_t PixelsPerLine,Sauce::Point64_st Offset={0,0,0},GOP_PixelStructure* PixelBuffer=nullptr);
                bool SetColor(Sauce::IO::Debug::Debugger_st* pDebugger,GOP_PixelStructure ForegroundColor,GOP_PixelStructure BackgroundColor);
                bool SetColor(Sauce::IO::Debug::Debugger_st* pDebugger,GOP_PixelStructure ForegroundColor);
                void ReverseColor(Sauce::IO::Debug::Debugger_st* pDebugger);
                bool RowFill(Sauce::IO::Debug::Debugger_st* pDebugger,size_t RowIndex,GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF});
                bool ColumnFill(Sauce::IO::Debug::Debugger_st* pDebugger,size_t ColumnIndex,GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF});
                bool Fill(Sauce::IO::Debug::Debugger_st* pDebugger,GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF});
                bool PutPixel(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location,GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF});
                bool RowClear(Sauce::IO::Debug::Debugger_st* pDebugger,size_t RowIndex);
                bool ColumnClear(Sauce::IO::Debug::Debugger_st* pDebugger,size_t ColumnIndex);
                bool Clear(Sauce::IO::Debug::Debugger_st* pDebugger);
                bool SetCursor(Sauce::IO::Debug::Debugger_st* pDebugger,int64_t X,int64_t Y,int64_t Z=0);
                bool CopyTo(Sauce::IO::Debug::Debugger_st* pDebugger,GOP_PixelStructure* OtherPixelBuffer,size_t OtherPixelBufferTotalSize,size_t OtherPixelsPerLine,Sauce::Point64_st Offset={0,0,0});
                bool CopyFrom(Sauce::IO::Debug::Debugger_st* pDebugger,Terminal_cl* OtherTerminal);
                bool SwapTo(Sauce::IO::Debug::Debugger_st* pDebugger,GOP_PixelStructure* OtherPixelBuffer);
                bool SwapFrom(Sauce::IO::Debug::Debugger_st* pDebugger,Terminal_cl* OtherTerminal);
				Sauce::uPoint64_st Size(Sauce::IO::Debug::Debugger_st* pDebugger);
                bool Move(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Offset);
                void setID(Sauce::IO::Debug::Debugger_st* pDebugger,const char* nID);
                //Mouse related functions
                bool Is_Mouse_Over(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location);
				void Notify_Of_Mouse_Left_Down(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location);
                void Notify_Of_Mouse_Right_Down(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location);
                void Notify_Of_Mouse_Center_Down(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location);
				void Notify_Of_Mouse_Left_Up(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location);
				void Notify_Of_Mouse_Right_Up(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location);
				void Notify_Of_Mouse_Center_Up(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location);
                void Notify_Of_Mouse_Left_Drag(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location,Sauce::Point64_st OldLocation);
				void Notify_Of_Mouse_Right_Drag(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location,Sauce::Point64_st OldLocation);
				void Notify_Of_Mouse_Center_Drag(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location,Sauce::Point64_st OldLocation);
                void Notify_Of_Keyboard_Press(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Keyboard_st KeyData);
        };
    };
};



/*
(just ignore this XD , i keep forgetting this.)
    Rows are horizontal.
    Columns are vertical.
*/

