
#include "Bitstream_Read.h"
#include "Bitwalker_Peek_Normal.h"

uint64_t Bitstream_Read(Bitstream* s, uint32_t length)
{
    uint64_t value =  Bitwalker_Peek_Normal(s->addr, s->size, s->bitpos, length);

    s->bitpos += length;

    return value;
}

