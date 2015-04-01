
#include "Adhesion_Factor_Decoder.h"
#include "Adhesion_Factor_Encoder.h"

/*@
    requires valid_stream:      Writeable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires normal:            Normal(stream, MaxBitSize(p));
    requires valid_package:     \valid(p);
    requires invariant:         Invariant(p);

    requires separation:        Separated(stream, p);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:   Unchanged{Here,Old}(stream, 0, 8 * stream->size);
*/
void Adhesion_Factor_DecoderThenEncoder(Bitstream* stream, Adhesion_Factor* p)
{
    const uint32_t length = ADHESION_FACTOR_BITSIZE;
    //@ ghost uint32_t pos = stream->bitpos;

    //@ assert Normal(stream, length);
    Adhesion_Factor_Decoder(stream, p);

    //@ assert pos:        stream->bitpos == pos + length;
    //@ assert equal:      EqualBits{Pre,Here}(stream, pos, p);
    //@ assert upper:      UpperBitsNotSet(p);
    //@ assert increment:  stream->bitpos == pos + length;
    //@ assert unchanged:  Unchanged{Here,Pre}(stream, 0, 8 * stream->size);

    /*@
        assigns stream->bitpos;
        ensures stream->bitpos == pos;
        ensures Normal(stream, length);
        ensures EqualBits{Pre,Here}(stream, pos, p);
    */
    stream->bitpos -= length;

    /*@
        requires equal: EqualBits{Pre,Here}(stream, pos, p);

        assigns stream->addr[0..stream->size-1];
        assigns stream->bitpos;

        ensures left:   Unchanged{Here,Old}(stream, 0, pos);
        ensures middle: EqualBits{Here,Old}(stream, pos, p);
        ensures right:  Unchanged{Here,Old}(stream, pos + length, 8 * stream->size);
    */
    Adhesion_Factor_Encoder(stream, p);
    //@ assert middle:  Unchanged{Here,Pre}(stream, pos, pos + length);

}

