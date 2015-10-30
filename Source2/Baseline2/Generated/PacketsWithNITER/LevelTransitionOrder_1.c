
#include "LevelTransitionOrder_1.h"
#include "Bit64.h"

LevelTransitionOrder_1* LevelTransitionOrder_1_New(void)
{
    void* raw = malloc(sizeof(LevelTransitionOrder_1));
    LevelTransitionOrder_1* ptr = (LevelTransitionOrder_1*)raw;
    LevelTransitionOrder_1_Init(ptr);
    return ptr;
}


void LevelTransitionOrder_1_Delete(LevelTransitionOrder_1* ptr)
{
    free(ptr);
}


int LevelTransitionOrder_1_UpperBitsNotSet(const LevelTransitionOrder_1* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->M_LEVELTR,         3) ;
    if (p->M_LEVELTR == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_STM,           8) ;
    }
    status = status && UpperBitsNotSet64(p->L_ACKLEVELTR,      15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int LevelTransitionOrder_1_EncodeBit(const LevelTransitionOrder_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, LEVELTRANSITIONORDER_1_BITSIZE))
    {
        if (LevelTransitionOrder_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 3,  p->M_LEVELTR);
            if (p->M_LEVELTR == 1)
            {
                Bitstream_Write(stream, 8,  p->NID_STM);
            }

            Bitstream_Write(stream, 15, p->L_ACKLEVELTR);


            //@ assert M_LEVELTR:         EqualBits(stream, pos,       pos + 3,   p->M_LEVELTR);

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

int LevelTransitionOrder_1_DecodeBit(LevelTransitionOrder_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, LEVELTRANSITIONORDER_1_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires M_LEVELTR:      stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->M_LEVELTR;
          ensures  M_LEVELTR:      stream->bitpos == pos + 3;
          ensures  M_LEVELTR:      EqualBits(stream, pos + 0, pos + 3, p->M_LEVELTR);
          ensures  M_LEVELTR:      UpperBitsNotSet(p->M_LEVELTR, 3);
        */
        {
            p->M_LEVELTR        = Bitstream_Read(stream, 3);
        }

        if (p->M_LEVELTR == 1)
        {
            {
                p->NID_STM        = Bitstream_Read(stream, 8);
            }

        }

        {
            p->L_ACKLEVELTR        = Bitstream_Read(stream, 15);
        }

        //@ assert M_LEVELTR:         EqualBits(stream, pos,       pos + 3,   p->M_LEVELTR);

        //@ assert M_LEVELTR:         UpperBitsNotSet(p->M_LEVELTR,         3);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int LevelTransitionOrder_1_EncodeInt(const LevelTransitionOrder_1* p, kcg_int* startAddress, kcg_int* stream)
{
    stream[(*startAddress)++] = p->M_LEVELTR;
    stream[(*startAddress)++] = p->NID_STM;
    stream[(*startAddress)++] = p->L_ACKLEVELTR;

    return 1;
}

int LevelTransitionOrder_1_DecodeInt(LevelTransitionOrder_1* p, kcg_int* startAddress, const kcg_int* stream)
{
    p->M_LEVELTR = stream[(*startAddress)++];
    p->NID_STM = stream[(*startAddress)++];
    p->L_ACKLEVELTR = stream[(*startAddress)++];

    return 1;
}

