
#include "EOLM_Packet_Decoder.h"
#include "EOLM_Packet_Encoder.h"

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
void EOLM_Packet_EncoderThenDecoder(Bitstream* stream, EOLM_Packet* p)
{
    const uint32_t length = EOLM_PACKET_BITSIZE;
    //@ ghost uint32_t pos = stream->bitpos;

    //@ assert Normal(stream, length);
    EOLM_Packet_Encoder(stream, p);

    //@ assert left:    Unchanged{Here,Pre}(stream, 0, pos);
    //@ assert middle:  EqualBits(stream, pos, p);
    //@ assert right:   Unchanged{Here,Pre}(stream, pos + length, 8 * stream->size);

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert Normal(stream, length);

    /*@
        assigns *p;

	ensures equal: EqualBits(stream, pos, p);
	ensures upper: UpperBitsNotSet(p);
    */
    EOLM_Packet_Decoder(stream, p);

}

