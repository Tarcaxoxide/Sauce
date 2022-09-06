#include<Sauce/Storage/FileSystem/FAT.hpp>
#include<Sauce/Global/Global.hpp>
#include<Sauce/Storage/AHCI.hpp>

#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/Utility/Manipulations.hpp>

namespace Sauce{
	namespace Storage{
		namespace FileSystem{
			FAT32Driver_cl::FAT32Driver_cl(size_t AHCI_portNumber){
				BootSector=new FAT32_BootSector_st;
				size_t BootSector_CurrentAddress=0;
				this->AHCI_portNumber=AHCI_portNumber;
				
				for(size_t i=0;i<3;i++){BootSector->Jmp_Boot[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<8;i++){BootSector->OEM_Name[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<2;i++){BootSector->Bytes_Per_Sector[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<1;i++){BootSector->Sectors_Per_Cluster[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<2;i++){BootSector->Reserved_Sector_Count[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<1;i++){BootSector->Number_Of_FATs[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<2;i++){BootSector->Root_Entry_Count[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<2;i++){BootSector->Total_Sector_Count16[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<1;i++){BootSector->Media_Type[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<2;i++){BootSector->Sectors_Per_FAT16[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<2;i++){BootSector->Sectors_Per_Track[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<2;i++){BootSector->Number_Of_Heads[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<4;i++){BootSector->Hidden_Sector_Count[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<4;i++){BootSector->Total_Sector_Count32[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<4;i++){BootSector->Sectors_Per_FAT32[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<2;i++){BootSector->Flags[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<2;i++){BootSector->FS_Version[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<4;i++){BootSector->Root_Cluster[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<2;i++){BootSector->FS_Info[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<2;i++){BootSector->Backup_Boot_Sector[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<12;i++){BootSector->Reserved[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<1;i++){BootSector->Drive_Number[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<1;i++){BootSector->Reserved1[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<1;i++){BootSector->Boot_Signature[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<4;i++){BootSector->Volume_ID[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<11;i++){BootSector->Volume_Label[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}
				for(size_t i=0;i<8;i++){BootSector->FS_Type[i]=Sauce::Global::AHCIDriver->Read(AHCI_portNumber,BootSector_CurrentAddress++);}

				
			}
			void FAT32Driver_cl::Traverse(char* path){
				Sauce::Memory::List_cl<char*> pathparts = Sauce::Utility::split(path, '/');

				Sauce::Memory::List_cl<FSObject> dirs = ReadDir(((uint32_t)*BootSector->Root_Cluster));
			}
			Sauce::Memory::List_cl<FSObject> FAT32Driver_cl::ReadDir(uint32_t cluster){
				Sauce::Memory::List_cl<FSObject> Result;
				// if the cluster number is zero, assume we're trying to read from the root directory.
				if(cluster == 0)
					cluster = ((uint32_t)*BootSector->Root_Cluster);
				
				Sauce::Memory::List_cl<uint8_t> buf;

				// Get the cluster chain of the directory. This contains the directory entries themselves.
				uint64_t numclus = 0;
				Sauce::Memory::List_cl<uint32_t> clusters = GetClusterChain(cluster, &numclus);
				for(size_t i=0;i<clusters.Size();i++){
					Sauce::Global::AHCIDriver->Read(AHCI_portNumber,ClusterToLBA(clusters[i]),((uint8_t)*BootSector->Sectors_Per_Cluster),buf);
				}
				return Result;
			}
			Sauce::Memory::List_cl<uint32_t> FAT32Driver_cl::GetClusterChain(uint32_t firstcluster, uint64_t* numclus){
				uint32_t Cluster = firstcluster;
				uint32_t cchain = 0;
				Sauce::Memory::List_cl<uint32_t> Result;
				
				Sauce::Memory::List_cl<uint8_t> buf;

				do{
					uint32_t FatOffset = (Cluster * 4) % 512;
					uint32_t FatSector = ((uint16_t)*BootSector->Reserved_Sector_Count) + (FatOffset / ((uint16_t)*BootSector->Bytes_Per_Sector));
					
					// read 512 bytes into buf.
					Sauce::Global::AHCIDriver->Read(AHCI_portNumber,FatSector,1,buf);

					// using FatOffset, we just index into the array to get the value we want.
					cchain = *((uint32_t*)&buf[FatOffset]) & 0x0FFFFFFF;

					// the value of 'Cluster' will change by the next iteration.
					// Because we're nice people, we need to include the first cluster in the list of clusters we return.
					Result.AddLast(Cluster);

					// since cchain is the next cluster in the list, we just modify the things, shouldn't be too hard to grasp.
					Cluster = cchain;

					// numclus tells the caller how many clusters are in the chain.
					(*numclus)++;

				} while((cchain != 0) && !((cchain & 0x0FFFFFFF) >= 0x0FFFFFF8));	

				return Result;
			}
			size_t FAT32Driver_cl::ClusterToLBA(uint32_t cluster){
				static size_t FirstUsableCluster = ((uint16_t)*BootSector->Reserved_Sector_Count) + (((uint8_t)*BootSector->Number_Of_FATs) * ((uint32_t)*BootSector->Sectors_Per_FAT32)) + ((uint16_t)*BootSector->Root_Entry_Count);
				return FirstUsableCluster + cluster * ((uint8_t)*BootSector->Sectors_Per_Cluster) - (2 * ((uint8_t)*BootSector->Sectors_Per_Cluster));
			}
			FAT32Driver_cl::~FAT32Driver_cl(){
				delete[] BootSector;
			}
		};
	};
};
