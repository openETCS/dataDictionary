
#include "Package_Foo_Encoder.h"
#include "Package_Foo_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Package_Foo_Encoder(Bitstream* stream, const Package_Foo* p)
{
    if (stream->bitpos + 28 <= 8 * stream->size)
    {
        if (Package_Foo_UpperBitsNotSet(p))
        {
            //@ assert NormalBitsequence(stream, 28);
            //@ ghost uint32_t pos = stream->bitpos;

            /*@
                requires ABC_normal: NormalBitsequence(stream, 8);
                requires ABC_upper:  UpperBitsNotSet(p->ABC, 8);

                assigns stream->bitpos;
                assigns stream->addr[0..(stream->size-1)];

                ensures ABC_bitpos: stream->bitpos == pos + 8;
                ensures ABC_left:   BitstreamUnchanged{Old}(stream, 0, pos);
                ensures ABC_equal:  BitstreamEqual64(stream, pos, pos + 8,  p->ABC);
                ensures ABC_right:  BitstreamUnchanged{Old}(stream, pos + 8, 8 * stream->size);
            */
            Bitstream_Write(stream, 8, p->ABC);
            //@ ghost post_ABC:

            /*@
                requires DEF_normal: NormalBitsequence{Here}(stream, 3);
                requires DEF_upper:  UpperBitsNotSet(p->DEF, 3);

                assigns stream->bitpos;
                assigns stream->addr[0..(stream->size-1)];

                ensures DEF_bitpos: stream->bitpos == pos + 11;
                ensures DEF_left:   BitstreamUnchanged{Old}(stream, 0, pos + 8);
                ensures DEF_equal:  BitstreamEqual64(stream, pos + 8, pos + 11,  p->DEF);
                ensures DEF_right:  BitstreamUnchanged{Old}(stream, pos + 11, 8 * stream->size);

                //ensures BitstreamUnchanged{post_ABC}(stream, pos, pos + 8);
            */
            Bitstream_Write(stream, 3, p->DEF);

            // assert BitstreamUnchanged{post_ABC}(stream, pos, pos + 8);
            //@ assert ABC_equal:  BitstreamEqual64(stream, pos, pos + 8,  p->ABC);

            /*@
                requires GHI_normal: NormalBitsequence{Here}(stream, 17);
                requires GHI_upper:  UpperBitsNotSet(p->GHI, 17);

                assigns stream->bitpos;
                assigns stream->addr[0..(stream->size-1)];

                ensures GHI_bitpos: stream->bitpos == pos + 28;
                ensures GHI_left:   BitstreamUnchanged{Old}(stream, 0, pos + 11);
                ensures GHI_equal:  BitstreamEqual64(stream, pos + 11, pos + 28,  p->GHI);
                ensures GHI_right:  BitstreamUnchanged{Old}(stream, pos + 28, 8 * stream->size);
            */
            Bitstream_Write(stream, 17, p->GHI);

            //@ assert ABC_equal:  BitstreamEqual64(stream, pos, pos + 8,  p->ABC);
            //@ assert DEF_equal:  BitstreamEqual64(stream, pos + 8, pos + 11,  p->DEF);
            //@ assert GHI_equal:  BitstreamEqual64(stream, pos + 11, pos + 28,  p->GHI);
            //@ assert p_equal: BitstreamEqual(stream, pos, p);

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

