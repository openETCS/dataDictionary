
#include "Bitstream_Read_Normal.h"
#include "Bitwalker_Peek.h"

uint64_t Bitstream_Read_Normal(Bitstream* stream, uint32_t length)
{
    uint64_t retval = Bitwalker_Peek(stream->addr, stream->size, stream->bitpos, length);

    stream->bitpos += length;
    return retval;
}

