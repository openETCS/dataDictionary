
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_TrackAheadFreeUpToLevel23TransitionLocation
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

#include "TrackAheadFreeUpToLevel23TransitionLocation.h"
#include "Bit64.h"

// number of cells in allocation memory
#define TrackAheadFreeUpToLevel23TransitionLocationMemoryMax		8

// end-of-freelist indicator
#define TrackAheadFreeUpToLevel23TransitionLocationMemoryNil		(-1)

// allocation memory
static TrackAheadFreeUpToLevel23TransitionLocation TrackAheadFreeUpToLevel23TransitionLocationMemory[TrackAheadFreeUpToLevel23TransitionLocationMemoryMax];

// lowest unused cell of allocation memory
static uint64_t TrackAheadFreeUpToLevel23TransitionLocationMemoryTop = 0;

// index of first element of freelist
static uint64_t TrackAheadFreeUpToLevel23TransitionLocationMemoryFreeList = TrackAheadFreeUpToLevel23TransitionLocationMemoryNil;

TrackAheadFreeUpToLevel23TransitionLocation* TrackAheadFreeUpToLevel23TransitionLocation_New(void)
{
    TrackAheadFreeUpToLevel23TransitionLocation* ptr;

    if (TrackAheadFreeUpToLevel23TransitionLocationMemoryFreeList != TrackAheadFreeUpToLevel23TransitionLocationMemoryNil)
    {
        // allocate from freelist
        ptr = &TrackAheadFreeUpToLevel23TransitionLocationMemory[TrackAheadFreeUpToLevel23TransitionLocationMemoryFreeList];
        TrackAheadFreeUpToLevel23TransitionLocationMemoryFreeList = TrackAheadFreeUpToLevel23TransitionLocationMemory[TrackAheadFreeUpToLevel23TransitionLocationMemoryFreeList].header.NID_PACKET;
    }
    else if (TrackAheadFreeUpToLevel23TransitionLocationMemoryTop < TrackAheadFreeUpToLevel23TransitionLocationMemoryMax)
    {
        // allocate from top
        ptr = &TrackAheadFreeUpToLevel23TransitionLocationMemory[TrackAheadFreeUpToLevel23TransitionLocationMemoryTop];
        TrackAheadFreeUpToLevel23TransitionLocationMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    TrackAheadFreeUpToLevel23TransitionLocation_Init(ptr);

    return ptr;
}


void TrackAheadFreeUpToLevel23TransitionLocation_Delete(TrackAheadFreeUpToLevel23TransitionLocation* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = TrackAheadFreeUpToLevel23TransitionLocationMemoryFreeList;
    TrackAheadFreeUpToLevel23TransitionLocationMemoryFreeList = ptr - TrackAheadFreeUpToLevel23TransitionLocationMemory;
}


int TrackAheadFreeUpToLevel23TransitionLocation_UpperBitsNotSet(const TrackAheadFreeUpToLevel23TransitionLocation* p)
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

int TrackAheadFreeUpToLevel23TransitionLocation_EncodeBit(const TrackAheadFreeUpToLevel23TransitionLocation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, TRACKAHEADFREEUPTOLEVEL23TRANSITIONLOCATION_BITSIZE))
    {
        if (TrackAheadFreeUpToLevel23TransitionLocation_UpperBitsNotSet(p))
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

int TrackAheadFreeUpToLevel23TransitionLocation_DecodeBit(TrackAheadFreeUpToLevel23TransitionLocation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, TRACKAHEADFREEUPTOLEVEL23TRANSITIONLOCATION_BITSIZE))
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

int TrackAheadFreeUpToLevel23TransitionLocation_EncodeInt(const TrackAheadFreeUpToLevel23TransitionLocation* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 90;
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

int TrackAheadFreeUpToLevel23TransitionLocation_DecodeInt(TrackAheadFreeUpToLevel23TransitionLocation* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 90)
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

