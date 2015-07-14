
#include "Validated_train_data_Core_2.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Validated_train_data_Core_2_UpperBitsNotSet(const Validated_train_data_Core_2* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->NID_NTC_n,         8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Validated_train_data_Core_2_Encoder(Bitstream* stream, const Validated_train_data_Core_2* p)
{
    if (NormalBitstream(stream, VALIDATED_TRAIN_DATA_CORE_2_CORE_BITSIZE))
    {
        if (Validated_train_data_Core_2_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 8,  p->NID_NTC_n);


            //@ assert NID_NTC_n:         EqualBits(stream, pos,       pos + 8,   p->NID_NTC_n);

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

int Validated_train_data_Core_2_Decoder(Bitstream* stream, Validated_train_data_Core_2* p)
{
    if (NormalBitstream(stream, VALIDATED_TRAIN_DATA_CORE_2_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires NID_NTC_n:      stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_NTC_n;
	  ensures  NID_NTC_n:      stream->bitpos == pos + 8;
	  ensures  NID_NTC_n:      EqualBits(stream, pos + 0, pos + 8, p->NID_NTC_n);
	  ensures  NID_NTC_n:      UpperBitsNotSet(p->NID_NTC_n, 8);
	*/
	{ p->NID_NTC_n		= Bitstream_Read(stream, 8); }

        //@ assert NID_NTC_n:         EqualBits(stream, pos,       pos + 8,   p->NID_NTC_n);

        //@ assert NID_NTC_n:         UpperBitsNotSet(p->NID_NTC_n,         8);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

