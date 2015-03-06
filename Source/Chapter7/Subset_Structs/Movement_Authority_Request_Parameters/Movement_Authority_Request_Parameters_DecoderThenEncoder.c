
#include "Movement_Authority_Request_Parameters_Decoder.h"
#include "Movement_Authority_Request_Parameters_Encoder.h"

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
void Movement_Authority_Request_Parameters_DecoderThenEncoder(Bitstream* stream, Movement_Authority_Request_Parameters* p)
{
    const uint32_t length = MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_BITSIZE;
    //@ ghost uint32_t pos = stream->bitpos;

    //@ assert Normal(stream, length);
    Movement_Authority_Request_Parameters_Decoder(stream, p);

    //@ assert pos:        stream->bitpos == pos + length;
    //@ assert equal:      EqualBits(stream, pos, p);
    //@ assert upper:      UpperBitsNotSet(p);
    //@ assert increment:  stream->bitpos == pos + length;

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert Normal(stream, length);

    Movement_Authority_Request_Parameters_Encoder(stream, p);

    //@ assert left:    Unchanged{Here,Pre}(stream, 0, pos);
    //@ assert middle:  EqualBits(stream, pos, p);
    //@ assert right:   Unchanged{Here,Pre}(stream, pos + length, 8 * stream->size);
}

