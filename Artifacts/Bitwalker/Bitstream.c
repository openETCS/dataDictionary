
#include "Bitstream.h"

int NormalBitstream(const Bitstream* stream, uint32_t length)
{
    return NormalBitwalker(stream->size, stream->bitpos, length);
}

