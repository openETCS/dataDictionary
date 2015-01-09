
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

    ensures unchanged:   EqualBits{Here,Old}(stream, 0, 8 * stream->size);
*/
void Adhesion_Factor_DecoderThenEncoder(Bitstream* stream, Adhesion_Factor* p)
{
    const uint32_t length = ADHESION_FACTOR_BITSIZE;
    //@ ghost uint32_t pos = stream->bitpos;

    //@ assert Normal(stream, length);
    Adhesion_Factor_Decoder(stream, p);

    //@ assert pos:        stream->bitpos == pos + length;
    //@ assert equal:      EqualBits(stream, pos, p);
    //@ assert upper:      UpperBitsNotSet(p);
    //@ assert increment:  stream->bitpos == pos + length;

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert Normal(stream, length);

    Adhesion_Factor_Encoder(stream, p);

    //@ assert left:    EqualBits{Here,Pre}(stream, 0, pos);
    //@ assert middle:  EqualBits(stream, pos, p);
    //@ assert right:   EqualBits{Here,Pre}(stream, pos + length, 8 * stream->size);
}
