
#include "Bitstream_Read.h"
#include "Bitstream_Write.h"

/*@
    requires valid:     Writeable(stream);

    requires invariant: Invariant(stream, length);

    requires normal:    Normal(stream, length);

    requires upper:     UpperBitsNotSet(value, length);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;

    ensures unchanged:  \result == value;
*/
uint64_t Bitstream_WriteThenRead(Bitstream* stream, const uint32_t length, uint64_t value)
{
    //@ ghost uint32_t pos = stream->bitpos;

    Bitstream_Write(stream, length, value);

    //@ assert left:   Unchanged{Here,Pre}(stream, 0, pos);
    //@ assert middle: EqualBits(stream, pos, pos + length, value);
    //@ assert right:  Unchanged{Here,Pre}(stream, pos + length, 8 * stream->size);

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert Normal(stream, length);

    uint64_t result = Bitstream_Read(stream, length);

    //@ assert equal:  EqualBits(stream, pos, pos + length, result);
    //@ assert upper:  UpperBitsNotSet(result, length);

    return result;
}

