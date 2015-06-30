
#include "Track_Condition_Station_Platforms_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Track_Condition_Station_Platforms_UpperBitsNotSet(const Track_Condition_Station_Platforms_Core* p)
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
    status = status && UpperBitsNotSet64(p->D_TRACKCOND,       15);
    status = status && UpperBitsNotSet64(p->L_TRACKCOND,       15);
    status = status && UpperBitsNotSet64(p->M_PLATFORM,        4) ;
    status = status && UpperBitsNotSet64(p->Q_PLATFORM,        2) ;
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Track_Condition_Station_Platforms_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int Track_Condition_Station_Platforms_Encoder(Bitstream* stream, const Track_Condition_Station_Platforms_Core* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_STATION_PLATFORMS_CORE_BITSIZE))
    {
        if (Track_Condition_Station_Platforms_UpperBitsNotSet(p))
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
            Bitstream_Write(stream, 15, p->D_TRACKCOND);
            Bitstream_Write(stream, 15, p->L_TRACKCOND);
            Bitstream_Write(stream, 4,  p->M_PLATFORM);
            Bitstream_Write(stream, 2,  p->Q_PLATFORM);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Track_Condition_Station_Platforms_Core_1_Encoder(stream, &(p->sub_1[i]));
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

int Track_Condition_Station_Platforms_Decoder(Bitstream* stream, Track_Condition_Station_Platforms_Core* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_STATION_PLATFORMS_CORE_BITSIZE))
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
	{ p->D_TRACKCOND		= Bitstream_Read(stream, 15); }

	{ p->L_TRACKCOND		= Bitstream_Read(stream, 15); }

	{ p->M_PLATFORM		= Bitstream_Read(stream, 4); }

	{ p->Q_PLATFORM		= Bitstream_Read(stream, 2); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Track_Condition_Station_Platforms_Core_1_Decoder(stream, &(p->sub_1[i]));
        }        }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

