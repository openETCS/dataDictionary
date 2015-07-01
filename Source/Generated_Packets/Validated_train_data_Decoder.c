
#include "Validated_train_data_Decoder.h"
#include "Bitstream_Read.h"
#include "Validated_train_data_Core_1_Decoder.h"
#include "Validated_train_data_Core_2_Decoder.h"

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

