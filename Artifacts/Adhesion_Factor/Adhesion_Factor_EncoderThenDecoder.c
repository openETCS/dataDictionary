
#include "Adhesion_Factor_Decoder.h"
#include "Adhesion_Factor_Encoder.h"

/*@
    requires valid_stream: \valid(stream);
    requires stream_inv:   BitstreamInvariant(stream);
    requires max_pos:      stream->bitpos + BitSize(p) <= UINT32_MAX;
    requires max_pos:      NormalBitsequence(stream, BitSize(p));

    requires \valid(p);
    requires \separated(stream, p);
    requires \separated(stream->addr + (0..stream->size-1), p);

    requires not_set:      UpperBitsNotSet(p);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:   *p == \old(*p);
*/
void Adhesion_Factor_EncoderThenDecoder(Bitstream* stream, Adhesion_Factor* p)
{
    const uint32_t length = ADHESION_FACTOR_BITSIZE;
    //@ ghost uint32_t pos = stream->bitpos;

    //@ assert NormalBitsequence(stream, length);
    Adhesion_Factor_Encoder(stream, p);

    //@ assert unchanged_left:  BitstreamUnchanged{Here,Pre}(stream, 0, pos);
    //@ assert copied2:         BitstreamEqual(stream, pos, p);
    //@ assert unchanged_right: BitstreamUnchanged{Here,Pre}(stream, pos + length, 8 * stream->size);

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert NormalBitsequence(stream, length);

    Adhesion_Factor_Decoder(stream, p);

    //@ assert new_pos:    stream->bitpos == pos + length;
    //@ assert size:       stream->size   == \at(stream->size, Pre);
    //@ assert copied1:    BitstreamEqual(stream, pos, p);
    //@ assert not_set:    UpperBitsNotSet(p);
    //@ assert increment:  stream->bitpos == pos + length;
}
