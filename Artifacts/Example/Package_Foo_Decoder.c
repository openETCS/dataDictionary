
#include "Package_Foo_Decoder.h"
#include "Bitstream_Read.h"

int Package_Foo_Decoder(Bitstream* stream, Package_Foo* p)
{
    if (stream->bitpos + 28 <= 8 * stream->size)
    {
        //@ assert NormalBitsequence(stream, 28);
        //@ ghost uint32_t pos = stream->bitpos;

        /*@
            requires ABC_normal: NormalBitsequence(stream, 8);

            assigns stream->bitpos;
            assigns p->ABC;

            ensures ABC_bitpos: stream->bitpos == pos + 8;
            ensures ABC_equal:  BitstreamEqual64(stream, pos, pos + 8,  p->ABC);
            ensures ABC_upper:  UpperBitsNotSet(p->ABC, 8);
        */
        p->ABC = Bitstream_Read(stream, 8);

        p->DEF = Bitstream_Read(stream, 3);
        //@ assert stream->bitpos == pos + 11;
        //@ assert BitstreamEqual64(stream, pos + 8,  pos + 11,  p->DEF);
        //@ assert UpperBitsNotSet(p->ABC, 3);

        p->GHI = Bitstream_Read(stream, 17);
        //@ assert stream->bitpos == pos + 28;
        //@ assert BitstreamEqual64(stream, pos + 11,  pos + 28,  p->GHI);
        //@ assert UpperBitsNotSet(p->ABC, 17);

        return 1;
    }
    else
    {
        return 0;
    }
}

