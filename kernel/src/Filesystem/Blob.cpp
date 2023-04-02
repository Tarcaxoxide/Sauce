#include<Sauce/Filesystem/Blob.hpp>
#include<Sauce/Global.hpp>
#include<std/string.hpp>
#include<std/to_string.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Blob{
			std::string Blob_st::List(){
				std::string Result="[";
				for(size_t i=0;i<Sub.Size();i++){
					switch(Sub[i].Header.Classification){
						case Sauce::Filesystem::Header::Classification_en::Classification_Data:{Result+="Data:";}break;
						case Sauce::Filesystem::Header::Classification_en::Classification_File:{Result+="File:";}break;
						case Sauce::Filesystem::Header::Classification_en::Classification_Directory:{Result+="Directory:";}break;
						case Sauce::Filesystem::Header::Classification_en::Classification_Descriptor:{Result+="Descriptor:";}break;
					}
					Result+="`";
					Result+=*Sub[i].Header.Name;
					Result+="`:";
					Result+=std::to_string(i);
					
					if(i<Sub.Size()-1)Result+=",";
				}
				Result+="]";
				return Result;
			}
			Blob_st& Blob_st::GetSub(size_t index){
				return Sub[index];
			}
			uint8_t& Blob_st::GetByte(size_t byte){
				CurrentByte=byte%Header.BytesPerSector;// we get the offset the byte is at within the sector
				size_t sector=Header.Sectors[(byte/Header.BytesPerSector)%Header.Sectors.Size()];// we get the sector number the byte is in (note:loops back around)
				if(sector != CurrentSector){// if we are reading from a different sector
					CurrentSector=sector;
					CurrentSectorData.Clear(); // we clear the old data
					Sauce::Global::Storage::AHCIDrivers.First()->Read(Header.PortNumber,CurrentSector,1/*read 1 sector*/,CurrentSectorData); //and read the new sector in
				}
				return CurrentSectorData[CurrentByte]; // we return the read byte.
			}
			void Blob_st::Add(Sauce::Memory::SmartPtr_cl<char,9> name,Sauce::Memory::SmartPtr_cl<char,4> ext,Sauce::Filesystem::Header::Classification_en classification){
				Sub.AddLast(Blob_st(name,ext,classification));
			}
		};
	};
};