
#include "Bitstream_Read.h"

uint64_t Bitstream_Read(Bitstream* s, uint32_t length)
{
    uint64_t value =  Bitwalker_Read(s->addr, s->size, s->bitpos, length);

    s->bitpos += length;

    return value;
}

