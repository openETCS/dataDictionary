
#include "Radio_infill_area_information_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Radio_infill_area_information_UpperBitsNotSet(const Radio_infill_area_information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->Q_RIU,             1) ;
    status = status && UpperBitsNotSet64(p->NID_C,             10);
    status = status && UpperBitsNotSet64(p->NID_RIU,           14);
    status = status && UpperBitsNotSet64(p->NID_RADIO,         64);
    status = status && UpperBitsNotSet64(p->D_INFILL,          15);
    status = status && UpperBitsNotSet64(p->NID_BG,            14);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Radio_infill_area_information_Encoder(Bitstream* stream, const Radio_infill_area_information_Core* p)
{
    if (NormalBitstream(stream, RADIO_INFILL_AREA_INFORMATION_CORE_BITSIZE))
    {
        if (Radio_infill_area_information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 1,  p->Q_RIU);
            Bitstream_Write(stream, 10, p->NID_C);
            Bitstream_Write(stream, 14, p->NID_RIU);
            Bitstream_Write(stream, 64, p->NID_RADIO);
            Bitstream_Write(stream, 15, p->D_INFILL);
            Bitstream_Write(stream, 14, p->NID_BG);



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

int Radio_infill_area_information_Decoder(Bitstream* stream, Radio_infill_area_information_Core* p)
{
    if (NormalBitstream(stream, RADIO_INFILL_AREA_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->Q_RIU		= Bitstream_Read(stream, 1); }

	{ p->NID_C		= Bitstream_Read(stream, 10); }

	{ p->NID_RIU		= Bitstream_Read(stream, 14); }

	{ p->NID_RADIO		= Bitstream_Read(stream, 64); }

	{ p->D_INFILL		= Bitstream_Read(stream, 15); }

	{ p->NID_BG		= Bitstream_Read(stream, 14); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

