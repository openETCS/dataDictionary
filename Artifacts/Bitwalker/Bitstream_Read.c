
#include "Bitstream_Read.h"
#include "Bitstream_Read_Normal.h"

uint64_t Bitstream_Read(Bitstream* stream, uint32_t length)
{
    if (stream->bitpos + length <= 8 * stream->size)
    {
        return Bitstream_Read_Normal(stream, length);
    }
    else
    {
        stream->bitpos += length;
        return 0u;
    }
}

