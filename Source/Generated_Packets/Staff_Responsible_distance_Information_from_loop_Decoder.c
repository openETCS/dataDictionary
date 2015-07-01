
#include "Staff_Responsible_distance_Information_from_loop_Decoder.h"
#include "Bitstream_Read.h"
#include "Staff_Responsible_distance_Information_from_loop_Core_1_Decoder.h"

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

