
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
            //@ assert Normal(stream, 28);
            //@ assert \separated(stream, stream->addr + (0..stream->size-1));
            //@ assert \separated(p,      stream->addr + (0..stream->size-1));
            //@ assert \separated(p,      stream);

            /*@
                requires ABC_normal: Normal(stream, 8);
                requires ABC_upper:  UpperBitsNotSet(p->ABC, 8);

                assigns addr[0..(size-1)];

                ensures ABC_left:   BitsUnchanged{Here,Old}(addr, 0, pos);
                ensures ABC_equal:  EqualBits64(addr, pos, pos + 8,  p->ABC);
                ensures ABC_right:  BitsUnchanged{Here,Old}(addr, pos + 8, 8 * size);
            */
            Bitwalker_Poke_Normal(addr, size, pos, 8, p->ABC);

            /*@
                requires DEF_normal: Normal{Here}(stream, 3);
                requires DEF_upper:  UpperBitsNotSet(p->DEF, 3);

                assigns addr[0..(size-1)];

                ensures DEF_left:   BitsUnchanged{Here,Old}(addr, 0, pos + 8);
                ensures DEF_equal:  EqualBits64(addr, pos + 8, pos + 11,  p->DEF);
                ensures DEF_right:  BitsUnchanged{Here,Old}(addr, pos + 11, 8 * size);
            */
            Bitwalker_Poke_Normal(addr, size, pos + 8, 3, p->DEF);
            //@ ghost post_DEF:

            /*@
                requires GHI_normal: Normal{Here}(stream, 17);
                requires GHI_upper:  UpperBitsNotSet(p->GHI, 17);
                requires \separated(stream, p);

                assigns addr[0..(size-1)];

                ensures GHI_left:   BitsUnchanged{Here,Old}(addr, 0, pos + 11);
                ensures GHI_equal:  EqualBits64(addr, pos + 11, pos + 28,  p->GHI);
                ensures GHI_right:  BitsUnchanged{Here,Old}(addr, pos + 28, 8 * size);
            */
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

