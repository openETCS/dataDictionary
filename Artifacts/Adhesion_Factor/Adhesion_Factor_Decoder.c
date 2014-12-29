
#include "Adhesion_Factor_Decoder.h"
#include "Bitstream_Read.h"

int Adhesion_Factor_Decoder(Bitstream* stream, Adhesion_Factor* p)
{
    if (stream->bitpos + 28 > 8 * stream->size)
    {
        return 0;
    }
    else
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

        /*@
            requires DEF_normal: NormalBitsequence{Here}(stream, 3);

            assigns stream->bitpos;
            assigns p->DEF;

            ensures DEF_bitpos: stream->bitpos == pos + 11;
            ensures DEF_equal:  BitstreamEqual64(stream, pos + 8, pos + 11,  p->DEF);
            ensures DEF_upper:  UpperBitsNotSet(p->DEF, 3);
        */
        p->DEF = Bitstream_Read(stream, 3);

        /*@
            requires GHI_normal: NormalBitsequence(stream, 17);

            assigns stream->bitpos;
            assigns p->GHI;

            ensures GHI_bitpos: stream->bitpos == pos + 28;
            ensures GHI_equal:  BitstreamEqual64(stream, pos + 11, pos + 28,  p->GHI);
            ensures GHI_upper:  UpperBitsNotSet(p->GHI, 17);
        */
        p->GHI = Bitstream_Read(stream, 17);

        //@ assert ABC_final:  BitstreamEqual64(stream, pos, pos + 8,  p->ABC);
        //@ assert DEF_final:  BitstreamEqual64(stream, pos + 8, pos + 11,  p->DEF);
        //@ assert GHI_final:  BitstreamEqual64(stream, pos + 11, pos + 28,  p->GHI);
        //@ assert p_equal: BitstreamEqual(stream, pos, p);

        return 1;
    }
}

