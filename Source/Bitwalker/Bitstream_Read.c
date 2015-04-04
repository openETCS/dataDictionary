
#include "Bitstream_Read.h"
#include "Bitwalker_Peek_Normal.h"

uint64_t Bitstream_Read(Bitstream* stream, uint32_t length)
{
    return Bitwalker_Peek_Normal(stream->addr, stream->size, stream->bitpos, length);
}

