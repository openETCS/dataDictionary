
#include "OnboardTelephoneNumbers.h"
#include "Bit64.h"

OnboardTelephoneNumbers* OnboardTelephoneNumbers_New(void)
{
    void* raw = malloc(sizeof(OnboardTelephoneNumbers));
    OnboardTelephoneNumbers* ptr = (OnboardTelephoneNumbers*)raw;
    OnboardTelephoneNumbers_Init(ptr);
    return ptr;
}


void OnboardTelephoneNumbers_Delete(OnboardTelephoneNumbers* ptr)
{
    free(ptr);
}


int OnboardTelephoneNumbers_UpperBitsNotSet(const OnboardTelephoneNumbers* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && OnboardTelephoneNumbers_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int OnboardTelephoneNumbers_EncodeBit(const OnboardTelephoneNumbers* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, ONBOARDTELEPHONENUMBERS_BITSIZE))
    {
        if (OnboardTelephoneNumbers_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                OnboardTelephoneNumbers_1_EncodeBit(&(p->sub_1[i]), stream);
            }


            //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);

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

int OnboardTelephoneNumbers_DecodeBit(OnboardTelephoneNumbers* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, ONBOARDTELEPHONENUMBERS_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires L_PACKET:       stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->L_PACKET;
          ensures  L_PACKET:       stream->bitpos == pos + 13;
          ensures  L_PACKET:       EqualBits(stream, pos + 0, pos + 13, p->L_PACKET);
          ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
        */
        {
            p->L_PACKET        = Bitstream_Read(stream, 13);
        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            OnboardTelephoneNumbers_1_DecodeBit(&(p->sub_1[i]), stream);
        }
        //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);

        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

/*
int OnboardTelephoneNumbers_EncodeInt(const OnboardTelephoneNumbers* p, PacketInfo* data, kcg_int* stream)
{

}

int OnboardTelephoneNumbers_DecodeInt(OnboardTelephoneNumbers* p, PacketInfo* data, kcg_int* stream)
{

}
*/

