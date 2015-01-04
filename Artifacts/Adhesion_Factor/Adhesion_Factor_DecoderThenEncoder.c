
#include "Adhesion_Factor_Decoder.h"
#include "Adhesion_Factor_Encoder.h"

/*@
    requires valid_stream:      Writeable(stream);

    requires stream_invariant:  Invariant(stream, BitSize(p));

    requires normal:            Normal(stream, BitSize(p));

    requires valid_package:     \valid(p);

    requires separation:        Separated(stream, p);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:   BitstreamUnchanged{Here,Old}(stream, 0, 8 * stream->size);
*/
void Adhesion_Factor_DecoderThenEncoder(Bitstream* stream, Adhesion_Factor* p)
{
    const uint32_t length = ADHESION_FACTOR_BITSIZE;
    //@ ghost uint32_t pos = stream->bitpos;

    //@ assert Normal(stream, length);
    Adhesion_Factor_Decoder(stream, p);

    //@ assert new_pos:    stream->bitpos == pos + length;
    //@ assert size:       stream->size   == \at(stream->size, Pre);
    //@ assert copied:     BitstreamEqual(stream, pos, p);
    //@ assert not_set:    UpperBitsNotSet(p);
    //@ assert increment:  stream->bitpos == pos + length;

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert Normal(stream, length);

    Adhesion_Factor_Encoder(stream, p);

    //@ assert left:    BitstreamUnchanged{Here,Pre}(stream, 0, pos);
    //@ assert middle:  BitstreamEqual(stream, pos, p);
    //@ assert right:   BitstreamUnchanged{Here,Pre}(stream, pos + length, 8 * stream->size);
}
