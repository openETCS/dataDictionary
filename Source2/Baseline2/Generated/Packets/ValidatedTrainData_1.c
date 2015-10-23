
#include "ValidatedTrainData_1.h"
#include "Bit64.h"

ValidatedTrainData_1* ValidatedTrainData_1_New(void)
{
    void* raw = malloc(sizeof(ValidatedTrainData_1));
    ValidatedTrainData_1* ptr = (ValidatedTrainData_1*)raw;
    ValidatedTrainData_1_Init(ptr);
    return ptr;
}


void ValidatedTrainData_1_Delete(ValidatedTrainData_1* ptr)
{
    free(ptr);
}


int ValidatedTrainData_1_UpperBitsNotSet(const ValidatedTrainData_1* p)
{
    int status = 1;

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

int ValidatedTrainData_1_EncodeBit(const ValidatedTrainData_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, VALIDATEDTRAINDATA_1_BITSIZE))
    {
        if (ValidatedTrainData_1_UpperBitsNotSet(p))
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

int ValidatedTrainData_1_DecodeBit(ValidatedTrainData_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, VALIDATEDTRAINDATA_1_BITSIZE))
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

int ValidatedTrainData_1_EncodeInt(const ValidatedTrainData_1* p, kcg_int* startAddress, kcg_int* stream)
{
    stream[(*startAddress)++] = p->M_TRACTION;

    return 1;
}

int ValidatedTrainData_1_DecodeInt(ValidatedTrainData_1* p, kcg_int* startAddress, const kcg_int* stream)
{
    p->M_TRACTION = stream[(*startAddress)++];

    return 1;
}

