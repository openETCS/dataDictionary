
#include "Bitstream_Read.h"
#include "Bitstream_Write.h"

/*@
    requires valid:      Writeable(stream);
    requires invariant:  Invariant(stream, length);
    requires normal:     Normal(stream, length);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;

    ensures  unchanged:  Unchanged{Here,Old}(stream, 0, 8 * stream->size);
*/
void Bitstream_ReadThenWrite(Bitstream* stream, uint32_t length)
{
    uint64_t value = Bitstream_Read(stream, length);
    //@ assert equal:  EqualBits{Here,Pre}(stream, value);

    stream->bitpos -= length;
    //@ assert stream->bitpos == \at(stream->bitpos, Pre);

    Bitstream_Write(stream, length, value);
    //@ assert unchanged:  Unchanged{Here,Pre}(stream, \at(stream->bitpos,Pre), stream->bitpos);
}

