
#include "Bitstream_Read_Normal.h"
#include "Bitwalker_Peek_Normal.h"

uint64_t Bitstream_Read_Normal(Bitstream* stream, uint32_t length)
{
    uint64_t value = Bitwalker_Peek_Normal(stream->addr, stream->size, stream->bitpos, length);

    stream->bitpos += length;

    return value;
}

