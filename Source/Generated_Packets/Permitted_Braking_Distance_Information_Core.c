
#include "Permitted_Braking_Distance_Information_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Permitted_Braking_Distance_Information_UpperBitsNotSet(const Permitted_Braking_Distance_Information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->Q_TRACKINIT,       1) ;
    if (p->Q_TRACKINIT == 1)
    {
    status = status && UpperBitsNotSet64(p->D_TRACKINIT,       15);
    }
    if (p->Q_TRACKINIT == 0)
    {
    status = status && UpperBitsNotSet64(p->D_PBD,             15);
    status = status && UpperBitsNotSet64(p->Q_GDIR,            1) ;
    status = status && UpperBitsNotSet64(p->G_PBDSR,           8) ;
    status = status && UpperBitsNotSet64(p->Q_PBDSR,           1) ;
    status = status && UpperBitsNotSet64(p->D_PBDSR,           15);
    status = status && UpperBitsNotSet64(p->L_PBDSR,           15);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Permitted_Braking_Distance_Information_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
    }
    }

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Permitted_Braking_Distance_Information_Encoder(Bitstream* stream, const Permitted_Braking_Distance_Information_Core* p)
{
    if (NormalBitstream(stream, PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_BITSIZE))
    {
        if (Permitted_Braking_Distance_Information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 1,  p->Q_TRACKINIT);
            if (p->Q_TRACKINIT == 1)
            {
            Bitstream_Write(stream, 15, p->D_TRACKINIT);
            }

            if (p->Q_TRACKINIT == 0)
            {
            Bitstream_Write(stream, 15, p->D_PBD);
            Bitstream_Write(stream, 1,  p->Q_GDIR);
            Bitstream_Write(stream, 8,  p->G_PBDSR);
            Bitstream_Write(stream, 1,  p->Q_PBDSR);
            Bitstream_Write(stream, 15, p->D_PBDSR);
            Bitstream_Write(stream, 15, p->L_PBDSR);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Permitted_Braking_Distance_Information_Core_1_Encoder(stream, &(p->sub_1[i]));
            }
            }




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

int Permitted_Braking_Distance_Information_Decoder(Bitstream* stream, Permitted_Braking_Distance_Information_Core* p)
{
    if (NormalBitstream(stream, PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->Q_TRACKINIT		= Bitstream_Read(stream, 1); }

        if (p->Q_TRACKINIT == 1)
        {
	{ p->D_TRACKINIT		= Bitstream_Read(stream, 15); }
        }

        if (p->Q_TRACKINIT == 0)
        {
	{ p->D_PBD		= Bitstream_Read(stream, 15); }

	{ p->Q_GDIR		= Bitstream_Read(stream, 1); }

	{ p->G_PBDSR		= Bitstream_Read(stream, 8); }

	{ p->Q_PBDSR		= Bitstream_Read(stream, 1); }

	{ p->D_PBDSR		= Bitstream_Read(stream, 15); }

	{ p->L_PBDSR		= Bitstream_Read(stream, 15); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Permitted_Braking_Distance_Information_Core_1_Decoder(stream, &(p->sub_1[i]));
        }        }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

