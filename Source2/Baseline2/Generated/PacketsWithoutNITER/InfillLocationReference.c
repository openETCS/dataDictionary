
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_InfillLocationReference
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

#include "InfillLocationReference.h"
#include "Bit64.h"

// number of cells in allocation memory
#define InfillLocationReferenceMemoryMax		8

// end-of-freelist indicator
#define InfillLocationReferenceMemoryNil		(-1)

// allocation memory
static InfillLocationReference InfillLocationReferenceMemory[InfillLocationReferenceMemoryMax];

// lowest unused cell of allocation memory
static uint64_t InfillLocationReferenceMemoryTop = 0;

// index of first element of freelist
static uint64_t InfillLocationReferenceMemoryFreeList = InfillLocationReferenceMemoryNil;

InfillLocationReference* InfillLocationReference_New(void)
{
    InfillLocationReference* ptr;

    if (InfillLocationReferenceMemoryFreeList != InfillLocationReferenceMemoryNil)
    {
        // allocate from freelist
        ptr = &InfillLocationReferenceMemory[InfillLocationReferenceMemoryFreeList];
        InfillLocationReferenceMemoryFreeList = InfillLocationReferenceMemory[InfillLocationReferenceMemoryFreeList].header.NID_PACKET;
    }
    else if (InfillLocationReferenceMemoryTop < InfillLocationReferenceMemoryMax)
    {
        // allocate from top
        ptr = &InfillLocationReferenceMemory[InfillLocationReferenceMemoryTop];
        InfillLocationReferenceMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    InfillLocationReference_Init(ptr);

    return ptr;
}


void InfillLocationReference_Delete(InfillLocationReference* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = InfillLocationReferenceMemoryFreeList;
    InfillLocationReferenceMemoryFreeList = ptr - InfillLocationReferenceMemory;
}


int InfillLocationReference_UpperBitsNotSet(const InfillLocationReference* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY,      1) ;
    if (p->Q_NEWCOUNTRY == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_C,             10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG,            14);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int InfillLocationReference_EncodeBit(const InfillLocationReference* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, INFILLLOCATIONREFERENCE_BITSIZE))
    {
        if (InfillLocationReference_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY);
            if (p->Q_NEWCOUNTRY == 1)
            {
                Bitstream_Write(stream, 10, p->NID_C);
            }

            Bitstream_Write(stream, 14, p->NID_BG);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos + 15,  pos + 16,  p->Q_NEWCOUNTRY);

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

int InfillLocationReference_DecodeBit(InfillLocationReference* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, INFILLLOCATIONREFERENCE_BITSIZE))
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
          requires Q_NEWCOUNTRY:   stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->Q_NEWCOUNTRY;
          ensures  Q_NEWCOUNTRY:   stream->bitpos == pos + 16;
          ensures  Q_NEWCOUNTRY:   EqualBits(stream, pos + 15, pos + 16, p->Q_NEWCOUNTRY);
          ensures  Q_NEWCOUNTRY:   UpperBitsNotSet(p->Q_NEWCOUNTRY, 1);
        */
        {
            p->Q_NEWCOUNTRY        = Bitstream_Read(stream, 1);
        }

        if (p->Q_NEWCOUNTRY == 1)
        {
            {
                p->NID_C        = Bitstream_Read(stream, 10);
            }

        }

        {
            p->NID_BG        = Bitstream_Read(stream, 14);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos + 15,  pos + 16,  p->Q_NEWCOUNTRY);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_NEWCOUNTRY:      UpperBitsNotSet(p->Q_NEWCOUNTRY,      1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int InfillLocationReference_EncodeInt(const InfillLocationReference* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 136;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_NEWCOUNTRY;
    stream[startAddress++] = p->NID_C;
    stream[startAddress++] = p->NID_BG;

    data->endAddress = startAddress-1;

    return 1;
}

int InfillLocationReference_DecodeInt(InfillLocationReference* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 136)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_NEWCOUNTRY = stream[startAddress++];
    p->NID_C = stream[startAddress++];
    p->NID_BG = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

