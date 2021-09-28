#include <Filesystem.hpp>

namespace Sauce{
    namespace Filesystem{
        _File FileTable[50];
        uint64_t FileTableIndex=0;

        void Initialize_Filesystem(){
        	Sauce::Terminal::String("Filesystem Init; Currently we do nothing for this.\n\r");
	}
        void AddFile(uint64_t Sector,char* Name){
            size_t nameSize=Sauce::Utils::String_Length(Name);
            if(nameSize > _File::NAME_SIZE)return;
            _File nFile;
            size_t A=0;

            for(A=0;A<=_File::NAME_SIZE;A++){
                nFile.Name[A] = 0;
            }
            for(A=0;A<nameSize;A++){
                nFile.Name[A] = Name[A];
            }
            nFile.Sector=Sector;
            nFile.ID=FileTableIndex++;
            FileTable[nFile.ID]=nFile;
            Sauce::Terminal::String("File Added::[Name=");
            Sauce::Terminal::String(nFile.Name);
            Sauce::Terminal::String(",ID=");
            Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64(nFile.ID));
            Sauce::Terminal::String("];\n\r");
        }
    };
};
