
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_DangerForShuntingInformation
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


#include "DangerForShuntingInformation.h"
#include "Bit64.h"


int DangerForShuntingInformation_UpperBitsNotSet(const DangerForShuntingInformation* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_ASPECT,          1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int DangerForShuntingInformation_EncodeBit(const DangerForShuntingInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, DANGERFORSHUNTINGINFORMATION_BITSIZE))
    {
        if (DangerForShuntingInformation_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_ASPECT);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_ASPECT:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_ASPECT);

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

int DangerForShuntingInformation_DecodeBit(DangerForShuntingInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, DANGERFORSHUNTINGINFORMATION_BITSIZE))
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
          requires Q_ASPECT:       stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->Q_ASPECT;
          ensures  Q_ASPECT:       stream->bitpos == pos + 16;
          ensures  Q_ASPECT:       EqualBits(stream, pos + 15, pos + 16, p->Q_ASPECT);
          ensures  Q_ASPECT:       UpperBitsNotSet(p->Q_ASPECT, 1);
        */
        {
            p->Q_ASPECT        = Bitstream_Read(stream, 1);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_ASPECT:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_ASPECT);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_ASPECT:          UpperBitsNotSet(p->Q_ASPECT,          1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

#ifndef FRAMAC_IGNORE

int DangerForShuntingInformation_EncodeInt(const DangerForShuntingInformation* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 132;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_ASPECT;

    data->endAddress = startAddress-1;

    return 1;
}

int DangerForShuntingInformation_DecodeInt(DangerForShuntingInformation* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 132)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_ASPECT = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

// number of cells in allocation memory
#define DangerForShuntingInformationMemoryMax		8

// end-of-freelist indicator
#define DangerForShuntingInformationMemoryNil		(-1)

// allocation memory
static DangerForShuntingInformation DangerForShuntingInformationMemory[DangerForShuntingInformationMemoryMax];

// lowest unused cell of allocation memory
static uint64_t DangerForShuntingInformationMemoryTop = 0;

// index of first element of freelist
static uint64_t DangerForShuntingInformationMemoryFreeList = DangerForShuntingInformationMemoryNil;

DangerForShuntingInformation* DangerForShuntingInformation_New(void)
{
    DangerForShuntingInformation* ptr;

    if (DangerForShuntingInformationMemoryFreeList != DangerForShuntingInformationMemoryNil)
    {
        // allocate from freelist
        ptr = &DangerForShuntingInformationMemory[DangerForShuntingInformationMemoryFreeList];
        DangerForShuntingInformationMemoryFreeList = DangerForShuntingInformationMemory[DangerForShuntingInformationMemoryFreeList].header.NID_PACKET;
    }
    else if (DangerForShuntingInformationMemoryTop < DangerForShuntingInformationMemoryMax)
    {
        // allocate from top
        ptr = &DangerForShuntingInformationMemory[DangerForShuntingInformationMemoryTop];
        DangerForShuntingInformationMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    DangerForShuntingInformation_Init(ptr);

    return ptr;
}


void DangerForShuntingInformation_Delete(DangerForShuntingInformation* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = DangerForShuntingInformationMemoryFreeList;
    DangerForShuntingInformationMemoryFreeList = ptr - DangerForShuntingInformationMemory;
}

#endif // FRAMAC_IGNORE

