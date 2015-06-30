
#include "Gradient_Profile_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Gradient_Profile_Core_1_UpperBitsNotSet(const Gradient_Profile_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_GRADIENT_k,      15);
    status = status && UpperBitsNotSet64(p->Q_GDIR_k,          1) ;
    status = status && UpperBitsNotSet64(p->G_A_k,             8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Gradient_Profile_Core_1_Encoder(Bitstream* stream, const Gradient_Profile_Core_1* p)
{
    if (NormalBitstream(stream, GRADIENT_PROFILE_CORE_1_CORE_BITSIZE))
    {
        if (Gradient_Profile_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_GRADIENT_k);
            Bitstream_Write(stream, 1,  p->Q_GDIR_k);
            Bitstream_Write(stream, 8,  p->G_A_k);



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

int Gradient_Profile_Core_1_Decoder(Bitstream* stream, Gradient_Profile_Core_1* p)
{
    if (NormalBitstream(stream, GRADIENT_PROFILE_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->D_GRADIENT_k		= Bitstream_Read(stream, 15); }

	{ p->Q_GDIR_k		= Bitstream_Read(stream, 1); }

	{ p->G_A_k		= Bitstream_Read(stream, 8); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

