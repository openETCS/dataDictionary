
#include "Bitstream_Read.h"
#include "Bitstream_Write.h"

/*@
    requires valid:     Writeable(stream);

    requires invariant: Invariant(stream, length);

    requires normal:    Normal(stream, length);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;

    ensures unchanged:  Unchanged{Here,Old}(stream, 0, 8 * stream->size);
*/
void Bitstream_ReadThenWrite(Bitstream* stream, const uint32_t length)
{
    //@ assert Normal(stream, length);
    //@ ghost uint32_t pos = stream->bitpos;

    uint64_t value = Bitstream_Read(stream, length);

    //@ assert equal:     EqualBits(stream, pos, pos + length, value);
    //@ assert not_set:    UpperBitsNotSet(value, length);
    //@ assert increment:  stream->bitpos == pos + length;

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert Normal(stream, length);

    Bitstream_Write(stream, length, value);

    //@ assert left:   Unchanged{Here,Pre}(stream, 0, pos);
    //@ assert middle: EqualBits(stream, pos, pos + length, value);
    //@ assert right:  Unchanged{Here,Pre}(stream, pos + length, 8 * stream->size);
}

