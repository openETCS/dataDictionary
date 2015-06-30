
#include "Staff_Responsible_distance_Information_from_loop_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Staff_Responsible_distance_Information_from_loop_UpperBitsNotSet(const Staff_Responsible_distance_Information_from_loop_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY_0,    1) ;
    if (p->Q_NEWCOUNTRY_0 == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_C_0,           10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG_0,          14);
    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY_1,    1) ;
    if (p->Q_NEWCOUNTRY_1 == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_C_1,           10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG_1,          14);
    status = status && UpperBitsNotSet64(p->D_SR,              15);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Staff_Responsible_distance_Information_from_loop_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int Staff_Responsible_distance_Information_from_loop_Encoder(Bitstream* stream, const Staff_Responsible_distance_Information_from_loop_Core* p)
{
    if (NormalBitstream(stream, STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_BITSIZE))
    {
        if (Staff_Responsible_distance_Information_from_loop_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY_0);
            if (p->Q_NEWCOUNTRY_0 == 1)
            {
            Bitstream_Write(stream, 10, p->NID_C_0);
            }

            Bitstream_Write(stream, 14, p->NID_BG_0);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY_1);
            if (p->Q_NEWCOUNTRY_1 == 1)
            {
            Bitstream_Write(stream, 10, p->NID_C_1);
            }

            Bitstream_Write(stream, 14, p->NID_BG_1);
            Bitstream_Write(stream, 15, p->D_SR);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Staff_Responsible_distance_Information_from_loop_Core_1_Encoder(stream, &(p->sub_1[i]));
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

int Staff_Responsible_distance_Information_from_loop_Decoder(Bitstream* stream, Staff_Responsible_distance_Information_from_loop_Core* p)
{
    if (NormalBitstream(stream, STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->Q_NEWCOUNTRY_0		= Bitstream_Read(stream, 1); }

        if (p->Q_NEWCOUNTRY_0 == 1)
        {
	{ p->NID_C_0		= Bitstream_Read(stream, 10); }
        }

	{ p->NID_BG_0		= Bitstream_Read(stream, 14); }

	{ p->Q_NEWCOUNTRY_1		= Bitstream_Read(stream, 1); }

        if (p->Q_NEWCOUNTRY_1 == 1)
        {
	{ p->NID_C_1		= Bitstream_Read(stream, 10); }
        }

	{ p->NID_BG_1		= Bitstream_Read(stream, 14); }

	{ p->D_SR		= Bitstream_Read(stream, 15); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Staff_Responsible_distance_Information_from_loop_Core_1_Decoder(stream, &(p->sub_1[i]));
        }


	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

