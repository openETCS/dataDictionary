
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrainToTrack_OnboardTelephoneNumbers
- Description: UNISIG SUBSET-026-7, ISSUE : 3.3.0, 3.5 ERTMS/ETCS language) 
- Copyright (c) 

- Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl )
- Gist URL: none
- Cryptography: No
- Author(s): Fraunhofer FOKUS

Disclaimer:

The use of this software is limited to NON-vital applications. 
It has NOT been developed for vital operation purposes and MUST NOT be used for applications 
which may cause harm to people, physical accidents or financial loss. 

THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OTHER KIND OF USE.       
============================================================================= */

#include "OnboardTelephoneNumbers_1.h"
#include "Bit64.h"

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

int OnboardTelephoneNumbers_1_EncodeInt(const OnboardTelephoneNumbers_1* p, kcg_int* startAddress, kcg_int* stream)
{
    stream[(*startAddress)++] = p->NID_RADIO;

    return 1;
}

int OnboardTelephoneNumbers_1_DecodeInt(OnboardTelephoneNumbers_1* p, kcg_int* startAddress, const kcg_int* stream)
{
    p->NID_RADIO = stream[(*startAddress)++];

    return 1;
}

