
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

    ensures unchanged:   BitstreamUnchanged{Old}(stream, 0, 8 * stream->size);
*/
void ReadThenWrite(Bitstream* stream, const uint32_t length)
{
    uint64_t value = Bitstream_Read(stream, length);

    //@ assert copied1:      BitstreamEqual64(stream, \at(stream->bitpos, Pre), stream->bitpos, value);
    //@ assert not_set:      UpperBitsNotSet(value, length);
    //@ assert increment:    stream->bitpos == \at(stream->bitpos, Pre) + length;

    stream->bitpos -= length;
    //@ assert stream->bitpos == \at(stream->bitpos, Pre);
    //@ assert NormalBitsequence(stream, length);

    Bitstream_Write(stream, length, value);

    //@ assert unchanged_left:  BitstreamUnchanged{Pre}(stream, 0, \at(stream->bitpos, Pre));
    //@ assert copied2:         BitstreamEqual64(stream, \at(stream->bitpos, Pre), stream->bitpos, value);
    //@ assert unchanged_right: BitstreamUnchanged{Pre}(stream, stream->bitpos, 8 * stream->size);
}
