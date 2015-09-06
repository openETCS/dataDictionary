
#include "Bitstream_Write.h"

void Bitstream_Write(Bitstream* stream, uint32_t length, uint64_t value)
{
    Bitwalker_Write(stream->addr, stream->size, stream->bitpos, length, value);
    //@ assert EqualBits(stream, stream->bitpos, stream->bitpos + length, value);

    stream->bitpos += length;
    //@ assert EqualBits(stream, \at(stream->bitpos,Pre), stream->bitpos, value);
}

