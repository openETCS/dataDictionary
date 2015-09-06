
#include "Bitstream_Init.h"
#include "Bitstream_Normal.h"
#include "Bitstream_Read.h"
#include "Bitstream_Write.h"

void
Bitstream_Init(Bitstream* stream, uint8_t* addr, uint32_t size, uint32_t bitpos)
{
    stream->addr    = addr;
    stream->size    = size;
    stream->bitpos  = bitpos;
}


int
Bitstream_Normal(const Bitstream* stream, uint32_t length)
{
    return stream->bitpos + length <= 8 * stream->size;
}


uint64_t
Bitstream_Read(Bitstream* s, uint32_t length)
{
    uint64_t value =  Bitwalker_Read(s->addr, s->size, s->bitpos, length);

    s->bitpos += length;

    return value;
}


void
Bitstream_Write(Bitstream* stream, uint32_t length, uint64_t value)
{
    Bitwalker_Write(stream->addr, stream->size, stream->bitpos, length, value);
    //@ assert EqualBits(stream, stream->bitpos, stream->bitpos + length, value);

    stream->bitpos += length;
    //@ assert EqualBits(stream, \at(stream->bitpos,Pre), stream->bitpos, value);
}

