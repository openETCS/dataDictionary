
#include "Bitstream_Write.h"
#include "Bitwalker_Poke.h"

int Bitstream_Write(Bitstream* stream, uint32_t length, uint64_t value)
{
    //@ assert \separated(stream, stream->addr + (0..stream->size-1));
    int retval = Bitwalker_Poke(stream->addr, stream->size, stream->bitpos, length, value);

    //@ assert bitpos_unchanged: stream->bitpos == \at(stream->bitpos, Pre);
    stream->bitpos += length;

    return retval;
}

