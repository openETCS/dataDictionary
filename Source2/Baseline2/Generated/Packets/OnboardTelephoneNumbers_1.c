
#include "OnboardTelephoneNumbers_1.h"
#include "Bit64.h"

OnboardTelephoneNumbers_1* OnboardTelephoneNumbers_1_New(void)
{
    void* raw = malloc(sizeof(OnboardTelephoneNumbers_1));
    OnboardTelephoneNumbers_1* ptr = (OnboardTelephoneNumbers_1*)raw;
    OnboardTelephoneNumbers_1_Init(ptr);
    return ptr;
}


void OnboardTelephoneNumbers_1_Delete(OnboardTelephoneNumbers_1* ptr)
{
    free(ptr);
}


int OnboardTelephoneNumbers_1_UpperBitsNotSet(const OnboardTelephoneNumbers_1* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->NID_RADIO,         64);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int OnboardTelephoneNumbers_1_EncodeBit(const OnboardTelephoneNumbers_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, ONBOARDTELEPHONENUMBERS_1_BITSIZE))
    {
        if (OnboardTelephoneNumbers_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 64, p->NID_RADIO);


            //@ assert NID_RADIO:         EqualBits(stream, pos,       pos + 64,  p->NID_RADIO);

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

int OnboardTelephoneNumbers_1_DecodeBit(OnboardTelephoneNumbers_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, ONBOARDTELEPHONENUMBERS_1_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires NID_RADIO:      stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->NID_RADIO;
          ensures  NID_RADIO:      stream->bitpos == pos + 64;
          ensures  NID_RADIO:      EqualBits(stream, pos + 0, pos + 64, p->NID_RADIO);
          ensures  NID_RADIO:      UpperBitsNotSet(p->NID_RADIO, 64);
        */
        {
            p->NID_RADIO        = Bitstream_Read(stream, 64);
        }

        //@ assert NID_RADIO:         EqualBits(stream, pos,       pos + 64,  p->NID_RADIO);

        //@ assert NID_RADIO:         UpperBitsNotSet(p->NID_RADIO,         64);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int OnboardTelephoneNumbers_1_EncodeInt(const OnboardTelephoneNumbers_1* p, PacketInfo* data, kcg_int* stream)
{
    return 0;
}

int OnboardTelephoneNumbers_1_DecodeInt(OnboardTelephoneNumbers_1* p, PacketInfo* data, kcg_int* stream)
{
    return 0;
}

