
#include "Train_running_number_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Train_running_number_UpperBitsNotSet(const Train_running_number_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_OPERATIONAL,   32);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Train_running_number_Encoder(Bitstream* stream, const Train_running_number_Core* p)
{
    if (NormalBitstream(stream, TRAIN_RUNNING_NUMBER_CORE_BITSIZE))
    {
        if (Train_running_number_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 32, p->NID_OPERATIONAL);



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

