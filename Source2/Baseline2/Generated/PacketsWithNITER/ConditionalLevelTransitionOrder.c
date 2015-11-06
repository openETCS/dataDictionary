
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_ConditionalLevelTransitionOrder
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

#include "ConditionalLevelTransitionOrder.h"
#include "Bit64.h"

// number of cells in allocation memory
#define ConditionalLevelTransitionOrderMemoryMax		8

// end-of-freelist indicator
#define ConditionalLevelTransitionOrderMemoryNil		(-1)

// allocation memory
static ConditionalLevelTransitionOrder ConditionalLevelTransitionOrderMemory[ConditionalLevelTransitionOrderMemoryMax];

// lowest unused cell of allocation memory
static uint64_t ConditionalLevelTransitionOrderMemoryTop = 0;

// index of first element of freelist
static uint64_t ConditionalLevelTransitionOrderMemoryFreeList = ConditionalLevelTransitionOrderMemoryNil;

ConditionalLevelTransitionOrder* ConditionalLevelTransitionOrder_New(void)
{
    ConditionalLevelTransitionOrder* ptr;

    if (ConditionalLevelTransitionOrderMemoryFreeList != ConditionalLevelTransitionOrderMemoryNil)
    {
        // allocate from freelist
        ptr = &ConditionalLevelTransitionOrderMemory[ConditionalLevelTransitionOrderMemoryFreeList];
        ConditionalLevelTransitionOrderMemoryFreeList = ConditionalLevelTransitionOrderMemory[ConditionalLevelTransitionOrderMemoryFreeList].header.NID_PACKET;
    }
    else if (ConditionalLevelTransitionOrderMemoryTop < ConditionalLevelTransitionOrderMemoryMax)
    {
        // allocate from top
        ptr = &ConditionalLevelTransitionOrderMemory[ConditionalLevelTransitionOrderMemoryTop];
        ConditionalLevelTransitionOrderMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    ConditionalLevelTransitionOrder_Init(ptr);

    return ptr;
}


void ConditionalLevelTransitionOrder_Delete(ConditionalLevelTransitionOrder* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = ConditionalLevelTransitionOrderMemoryFreeList;
    ConditionalLevelTransitionOrderMemoryFreeList = ptr - ConditionalLevelTransitionOrderMemory;
}


int ConditionalLevelTransitionOrder_UpperBitsNotSet(const ConditionalLevelTransitionOrder* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->M_LEVELTR,         3) ;
    if (p->M_LEVELTR == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_STM,           8) ;
    }
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && ConditionalLevelTransitionOrder_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int ConditionalLevelTransitionOrder_EncodeBit(const ConditionalLevelTransitionOrder* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, CONDITIONALLEVELTRANSITIONORDER_BITSIZE))
    {
        if (ConditionalLevelTransitionOrder_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 3,  p->M_LEVELTR);
            if (p->M_LEVELTR == 1)
            {
                Bitstream_Write(stream, 8,  p->NID_STM);
            }

            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                ConditionalLevelTransitionOrder_1_EncodeBit(&(p->sub_1[i]), stream);
            }


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert M_LEVELTR:         EqualBits(stream, pos + 15,  pos + 18,  p->M_LEVELTR);

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

int ConditionalLevelTransitionOrder_DecodeBit(ConditionalLevelTransitionOrder* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, CONDITIONALLEVELTRANSITIONORDER_BITSIZE))
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
          requires M_LEVELTR:      stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->M_LEVELTR;
          ensures  M_LEVELTR:      stream->bitpos == pos + 18;
          ensures  M_LEVELTR:      EqualBits(stream, pos + 15, pos + 18, p->M_LEVELTR);
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
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            ConditionalLevelTransitionOrder_1_DecodeBit(&(p->sub_1[i]), stream);
        }
        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert M_LEVELTR:         EqualBits(stream, pos + 15,  pos + 18,  p->M_LEVELTR);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert M_LEVELTR:         UpperBitsNotSet(p->M_LEVELTR,         3);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int ConditionalLevelTransitionOrder_EncodeInt(const ConditionalLevelTransitionOrder* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 46;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->N_ITER_1 + 1;
    stream[startAddress++] = p->M_LEVELTR;
    stream[startAddress++] = p->NID_STM;

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        ConditionalLevelTransitionOrder_1_EncodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    data->endAddress = startAddress-1;

    return 1;
}

int ConditionalLevelTransitionOrder_DecodeInt(ConditionalLevelTransitionOrder* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 46)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->N_ITER_1 = stream[startAddress++] - 1;
    p->M_LEVELTR = stream[startAddress++];
    p->NID_STM = stream[startAddress++];

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        ConditionalLevelTransitionOrder_1_DecodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

