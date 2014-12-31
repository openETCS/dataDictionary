
#include "Bitstream_Write_Normal.h"
#include "Bitwalker_Poke_Normal.h"

void Bitstream_Write_Normal(Bitstream* stream, uint32_t length, uint64_t value)
{
    Bitwalker_Poke_Normal(stream->addr, stream->size, stream->bitpos, length, value);
    //@ assert middle: EqualBits64(stream->addr, stream->bitpos, stream->bitpos + length, value);
    
    stream->bitpos += length;
}

