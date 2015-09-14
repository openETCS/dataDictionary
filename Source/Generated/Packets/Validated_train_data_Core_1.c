
#include "Validated_train_data_Core_1.h"
#include "Bit64.h"

int Validated_train_data_Core_1_UpperBitsNotSet(const Validated_train_data_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->M_VOLTAGE,         4) ;
    if ((p->M_VOLTAGE != 0) && (p->NID_CTRACTION != 0))
    {
        status = status && UpperBitsNotSet64(p->NID_CTRACTION,     10);
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

int Validated_train_data_Core_1_Encode_Bit(Bitstream* stream, const Validated_train_data_Core_1* p)
{
    if (Bitstream_Normal(stream, VALIDATED_TRAIN_DATA_CORE_1_CORE_BITSIZE))
    {
        if (Validated_train_data_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 4,  p->M_VOLTAGE);
            if ((p->M_VOLTAGE != 0) && (p->NID_CTRACTION != 0))
            {
                Bitstream_Write(stream, 10, p->NID_CTRACTION);
            }



            //@ assert M_VOLTAGE:         EqualBits(stream, pos,       pos + 4,   p->M_VOLTAGE);

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

int Validated_train_data_Core_1_Decode_Bit(Bitstream* stream, Validated_train_data_Core_1* p)
{
    if (Bitstream_Normal(stream, VALIDATED_TRAIN_DATA_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires M_VOLTAGE:      stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->M_VOLTAGE;
          ensures  M_VOLTAGE:      stream->bitpos == pos + 4;
          ensures  M_VOLTAGE:      EqualBits(stream, pos + 0, pos + 4, p->M_VOLTAGE);
          ensures  M_VOLTAGE:      UpperBitsNotSet(p->M_VOLTAGE, 4);
        */
        {
            p->M_VOLTAGE        = Bitstream_Read(stream, 4);
        }

        if ((p->M_VOLTAGE != 0) && (p->NID_CTRACTION != 0))
        {
            {
                p->NID_CTRACTION        = Bitstream_Read(stream, 10);
            }

        }

        //@ assert M_VOLTAGE:         EqualBits(stream, pos,       pos + 4,   p->M_VOLTAGE);

        //@ assert M_VOLTAGE:         UpperBitsNotSet(p->M_VOLTAGE,         4);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Validated_train_data_Core_1_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Validated_train_data_Core_1* p)
{

    return 0;
}

int Validated_train_data_Core_1_Decode_Int(const Packet_Info* data, const kcg_int* stream, Validated_train_data_Core_1* p)
{

    return 0;
}

