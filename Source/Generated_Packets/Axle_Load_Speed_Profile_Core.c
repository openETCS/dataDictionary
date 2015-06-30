
#include "Axle_Load_Speed_Profile_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Axle_Load_Speed_Profile_UpperBitsNotSet(const Axle_Load_Speed_Profile_Core* p)
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
    status = status && UpperBitsNotSet64(p->D_AXLELOAD,        15);
    status = status && UpperBitsNotSet64(p->L_AXLELOAD,        15);
    status = status && UpperBitsNotSet64(p->Q_FRONT,           1) ;
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Axle_Load_Speed_Profile_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
    }
    status = status && UpperBitsNotSet64(p->N_ITER_2,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_2; ++i)
    {
        status = status && Axle_Load_Speed_Profile_Core_2_UpperBitsNotSet(&(p->sub_2[i]));
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

int Axle_Load_Speed_Profile_Encoder(Bitstream* stream, const Axle_Load_Speed_Profile_Core* p)
{
    if (NormalBitstream(stream, AXLE_LOAD_SPEED_PROFILE_CORE_BITSIZE))
    {
        if (Axle_Load_Speed_Profile_UpperBitsNotSet(p))
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
            Bitstream_Write(stream, 15, p->D_AXLELOAD);
            Bitstream_Write(stream, 15, p->L_AXLELOAD);
            Bitstream_Write(stream, 1,  p->Q_FRONT);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Axle_Load_Speed_Profile_Core_1_Encoder(stream, &(p->sub_1[i]));
            }
            Bitstream_Write(stream, 5,  p->N_ITER_2);
            for (uint32_t i = 0; i < p->N_ITER_2; ++i)
            {
                Axle_Load_Speed_Profile_Core_2_Encoder(stream, &(p->sub_2[i]));
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

int Axle_Load_Speed_Profile_Decoder(Bitstream* stream, Axle_Load_Speed_Profile_Core* p)
{
    if (NormalBitstream(stream, AXLE_LOAD_SPEED_PROFILE_CORE_BITSIZE))
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
	{ p->D_AXLELOAD		= Bitstream_Read(stream, 15); }

	{ p->L_AXLELOAD		= Bitstream_Read(stream, 15); }

	{ p->Q_FRONT		= Bitstream_Read(stream, 1); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Axle_Load_Speed_Profile_Core_1_Decoder(stream, &(p->sub_1[i]));
        }
	{ p->N_ITER_2		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_2; ++i)
        {
            Axle_Load_Speed_Profile_Core_2_Decoder(stream, &(p->sub_2[i]));
        }        }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

