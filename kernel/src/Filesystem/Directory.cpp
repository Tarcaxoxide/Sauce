#include<Sauce/Filesystem/Directory.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Directory{
			Sauce::Filesystem::Blob::Blob_st& Directory_st::operator[](size_t index){
				return Sub[index];
			}
		};
	};
};