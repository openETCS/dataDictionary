
#include "Adhesion_Factor_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Adhesion_Factor_UpperBitsNotSet(const Adhesion_Factor_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_ADHESION,        15);
    status = status && UpperBitsNotSet64(p->L_ADHESION,        15);
    status = status && UpperBitsNotSet64(p->M_ADHESION,        1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Adhesion_Factor_Encoder(Bitstream* stream, const Adhesion_Factor_Core* p)
{
    if (NormalBitstream(stream, ADHESION_FACTOR_CORE_BITSIZE))
    {
        if (Adhesion_Factor_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_ADHESION);
            Bitstream_Write(stream, 15, p->L_ADHESION);
            Bitstream_Write(stream, 1,  p->M_ADHESION);



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

int Adhesion_Factor_Decoder(Bitstream* stream, Adhesion_Factor_Core* p)
{
    if (NormalBitstream(stream, ADHESION_FACTOR_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->D_ADHESION		= Bitstream_Read(stream, 15); }

	{ p->L_ADHESION		= Bitstream_Read(stream, 15); }

	{ p->M_ADHESION		= Bitstream_Read(stream, 1); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

