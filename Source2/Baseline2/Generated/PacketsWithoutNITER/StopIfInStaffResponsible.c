
#include "StopIfInStaffResponsible.h"
#include "Bit64.h"

// number of cells in allocation memory
#define StopIfInStaffResponsibleMemoryMax		32

// end-of-freelist indicator
#define StopIfInStaffResponsibleMemoryNil		(-1)

// allocation memory
static StopIfInStaffResponsible StopIfInStaffResponsibleMemory[StopIfInStaffResponsibleMemoryMax];

// lowest unused cell of allocation memory
static uint64_t StopIfInStaffResponsibleMemoryTop = 0;

// index of first element of freelist
static uint64_t StopIfInStaffResponsibleMemoryFreeList = StopIfInStaffResponsibleMemoryNil;

StopIfInStaffResponsible* StopIfInStaffResponsible_New(void)
{
    StopIfInStaffResponsible* ptr;

    if (StopIfInStaffResponsibleMemoryFreeList != StopIfInStaffResponsibleMemoryNil)
    {
        // allocate from freelist
        ptr = &StopIfInStaffResponsibleMemory[StopIfInStaffResponsibleMemoryFreeList];
        StopIfInStaffResponsibleMemoryFreeList = StopIfInStaffResponsibleMemory[StopIfInStaffResponsibleMemoryFreeList].header.NID_PACKET;
    }
    else if (StopIfInStaffResponsibleMemoryTop < StopIfInStaffResponsibleMemoryMax)
    {
        // allocate from top
        ptr = &StopIfInStaffResponsibleMemory[StopIfInStaffResponsibleMemoryTop];
        StopIfInStaffResponsibleMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    StopIfInStaffResponsible_Init(ptr);

    return ptr;
}


void StopIfInStaffResponsible_Delete(StopIfInStaffResponsible* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = StopIfInStaffResponsibleMemoryFreeList;
    StopIfInStaffResponsibleMemoryFreeList = ptr - StopIfInStaffResponsibleMemory;
}


int StopIfInStaffResponsible_UpperBitsNotSet(const StopIfInStaffResponsible* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SRSTOP,          1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int StopIfInStaffResponsible_EncodeBit(const StopIfInStaffResponsible* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, STOPIFINSTAFFRESPONSIBLE_BITSIZE))
    {
        if (StopIfInStaffResponsible_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_SRSTOP);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SRSTOP:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_SRSTOP);

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

int StopIfInStaffResponsible_DecodeBit(StopIfInStaffResponsible* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, STOPIFINSTAFFRESPONSIBLE_BITSIZE))
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
          requires Q_SRSTOP:       stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->Q_SRSTOP;
          ensures  Q_SRSTOP:       stream->bitpos == pos + 16;
          ensures  Q_SRSTOP:       EqualBits(stream, pos + 15, pos + 16, p->Q_SRSTOP);
          ensures  Q_SRSTOP:       UpperBitsNotSet(p->Q_SRSTOP, 1);
        */
        {
            p->Q_SRSTOP        = Bitstream_Read(stream, 1);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SRSTOP:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_SRSTOP);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SRSTOP:          UpperBitsNotSet(p->Q_SRSTOP,          1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int StopIfInStaffResponsible_EncodeInt(const StopIfInStaffResponsible* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 137;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SRSTOP;

    data->endAddress = startAddress-1;

    return 1;
}

int StopIfInStaffResponsible_DecodeInt(StopIfInStaffResponsible* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 137)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SRSTOP = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

