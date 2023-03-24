#include<Sauce/Filesystem/FAT32.hpp>
#include<Sauce/Global.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
#include<std/string.hpp>
#include<Sauce/Utility/Conversion.hpp>

#include<Sauce/Memory/SmartPtr.hpp>

namespace Sauce{
	namespace Filesystem{
		namespace FAT32{
			FAT32_cl::FAT32_cl(size_t portNumber,size_t partitionNumber):Sauce::Filesystem::MsDosPartition::MsDosPartition_cl(portNumber){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"FAT32_cl::FAT32_cl",_NAMESPACE_,_ALLOW_PRINT_);
				PartitionNumber=partitionNumber;
				PartitionTableEntry= &MasterBootRecord.PrimaryPartitionTableEntries[partitionNumber];
				Sauce::Memory::SmartPtr_cl<char,9> NameContainer('\0');
				Sauce::Global::Filesystem::RootDirectory.Sub.AddLast(ReadDirectory(PartitionTableEntry->LbaStart,NameContainer));
			}
			Sauce::Filesystem::Blob::Blob_st FAT32_cl::ReadDirectory(size_t Offset,Sauce::Memory::SmartPtr_cl<char, 9> directoryName){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"FAT32_cl::ReadDirectory",_NAMESPACE_,_ALLOW_PRINT_);
				std::string buff;
				buff.Clear();
				buff+="Reading:{";
				buff+=directoryName.Dumb();
				buff+=",";
				buff+=Sauce::Utility::Conversion::HexToString(Offset);
				buff+="}";
				Debugger.Print(buff);
				Sauce::Memory::SmartPtr_cl<char,4> ExtContainer('\0');
				Sauce::Filesystem::Blob::Blob_st Directory(directoryName,ExtContainer,Sauce::Filesystem::Header::Classification_en::Classification_Directory);
				Directory.Header.Sectors.AddLast(Offset);
				Directory.Header.PortNumber=PortNumber;
				Sauce::Global::Storage::AHCIDrivers.First()->Read(PortNumber,Directory.Header.Sectors.First(),BiosParameterBlock);
				
				buff.Clear();
				buff+="Jump:";
				for(int i=0;i<3;i++)buff+=Sauce::Utility::Conversion::HexToString(BiosParameterBlock.Jump[i]);
				buff+=",SoftName:";
				for(int i=0;i<8;i++)buff+=(char)BiosParameterBlock.SoftName[i];
				buff+=",BytesPerSector:";
				buff+=Sauce::Utility::Conversion::ToString(BiosParameterBlock.BytesPerSector);
				buff+=",SectorsPerCluster:";
				buff+=Sauce::Utility::Conversion::ToString(BiosParameterBlock.SectorsPerCluster);
				buff+=",ReservedSectors:";
				buff+=Sauce::Utility::Conversion::ToString(BiosParameterBlock.ReservedSectors);
				buff+=",FatCopies:";
				buff+=Sauce::Utility::Conversion::ToString(BiosParameterBlock.FatCopies);
				buff+=",RootDirectoryEntries:";
				buff+=Sauce::Utility::Conversion::ToString(BiosParameterBlock.RootDirectoryEntries);
				buff+=",TotalSectors:";
				buff+=Sauce::Utility::Conversion::ToString(BiosParameterBlock.TotalSectors);
				buff+=",MediaType:";
				buff+=Sauce::Utility::Conversion::HexToString(BiosParameterBlock.MediaType);
				buff+=",FatSectorCount:";
				buff+=Sauce::Utility::Conversion::ToString(BiosParameterBlock.FatSectorCount);
				buff+=",SectorsPerTrack:";
				buff+=Sauce::Utility::Conversion::ToString(BiosParameterBlock.SectorsPerTrack);
				buff+=",HeadCount:";
				buff+=Sauce::Utility::Conversion::ToString(BiosParameterBlock.HeadCount);
				buff+=",HiddenSectors:";
				buff+=Sauce::Utility::Conversion::ToString(BiosParameterBlock.HiddenSectors);
				buff+=",TotalSectorCount:";
				buff+=Sauce::Utility::Conversion::ToString(BiosParameterBlock.TotalSectorCount);
				buff+=",TableSize:";
				buff+=Sauce::Utility::Conversion::ToString(BiosParameterBlock.TableSize);
				buff+=",ExtFlags:";
				buff+=Sauce::Utility::Conversion::HexToString(BiosParameterBlock.ExtFlags);
				buff+=",FatVersion:";
				buff+="`";
				buff+=Sauce::Utility::Conversion::ToString(BiosParameterBlock.FatVersion[0]);
				buff+=":";
				buff+=Sauce::Utility::Conversion::ToString(BiosParameterBlock.FatVersion[1]);
				buff+="`";
				buff+=",RootCluster:";
				buff+=Sauce::Utility::Conversion::HexToString(BiosParameterBlock.RootCluster);
				buff+=",FatInfo:";
				buff+=Sauce::Utility::Conversion::HexToString(BiosParameterBlock.FatInfo);
				buff+=",BackupSector:";
				buff+=Sauce::Utility::Conversion::HexToString(BiosParameterBlock.BackupSector);
				buff+=",DriveNumber:";
				buff+=Sauce::Utility::Conversion::HexToString(BiosParameterBlock.DriveNumber);
				buff+=",BootSignature:";
				buff+=Sauce::Utility::Conversion::HexToString(BiosParameterBlock.BootSignature);
				buff+=",VolumeId:";
				buff+=Sauce::Utility::Conversion::HexToString(BiosParameterBlock.VolumeId);
				buff+=",VolumeLabel:";
				for(int i=0;i<11;i++){Directory.Header.Name[i]=(char)BiosParameterBlock.VolumeLabel[i];buff+=(char)BiosParameterBlock.VolumeLabel[i];}
				buff+=",FatTypeLabel:";
				for(int i=0;i<8;i++)buff+=(char)BiosParameterBlock.FatTypeLabel[i];
				Debugger.Print(buff);
				uint32_t fatStart = PartitionTableEntry->LbaStart + BiosParameterBlock.ReservedSectors;
				uint32_t fatSize = BiosParameterBlock.TableSize;
				uint32_t dataStart = fatStart+fatSize*BiosParameterBlock.FatCopies;
				uint32_t rootStart = dataStart + BiosParameterBlock.SectorsPerCluster*(BiosParameterBlock.RootCluster-2);
				DirectoryEntry_st dirent[16];
				Sauce::Global::Storage::AHCIDrivers.First()->Read(PortNumber,rootStart,dirent);
				buff.Clear();
				Sauce::Memory::SmartPtr_cl<char,9> NameContainer('\0');
				//Sauce::Memory::SmartPtr_cl<char,4> ExtContainer('\0');


				for(int i=0;i<16;i++){
					DirectoryEntry_st& cdirent=dirent[i];
					buff.Clear();
					if(cdirent.Name[0] == 0x00)break;//No more entries.
					if((cdirent.Attributes & 0x0F) == 0x0F)continue;//long name entry
					buff+="Entry[";
					buff+=Sauce::Utility::Conversion::ToString(i);
					buff+="]";
					buff+=",Name:";
					for(int z=0;z<8;z++){buff+=(char)cdirent.Name[z];NameContainer[z]=(char)cdirent.Name[z];}
					buff+=",Extension:";
					for(int z=0;z<3;z++){buff+=(char)cdirent.Extension[z];ExtContainer[z]=(char)cdirent.Extension[z];}
					buff+=",Attributes:";
					buff+=Sauce::Utility::Conversion::HexToString(cdirent.Attributes);
					buff+=",CreationTimeTenth:";
					buff+=Sauce::Utility::Conversion::HexToString(cdirent.CreationTimeTenth);
					buff+=",CreationTime:";
					buff+=Sauce::Utility::Conversion::HexToString(cdirent.CreationTime);
					buff+=",CreationDate:";
					buff+=Sauce::Utility::Conversion::HexToString(cdirent.CreationDate);
					buff+=",AccessTime:";
					buff+=Sauce::Utility::Conversion::HexToString(cdirent.AccessTime);
					buff+=",FirstClusterHigh:";
					buff+=Sauce::Utility::Conversion::HexToString(cdirent.FirstClusterHigh);
					buff+=",WriteTime:";
					buff+=Sauce::Utility::Conversion::HexToString(cdirent.WriteTime);
					buff+=",WriteDate:";
					buff+=Sauce::Utility::Conversion::HexToString(cdirent.WriteDate);
					buff+=",FirstClusterLow:";
					buff+=Sauce::Utility::Conversion::HexToString(cdirent.FirstClusterLow);
					buff+=",Size:";
					buff+=Sauce::Utility::Conversion::HexToString(cdirent.Size);
					Debugger.Print(buff);
					if((cdirent.Attributes & 0x10) == 0x10/*directory*/){
						Directory.Add(NameContainer,ExtContainer,Sauce::Filesystem::Header::Classification_en::Classification_Directory);
						uint32_t firstDirectoryCluster = (((uint32_t)cdirent.FirstClusterHigh) << 16) | ((uint32_t)cdirent.FirstClusterLow);
						uint32_t nextDirectoryCluster = firstDirectoryCluster;
						uint32_t directorySector = dataStart + BiosParameterBlock.SectorsPerCluster*(nextDirectoryCluster-2);
						Directory.Sub.Last().Sub.AddLast(ReadDirectory(directorySector,NameContainer));
						Directory.Sub.Last().Header.PortNumber=PortNumber;
						Directory.Sub.Last().Header.BytesPerSector=BiosParameterBlock.BytesPerSector;
					}
					else if((cdirent.Attributes & 0x20) == 0x20/*file*/){
						Directory.Add(NameContainer,ExtContainer,Sauce::Filesystem::Header::Classification_en::Classification_File);
						uint32_t firstFileCluster = (((uint32_t)cdirent.FirstClusterHigh) << 16) | ((uint32_t)cdirent.FirstClusterLow);
						int64_t fileSize=(int64_t)cdirent.Size;
						uint32_t nextFileCluster = firstFileCluster;
						while(fileSize>0){
							uint32_t fileSector = dataStart + BiosParameterBlock.SectorsPerCluster*(nextFileCluster-2);
							uint32_t sectorOffset=0;
							for(;fileSize>0;fileSize-=BiosParameterBlock.BytesPerSector){
								Directory.Sub.Last().Header.Sectors.AddLast(fileSector+sectorOffset);
								if(++sectorOffset > BiosParameterBlock.SectorsPerCluster)break;
							}
							if(fileSize>0){
								uint32_t fatSectorForCurrentCluster = nextFileCluster/(BiosParameterBlock.BytesPerSector/sizeof(uint32_t));
								std::ustring fatBuffer;
								Sauce::Global::Storage::AHCIDrivers.First()->Read(PortNumber,fatStart+fatSectorForCurrentCluster,1/*read 1 sector*/,fatBuffer);
								uint32_t fatOffsetInSectorForCurrentCluster = nextFileCluster%(BiosParameterBlock.BytesPerSector/sizeof(uint32_t));
								nextFileCluster = (((uint32_t*)fatBuffer.Raw()))[fatOffsetInSectorForCurrentCluster] & 0x0FFFFFFF;
							}
						}
						Directory.Sub.Last().Header.PortNumber=PortNumber;
						Directory.Sub.Last().Header.BytesPerSector=BiosParameterBlock.BytesPerSector;
					}
				}
				return Directory;
			}
		};
	};
};