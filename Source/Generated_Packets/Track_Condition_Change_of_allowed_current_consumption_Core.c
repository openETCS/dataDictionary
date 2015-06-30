
#include "Track_Condition_Change_of_allowed_current_consumption_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Track_Condition_Change_of_allowed_current_consumption_UpperBitsNotSet(const Track_Condition_Change_of_allowed_current_consumption_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_CURRENT,         15);
    status = status && UpperBitsNotSet64(p->M_CURRENT,         10);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Track_Condition_Change_of_allowed_current_consumption_Encoder(Bitstream* stream, const Track_Condition_Change_of_allowed_current_consumption_Core* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_CORE_BITSIZE))
    {
        if (Track_Condition_Change_of_allowed_current_consumption_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_CURRENT);
            Bitstream_Write(stream, 10, p->M_CURRENT);



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

int Track_Condition_Change_of_allowed_current_consumption_Decoder(Bitstream* stream, Track_Condition_Change_of_allowed_current_consumption_Core* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->D_CURRENT		= Bitstream_Read(stream, 15); }

	{ p->M_CURRENT		= Bitstream_Read(stream, 10); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

