
#include "ValidatedTrainData_2.h"
#include "Bit64.h"

ValidatedTrainData_2* ValidatedTrainData_2_New(void)
{
    void* raw = malloc(sizeof(ValidatedTrainData_2));
    ValidatedTrainData_2* ptr = (ValidatedTrainData_2*)raw;
    ValidatedTrainData_2_Init(ptr);
    return ptr;
}


void ValidatedTrainData_2_Delete(ValidatedTrainData_2* ptr)
{
    free(ptr);
}


int ValidatedTrainData_2_UpperBitsNotSet(const ValidatedTrainData_2* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->NID_STM,           8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ValidatedTrainData_2_EncodeBit(const ValidatedTrainData_2* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, VALIDATEDTRAINDATA_2_BITSIZE))
    {
        if (ValidatedTrainData_2_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 8,  p->NID_STM);


            //@ assert NID_STM:           EqualBits(stream, pos,       pos + 8,   p->NID_STM);

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

int ValidatedTrainData_2_DecodeBit(ValidatedTrainData_2* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, VALIDATEDTRAINDATA_2_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires NID_STM:        stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->NID_STM;
          ensures  NID_STM:        stream->bitpos == pos + 8;
          ensures  NID_STM:        EqualBits(stream, pos + 0, pos + 8, p->NID_STM);
          ensures  NID_STM:        UpperBitsNotSet(p->NID_STM, 8);
        */
        {
            p->NID_STM        = Bitstream_Read(stream, 8);
        }

        //@ assert NID_STM:           EqualBits(stream, pos,       pos + 8,   p->NID_STM);

        //@ assert NID_STM:           UpperBitsNotSet(p->NID_STM,           8);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int ValidatedTrainData_2_EncodeInt(const ValidatedTrainData_2* p, kcg_int* startAddress, kcg_int* stream)
{
    stream[(*startAddress)++] = p->NID_STM;

    return 1;
}

int ValidatedTrainData_2_DecodeInt(ValidatedTrainData_2* p, kcg_int* startAddress, const kcg_int* stream)
{
    p->NID_STM = stream[(*startAddress)++];

    return 1;
}

