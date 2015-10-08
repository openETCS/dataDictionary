
#include "Default_Gradient_for_Temporary_Speed_Restriction_Decoder.h"
#include "Default_Gradient_for_Temporary_Speed_Restriction_Encoder.h"

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
void Default_Gradient_for_Temporary_Speed_Restriction_DecoderThenEncoder(Bitstream* stream, Default_Gradient_for_Temporary_Speed_Restriction* p)
{
    const uint32_t length = DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_BITSIZE;
    //@ ghost uint32_t pos = stream->bitpos;

    //@ assert Normal(stream, length);
    Default_Gradient_for_Temporary_Speed_Restriction_Decoder(stream, p);

    //@ assert pos:        stream->bitpos == pos + length;
    //@ assert equal:      EqualBits(stream, pos, p);
    //@ assert upper:      UpperBitsNotSet(p);
    //@ assert increment:  stream->bitpos == pos + length;
    //@ assert unchanged:  Unchanged{Here,Pre}(stream, 0, 8 * stream->size);

    /*@
        assigns stream->bitpos;
	ensures stream->bitpos == pos;
	ensures Normal(stream, length);
	ensures EqualBits(stream, pos, p);
    */
    stream->bitpos -= length;

    /*@
        requires equal: EqualBits(stream, pos, p);

	assigns stream->addr[0..stream->size-1];
	assigns stream->bitpos;

	ensures left:   Unchanged{Here,Old}(stream, 0, pos);
	ensures middle: EqualBits(stream, pos, p);
	ensures right:  Unchanged{Here,Old}(stream, pos + length, 8 * stream->size);
    */
    Default_Gradient_for_Temporary_Speed_Restriction_Encoder(stream, p);
    //@ assert middle:  Unchanged{Here,Pre}(stream, pos, pos + length);

}

