
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_DefaultBaliseLoopOrRIUInformation
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


#include "DefaultBaliseLoopOrRIUInformation.h"
#include "Bit64.h"


int DefaultBaliseLoopOrRIUInformation_UpperBitsNotSet(const DefaultBaliseLoopOrRIUInformation* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int DefaultBaliseLoopOrRIUInformation_EncodeBit(const DefaultBaliseLoopOrRIUInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, DEFAULTBALISELOOPORRIUINFORMATION_BITSIZE))
    {
        if (DefaultBaliseLoopOrRIUInformation_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

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

int DefaultBaliseLoopOrRIUInformation_DecodeBit(DefaultBaliseLoopOrRIUInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, DEFAULTBALISELOOPORRIUINFORMATION_BITSIZE))
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

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
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

int DefaultBaliseLoopOrRIUInformation_EncodeInt(const DefaultBaliseLoopOrRIUInformation* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 254;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;

    data->endAddress = startAddress-1;

    return 1;
}

int DefaultBaliseLoopOrRIUInformation_DecodeInt(DefaultBaliseLoopOrRIUInformation* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 254)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

// number of cells in allocation memory
#define DefaultBaliseLoopOrRIUInformationMemoryMax		8

// end-of-freelist indicator
#define DefaultBaliseLoopOrRIUInformationMemoryNil		(-1)

// allocation memory
static DefaultBaliseLoopOrRIUInformation DefaultBaliseLoopOrRIUInformationMemory[DefaultBaliseLoopOrRIUInformationMemoryMax];

// lowest unused cell of allocation memory
static uint64_t DefaultBaliseLoopOrRIUInformationMemoryTop = 0;

// index of first element of freelist
static uint64_t DefaultBaliseLoopOrRIUInformationMemoryFreeList = DefaultBaliseLoopOrRIUInformationMemoryNil;

DefaultBaliseLoopOrRIUInformation* DefaultBaliseLoopOrRIUInformation_New(void)
{
    DefaultBaliseLoopOrRIUInformation* ptr;

    if (DefaultBaliseLoopOrRIUInformationMemoryFreeList != DefaultBaliseLoopOrRIUInformationMemoryNil)
    {
        // allocate from freelist
        ptr = &DefaultBaliseLoopOrRIUInformationMemory[DefaultBaliseLoopOrRIUInformationMemoryFreeList];
        DefaultBaliseLoopOrRIUInformationMemoryFreeList = DefaultBaliseLoopOrRIUInformationMemory[DefaultBaliseLoopOrRIUInformationMemoryFreeList].header.NID_PACKET;
    }
    else if (DefaultBaliseLoopOrRIUInformationMemoryTop < DefaultBaliseLoopOrRIUInformationMemoryMax)
    {
        // allocate from top
        ptr = &DefaultBaliseLoopOrRIUInformationMemory[DefaultBaliseLoopOrRIUInformationMemoryTop];
        DefaultBaliseLoopOrRIUInformationMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    DefaultBaliseLoopOrRIUInformation_Init(ptr);

    return ptr;
}


void DefaultBaliseLoopOrRIUInformation_Delete(DefaultBaliseLoopOrRIUInformation* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = DefaultBaliseLoopOrRIUInformationMemoryFreeList;
    DefaultBaliseLoopOrRIUInformationMemoryFreeList = ptr - DefaultBaliseLoopOrRIUInformationMemory;
}

#endif // FRAMAC_IGNORE

