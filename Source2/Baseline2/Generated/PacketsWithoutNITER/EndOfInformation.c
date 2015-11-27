
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / BothWays_EndOfInformation
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


#include "EndOfInformation.h"
#include "Bit64.h"


int EndOfInformation_UpperBitsNotSet(const EndOfInformation* p)
{
    int status = 1;


    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int EndOfInformation_EncodeBit(const EndOfInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, ENDOFINFORMATION_BITSIZE))
    {
        if (EndOfInformation_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;




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

int EndOfInformation_DecodeBit(EndOfInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, ENDOFINFORMATION_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;



        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

#ifndef FRAMAC_IGNORE

int EndOfInformation_EncodeInt(const EndOfInformation* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 255;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;


    data->endAddress = startAddress-1;

    return 1;
}

int EndOfInformation_DecodeInt(EndOfInformation* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 255)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];


    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

// number of cells in allocation memory
#define EndOfInformationMemoryMax		8

// end-of-freelist indicator
#define EndOfInformationMemoryNil		(-1)

// allocation memory
static EndOfInformation EndOfInformationMemory[EndOfInformationMemoryMax];

// lowest unused cell of allocation memory
static uint64_t EndOfInformationMemoryTop = 0;

// index of first element of freelist
static uint64_t EndOfInformationMemoryFreeList = EndOfInformationMemoryNil;

EndOfInformation* EndOfInformation_New(void)
{
    EndOfInformation* ptr;

    if (EndOfInformationMemoryFreeList != EndOfInformationMemoryNil)
    {
        // allocate from freelist
        ptr = &EndOfInformationMemory[EndOfInformationMemoryFreeList];
        EndOfInformationMemoryFreeList = EndOfInformationMemory[EndOfInformationMemoryFreeList].header.NID_PACKET;
    }
    else if (EndOfInformationMemoryTop < EndOfInformationMemoryMax)
    {
        // allocate from top
        ptr = &EndOfInformationMemory[EndOfInformationMemoryTop];
        EndOfInformationMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    EndOfInformation_Init(ptr);

    return ptr;
}


void EndOfInformation_Delete(EndOfInformation* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = EndOfInformationMemoryFreeList;
    EndOfInformationMemoryFreeList = ptr - EndOfInformationMemory;
}

#endif // FRAMAC_IGNORE

