
#include "Bitstream_Read.h"
#include "Bitstream_Write.h"

/*@
    requires valid_stream: \valid(stream);
    requires stream_inv:   BitstreamInvariant(stream);
    requires max_length:   length <= 64;
    requires max_pos:      stream->bitpos + length <= UINT32_MAX;
    requires max_pos:      NormalBitsequence(stream, length);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;

    ensures unchanged:   BitstreamUnchanged{Here,Old}(stream, 0, 8 * stream->size);
*/
void ReadThenWrite(Bitstream* stream, const uint32_t length)
{
    //@ assert NormalBitsequence(stream, length);
    //@ ghost uint32_t pos = stream->bitpos;

    uint64_t value = Bitstream_Read(stream, length);

    //@ assert copied1:      BitstreamEqual64(stream, pos, pos + length, value);
    //@ assert not_set:      UpperBitsNotSet(value, length);
    //@ assert increment:    stream->bitpos == pos + length;

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert NormalBitsequence(stream, length);

    Bitstream_Write(stream, length, value);

    //@ assert unchanged_left:  BitstreamUnchanged{Here,Pre}(stream, 0, pos);
    //@ assert copied2:         BitstreamEqual64(stream, pos, pos + length, value);
    //@ assert unchanged_right: BitstreamUnchanged{Here,Pre}(stream, pos + length, 8 * stream->size);
}
