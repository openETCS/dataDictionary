
#include "Bitstream_Read.h"
#include "Bitstream_Write.h"

/*@
    requires valid_stream: \valid(stream);
    requires stream_inv:   BitstreamInvariant(stream);
    requires max_length:   length <= 64;
    requires max_pos:      stream->bitpos + length <= UINT32_MAX;
    requires max_pos:      NormalBitsequence(stream, length);
    requires not_set:      UpperBitsNotSet(value, length);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;

    ensures unchanged:   value == \result;
*/
uint64_t WriteThenRead(Bitstream* stream, const uint32_t length, uint64_t value)
{
    //@ assert NormalBitsequence(stream, length);
    //@ ghost uint32_t pos = stream->bitpos;

    Bitstream_Write(stream, length, value);

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert NormalBitsequence(stream, length);

    uint64_t result = Bitstream_Read(stream, length);

    //@ assert lower_bits: EqualBitRange(value, result, 0, length);
    //@ assert upper_bits: EqualBitRange(value, result, length, 64);
    //@ assert equal_bits: EqualBitRange(value, result, 0, 64);

    return result;
}
