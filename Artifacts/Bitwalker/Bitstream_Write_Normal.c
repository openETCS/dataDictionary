
#include "Bitstream_Write_Normal.h"
#include "Bitwalker_Poke.h"

void Bitstream_Write_Normal(Bitstream* stream, uint32_t length, uint64_t value)
{
    //@ assert \separated(stream, stream->addr + (0..stream->size-1));
    Bitwalker_Poke_Core(stream->addr, stream->size, stream->bitpos, length, value);

    //@ assert bitpos_unchanged: stream->bitpos == \at(stream->bitpos, Pre);
    stream->bitpos += length;
}

