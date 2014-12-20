
#include "Package_Foo.h"

void Package_Foo_Init(Package_Foo* p)
{
    p->ABC = 0;
    p->DEF = 0;
    p->GHI = 0;
}


int Package_Foo_Decoder(Bitstream* stream, Package_Foo* p)
{
    if (stream->bitpos + 28 <= 8 * stream->size)
    {
        p->ABC = Bitstream_Read(stream, 8);
        //@ assert stream->bitpos == \at(stream->bitpos, Pre) + 8;

        p->DEF = Bitstream_Read(stream, 3);
        //@ assert stream->bitpos == \at(stream->bitpos, Pre) + 11;

        p->GHI = Bitstream_Read(stream, 17);
        //@ assert stream->bitpos == \at(stream->bitpos, Pre) + 28;

        return 1;
    }
    else
    {
        return 0;
    }
}

