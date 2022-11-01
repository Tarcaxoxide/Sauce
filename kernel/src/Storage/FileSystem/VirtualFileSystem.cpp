#include<Sauce/Storage/FileSystem/VirtualFileSystem.hpp>

namespace Sauce{
    namespace Storage{
        namespace FileSystem{
            namespace VirtualFileSystem{
                //Folder_st
                Folder_st::Folder_st(Sauce::string nName){
                    Name=nName;
                }
                Folder_st::~Folder_st(){
                    SubFiles.Clear();
                    SubFolders.Clear();
                }
                Folder_st* Folder_st::FindSubFolder(Sauce::string tName){
                    for(size_t i=0;i<SubFolders.Size();i++){
                        if(SubFolders[i]->Name == tName)return SubFolders[i];
                    }
                    return nullptr;
                }
                File_st* Folder_st::FindSubFile(Sauce::string tName){
                    for(size_t i=0;i<SubFiles.Size();i++){
                        if(SubFiles[i]->Name == tName)return SubFiles[i];
                    }
                    return nullptr;
                }
                File_st* Folder_st::CreateFile(Sauce::string tName){
                    File_st* File = FindSubFile(tName);
                    if(File != nullptr)return nullptr;//don't create a file if it exist already.
                    if(tName.Size() < 1)return nullptr;//don't create a file with a name of 0 length.
                    SubFiles.AddLast(new File_st{tName,(char*)"text/html",(char*)""});
                    return SubFiles[SubFiles.Size()-1];
                }
                Folder_st* Folder_st::CreateFolder(Sauce::string tName){
                    Folder_st* Folder = FindSubFolder(tName);
                    if(Folder != nullptr)return nullptr;//don't create a folder if it exists already.
                    if(tName.Size() < 1)return nullptr;//don't create a folder with a name of 0 length.
                    SubFolders.AddLast(new Folder_st(tName));
                    return SubFolders[SubFolders.Size()-1];
                }
                bool Folder_st::DeleteFile(Sauce::string tName){
                    for(size_t i=0;i<SubFiles.Size();i++){
                        if(SubFiles[i]->Name == tName){
                            SubFiles.Remove(i);
                            return true;
                        }
                    }
                    return false;
                }
                bool Folder_st::DeleteFolder(Sauce::string tName){
                    for(size_t i=0;i<SubFolders.Size();i++){
                        if(SubFolders[i]->Name == tName){
                            SubFolders.Remove(i);
                            return true;
                        }
                    }
                    return false;
                }
                //FilesystemManager_cl
                FilesystemManager_cl::FilesystemManager_cl(){
                    RootFolder=new Folder_st((char*)"/");
                }
                FilesystemManager_cl::~FilesystemManager_cl(){
                    delete[] RootFolder;
                }
                File_st* FilesystemManager_cl::FileCreate(Sauce::string Path){
                    Sauce::Memory::List_cl<Sauce::string> TokenizedPath=Sauce::Utility::split(Path,'/');
                    Folder_st* CurrentFolder=RootFolder;
                    Folder_st* PreviousFolder=RootFolder;
                    for(size_t i=0;i<TokenizedPath.Size()-1/*last one is blank or a file*/;i++){
                        PreviousFolder=CurrentFolder;
                        CurrentFolder->FindSubFolder(TokenizedPath[i]);
                        if(CurrentFolder == nullptr){
                            CurrentFolder=PreviousFolder->CreateFolder(TokenizedPath[i]);
                        }
                    }
                    return CurrentFolder->CreateFile(TokenizedPath[TokenizedPath.Size()-1]);
                }
                Folder_st* FilesystemManager_cl::FolderCreate(Sauce::string Path){
                    Sauce::Memory::List_cl<Sauce::string> TokenizedPath=Sauce::Utility::split(Path,'/');
                    bool Created=false;
                    Folder_st* CurrentFolder=RootFolder;
                    Folder_st* PreviousFolder=RootFolder;
                    for(size_t i=0;i<TokenizedPath.Size()-1/*last one is blank or a file*/;i++){
                        PreviousFolder=CurrentFolder;
                        CurrentFolder->FindSubFolder(TokenizedPath[i]);
                        if(CurrentFolder == nullptr){
                            Created=true;
                            CurrentFolder=PreviousFolder->CreateFolder(TokenizedPath[i]);
                        }
                    }
                    return (Created? CurrentFolder : nullptr);
                }
                File_st* FilesystemManager_cl::FileSearch(Sauce::string Path){
                    Sauce::Memory::List_cl<Sauce::string> TokenizedPath=Sauce::Utility::split(Path,'/');
                    Folder_st* CurrentFolder=RootFolder;
                    Folder_st* PreviousFolder=RootFolder;
                    for(size_t i=0;i<TokenizedPath.Size()-1/*last one is blank or a file*/;i++){
                        PreviousFolder=CurrentFolder;
                        CurrentFolder->FindSubFolder(TokenizedPath[i]);
                        if(CurrentFolder == nullptr)return nullptr;
                    }
                    return CurrentFolder->FindSubFile(TokenizedPath[TokenizedPath.Size()-1]);
                }
                Folder_st* FilesystemManager_cl::FolderSearch(Sauce::string Path){
                    Sauce::Memory::List_cl<Sauce::string> TokenizedPath=Sauce::Utility::split(Path,'/');
                    Folder_st* CurrentFolder=RootFolder;
                    Folder_st* PreviousFolder=RootFolder;
                    for(size_t i=0;i<TokenizedPath.Size()-1/*last one is blank or a file*/;i++){
                        PreviousFolder=CurrentFolder;
                        CurrentFolder->FindSubFolder(TokenizedPath[i]);
                        if(CurrentFolder == nullptr)return nullptr;
                    }
                    return CurrentFolder;
                }
                bool FilesystemManager_cl::FileDelete(Sauce::string Path){
                    Sauce::Memory::List_cl<Sauce::string> TokenizedPath=Sauce::Utility::split(Path,'/');
                    Folder_st* CurrentFolder=RootFolder;
                    Folder_st* PreviousFolder=RootFolder;
                    for(size_t i=0;i<TokenizedPath.Size()-1/*last one is blank or a file*/;i++){
                        PreviousFolder=CurrentFolder;
                        CurrentFolder->FindSubFolder(TokenizedPath[i]);
                        if(CurrentFolder == nullptr)return false;
                    }
                    return CurrentFolder->DeleteFile(TokenizedPath[TokenizedPath.Size()-1]);
                }
                bool FilesystemManager_cl::FolderDelete(Sauce::string Path){
                    Sauce::Memory::List_cl<Sauce::string> TokenizedPath=Sauce::Utility::split(Path,'/');
                    Folder_st* CurrentFolder=RootFolder;
                    Folder_st* PreviousFolder=RootFolder;
                    for(size_t i=0;i<TokenizedPath.Size()-2/*last one is blank or a file,2nd from last is the target*/;i++){
                        PreviousFolder=CurrentFolder;
                        CurrentFolder->FindSubFolder(TokenizedPath[i]);
                        if(CurrentFolder == nullptr)return false;
                    }
                    return CurrentFolder->DeleteFolder(TokenizedPath[TokenizedPath.Size()-2]);
                }
            };
        };
    };
};