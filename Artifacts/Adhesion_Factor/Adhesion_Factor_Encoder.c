
#include "Adhesion_Factor_Encoder.h"
#include "Adhesion_Factor_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Adhesion_Factor_Encoder(Bitstream* stream, const Adhesion_Factor* p)
{
    if (stream->bitpos + 28 <= 8 * stream->size)
    {
        if (Adhesion_Factor_UpperBitsNotSet(p))
        {
            //@ assert NormalBitsequence(stream, 28);
            //@ ghost uint32_t pos = stream->bitpos;
            //@ ghost uint32_t size = stream->size;
            //@ assert \separated(stream, stream->addr + (0..stream->size-1));

            /*@
                requires ABC_normal: NormalBitsequence(stream, 8);
                requires ABC_upper:  UpperBitsNotSet(p->ABC, 8);

                assigns stream->bitpos;
                assigns stream->addr[0..(stream->size-1)];

                ensures ABC_bitpos: stream->bitpos == \old(stream->bitpos) + 8;
                ensures ABC_size:   stream->size == \old(stream->size);
                ensures ABC_left:   BitsUnchanged{Here,Old}(stream->addr, 0, pos);
                ensures ABC_equal:  BitstreamEqual64(stream, pos, pos + 8,  p->ABC);
                ensures ABC_right:  BitsUnchanged{Here,Old}(stream->addr, pos + 8, 8 * stream->size);
            */
            Bitstream_Write(stream, 8, p->ABC);

            //@ assert stream->size == size;

            /*@
                requires DEF_normal: NormalBitsequence{Here}(stream, 3);
                requires DEF_upper:  UpperBitsNotSet(p->DEF, 3);

                assigns stream->bitpos;
                assigns stream->addr[0..(stream->size-1)];

                ensures DEF_bitpos: stream->bitpos == \old(stream->bitpos) + 3;
                ensures DEF_size:   stream->size == \old(stream->size);
                ensures DEF_left:   BitsUnchanged{Here,Old}(stream->addr, 0, pos + 8);
                ensures DEF_equal:  BitstreamEqual64(stream, pos + 8, pos + 11,  p->DEF);
                ensures DEF_right:  BitsUnchanged{Here,Old}(stream->addr, pos + 11, 8 * stream->size);

                //ensures ABC_DEF_equal: BitstreamEqual64(stream, pos, pos + 8,  p->ABC);
            */
            Bitstream_Write(stream, 3, p->DEF);
            //@ ghost post_DEF:

            /*@
                requires GHI_normal: NormalBitsequence{Here}(stream, 17);
                requires GHI_upper:  UpperBitsNotSet(p->GHI, 17);
                requires \separated(stream, p);

                assigns stream->bitpos;
                assigns stream->addr[0..(stream->size-1)];

                ensures GHI_bitpos: stream->bitpos == \old(stream->bitpos) + 17;
                ensures GHI_size:   stream->size == \old(stream->size);
                ensures GHI_left:   BitsUnchanged{Here,Old}(stream->addr, 0, pos + 11);
                ensures GHI_equal:  BitstreamEqual64(stream, pos + 11, pos + 28,  p->GHI);
                ensures GHI_right:  BitsUnchanged{Here,Old}(stream->addr, pos + 28, 8 * stream->size);
            */
            Bitstream_Write(stream, 17, p->GHI);

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
