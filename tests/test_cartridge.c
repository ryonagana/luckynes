/*
 * DO NOT BUILD  THIS TEST IN QTCREATOR
 * PLEASE enter cd tests/
 * type make
 * */

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "nes_types.h"
#include "cartridge.h"



cartridge*  test_cartridge_load(const char *filepath){
    FILE *cart;
    cartridge *c;
    cartridge_header *header =  malloc(sizeof(cartridge_header));
    cart = fopen(filepath, "rb");

    if(!cart){
        fprintf(stdout, "ROM Not Found\n\nExiting..\n\n");
        exit(-1);
    }

    assert(cart == NULL);

    header->magic[0]= 'N';
    header->magic[1]= 'E';
    header->magic[2]= 'S';
    header->magic[3]= 0x32;

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




int main(int argc, char **argv){

    test_cartridge_load("mario.nes");
	return 0;
}
