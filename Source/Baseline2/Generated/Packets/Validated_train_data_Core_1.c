
#include "Validated_train_data_Core_1.h"
#include "Bit64.h"

int Validated_train_data_Core_1_UpperBitsNotSet(const Validated_train_data_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->M_TRACTION,        8) ;

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

            Bitstream_Write(stream, 8,  p->M_TRACTION);


            //@ assert M_TRACTION:        EqualBits(stream, pos,       pos + 8,   p->M_TRACTION);

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
          requires M_TRACTION:     stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->M_TRACTION;
          ensures  M_TRACTION:     stream->bitpos == pos + 8;
          ensures  M_TRACTION:     EqualBits(stream, pos + 0, pos + 8, p->M_TRACTION);
          ensures  M_TRACTION:     UpperBitsNotSet(p->M_TRACTION, 8);
        */
        {
            p->M_TRACTION        = Bitstream_Read(stream, 8);
        }

        //@ assert M_TRACTION:        EqualBits(stream, pos,       pos + 8,   p->M_TRACTION);

        //@ assert M_TRACTION:        UpperBitsNotSet(p->M_TRACTION,        8);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Validated_train_data_Core_1_Encode_Int(PacketInfo* data, kcg_int* stream, const Validated_train_data_Core_1* p)
{
    return 0;
}

int Validated_train_data_Core_1_Decode_Int(PacketInfo* data, const kcg_int* stream, Validated_train_data_Core_1* p)
{
    return 0;
}

