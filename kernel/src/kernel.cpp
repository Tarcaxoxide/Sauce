#define CCPP 
#include <Sauce/Common.h>

extern "C" int64_t _start(DataStructure* DFBL){


    for(unsigned int x = 0; x < DFBL->FrameBuffer->Width/2;x++){
		DFBL->FrameBuffer->BaseAddress[x]= GOP_BLUE;
	}

    return DFBL->TestNumber;
}