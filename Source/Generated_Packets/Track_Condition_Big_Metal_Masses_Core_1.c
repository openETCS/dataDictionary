
#include "Track_Condition_Big_Metal_Masses_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Track_Condition_Big_Metal_Masses_Core_1_UpperBitsNotSet(const Track_Condition_Big_Metal_Masses_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_TRACKCOND_k,     15);
    status = status && UpperBitsNotSet64(p->L_TRACKCOND_k,     15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Track_Condition_Big_Metal_Masses_Core_1_Encoder(Bitstream* stream, const Track_Condition_Big_Metal_Masses_Core_1* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_BITSIZE))
    {
        if (Track_Condition_Big_Metal_Masses_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_TRACKCOND_k);
            Bitstream_Write(stream, 15, p->L_TRACKCOND_k);



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

int Track_Condition_Big_Metal_Masses_Core_1_Decoder(Bitstream* stream, Track_Condition_Big_Metal_Masses_Core_1* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->D_TRACKCOND_k		= Bitstream_Read(stream, 15); }

	{ p->L_TRACKCOND_k		= Bitstream_Read(stream, 15); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

