
#include "Validated_train_data_Core_2_Decoder.h"
#include "Bitstream_Read.h"

int Validated_train_data_Core_2_Decoder(Bitstream* stream, Validated_train_data_Core_2* p)
{
    if (NormalBitstream(stream, VALIDATED_TRAIN_DATA_CORE_2_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->NID_NTC_n		= Bitstream_Read(stream, 8); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

