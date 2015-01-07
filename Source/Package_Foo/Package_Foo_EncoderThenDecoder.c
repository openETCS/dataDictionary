
#include "Package_Foo_Decoder.h"
#include "Package_Foo_Encoder.h"

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
void Package_Foo_EncoderThenDecoder(Bitstream* stream, Package_Foo* p)
{
    const uint32_t length = 28;
    //@ ghost uint32_t pos = stream->bitpos;

    //@ assert Normal(stream, length);
    Package_Foo_Encoder(stream, p);

    //@ assert left:   EqualBits{Here,Pre}(stream, 0, pos);
    //@ assert middle: EqualBits(stream, pos, p);
    //@ assert right:  EqualBits{Here,Pre}(stream, pos + length, 8 * stream->size);

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert Normal(stream, length);

    Package_Foo_Decoder(stream, p);

    //@ assert equal:     EqualBits(stream, pos, p);
    //@ assert not_set:   UpperBitsNotSet(p);
    //@ assert increment: stream->bitpos == pos + length;
}
