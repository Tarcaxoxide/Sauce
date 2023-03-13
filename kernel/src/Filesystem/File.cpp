#include<Sauce/Filesystem/File.hpp>
#include<Sauce/Global.hpp>

namespace Sauce{
	namespace Filesystem{
		namespace File{
			uint8_t& File_st::operator[](size_t byte){
				CurrentByte=byte%Header.BytesPerSector;// we get the offset the byte is at within the sector
				size_t sector=Header.Sectors[(byte/Header.BytesPerSector)%Header.Sectors.Size()];// we get the sector number the byte is in (note:loops back around)
				if(sector != CurrentSector){// if we are reading from a different sector
					CurrentSector=sector;
					CurrentSectorData.Clear(); // we clear the old data
					Sauce::Global::Storage::AHCIDrivers.First()->Read(Header.PortNumber,CurrentSector,1/*read 1 sector*/,CurrentSectorData); //and read the new sector in
				}
				return CurrentSectorData[CurrentByte]; // we return the read byte.
			}
		};
	};
};