
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_ListOfBalisesForSHArea
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


#include "ListOfBalisesForSHArea.h"
#include "Bit64.h"


int ListOfBalisesForSHArea_UpperBitsNotSet(const ListOfBalisesForSHArea* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && ListOfBalisesForSHArea_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int ListOfBalisesForSHArea_EncodeBit(const ListOfBalisesForSHArea* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, LISTOFBALISESFORSHAREA_BITSIZE))
    {
        if (ListOfBalisesForSHArea_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                ListOfBalisesForSHArea_1_EncodeBit(&(p->sub_1[i]), stream);
            }


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

int ListOfBalisesForSHArea_DecodeBit(ListOfBalisesForSHArea* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, LISTOFBALISESFORSHAREA_BITSIZE))
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

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            ListOfBalisesForSHArea_1_DecodeBit(&(p->sub_1[i]), stream);
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

int ListOfBalisesForSHArea_EncodeInt(const ListOfBalisesForSHArea* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 49;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->N_ITER_1;

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        ListOfBalisesForSHArea_1_EncodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    data->endAddress = startAddress-1;

    return 1;
}

int ListOfBalisesForSHArea_DecodeInt(ListOfBalisesForSHArea* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 49)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->N_ITER_1 = stream[startAddress++];

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        ListOfBalisesForSHArea_1_DecodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

// number of cells in allocation memory
#define ListOfBalisesForSHAreaMemoryMax		8

// end-of-freelist indicator
#define ListOfBalisesForSHAreaMemoryNil		(-1)

// allocation memory
static ListOfBalisesForSHArea ListOfBalisesForSHAreaMemory[ListOfBalisesForSHAreaMemoryMax];

// lowest unused cell of allocation memory
static uint64_t ListOfBalisesForSHAreaMemoryTop = 0;

// index of first element of freelist
static uint64_t ListOfBalisesForSHAreaMemoryFreeList = ListOfBalisesForSHAreaMemoryNil;

ListOfBalisesForSHArea* ListOfBalisesForSHArea_New(void)
{
    ListOfBalisesForSHArea* ptr;

    if (ListOfBalisesForSHAreaMemoryFreeList != ListOfBalisesForSHAreaMemoryNil)
    {
        // allocate from freelist
        ptr = &ListOfBalisesForSHAreaMemory[ListOfBalisesForSHAreaMemoryFreeList];
        ListOfBalisesForSHAreaMemoryFreeList = ListOfBalisesForSHAreaMemory[ListOfBalisesForSHAreaMemoryFreeList].header.NID_PACKET;
    }
    else if (ListOfBalisesForSHAreaMemoryTop < ListOfBalisesForSHAreaMemoryMax)
    {
        // allocate from top
        ptr = &ListOfBalisesForSHAreaMemory[ListOfBalisesForSHAreaMemoryTop];
        ListOfBalisesForSHAreaMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    ListOfBalisesForSHArea_Init(ptr);

    return ptr;
}


void ListOfBalisesForSHArea_Delete(ListOfBalisesForSHArea* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = ListOfBalisesForSHAreaMemoryFreeList;
    ListOfBalisesForSHAreaMemoryFreeList = ptr - ListOfBalisesForSHAreaMemory;
}

#endif // FRAMAC_IGNORE

