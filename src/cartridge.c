#include "cartridge.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "nes_types.h"




static cartridge*  cartridge_load(const char *filepath){
    FILE *cart;
    cartridge *c;
    cartridge_header *header =  malloc(sizeof(cartridge_header));
    cart = fopen(filepath, "rb");

    assert(cart == NULL);

    header->magic[0]= 'N';
    header->magic[1]= 'E';
    header->magic[2]= 'S';
    header->magic[3]= '\32';

    char mgc[3];

    fread(&mgc, sizeof(char), 3, cart);

    assert(mgc[0] == header->magic[0]);
    assert(mgc[1] == header->magic[1]);
    assert(mgc[2] == header->magic[2]);
    assert(mgc[3] == header->magic[3]);

    header->rom16count = fgetc(cart);
    header->vrom8count = fgetc(cart);
    header->ctrlbyte   = fgetc(cart);
    header->ctrlbyte2 =  fgetc(cart) | (header->ctrlbyte >> 4);

    if(header->ctrlbyte2 == 0x40 ) header->ctrlbyte2 &= 15;

    c = malloc(sizeof(cartridge));


    c->rom = malloc( header->rom16count * MAX_ROM_SIZE);
    c->vram= malloc(header->vrom8count * MAX_VRAM_SIZE);

    free(header);


    return c;







}


void cartridge_init(){

}

