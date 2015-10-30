
#include "TemporarySpeedRestrictionRevocation.h"
#include "Bit64.h"

// number of cells in allocation memory
#define TemporarySpeedRestrictionRevocationMemoryMax		32

// end-of-freelist indicator
#define TemporarySpeedRestrictionRevocationMemoryNil		(-1)

// allocation memory
static TemporarySpeedRestrictionRevocation TemporarySpeedRestrictionRevocationMemory[TemporarySpeedRestrictionRevocationMemoryMax];

// lowest unused cell of allocation memory
static uint64_t TemporarySpeedRestrictionRevocationMemoryTop = 0;

// index of first element of freelist
static uint64_t TemporarySpeedRestrictionRevocationMemoryFreeList = TemporarySpeedRestrictionRevocationMemoryNil;

TemporarySpeedRestrictionRevocation* TemporarySpeedRestrictionRevocation_New(void)
{
    TemporarySpeedRestrictionRevocation* ptr;

    if (TemporarySpeedRestrictionRevocationMemoryFreeList != TemporarySpeedRestrictionRevocationMemoryNil)
    {
        // allocate from freelist
        ptr = &TemporarySpeedRestrictionRevocationMemory[TemporarySpeedRestrictionRevocationMemoryFreeList];
        TemporarySpeedRestrictionRevocationMemoryFreeList = TemporarySpeedRestrictionRevocationMemory[TemporarySpeedRestrictionRevocationMemoryFreeList].header.NID_PACKET;
    }
    else if (TemporarySpeedRestrictionRevocationMemoryTop < TemporarySpeedRestrictionRevocationMemoryMax)
    {
        // allocate from top
        ptr = &TemporarySpeedRestrictionRevocationMemory[TemporarySpeedRestrictionRevocationMemoryTop];
        TemporarySpeedRestrictionRevocationMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    TemporarySpeedRestrictionRevocation_Init(ptr);

    return ptr;
}


void TemporarySpeedRestrictionRevocation_Delete(TemporarySpeedRestrictionRevocation* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = TemporarySpeedRestrictionRevocationMemoryFreeList;
    TemporarySpeedRestrictionRevocationMemoryFreeList = ptr - TemporarySpeedRestrictionRevocationMemory;
}


int TemporarySpeedRestrictionRevocation_UpperBitsNotSet(const TemporarySpeedRestrictionRevocation* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_TSR,           8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int TemporarySpeedRestrictionRevocation_EncodeBit(const TemporarySpeedRestrictionRevocation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, TEMPORARYSPEEDRESTRICTIONREVOCATION_BITSIZE))
    {
        if (TemporarySpeedRestrictionRevocation_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 8,  p->NID_TSR);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert NID_TSR:           EqualBits(stream, pos + 15,  pos + 23,  p->NID_TSR);

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

int TemporarySpeedRestrictionRevocation_DecodeBit(TemporarySpeedRestrictionRevocation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, TEMPORARYSPEEDRESTRICTIONREVOCATION_BITSIZE))
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
          requires NID_TSR:        stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->NID_TSR;
          ensures  NID_TSR:        stream->bitpos == pos + 23;
          ensures  NID_TSR:        EqualBits(stream, pos + 15, pos + 23, p->NID_TSR);
          ensures  NID_TSR:        UpperBitsNotSet(p->NID_TSR, 8);
        */
        {
            p->NID_TSR        = Bitstream_Read(stream, 8);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert NID_TSR:           EqualBits(stream, pos + 15,  pos + 23,  p->NID_TSR);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert NID_TSR:           UpperBitsNotSet(p->NID_TSR,           8);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int TemporarySpeedRestrictionRevocation_EncodeInt(const TemporarySpeedRestrictionRevocation* p, PacketInfo* data, kcg_int* stream)
{
    data->nid_packet = 66;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->NID_TSR;

    data->endAddress = startAddress-1;

    return 1;
}

int TemporarySpeedRestrictionRevocation_DecodeInt(TemporarySpeedRestrictionRevocation* p, const PacketInfo* data, const kcg_int* stream)
{
    if(data->nid_packet != 66)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->NID_TSR = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}
