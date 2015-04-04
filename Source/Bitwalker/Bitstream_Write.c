
#include "Bitstream_Write.h"
#include "Bitwalker_Poke_Normal.h"

void Bitstream_Write(Bitstream* stream, uint32_t length, uint64_t value)
{
    Bitwalker_Poke_Normal(stream->addr, stream->size, stream->bitpos, length, value);
    stream->bitpos += length;
}

