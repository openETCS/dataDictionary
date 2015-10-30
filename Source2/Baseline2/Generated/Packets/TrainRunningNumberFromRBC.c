
#include "TrainRunningNumberFromRBC.h"
#include "Bit64.h"

// number of cells in allocation memory
#define TrainRunningNumberFromRBCMemoryMax		32

// end-of-freelist indicator
#define TrainRunningNumberFromRBCMemoryNil		(-1)

// allocation memory
static TrainRunningNumberFromRBC TrainRunningNumberFromRBCMemory[TrainRunningNumberFromRBCMemoryMax];

// lowest unused cell of allocation memory
static uint64_t TrainRunningNumberFromRBCMemoryTop = 0;

// index of first element of freelist
static uint64_t TrainRunningNumberFromRBCMemoryFreeList = TrainRunningNumberFromRBCMemoryNil;

TrainRunningNumberFromRBC* TrainRunningNumberFromRBC_New(void)
{
    TrainRunningNumberFromRBC* ptr;

    if (TrainRunningNumberFromRBCMemoryFreeList != TrainRunningNumberFromRBCMemoryNil)
    {
        // allocate from freelist
        ptr = &TrainRunningNumberFromRBCMemory[TrainRunningNumberFromRBCMemoryFreeList];
        TrainRunningNumberFromRBCMemoryFreeList = TrainRunningNumberFromRBCMemory[TrainRunningNumberFromRBCMemoryFreeList].header.NID_PACKET;
    }
    else if (TrainRunningNumberFromRBCMemoryTop < TrainRunningNumberFromRBCMemoryMax)
    {
        // allocate from top
        ptr = &TrainRunningNumberFromRBCMemory[TrainRunningNumberFromRBCMemoryTop];
        TrainRunningNumberFromRBCMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    TrainRunningNumberFromRBC_Init(ptr);

    return ptr;
}


void TrainRunningNumberFromRBC_Delete(TrainRunningNumberFromRBC* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = TrainRunningNumberFromRBCMemoryFreeList;
    TrainRunningNumberFromRBCMemoryFreeList = ptr - TrainRunningNumberFromRBCMemory;
}


int TrainRunningNumberFromRBC_UpperBitsNotSet(const TrainRunningNumberFromRBC* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_OPERATIONAL,   32);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int TrainRunningNumberFromRBC_EncodeBit(const TrainRunningNumberFromRBC* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, TRAINRUNNINGNUMBERFROMRBC_BITSIZE))
    {
        if (TrainRunningNumberFromRBC_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 32, p->NID_OPERATIONAL);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert NID_OPERATIONAL:   EqualBits(stream, pos + 15,  pos + 47,  p->NID_OPERATIONAL);

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

int TrainRunningNumberFromRBC_DecodeBit(TrainRunningNumberFromRBC* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, TRAINRUNNINGNUMBERFROMRBC_BITSIZE))
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
          requires NID_OPERATIONAL: stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->NID_OPERATIONAL;
          ensures  NID_OPERATIONAL: stream->bitpos == pos + 47;
          ensures  NID_OPERATIONAL: EqualBits(stream, pos + 15, pos + 47, p->NID_OPERATIONAL);
          ensures  NID_OPERATIONAL: UpperBitsNotSet(p->NID_OPERATIONAL, 32);
        */
        {
            p->NID_OPERATIONAL        = Bitstream_Read(stream, 32);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert NID_OPERATIONAL:   EqualBits(stream, pos + 15,  pos + 47,  p->NID_OPERATIONAL);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert NID_OPERATIONAL:   UpperBitsNotSet(p->NID_OPERATIONAL,   32);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int TrainRunningNumberFromRBC_EncodeInt(const TrainRunningNumberFromRBC* p, PacketInfo* data, kcg_int* stream)
{
    data->nid_packet = 140;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->NID_OPERATIONAL;

    data->endAddress = startAddress-1;

    return 1;
}

int TrainRunningNumberFromRBC_DecodeInt(TrainRunningNumberFromRBC* p, const PacketInfo* data, const kcg_int* stream)
{
    if(data->nid_packet != 140)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->NID_OPERATIONAL = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

