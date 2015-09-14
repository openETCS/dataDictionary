
#include "National_Values_Core_1.h"
#include "Bit64.h"

int National_Values_Core_1_UpperBitsNotSet(const National_Values_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->NID_C,             10);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int National_Values_Core_1_Encode_Bit(Bitstream* stream, const National_Values_Core_1* p)
{
    if (Bitstream_Normal(stream, NATIONAL_VALUES_CORE_1_CORE_BITSIZE))
    {
        if (National_Values_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 10, p->NID_C);


            //@ assert NID_C:             EqualBits(stream, pos,       pos + 10,  p->NID_C);

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

int National_Values_Core_1_Decode_Bit(Bitstream* stream, National_Values_Core_1* p)
{
    if (Bitstream_Normal(stream, NATIONAL_VALUES_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires NID_C:          stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->NID_C;
          ensures  NID_C:          stream->bitpos == pos + 10;
          ensures  NID_C:          EqualBits(stream, pos + 0, pos + 10, p->NID_C);
          ensures  NID_C:          UpperBitsNotSet(p->NID_C, 10);
        */
        {
            p->NID_C        = Bitstream_Read(stream, 10);
        }

        //@ assert NID_C:             EqualBits(stream, pos,       pos + 10,  p->NID_C);

        //@ assert NID_C:             UpperBitsNotSet(p->NID_C,             10);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int National_Values_Core_1_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const National_Values_Core_1* p)
{

    return 0;
}

int National_Values_Core_1_Decode_Int(const Packet_Info* data, const kcg_int* stream, National_Values_Core_1* p)
{

    return 0;
}

