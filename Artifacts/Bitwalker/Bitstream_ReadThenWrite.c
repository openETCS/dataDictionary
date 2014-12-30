
#include "Bitstream_Read.h"
#include "Bitstream_Write.h"

/*@
    requires valid_stream: \valid(stream);
    requires stream_inv:   Invariant(stream);
    requires max_length:   length <= 64;
    requires max_pos:      stream->bitpos + length <= UINT32_MAX;
    requires max_pos:      Normal(stream, length);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;

    ensures unchanged:   BitstreamUnchanged{Here,Old}(stream, 0, 8 * stream->size);
*/
void Bitstream_ReadThenWrite(Bitstream* stream, const uint32_t length)
{
    //@ assert Normal(stream, length);
    //@ ghost uint32_t pos = stream->bitpos;

    uint64_t value = Bitstream_Read(stream, length);

    //@ assert copied:     BitstreamEqual64(stream, pos, pos + length, value);
    //@ assert not_set:    UpperBitsNotSet(value, length);
    //@ assert increment:  stream->bitpos == pos + length;

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert Normal(stream, length);

    Bitstream_Write(stream, length, value);

    //@ assert left:   BitstreamUnchanged{Here,Pre}(stream, 0, pos);
    //@ assert middle: BitstreamEqual64(stream, pos, pos + length, value);
    //@ assert right:  BitstreamUnchanged{Here,Pre}(stream, pos + length, 8 * stream->size);
}
