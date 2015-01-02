
#include "Bitstream_Read.h"
#include "Bitstream_Write.h"

/*@
    requires valid:      \valid(stream);

    requires invariant:  Invariant(stream);

    requires length:     length <= 64;

    requires normal:     Normal(stream, length);

    requires upper:      UpperBitsNotSet(value, length);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;

    ensures unchanged:   value == \result;
*/
uint64_t Bitstream_WriteThenRead(Bitstream* stream, const uint32_t length, uint64_t value)
{
    //@ assert Normal(stream, length);
    //@ ghost uint32_t pos = stream->bitpos;

    Bitstream_Write(stream, length, value);

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert Normal(stream, length);

    uint64_t result = Bitstream_Read(stream, length);

    //@ assert lower_bits: EqualBitRange(value, result, 0, length);
    //@ assert upper_bits: EqualBitRange(value, result, length, 64);
    //@ assert equal_bits: EqualBitRange(value, result, 0, 64);

    return result;
}

