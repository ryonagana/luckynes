#ifndef _CARTRIDGE_HEADER_
#define _CARTRIDGE_HEADER_

#include "nes_types.h"

#define MAX_ROM_SIZE 0x4000
#define MAX_VRAM_SIZE 0x2000


extern "C" {

    typedef struct cartridge_header {
        char magic[3];
        uint8 rom16count;
        uint8 vrom8count;
        uint8 ctrlbyte;
        uint8 ctrlbyte2;


    }cartridge_header;



    typedef struct cartridge  {
        cartridge_header header;
        uint8 *rom;
        uint8 *vram;
    }cartridge;

    cartridge *game_cartridge;

}


#endif
