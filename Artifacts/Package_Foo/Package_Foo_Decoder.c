
#include "Package_Foo_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Package_Foo_Decoder(Bitstream* stream, Package_Foo* p)
{
    if (NormalBitstream(stream, 28))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->ABC = Bitwalker_Peek_Normal(addr, size, pos,      8);
        p->DEF = Bitwalker_Peek_Normal(addr, size, pos + 8,  3);
        p->GHI = Bitwalker_Peek_Normal(addr, size, pos + 11, 17);

        stream->bitpos += 28;

        //@ assert ABC:  BitstreamEqual64(stream, pos, pos + 8,  p->ABC);
        //@ assert DEF:  BitstreamEqual64(stream, pos + 8, pos + 11,  p->DEF);
        //@ assert GHI:  BitstreamEqual64(stream, pos + 11, pos + 28,  p->GHI);

        return 1;
    }
    else
    {
        return 0;
    }
}

