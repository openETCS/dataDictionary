
#include "Train_running_number_from_RBC_Decoder.h"
#include "Bitstream_Read.h"

int Train_running_number_from_RBC_Decoder(Bitstream* stream, Train_running_number_from_RBC_Core* p)
{
    if (NormalBitstream(stream, TRAIN_RUNNING_NUMBER_FROM_RBC_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->NID_OPERATIONAL		= Bitstream_Read(stream, 32); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

