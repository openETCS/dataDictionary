
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


#include "OnboardTelephoneNumbers.h"
#include "Bit64.h"


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

#ifndef FRAMAC_IGNORE

int OnboardTelephoneNumbers_EncodeInt(const OnboardTelephoneNumbers* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 3;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->N_ITER_1;

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        OnboardTelephoneNumbers_1_EncodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    data->endAddress = startAddress-1;

    return 1;
}

int OnboardTelephoneNumbers_DecodeInt(OnboardTelephoneNumbers* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 3)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->L_PACKET = stream[startAddress++];
    p->N_ITER_1 = stream[startAddress++];

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        OnboardTelephoneNumbers_1_DecodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

// number of cells in allocation memory
#define OnboardTelephoneNumbersMemoryMax		8

// end-of-freelist indicator
#define OnboardTelephoneNumbersMemoryNil		(-1)

// allocation memory
static OnboardTelephoneNumbers OnboardTelephoneNumbersMemory[OnboardTelephoneNumbersMemoryMax];

// lowest unused cell of allocation memory
static uint64_t OnboardTelephoneNumbersMemoryTop = 0;

// index of first element of freelist
static uint64_t OnboardTelephoneNumbersMemoryFreeList = OnboardTelephoneNumbersMemoryNil;

OnboardTelephoneNumbers* OnboardTelephoneNumbers_New(void)
{
    OnboardTelephoneNumbers* ptr;

    if (OnboardTelephoneNumbersMemoryFreeList != OnboardTelephoneNumbersMemoryNil)
    {
        // allocate from freelist
        ptr = &OnboardTelephoneNumbersMemory[OnboardTelephoneNumbersMemoryFreeList];
        OnboardTelephoneNumbersMemoryFreeList = OnboardTelephoneNumbersMemory[OnboardTelephoneNumbersMemoryFreeList].header.NID_PACKET;
    }
    else if (OnboardTelephoneNumbersMemoryTop < OnboardTelephoneNumbersMemoryMax)
    {
        // allocate from top
        ptr = &OnboardTelephoneNumbersMemory[OnboardTelephoneNumbersMemoryTop];
        OnboardTelephoneNumbersMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    OnboardTelephoneNumbers_Init(ptr);

    return ptr;
}


void OnboardTelephoneNumbers_Delete(OnboardTelephoneNumbers* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = OnboardTelephoneNumbersMemoryFreeList;
    OnboardTelephoneNumbersMemoryFreeList = ptr - OnboardTelephoneNumbersMemory;
}

#endif // FRAMAC_IGNORE

