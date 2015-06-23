
#include "Validated_train_data_Encoder.h"
#include "Validated_train_data_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Validated_train_data_Core_1_Encoder.h"
#include "Validated_train_data_Core_2_Encoder.h"

int Validated_train_data_Encoder(Bitstream* stream, const Validated_train_data_Core* p)
{
    if (NormalBitstream(stream, VALIDATED_TRAIN_DATA_CORE_BITSIZE))
    {
        if (Validated_train_data_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 4,  p->NC_CDTRAIN);
            Bitstream_Write(stream, 15, p->NC_TRAIN);
            Bitstream_Write(stream, 12, p->L_TRAIN);
            Bitstream_Write(stream, 7,  p->V_MAXTRAIN);
            Bitstream_Write(stream, 8,  p->M_LOADINGGAUGE);
            Bitstream_Write(stream, 7,  p->M_AXLELOADCAT);
            Bitstream_Write(stream, 2,  p->M_AIRTIGHT);
            Bitstream_Write(stream, 10, p->N_AXLE);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Validated_train_data_Core_1_Encoder(stream, &(p->sub_1[i]));
            }
            Bitstream_Write(stream, 5,  p->N_ITER_2);
            for (uint32_t i = 0; i < p->N_ITER_2; ++i)
            {
                Validated_train_data_Core_2_Encoder(stream, &(p->sub_2[i]));
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

