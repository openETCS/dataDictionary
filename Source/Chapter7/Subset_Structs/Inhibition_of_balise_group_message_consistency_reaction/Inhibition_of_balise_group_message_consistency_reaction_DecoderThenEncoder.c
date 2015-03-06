
#include "Inhibition_of_balise_group_message_consistency_reaction_Decoder.h"
#include "Inhibition_of_balise_group_message_consistency_reaction_Encoder.h"

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
void Inhibition_of_balise_group_message_consistency_reaction_DecoderThenEncoder(Bitstream* stream, Inhibition_of_balise_group_message_consistency_reaction* p)
{
    const uint32_t length = INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_BITSIZE;
    //@ ghost uint32_t pos = stream->bitpos;

    //@ assert Normal(stream, length);
    Inhibition_of_balise_group_message_consistency_reaction_Decoder(stream, p);

    //@ assert pos:        stream->bitpos == pos + length;
    //@ assert equal:      EqualBits(stream, pos, p);
    //@ assert upper:      UpperBitsNotSet(p);
    //@ assert increment:  stream->bitpos == pos + length;

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert Normal(stream, length);

    Inhibition_of_balise_group_message_consistency_reaction_Encoder(stream, p);

    //@ assert left:    Unchanged{Here,Pre}(stream, 0, pos);
    //@ assert middle:  EqualBits(stream, pos, p);
    //@ assert right:   Unchanged{Here,Pre}(stream, pos + length, 8 * stream->size);
}

