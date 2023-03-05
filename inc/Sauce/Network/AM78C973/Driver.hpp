#ifndef __Sauce_Network_AM78C973_Driver
#define __Sauce_Network_AM78C973_Driver
#include<Sauce/IO/PCI.hpp>
#include<Sauce/IO/IO.hpp>
namespace Sauce{
	namespace Network{
		namespace AM78C973{
			class Driver_cl{
				Sauce::IO::PCI::PCIDeviceHeader_st* pciBaseAddress;
				public:
					Driver_cl(Sauce::IO::PCI::PCIDeviceHeader_st* pciBaseAddress);
					~Driver_cl();
			};
		};
	};
};
#endif