
#include "Validated_train_data_Core_1_Decoder.h"
#include "Bitstream_Read.h"

int Validated_train_data_Core_1_Decoder(Bitstream* stream, Validated_train_data_Core_1* p)
{
    if (NormalBitstream(stream, VALIDATED_TRAIN_DATA_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->M_VOLTAGE_k		= Bitstream_Read(stream, 4); }

        if ((p->M_VOLTAGE_k != 0) && (p->NID_CTRACTION_k != 0))
        {
	{ p->NID_CTRACTION_k		= Bitstream_Read(stream, 10); }
        }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

