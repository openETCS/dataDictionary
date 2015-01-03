
#include "Adhesion_Factor_Decoder.h"
#include "Adhesion_Factor_Encoder.h"

/*@
    requires valid:     \valid(p);

    requires upper:     UpperBitsNotSet(p);

    requires valid:     Writeable(stream);

    requires invariant: Invariant(stream, BitSize(p));

    requires normal:    Normal(stream, BitSize(p));

    requires seprated:  Separated(stream, p);

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

    //@ assert left:   BitstreamUnchanged{Here,Pre}(stream, 0, pos);
    //@ assert middle: BitstreamEqual(stream, pos, p);
    //@ assert right:  BitstreamUnchanged{Here,Pre}(stream, pos + length, 8 * stream->size);

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert Normal(stream, length);

    Adhesion_Factor_Decoder(stream, p);

    //@ assert copied:    BitstreamEqual(stream, pos, p);
    //@ assert upper:     UpperBitsNotSet(p);
    //@ assert increment: stream->bitpos == pos + length;
}
