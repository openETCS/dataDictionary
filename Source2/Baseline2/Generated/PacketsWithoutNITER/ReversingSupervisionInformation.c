
#include "ReversingSupervisionInformation.h"
#include "Bit64.h"

// number of cells in allocation memory
#define ReversingSupervisionInformationMemoryMax		32

// end-of-freelist indicator
#define ReversingSupervisionInformationMemoryNil		(-1)

// allocation memory
static ReversingSupervisionInformation ReversingSupervisionInformationMemory[ReversingSupervisionInformationMemoryMax];

// lowest unused cell of allocation memory
static uint64_t ReversingSupervisionInformationMemoryTop = 0;

// index of first element of freelist
static uint64_t ReversingSupervisionInformationMemoryFreeList = ReversingSupervisionInformationMemoryNil;

ReversingSupervisionInformation* ReversingSupervisionInformation_New(void)
{
    ReversingSupervisionInformation* ptr;

    if (ReversingSupervisionInformationMemoryFreeList != ReversingSupervisionInformationMemoryNil)
    {
        // allocate from freelist
        ptr = &ReversingSupervisionInformationMemory[ReversingSupervisionInformationMemoryFreeList];
        ReversingSupervisionInformationMemoryFreeList = ReversingSupervisionInformationMemory[ReversingSupervisionInformationMemoryFreeList].header.NID_PACKET;
    }
    else if (ReversingSupervisionInformationMemoryTop < ReversingSupervisionInformationMemoryMax)
    {
        // allocate from top
        ptr = &ReversingSupervisionInformationMemory[ReversingSupervisionInformationMemoryTop];
        ReversingSupervisionInformationMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    ReversingSupervisionInformation_Init(ptr);

    return ptr;
}


void ReversingSupervisionInformation_Delete(ReversingSupervisionInformation* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = ReversingSupervisionInformationMemoryFreeList;
    ReversingSupervisionInformationMemoryFreeList = ptr - ReversingSupervisionInformationMemory;
}


int ReversingSupervisionInformation_UpperBitsNotSet(const ReversingSupervisionInformation* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_REVERSE,         15);
    status = status && UpperBitsNotSet64(p->V_REVERSE,         7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ReversingSupervisionInformation_EncodeBit(const ReversingSupervisionInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, REVERSINGSUPERVISIONINFORMATION_BITSIZE))
    {
        if (ReversingSupervisionInformation_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_REVERSE);
            Bitstream_Write(stream, 7,  p->V_REVERSE);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_REVERSE:         EqualBits(stream, pos + 17,  pos + 32,  p->D_REVERSE);
            //@ assert V_REVERSE:         EqualBits(stream, pos + 32,  pos + 39,  p->V_REVERSE);

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

int ReversingSupervisionInformation_DecodeBit(ReversingSupervisionInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, REVERSINGSUPERVISIONINFORMATION_BITSIZE))
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
          requires D_REVERSE:      stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_REVERSE;
          ensures  D_REVERSE:      stream->bitpos == pos + 32;
          ensures  D_REVERSE:      EqualBits(stream, pos + 17, pos + 32, p->D_REVERSE);
          ensures  D_REVERSE:      UpperBitsNotSet(p->D_REVERSE, 15);
        */
        {
            p->D_REVERSE        = Bitstream_Read(stream, 15);
        }

        /*@
          requires V_REVERSE:      stream->bitpos == pos + 32;
          assigns                  stream->bitpos;
          assigns                  p->V_REVERSE;
          ensures  V_REVERSE:      stream->bitpos == pos + 39;
          ensures  V_REVERSE:      EqualBits(stream, pos + 32, pos + 39, p->V_REVERSE);
          ensures  V_REVERSE:      UpperBitsNotSet(p->V_REVERSE, 7);
        */
        {
            p->V_REVERSE        = Bitstream_Read(stream, 7);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_REVERSE:         EqualBits(stream, pos + 17,  pos + 32,  p->D_REVERSE);
        //@ assert V_REVERSE:         EqualBits(stream, pos + 32,  pos + 39,  p->V_REVERSE);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_REVERSE:         UpperBitsNotSet(p->D_REVERSE,         15);
        //@ assert V_REVERSE:         UpperBitsNotSet(p->V_REVERSE,         7);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int ReversingSupervisionInformation_EncodeInt(const ReversingSupervisionInformation* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 139;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->D_REVERSE;
    stream[startAddress++] = p->V_REVERSE;

    data->endAddress = startAddress-1;

    return 1;
}

int ReversingSupervisionInformation_DecodeInt(ReversingSupervisionInformation* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 139)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->D_REVERSE = stream[startAddress++];
    p->V_REVERSE = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

