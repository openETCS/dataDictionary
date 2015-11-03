
#include "TemporarySpeedRestriction.h"
#include "Bit64.h"

// number of cells in allocation memory
#define TemporarySpeedRestrictionMemoryMax		32

// end-of-freelist indicator
#define TemporarySpeedRestrictionMemoryNil		(-1)

// allocation memory
static TemporarySpeedRestriction TemporarySpeedRestrictionMemory[TemporarySpeedRestrictionMemoryMax];

// lowest unused cell of allocation memory
static uint64_t TemporarySpeedRestrictionMemoryTop = 0;

// index of first element of freelist
static uint64_t TemporarySpeedRestrictionMemoryFreeList = TemporarySpeedRestrictionMemoryNil;

TemporarySpeedRestriction* TemporarySpeedRestriction_New(void)
{
    TemporarySpeedRestriction* ptr;

    if (TemporarySpeedRestrictionMemoryFreeList != TemporarySpeedRestrictionMemoryNil)
    {
        // allocate from freelist
        ptr = &TemporarySpeedRestrictionMemory[TemporarySpeedRestrictionMemoryFreeList];
        TemporarySpeedRestrictionMemoryFreeList = TemporarySpeedRestrictionMemory[TemporarySpeedRestrictionMemoryFreeList].header.NID_PACKET;
    }
    else if (TemporarySpeedRestrictionMemoryTop < TemporarySpeedRestrictionMemoryMax)
    {
        // allocate from top
        ptr = &TemporarySpeedRestrictionMemory[TemporarySpeedRestrictionMemoryTop];
        TemporarySpeedRestrictionMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    TemporarySpeedRestriction_Init(ptr);

    return ptr;
}


void TemporarySpeedRestriction_Delete(TemporarySpeedRestriction* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = TemporarySpeedRestrictionMemoryFreeList;
    TemporarySpeedRestrictionMemoryFreeList = ptr - TemporarySpeedRestrictionMemory;
}


int TemporarySpeedRestriction_UpperBitsNotSet(const TemporarySpeedRestriction* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->NID_TSR,           8) ;
    status = status && UpperBitsNotSet64(p->D_TSR,             15);
    status = status && UpperBitsNotSet64(p->L_TSR,             15);
    status = status && UpperBitsNotSet64(p->Q_FRONT,           1) ;
    status = status && UpperBitsNotSet64(p->V_TSR,             7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int TemporarySpeedRestriction_EncodeBit(const TemporarySpeedRestriction* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, TEMPORARYSPEEDRESTRICTION_BITSIZE))
    {
        if (TemporarySpeedRestriction_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 8,  p->NID_TSR);
            Bitstream_Write(stream, 15, p->D_TSR);
            Bitstream_Write(stream, 15, p->L_TSR);
            Bitstream_Write(stream, 1,  p->Q_FRONT);
            Bitstream_Write(stream, 7,  p->V_TSR);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert NID_TSR:           EqualBits(stream, pos + 17,  pos + 25,  p->NID_TSR);
            //@ assert D_TSR:             EqualBits(stream, pos + 25,  pos + 40,  p->D_TSR);
            //@ assert L_TSR:             EqualBits(stream, pos + 40,  pos + 55,  p->L_TSR);
            //@ assert Q_FRONT:           EqualBits(stream, pos + 55,  pos + 56,  p->Q_FRONT);
            //@ assert V_TSR:             EqualBits(stream, pos + 56,  pos + 63,  p->V_TSR);

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

int TemporarySpeedRestriction_DecodeBit(TemporarySpeedRestriction* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, TEMPORARYSPEEDRESTRICTION_BITSIZE))
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
          requires NID_TSR:        stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->NID_TSR;
          ensures  NID_TSR:        stream->bitpos == pos + 25;
          ensures  NID_TSR:        EqualBits(stream, pos + 17, pos + 25, p->NID_TSR);
          ensures  NID_TSR:        UpperBitsNotSet(p->NID_TSR, 8);
        */
        {
            p->NID_TSR        = Bitstream_Read(stream, 8);
        }

        /*@
          requires D_TSR:          stream->bitpos == pos + 25;
          assigns                  stream->bitpos;
          assigns                  p->D_TSR;
          ensures  D_TSR:          stream->bitpos == pos + 40;
          ensures  D_TSR:          EqualBits(stream, pos + 25, pos + 40, p->D_TSR);
          ensures  D_TSR:          UpperBitsNotSet(p->D_TSR, 15);
        */
        {
            p->D_TSR        = Bitstream_Read(stream, 15);
        }

        /*@
          requires L_TSR:          stream->bitpos == pos + 40;
          assigns                  stream->bitpos;
          assigns                  p->L_TSR;
          ensures  L_TSR:          stream->bitpos == pos + 55;
          ensures  L_TSR:          EqualBits(stream, pos + 40, pos + 55, p->L_TSR);
          ensures  L_TSR:          UpperBitsNotSet(p->L_TSR, 15);
        */
        {
            p->L_TSR        = Bitstream_Read(stream, 15);
        }

        /*@
          requires Q_FRONT:        stream->bitpos == pos + 55;
          assigns                  stream->bitpos;
          assigns                  p->Q_FRONT;
          ensures  Q_FRONT:        stream->bitpos == pos + 56;
          ensures  Q_FRONT:        EqualBits(stream, pos + 55, pos + 56, p->Q_FRONT);
          ensures  Q_FRONT:        UpperBitsNotSet(p->Q_FRONT, 1);
        */
        {
            p->Q_FRONT        = Bitstream_Read(stream, 1);
        }

        /*@
          requires V_TSR:          stream->bitpos == pos + 56;
          assigns                  stream->bitpos;
          assigns                  p->V_TSR;
          ensures  V_TSR:          stream->bitpos == pos + 63;
          ensures  V_TSR:          EqualBits(stream, pos + 56, pos + 63, p->V_TSR);
          ensures  V_TSR:          UpperBitsNotSet(p->V_TSR, 7);
        */
        {
            p->V_TSR        = Bitstream_Read(stream, 7);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert NID_TSR:           EqualBits(stream, pos + 17,  pos + 25,  p->NID_TSR);
        //@ assert D_TSR:             EqualBits(stream, pos + 25,  pos + 40,  p->D_TSR);
        //@ assert L_TSR:             EqualBits(stream, pos + 40,  pos + 55,  p->L_TSR);
        //@ assert Q_FRONT:           EqualBits(stream, pos + 55,  pos + 56,  p->Q_FRONT);
        //@ assert V_TSR:             EqualBits(stream, pos + 56,  pos + 63,  p->V_TSR);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert NID_TSR:           UpperBitsNotSet(p->NID_TSR,           8);
        //@ assert D_TSR:             UpperBitsNotSet(p->D_TSR,             15);
        //@ assert L_TSR:             UpperBitsNotSet(p->L_TSR,             15);
        //@ assert Q_FRONT:           UpperBitsNotSet(p->Q_FRONT,           1);
        //@ assert V_TSR:             UpperBitsNotSet(p->V_TSR,             7);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int TemporarySpeedRestriction_EncodeInt(const TemporarySpeedRestriction* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 65;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->NID_TSR;
    stream[startAddress++] = p->D_TSR;
    stream[startAddress++] = p->L_TSR;
    stream[startAddress++] = p->Q_FRONT;
    stream[startAddress++] = p->V_TSR;

    data->endAddress = startAddress-1;

    return 1;
}

int TemporarySpeedRestriction_DecodeInt(TemporarySpeedRestriction* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 65)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->NID_TSR = stream[startAddress++];
    p->D_TSR = stream[startAddress++];
    p->L_TSR = stream[startAddress++];
    p->Q_FRONT = stream[startAddress++];
    p->V_TSR = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

