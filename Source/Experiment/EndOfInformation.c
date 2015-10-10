
#include "EndOfInformation.h"
#include "Bit64.h"

int EndOfInformation_UpperBitsNotSet(const EndOfInformation* p)
{
    int status = 1;


    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int EndOfInformation_EncodeBit(Bitstream* stream, const EndOfInformation* p)
{
    if (Bitstream_Normal(stream, ENDOFINFORMATION_BITSIZE))
    {
        if (EndOfInformation_UpperBitsNotSet(p))
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

int EndOfInformation_DecodeBit(Bitstream* stream, EndOfInformation* p)
{
    if (Bitstream_Normal(stream, ENDOFINFORMATION_BITSIZE))
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
/*
int EndOfInformation_EncodeInt(PacketInfo* data, kcg_int* stream, const EndOfInformation* p)
{

    return 1;
}

int EndOfInformation_DecodeInt(PacketInfo* data, const kcg_int* stream, EndOfInformation* p)
{

    return 1;
}
*/
