
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

    ensures unchanged:   \result == value;
*/
uint64_t WriteThenRead(Bitstream* stream, const uint32_t length, uint64_t value)
{
    //@ assert NormalBitsequence(stream, length);
    //@ ghost uint32_t pos = stream->bitpos;

    Bitstream_Write(stream, length, value);

    //@ assert unchanged_left:  BitstreamUnchanged{Here,Pre}(stream, 0, pos);
    //@ assert copied1:         BitstreamEqual64(stream, pos, pos + length, value);
    //@ assert unchanged_right: BitstreamUnchanged{Here,Pre}(stream, pos + length, 8 * stream->size);

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert NormalBitsequence(stream, length);

    uint64_t result = Bitstream_Read(stream, length);
    //@ assert stream->bitpos == pos + length;
    //@ assert stream->size == \at(stream->size, Pre);

    //@ assert copied1:    BitstreamEqual64(stream, pos, pos + length, value);
    //@ assert copied2:    BitstreamEqual64(stream, pos, pos + length, result);
    //@ assert lower_bits: \forall integer i; 0 <= i < length ==>  (BitTest(value, i) <==> BitTest(result, i));

    //@ assert not_set:    UpperBitsNotSet(result, length);
    //@ assert upper_bits: \forall integer i; length <= i < 64 ==>  (BitTest(value, i) <==> BitTest(result, i));

    //@ assert bit_equal:  \forall integer i; 0 <= i < 64 ==>  (BitTest(value, i) <==> BitTest(result, i));

    return result;
}
