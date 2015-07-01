
#include "Train_running_number_Decoder.h"
#include "Bitstream_Read.h"

int Train_running_number_Decoder(Bitstream* stream, Train_running_number_Core* p)
{
    if (NormalBitstream(stream, TRAIN_RUNNING_NUMBER_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

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

