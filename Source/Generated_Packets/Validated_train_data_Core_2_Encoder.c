
#include "Validated_train_data_Core_2_Encoder.h"
#include "Validated_train_data_Core_2_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Validated_train_data_Core_2_Encoder(Bitstream* stream, const Validated_train_data_Core_2* p)
{
    if (NormalBitstream(stream, VALIDATED_TRAIN_DATA_CORE_2_CORE_BITSIZE))
    {
        if (Validated_train_data_Core_2_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 8,  p->NID_NTC_n);



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

