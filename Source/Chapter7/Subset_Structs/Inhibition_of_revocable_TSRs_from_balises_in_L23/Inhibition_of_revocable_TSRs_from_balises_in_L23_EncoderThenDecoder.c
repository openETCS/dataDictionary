
#include "Inhibition_of_revocable_TSRs_from_balises_in_L23_Decoder.h"
#include "Inhibition_of_revocable_TSRs_from_balises_in_L23_Encoder.h"

/*@
    requires valid_stream:      Writeable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires normal:            Normal(stream, MaxBitSize(p));
    requires valid_package:     \valid(p);
    requires invariant:         Invariant(p);
    requires upper:             UpperBitsNotSet(p);
    requires separation:        Separated(stream, p);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:   *p == \old(*p);
*/
void Inhibition_of_revocable_TSRs_from_balises_in_L23_EncoderThenDecoder(Bitstream* stream, Inhibition_of_revocable_TSRs_from_balises_in_L23* p)
{
    const uint32_t length = INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_BITSIZE;
    //@ ghost uint32_t pos = stream->bitpos;

    //@ assert Normal(stream, length);
    Inhibition_of_revocable_TSRs_from_balises_in_L23_Encoder(stream, p);

    //@ assert left:    Unchanged{Here,Pre}(stream, 0, pos);
    //@ assert middle:  EqualBits(stream, pos, p);
    //@ assert right:   Unchanged{Here,Pre}(stream, pos + length, 8 * stream->size);

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert Normal(stream, length);

    Inhibition_of_revocable_TSRs_from_balises_in_L23_Decoder(stream, p);

    //@ assert equal:  EqualBits(stream, pos, p);
    //@ assert upper:  UpperBitsNotSet(p);
}

