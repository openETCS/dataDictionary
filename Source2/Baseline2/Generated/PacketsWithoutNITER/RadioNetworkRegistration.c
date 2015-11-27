
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_RadioNetworkRegistration
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


#include "RadioNetworkRegistration.h"
#include "Bit64.h"


int RadioNetworkRegistration_UpperBitsNotSet(const RadioNetworkRegistration* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_MN,            24);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int RadioNetworkRegistration_EncodeBit(const RadioNetworkRegistration* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, RADIONETWORKREGISTRATION_BITSIZE))
    {
        if (RadioNetworkRegistration_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 24, p->NID_MN);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert NID_MN:            EqualBits(stream, pos + 15,  pos + 39,  p->NID_MN);

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

int RadioNetworkRegistration_DecodeBit(RadioNetworkRegistration* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, RADIONETWORKREGISTRATION_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires Q_DIR:          stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->Q_DIR;
          ensures  Q_DIR:          stream->bitpos == pos + 2;
          ensures  Q_DIR:          EqualBits(stream, pos + 0, pos + 2, p->Q_DIR);
          ensures  Q_DIR:          UpperBitsNotSet(p->Q_DIR, 2);
        */
        {
            p->Q_DIR        = Bitstream_Read(stream, 2);
        }

        /*@
          requires L_PACKET:       stream->bitpos == pos + 2;
          assigns                  stream->bitpos;
          assigns                  p->L_PACKET;
          ensures  L_PACKET:       stream->bitpos == pos + 15;
          ensures  L_PACKET:       EqualBits(stream, pos + 2, pos + 15, p->L_PACKET);
          ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
        */
        {
            p->L_PACKET        = Bitstream_Read(stream, 13);
        }

        /*@
          requires NID_MN:         stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->NID_MN;
          ensures  NID_MN:         stream->bitpos == pos + 39;
          ensures  NID_MN:         EqualBits(stream, pos + 15, pos + 39, p->NID_MN);
          ensures  NID_MN:         UpperBitsNotSet(p->NID_MN, 24);
        */
        {
            p->NID_MN        = Bitstream_Read(stream, 24);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert NID_MN:            EqualBits(stream, pos + 15,  pos + 39,  p->NID_MN);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert NID_MN:            UpperBitsNotSet(p->NID_MN,            24);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

#ifndef FRAMAC_IGNORE

int RadioNetworkRegistration_EncodeInt(const RadioNetworkRegistration* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 45;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->NID_MN;

    data->endAddress = startAddress-1;

    return 1;
}

int RadioNetworkRegistration_DecodeInt(RadioNetworkRegistration* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 45)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->NID_MN = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

// number of cells in allocation memory
#define RadioNetworkRegistrationMemoryMax		8

// end-of-freelist indicator
#define RadioNetworkRegistrationMemoryNil		(-1)

// allocation memory
static RadioNetworkRegistration RadioNetworkRegistrationMemory[RadioNetworkRegistrationMemoryMax];

// lowest unused cell of allocation memory
static uint64_t RadioNetworkRegistrationMemoryTop = 0;

// index of first element of freelist
static uint64_t RadioNetworkRegistrationMemoryFreeList = RadioNetworkRegistrationMemoryNil;

RadioNetworkRegistration* RadioNetworkRegistration_New(void)
{
    RadioNetworkRegistration* ptr;

    if (RadioNetworkRegistrationMemoryFreeList != RadioNetworkRegistrationMemoryNil)
    {
        // allocate from freelist
        ptr = &RadioNetworkRegistrationMemory[RadioNetworkRegistrationMemoryFreeList];
        RadioNetworkRegistrationMemoryFreeList = RadioNetworkRegistrationMemory[RadioNetworkRegistrationMemoryFreeList].header.NID_PACKET;
    }
    else if (RadioNetworkRegistrationMemoryTop < RadioNetworkRegistrationMemoryMax)
    {
        // allocate from top
        ptr = &RadioNetworkRegistrationMemory[RadioNetworkRegistrationMemoryTop];
        RadioNetworkRegistrationMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    RadioNetworkRegistration_Init(ptr);

    return ptr;
}


void RadioNetworkRegistration_Delete(RadioNetworkRegistration* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = RadioNetworkRegistrationMemoryFreeList;
    RadioNetworkRegistrationMemoryFreeList = ptr - RadioNetworkRegistrationMemory;
}

#endif // FRAMAC_IGNORE

