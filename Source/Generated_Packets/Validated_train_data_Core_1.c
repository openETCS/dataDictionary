
#include "Validated_train_data_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Validated_train_data_Core_1_UpperBitsNotSet(const Validated_train_data_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->M_VOLTAGE_k,       4) ;
    if ((p->M_VOLTAGE_k != 0) && (p->NID_CTRACTION_k != 0))
    {
    status = status && UpperBitsNotSet64(p->NID_CTRACTION_k,   10);
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



            //@ assert M_VOLTAGE_k:       EqualBits(stream, pos,       pos + 4,   p->M_VOLTAGE_k);

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

int Validated_train_data_Core_1_Decoder(Bitstream* stream, Validated_train_data_Core_1* p)
{
    if (NormalBitstream(stream, VALIDATED_TRAIN_DATA_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires M_VOLTAGE_k:    stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_VOLTAGE_k;
	  ensures  M_VOLTAGE_k:    stream->bitpos == pos + 4;
	  ensures  M_VOLTAGE_k:    EqualBits(stream, pos + 0, pos + 4, p->M_VOLTAGE_k);
	  ensures  M_VOLTAGE_k:    UpperBitsNotSet(p->M_VOLTAGE_k, 4);
	*/
	{ p->M_VOLTAGE_k		= Bitstream_Read(stream, 4); }

        if ((p->M_VOLTAGE_k != 0) && (p->NID_CTRACTION_k != 0))
        {
	{ p->NID_CTRACTION_k		= Bitstream_Read(stream, 10); }
        }

        //@ assert M_VOLTAGE_k:       EqualBits(stream, pos,       pos + 4,   p->M_VOLTAGE_k);

        //@ assert M_VOLTAGE_k:       UpperBitsNotSet(p->M_VOLTAGE_k,       4);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

