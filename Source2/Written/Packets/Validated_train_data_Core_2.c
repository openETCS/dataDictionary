
#include "Validated_train_data_Core_2.h"
#include "Bit64.h"

int Validated_train_data_Core_2_UpperBitsNotSet(const Validated_train_data_Core_2* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->NID_NTC,           8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Validated_train_data_Core_2_Encode_Bit(Bitstream* stream, const Validated_train_data_Core_2* p)
{
    if (Bitstream_Normal(stream, VALIDATED_TRAIN_DATA_CORE_2_CORE_BITSIZE))
    {
        if (Validated_train_data_Core_2_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 8,  p->NID_NTC);


            //@ assert NID_NTC:           EqualBits(stream, pos,       pos + 8,   p->NID_NTC);

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

int Validated_train_data_Core_2_Decode_Bit(Bitstream* stream, Validated_train_data_Core_2* p)
{
    if (Bitstream_Normal(stream, VALIDATED_TRAIN_DATA_CORE_2_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires NID_NTC:        stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->NID_NTC;
          ensures  NID_NTC:        stream->bitpos == pos + 8;
          ensures  NID_NTC:        EqualBits(stream, pos + 0, pos + 8, p->NID_NTC);
          ensures  NID_NTC:        UpperBitsNotSet(p->NID_NTC, 8);
        */
        {
            p->NID_NTC        = Bitstream_Read(stream, 8);
        }

        //@ assert NID_NTC:           EqualBits(stream, pos,       pos + 8,   p->NID_NTC);

        //@ assert NID_NTC:           UpperBitsNotSet(p->NID_NTC,           8);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Validated_train_data_Core_2_Encode_Int(PacketInfo* data, kcg_int* stream, const Validated_train_data_Core_2* p)
{
    stream[data->startAddress++] = p->NID_NTC;

    return 1;
}

int Validated_train_data_Core_2_Decode_Int(PacketInfo* data, const kcg_int* stream, Validated_train_data_Core_2* p)
{
    p->NID_NTC = stream[data->startAddress++];

    return 1;
}

