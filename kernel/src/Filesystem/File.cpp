#include<Sauce/Filesystem/File.hpp>
#include<Sauce/Global.hpp>

namespace Sauce{
	namespace Filesystem{
		namespace File{
			uint8_t File_st::operator[](size_t byte){
				CurrentByte=byte%Header.BytesPerSector;
				CurrentSector=Header.Sectors[(byte/Header.BytesPerSector)%Header.Sectors.Size()];
				CurrentSectorData.Clear();
				Sauce::Global::Storage::AHCIDrivers.First()->Read(Header.PortNumber,CurrentSector,1/*read 1 sector*/,CurrentSectorData);
				return CurrentSectorData[CurrentByte];
			}
		};
	};
};