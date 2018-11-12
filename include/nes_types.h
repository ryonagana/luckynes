#ifndef _NES_TYPES_
#define _NES_TYPES_

#include <stdint.h>

extern "C" {
    typedef uint_least32_t   uint32;
    typedef int_least32_t    sint32;

    typedef uint_least16_t   uint16;
    typedef int_least16_t    sint16;


    typedef uint_least8_t    uint8;
    typedef int_least8_t     sint8;

    typedef uint8            byte;
    typedef uint16           word;
    typedef sint16           s_word; //joke?
    typedef uint16           address;
}

#endif
