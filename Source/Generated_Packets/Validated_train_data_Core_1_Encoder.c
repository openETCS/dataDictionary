
#include "Validated_train_data_Core_1_Encoder.h"
#include "Validated_train_data_Core_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Validated_train_data_Core_1_Encoder(Bitstream* stream, const Validated_train_data_Core_1* p)
{
    if (NormalBitstream(stream, VALIDATED_TRAIN_DATA_CORE_1_CORE_BITSIZE))
    {
        if (Validated_train_data_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 4,  p->M_VOLTAGE_k);
            if ((p->M_VOLTAGE_k != 0) && (p->NID_CTRACTION_k != 0))
            {
            Bitstream_Write(stream, 10, p->NID_CTRACTION_k);
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

