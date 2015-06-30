
#include "Mode_profile_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Mode_profile_Core_1_UpperBitsNotSet(const Mode_profile_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_MAMODE_k,        15);
    status = status && UpperBitsNotSet64(p->M_MAMODE_k,        2) ;
    status = status && UpperBitsNotSet64(p->V_MAMODE_k,        7) ;
    status = status && UpperBitsNotSet64(p->L_MAMODE_k,        15);
    status = status && UpperBitsNotSet64(p->L_ACKMAMODE_k,     15);
    status = status && UpperBitsNotSet64(p->Q_MAMODE_k,        1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Mode_profile_Core_1_Encoder(Bitstream* stream, const Mode_profile_Core_1* p)
{
    if (NormalBitstream(stream, MODE_PROFILE_CORE_1_CORE_BITSIZE))
    {
        if (Mode_profile_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_MAMODE_k);
            Bitstream_Write(stream, 2,  p->M_MAMODE_k);
            Bitstream_Write(stream, 7,  p->V_MAMODE_k);
            Bitstream_Write(stream, 15, p->L_MAMODE_k);
            Bitstream_Write(stream, 15, p->L_ACKMAMODE_k);
            Bitstream_Write(stream, 1,  p->Q_MAMODE_k);



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

int Mode_profile_Core_1_Decoder(Bitstream* stream, Mode_profile_Core_1* p)
{
    if (NormalBitstream(stream, MODE_PROFILE_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->D_MAMODE_k		= Bitstream_Read(stream, 15); }

	{ p->M_MAMODE_k		= Bitstream_Read(stream, 2); }

	{ p->V_MAMODE_k		= Bitstream_Read(stream, 7); }

	{ p->L_MAMODE_k		= Bitstream_Read(stream, 15); }

	{ p->L_ACKMAMODE_k		= Bitstream_Read(stream, 15); }

	{ p->Q_MAMODE_k		= Bitstream_Read(stream, 1); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

