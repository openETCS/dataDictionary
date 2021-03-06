
#include "End_of_Information_Core.h"
#include "Bit64.h"

int End_of_Information_UpperBitsNotSet(const End_of_Information_Core* p)
{
    bool status = true;


    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int End_of_Information_Encode_Bit(Bitstream* stream, const End_of_Information_Core* p)
{
    if (Bitstream_Normal(stream, END_OF_INFORMATION_CORE_BITSIZE))
    {
        if (End_of_Information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;




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

int End_of_Information_Decode_Bit(Bitstream* stream, End_of_Information_Core* p)
{
    if (Bitstream_Normal(stream, END_OF_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;



        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int End_of_Information_Encode_Int(PacketInfo* data, kcg_int* stream, const End_of_Information_Core* p)
{

    return 1;
}

int End_of_Information_Decode_Int(PacketInfo* data, const kcg_int* stream, End_of_Information_Core* p)
{

    return 1;
}

