#pragma once

#include<Sauce/Types.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Utility/Manipulations.hpp>

namespace Sauce{
    namespace Storage{
        namespace FileSystem{
            namespace VirtualFileSystem{
                struct File_st{
                    Sauce::Memory::List_cl<char> Name;
                    Sauce::Memory::List_cl<char> ContentType;
                    Sauce::Memory::List_cl<char> Contents;
                };
                struct Folder_st{
                    Sauce::Memory::List_cl<char> Name;
                    Sauce::Memory::List_cl<File_st*> SubFiles;
                    Sauce::Memory::List_cl<Folder_st*> SubFolders;
                    Folder_st(Sauce::Memory::List_cl<char> nName);
                    ~Folder_st();
                    Folder_st* FindSubFolder(Sauce::Memory::List_cl<char> tName);
                    File_st* FindSubFile(Sauce::Memory::List_cl<char> tName);
                    File_st* CreateFile(Sauce::Memory::List_cl<char> tName);
                    Folder_st* CreateFolder(Sauce::Memory::List_cl<char> tName);
                    bool DeleteFile(Sauce::Memory::List_cl<char> tName);
                    bool DeleteFolder(Sauce::Memory::List_cl<char> tName);
                };
                class FilesystemManager_cl{
                    Folder_st* RootFolder;
                    public:
                    FilesystemManager_cl();
                    ~FilesystemManager_cl();
                    File_st* FileCreate(Sauce::Memory::List_cl<char> Path);
                    Folder_st* FolderCreate(Sauce::Memory::List_cl<char> Path);
                    File_st* FileSearch(Sauce::Memory::List_cl<char> Path);
                    Folder_st* FolderSearch(Sauce::Memory::List_cl<char> Path);
                    bool FileDelete(Sauce::Memory::List_cl<char> Path);
                    bool FolderDelete(Sauce::Memory::List_cl<char> Path);
                };
            };
        };
    };
};