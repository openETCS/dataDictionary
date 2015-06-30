
#include "Staff_Responsible_distance_Information_from_loop_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Staff_Responsible_distance_Information_from_loop_Core_1_UpperBitsNotSet(const Staff_Responsible_distance_Information_from_loop_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY_k,    1) ;
    if (p->Q_NEWCOUNTRY_k == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_C_k,           10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG_k,          14);
    status = status && UpperBitsNotSet64(p->D_SR_k,            15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Staff_Responsible_distance_Information_from_loop_Core_1_Encoder(Bitstream* stream, const Staff_Responsible_distance_Information_from_loop_Core_1* p)
{
    if (NormalBitstream(stream, STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_1_CORE_BITSIZE))
    {
        if (Staff_Responsible_distance_Information_from_loop_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY_k);
            if (p->Q_NEWCOUNTRY_k == 1)
            {
            Bitstream_Write(stream, 10, p->NID_C_k);
            }

            Bitstream_Write(stream, 14, p->NID_BG_k);
            Bitstream_Write(stream, 15, p->D_SR_k);



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

int Staff_Responsible_distance_Information_from_loop_Core_1_Decoder(Bitstream* stream, Staff_Responsible_distance_Information_from_loop_Core_1* p)
{
    if (NormalBitstream(stream, STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_NEWCOUNTRY_k		= Bitstream_Read(stream, 1); }

        if (p->Q_NEWCOUNTRY_k == 1)
        {
	{ p->NID_C_k		= Bitstream_Read(stream, 10); }
        }

	{ p->NID_BG_k		= Bitstream_Read(stream, 14); }

	{ p->D_SR_k		= Bitstream_Read(stream, 15); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

