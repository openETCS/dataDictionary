
#include "Track_Condition_Change_of_traction_system_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Track_Condition_Change_of_traction_system_UpperBitsNotSet(const Track_Condition_Change_of_traction_system_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_TRACTION,        15);
    status = status && UpperBitsNotSet64(p->M_VOLTAGE,         4) ;
    if (p->M_VOLTAGE != 0)
    {
    status = status && UpperBitsNotSet64(p->NID_CTRACTION,     10);
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

int Track_Condition_Change_of_traction_system_Encoder(Bitstream* stream, const Track_Condition_Change_of_traction_system_Core* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_CORE_BITSIZE))
    {
        if (Track_Condition_Change_of_traction_system_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_TRACTION);
            Bitstream_Write(stream, 4,  p->M_VOLTAGE);
            if (p->M_VOLTAGE != 0)
            {
            Bitstream_Write(stream, 10, p->NID_CTRACTION);
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

int Track_Condition_Change_of_traction_system_Decoder(Bitstream* stream, Track_Condition_Change_of_traction_system_Core* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->D_TRACTION		= Bitstream_Read(stream, 15); }

	{ p->M_VOLTAGE		= Bitstream_Read(stream, 4); }

        if (p->M_VOLTAGE != 0)
        {
	{ p->NID_CTRACTION		= Bitstream_Read(stream, 10); }
        }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

