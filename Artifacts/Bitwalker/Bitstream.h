
#ifndef BITSTREAM_H_INCLUDED
#define BITSTREAM_H_INCLUDED

#include "FramaCBits.h"

struct Bitstream
{
    uint8_t*  addr;
    uint32_t  size;
    uint32_t  bitpos;
};

typedef struct Bitstream Bitstream;

#endif // BITSTREAM_H_INCLUDED

