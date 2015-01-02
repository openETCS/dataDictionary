
#include "Package_Foo_Decoder.h"
#include "Package_Foo_Encoder.h"

/*@
    requires valid_stream: \valid(stream);
    requires stream_inv:   Invariant(stream);
    requires max_pos:      Normal(stream, 28);
    requires \valid(p);
    requires \separated(stream, p);
    requires \separated(stream->addr + (0..stream->size-1), p);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:   BitstreamUnchanged{Here,Old}(stream, 0, 8 * stream->size);
*/
void Package_Foo_DecoderThenEncoder(Bitstream* stream, Package_Foo* p)
{
    const uint32_t length = 28;
    //@ ghost uint32_t pos = stream->bitpos;

    //@ assert Normal(stream, length);
    Package_Foo_Decoder(stream, p);

    //@ assert new_pos:    stream->bitpos == pos + length;
    //@ assert size:       stream->size   == \at(stream->size, Pre);
    //@ assert copied:     BitstreamEqual(stream, pos, p);
    //@ assert not_set:    UpperBitsNotSet(p);
    //@ assert increment:  stream->bitpos == pos + length;

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert Normal(stream, length);

    Package_Foo_Encoder(stream, p);

    //@ assert left:    BitstreamUnchanged{Here,Pre}(stream, 0, pos);
    //@ assert middle:  BitstreamEqual(stream, pos, p);
    //@ assert right:   BitstreamUnchanged{Here,Pre}(stream, pos + length, 8 * stream->size);
}
