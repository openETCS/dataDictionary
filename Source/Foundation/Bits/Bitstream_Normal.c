
#include "Bitstream_Normal.h"

int Bitstream_Normal(const Bitstream* stream, uint32_t length)
{
    return stream->bitpos + length <= 8 * stream->size;
}

