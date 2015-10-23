
#include "NationalValues_1.h"
#include "Bit64.h"

NationalValues_1* NationalValues_1_New(void)
{
    void* raw = malloc(sizeof(NationalValues_1));
    NationalValues_1* ptr = (NationalValues_1*)raw;
    NationalValues_1_Init(ptr);
    return ptr;
}


void NationalValues_1_Delete(NationalValues_1* ptr)
{
    free(ptr);
}


int NationalValues_1_UpperBitsNotSet(const NationalValues_1* p)
{
    int status = 1;

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

int NationalValues_1_EncodeBit(const NationalValues_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, NATIONALVALUES_1_BITSIZE))
    {
        if (NationalValues_1_UpperBitsNotSet(p))
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

int NationalValues_1_DecodeBit(NationalValues_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, NATIONALVALUES_1_BITSIZE))
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

int NationalValues_1_EncodeInt(const NationalValues_1* p, PacketInfo* data, kcg_int* stream)
{
    return 0;
}

int NationalValues_1_DecodeInt(NationalValues_1* p, PacketInfo* data, kcg_int* stream)
{
    return 0;
}

