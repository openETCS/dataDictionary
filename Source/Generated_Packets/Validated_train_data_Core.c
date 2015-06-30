
#include "Validated_train_data_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Validated_train_data_UpperBitsNotSet(const Validated_train_data_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NC_CDTRAIN,        4) ;
    status = status && UpperBitsNotSet64(p->NC_TRAIN,          15);
    status = status && UpperBitsNotSet64(p->L_TRAIN,           12);
    status = status && UpperBitsNotSet64(p->V_MAXTRAIN,        7) ;
    status = status && UpperBitsNotSet64(p->M_LOADINGGAUGE,    8) ;
    status = status && UpperBitsNotSet64(p->M_AXLELOADCAT,     7) ;
    status = status && UpperBitsNotSet64(p->M_AIRTIGHT,        2) ;
    status = status && UpperBitsNotSet64(p->N_AXLE,            10);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Validated_train_data_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
    }
    status = status && UpperBitsNotSet64(p->N_ITER_2,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_2; ++i)
    {
        status = status && Validated_train_data_Core_2_UpperBitsNotSet(&(p->sub_2[i]));
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

int Validated_train_data_Decoder(Bitstream* stream, Validated_train_data_Core* p)
{
    if (NormalBitstream(stream, VALIDATED_TRAIN_DATA_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->NC_CDTRAIN		= Bitstream_Read(stream, 4); }

	{ p->NC_TRAIN		= Bitstream_Read(stream, 15); }

	{ p->L_TRAIN		= Bitstream_Read(stream, 12); }

	{ p->V_MAXTRAIN		= Bitstream_Read(stream, 7); }

	{ p->M_LOADINGGAUGE		= Bitstream_Read(stream, 8); }

	{ p->M_AXLELOADCAT		= Bitstream_Read(stream, 7); }

	{ p->M_AIRTIGHT		= Bitstream_Read(stream, 2); }

	{ p->N_AXLE		= Bitstream_Read(stream, 10); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Validated_train_data_Core_1_Decoder(stream, &(p->sub_1[i]));
        }
	{ p->N_ITER_2		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_2; ++i)
        {
            Validated_train_data_Core_2_Decoder(stream, &(p->sub_2[i]));
        }


	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

