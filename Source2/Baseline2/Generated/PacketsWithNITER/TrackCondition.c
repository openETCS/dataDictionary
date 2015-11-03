
#include "TrackCondition.h"
#include "Bit64.h"

// number of cells in allocation memory
#define TrackConditionMemoryMax		32

// end-of-freelist indicator
#define TrackConditionMemoryNil		(-1)

// allocation memory
static TrackCondition TrackConditionMemory[TrackConditionMemoryMax];

// lowest unused cell of allocation memory
static uint64_t TrackConditionMemoryTop = 0;

// index of first element of freelist
static uint64_t TrackConditionMemoryFreeList = TrackConditionMemoryNil;

TrackCondition* TrackCondition_New(void)
{
    TrackCondition* ptr;

    if (TrackConditionMemoryFreeList != TrackConditionMemoryNil)
    {
        // allocate from freelist
        ptr = &TrackConditionMemory[TrackConditionMemoryFreeList];
        TrackConditionMemoryFreeList = TrackConditionMemory[TrackConditionMemoryFreeList].header.NID_PACKET;
    }
    else if (TrackConditionMemoryTop < TrackConditionMemoryMax)
    {
        // allocate from top
        ptr = &TrackConditionMemory[TrackConditionMemoryTop];
        TrackConditionMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    TrackCondition_Init(ptr);

    return ptr;
}


void TrackCondition_Delete(TrackCondition* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = TrackConditionMemoryFreeList;
    TrackConditionMemoryFreeList = ptr - TrackConditionMemory;
}


int TrackCondition_UpperBitsNotSet(const TrackCondition* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->Q_TRACKINIT,       1) ;
    if (p->Q_TRACKINIT == 1)
    {
        status = status && UpperBitsNotSet64(p->D_TRACKINIT,       15);
    }
    if (p->Q_TRACKINIT == 0)
    {
        status = status && UpperBitsNotSet64(p->D_TRACKCOND,       15);
        status = status && UpperBitsNotSet64(p->L_TRACKCOND,       15);
        status = status && UpperBitsNotSet64(p->M_TRACKCOND,       4) ;
    }
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && TrackCondition_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int TrackCondition_EncodeBit(const TrackCondition* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, TRACKCONDITION_BITSIZE))
    {
        if (TrackCondition_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 1,  p->Q_TRACKINIT);
            if (p->Q_TRACKINIT == 1)
            {
                Bitstream_Write(stream, 15, p->D_TRACKINIT);
            }

            if (p->Q_TRACKINIT == 0)
            {
                Bitstream_Write(stream, 15, p->D_TRACKCOND);
                Bitstream_Write(stream, 15, p->L_TRACKCOND);
                Bitstream_Write(stream, 4,  p->M_TRACKCOND);
            }

            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                TrackCondition_1_EncodeBit(&(p->sub_1[i]), stream);
            }


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert Q_TRACKINIT:       EqualBits(stream, pos + 17,  pos + 18,  p->Q_TRACKINIT);

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

int TrackCondition_DecodeBit(TrackCondition* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, TRACKCONDITION_BITSIZE))
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
          requires Q_SCALE:        stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->Q_SCALE;
          ensures  Q_SCALE:        stream->bitpos == pos + 17;
          ensures  Q_SCALE:        EqualBits(stream, pos + 15, pos + 17, p->Q_SCALE);
          ensures  Q_SCALE:        UpperBitsNotSet(p->Q_SCALE, 2);
        */
        {
            p->Q_SCALE        = Bitstream_Read(stream, 2);
        }

        /*@
          requires Q_TRACKINIT:    stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->Q_TRACKINIT;
          ensures  Q_TRACKINIT:    stream->bitpos == pos + 18;
          ensures  Q_TRACKINIT:    EqualBits(stream, pos + 17, pos + 18, p->Q_TRACKINIT);
          ensures  Q_TRACKINIT:    UpperBitsNotSet(p->Q_TRACKINIT, 1);
        */
        {
            p->Q_TRACKINIT        = Bitstream_Read(stream, 1);
        }

        if (p->Q_TRACKINIT == 1)
        {
            {
                p->D_TRACKINIT        = Bitstream_Read(stream, 15);
            }

        }

        if (p->Q_TRACKINIT == 0)
        {
            {
                p->D_TRACKCOND        = Bitstream_Read(stream, 15);
            }

            {
                p->L_TRACKCOND        = Bitstream_Read(stream, 15);
            }

            {
                p->M_TRACKCOND        = Bitstream_Read(stream, 4);
            }

        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            TrackCondition_1_DecodeBit(&(p->sub_1[i]), stream);
        }
        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert Q_TRACKINIT:       EqualBits(stream, pos + 17,  pos + 18,  p->Q_TRACKINIT);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert Q_TRACKINIT:       UpperBitsNotSet(p->Q_TRACKINIT,       1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int TrackCondition_EncodeInt(const TrackCondition* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 68;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->Q_TRACKINIT;
    stream[startAddress++] = p->D_TRACKINIT;
    stream[startAddress++] = p->D_TRACKCOND;
    stream[startAddress++] = p->L_TRACKCOND;
    stream[startAddress++] = p->M_TRACKCOND;
    stream[startAddress++] = p->N_ITER_1;

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        TrackCondition_1_EncodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    data->endAddress = startAddress-1;

    return 1;
}

int TrackCondition_DecodeInt(TrackCondition* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 68)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->Q_TRACKINIT = stream[startAddress++];
    p->D_TRACKINIT = stream[startAddress++];
    p->D_TRACKCOND = stream[startAddress++];
    p->L_TRACKCOND = stream[startAddress++];
    p->M_TRACKCOND = stream[startAddress++];
    p->N_ITER_1 = stream[startAddress++];

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        TrackCondition_1_DecodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

