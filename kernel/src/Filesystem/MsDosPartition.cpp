#include<Sauce/Filesystem/MsDosPartition.hpp>
#include<Sauce/Global.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<std/string.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace MsDosPartition{
			MsDosPartition_cl::MsDosPartition_cl(size_t portNumber):PortNumber(portNumber){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"MsDosPartition_cl::MsDosPartition_cl",_NAMESPACE_,_ALLOW_PRINT_);
				Sauce::Global::Storage::AHCIDrivers.First()->Read(PortNumber,0,MasterBootRecord);
				std::string buff;
				for(int i=0;i<4;i++){
					buff.Clear();
					buff+="BootableFlag:";
					buff+=Sauce::Utility::Conversion::HexToString(MasterBootRecord.PrimaryPartitionTableEntries[i].BootableFlag);
					buff+=",StartHead:";
					buff+=Sauce::Utility::Conversion::HexToString(MasterBootRecord.PrimaryPartitionTableEntries[i].StartHead);
					buff+=",StartSector:";
					buff+=Sauce::Utility::Conversion::HexToString(MasterBootRecord.PrimaryPartitionTableEntries[i].StartSector);
					buff+=",StartCylinder:";
					buff+=Sauce::Utility::Conversion::HexToString(MasterBootRecord.PrimaryPartitionTableEntries[i].StartCylinder);
					buff+=",PartitionId:";
					buff+=Sauce::Utility::Conversion::HexToString(MasterBootRecord.PrimaryPartitionTableEntries[i].PartitionId);
					buff+=",EndHead:";
					buff+=Sauce::Utility::Conversion::HexToString(MasterBootRecord.PrimaryPartitionTableEntries[i].EndHead);
					buff+=",EndSector:";
					buff+=Sauce::Utility::Conversion::HexToString(MasterBootRecord.PrimaryPartitionTableEntries[i].EndSector);
					buff+=",EndCylinder:";
					buff+=Sauce::Utility::Conversion::HexToString(MasterBootRecord.PrimaryPartitionTableEntries[i].EndCylinder);
					buff+=",LbaStart:";
					buff+=Sauce::Utility::Conversion::HexToString(MasterBootRecord.PrimaryPartitionTableEntries[i].LbaStart);
					buff+=",LbaLength:";
					buff+=Sauce::Utility::Conversion::HexToString(MasterBootRecord.PrimaryPartitionTableEntries[i].LbaLength);
					Debugger.Print(buff);
				}
				buff.Clear();
				buff+="MagicNumber:";
				buff+=Sauce::Utility::Conversion::HexToString(MasterBootRecord.MagicNumber);
				Debugger.Print(buff);
			}
		};
	};
};