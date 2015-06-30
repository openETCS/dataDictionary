
#include "Permitted_Braking_Distance_Information_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Permitted_Braking_Distance_Information_Core_1_UpperBitsNotSet(const Permitted_Braking_Distance_Information_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_PBD_k,           15);
    status = status && UpperBitsNotSet64(p->Q_GDIR_k,          1) ;
    status = status && UpperBitsNotSet64(p->G_PBDSR_k,         8) ;
    status = status && UpperBitsNotSet64(p->Q_PBDSR_k,         1) ;
    status = status && UpperBitsNotSet64(p->D_PBDSR_k,         15);
    status = status && UpperBitsNotSet64(p->L_PBDSR_k,         15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Permitted_Braking_Distance_Information_Core_1_Encoder(Bitstream* stream, const Permitted_Braking_Distance_Information_Core_1* p)
{
    if (NormalBitstream(stream, PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_BITSIZE))
    {
        if (Permitted_Braking_Distance_Information_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_PBD_k);
            Bitstream_Write(stream, 1,  p->Q_GDIR_k);
            Bitstream_Write(stream, 8,  p->G_PBDSR_k);
            Bitstream_Write(stream, 1,  p->Q_PBDSR_k);
            Bitstream_Write(stream, 15, p->D_PBDSR_k);
            Bitstream_Write(stream, 15, p->L_PBDSR_k);



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

int Permitted_Braking_Distance_Information_Core_1_Decoder(Bitstream* stream, Permitted_Braking_Distance_Information_Core_1* p)
{
    if (NormalBitstream(stream, PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->D_PBD_k		= Bitstream_Read(stream, 15); }

	{ p->Q_GDIR_k		= Bitstream_Read(stream, 1); }

	{ p->G_PBDSR_k		= Bitstream_Read(stream, 8); }

	{ p->Q_PBDSR_k		= Bitstream_Read(stream, 1); }

	{ p->D_PBDSR_k		= Bitstream_Read(stream, 15); }

	{ p->L_PBDSR_k		= Bitstream_Read(stream, 15); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

