
#include "Stop_if_in_Staff_Responsible_Decoder.h"
#include "Stop_if_in_Staff_Responsible_Encoder.h"

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
void Stop_if_in_Staff_Responsible_EncoderThenDecoder(Bitstream* stream, Stop_if_in_Staff_Responsible* p)
{
    const uint32_t length = STOP_IF_IN_STAFF_RESPONSIBLE_BITSIZE;
    //@ ghost uint32_t pos = stream->bitpos;

    //@ assert Normal(stream, length);
    Stop_if_in_Staff_Responsible_Encoder(stream, p);

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
    Stop_if_in_Staff_Responsible_Decoder(stream, p);

}

