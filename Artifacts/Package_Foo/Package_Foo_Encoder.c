
#include "Package_Foo_Encoder.h"
#include "Package_Foo_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Package_Foo_Encoder(Bitstream* stream, const Package_Foo* p)
{
    uint8_t* addr = stream->addr;
    const uint32_t pos  = stream->bitpos;
    const uint32_t size = stream->size;

    if (pos + 28 <= 8 * size)
    {
        if (Package_Foo_UpperBitsNotSet(p))
        {
            Bitwalker_Poke_Normal(addr, size, pos,       8, p->ABC);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   3, p->DEF);
            Bitwalker_Poke_Normal(addr, size, pos + 11, 17, p->GHI);

            stream->bitpos += 28;

            return 1;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
}

