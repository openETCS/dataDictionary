
#include "Bitstream.h"

int NormalBitstream(const Bitstream* stream, uint32_t length)
{
    return stream->bitpos + length <= 8 * stream->size;
}

