
#include "Adhesion_Factor_Decoder.h"
#include "Adhesion_Factor_Encoder.h"

/*@
    requires valid_stream:      Writeable(stream);
    requires stream_invariant:  Invariant(stream, BitSize(p));
    requires normal:            Normal(stream, BitSize(p));
    requires valid_package:     \valid(p);
    requires invariant:         Invariant(p);
    requires upper:             UpperBitsNotSet(p);
    requires separation:        Separated(stream, p);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:   *p == \old(*p);
*/
void Adhesion_Factor_EncoderThenDecoder(Bitstream* stream, Adhesion_Factor* p)
{
    const uint32_t length = ADHESION_FACTOR_BITSIZE;
    //@ ghost uint32_t pos = stream->bitpos;

    //@ assert Normal(stream, length);
    Adhesion_Factor_Encoder(stream, p);

    //@ assert left:    EqualBits{Here,Pre}(stream, 0, pos);
    //@ assert middle:  EqualBits(stream, pos, p);
    //@ assert right:   EqualBits{Here,Pre}(stream, pos + length, 8 * stream->size);

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert Normal(stream, length);

    Adhesion_Factor_Decoder(stream, p);

    //@ assert equal:  EqualBits(stream, pos, p);
    //@ assert upper:  UpperBitsNotSet(p);
}

