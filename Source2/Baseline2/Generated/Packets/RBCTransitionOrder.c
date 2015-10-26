
#include "RBCTransitionOrder.h"
#include "Bit64.h"

// number of xells in allocation memory
#define RBCTransitionOrderMemoryMax 32

// end-of-freelist indicator
#define RBCTransitionOrderMemoryNil (-1)

// allocation memory
static RBCTransitionOrder RBCTransitionOrderMemory[RBCTransitionOrderMemoryMax];

// lowest unused cell of allocation memory
static uint64_t RBCTransitionOrderMemoryTop = 0;

// index of first element of freelist
static uint64_t RBCTransitionOrderMemoryFreeList = RBCTransitionOrderMemoryNil;

RBCTransitionOrder* RBCTransitionOrder_New(void)
{
    RBCTransitionOrder* ptr;

    if (RBCTransitionOrderMemoryFreeList != RBCTransitionOrderMemoryNil)
    {
         // allocate from freelist
	 ptr = &RBCTransitionOrderMemory[RBCTransitionOrderMemoryFreeList];
	 RBCTransitionOrderMemoryFreeList = RBCTransitionOrderMemory[RBCTransitionOrderMemoryFreeList].header.NID_PACKET;
    }
    else if (RBCTransitionOrderMemoryTop < RBCTransitionOrderMemoryMax)
    {
         // allocate from top
	 ptr = &RBCTransitionOrderMemory[RBCTransitionOrderMemoryTop];
	 RBCTransitionOrderMemoryTop += 1;
    }
    else
    {
         // memory exhausted
	 return 0;
    }

    RBCTransitionOrder_Init(ptr);

    return ptr;
}


void RBCTransitionOrder_Delete(RBCTransitionOrder* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = RBCTransitionOrderMemoryFreeList;
    RBCTransitionOrderMemoryFreeList = ptr - RBCTransitionOrderMemory;
}


int RBCTransitionOrder_UpperBitsNotSet(const RBCTransitionOrder* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_RBCTR,           15);
    status = status && UpperBitsNotSet64(p->NID_C,             10);
    status = status && UpperBitsNotSet64(p->NID_RBC,           14);
    status = status && UpperBitsNotSet64(p->NID_RADIO,         64);
    status = status && UpperBitsNotSet64(p->Q_SLEEPSESSION,    1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int RBCTransitionOrder_EncodeBit(const RBCTransitionOrder* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, RBCTRANSITIONORDER_BITSIZE))
    {
        if (RBCTransitionOrder_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_RBCTR);
            Bitstream_Write(stream, 10, p->NID_C);
            Bitstream_Write(stream, 14, p->NID_RBC);
            Bitstream_Write(stream, 64, p->NID_RADIO);
            Bitstream_Write(stream, 1,  p->Q_SLEEPSESSION);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_RBCTR:           EqualBits(stream, pos + 17,  pos + 32,  p->D_RBCTR);
            //@ assert NID_C:             EqualBits(stream, pos + 32,  pos + 42,  p->NID_C);
            //@ assert NID_RBC:           EqualBits(stream, pos + 42,  pos + 56,  p->NID_RBC);
            //@ assert NID_RADIO:         EqualBits(stream, pos + 56,  pos + 120, p->NID_RADIO);
            //@ assert Q_SLEEPSESSION:    EqualBits(stream, pos + 120, pos + 121, p->Q_SLEEPSESSION);

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

int RBCTransitionOrder_DecodeBit(RBCTransitionOrder* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, RBCTRANSITIONORDER_BITSIZE))
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
          requires D_RBCTR:        stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_RBCTR;
          ensures  D_RBCTR:        stream->bitpos == pos + 32;
          ensures  D_RBCTR:        EqualBits(stream, pos + 17, pos + 32, p->D_RBCTR);
          ensures  D_RBCTR:        UpperBitsNotSet(p->D_RBCTR, 15);
        */
        {
            p->D_RBCTR        = Bitstream_Read(stream, 15);
        }

        /*@
          requires NID_C:          stream->bitpos == pos + 32;
          assigns                  stream->bitpos;
          assigns                  p->NID_C;
          ensures  NID_C:          stream->bitpos == pos + 42;
          ensures  NID_C:          EqualBits(stream, pos + 32, pos + 42, p->NID_C);
          ensures  NID_C:          UpperBitsNotSet(p->NID_C, 10);
        */
        {
            p->NID_C        = Bitstream_Read(stream, 10);
        }

        /*@
          requires NID_RBC:        stream->bitpos == pos + 42;
          assigns                  stream->bitpos;
          assigns                  p->NID_RBC;
          ensures  NID_RBC:        stream->bitpos == pos + 56;
          ensures  NID_RBC:        EqualBits(stream, pos + 42, pos + 56, p->NID_RBC);
          ensures  NID_RBC:        UpperBitsNotSet(p->NID_RBC, 14);
        */
        {
            p->NID_RBC        = Bitstream_Read(stream, 14);
        }

        /*@
          requires NID_RADIO:      stream->bitpos == pos + 56;
          assigns                  stream->bitpos;
          assigns                  p->NID_RADIO;
          ensures  NID_RADIO:      stream->bitpos == pos + 120;
          ensures  NID_RADIO:      EqualBits(stream, pos + 56, pos + 120, p->NID_RADIO);
          ensures  NID_RADIO:      UpperBitsNotSet(p->NID_RADIO, 64);
        */
        {
            p->NID_RADIO        = Bitstream_Read(stream, 64);
        }

        /*@
          requires Q_SLEEPSESSION: stream->bitpos == pos + 120;
          assigns                  stream->bitpos;
          assigns                  p->Q_SLEEPSESSION;
          ensures  Q_SLEEPSESSION: stream->bitpos == pos + 121;
          ensures  Q_SLEEPSESSION: EqualBits(stream, pos + 120, pos + 121, p->Q_SLEEPSESSION);
          ensures  Q_SLEEPSESSION: UpperBitsNotSet(p->Q_SLEEPSESSION, 1);
        */
        {
            p->Q_SLEEPSESSION        = Bitstream_Read(stream, 1);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_RBCTR:           EqualBits(stream, pos + 17,  pos + 32,  p->D_RBCTR);
        //@ assert NID_C:             EqualBits(stream, pos + 32,  pos + 42,  p->NID_C);
        //@ assert NID_RBC:           EqualBits(stream, pos + 42,  pos + 56,  p->NID_RBC);
        //@ assert NID_RADIO:         EqualBits(stream, pos + 56,  pos + 120, p->NID_RADIO);
        //@ assert Q_SLEEPSESSION:    EqualBits(stream, pos + 120, pos + 121, p->Q_SLEEPSESSION);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_RBCTR:           UpperBitsNotSet(p->D_RBCTR,           15);
        //@ assert NID_C:             UpperBitsNotSet(p->NID_C,             10);
        //@ assert NID_RBC:           UpperBitsNotSet(p->NID_RBC,           14);
        //@ assert NID_RADIO:         UpperBitsNotSet(p->NID_RADIO,         64);
        //@ assert Q_SLEEPSESSION:    UpperBitsNotSet(p->Q_SLEEPSESSION,    1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int RBCTransitionOrder_EncodeInt(const RBCTransitionOrder* p, PacketInfo* data, kcg_int* stream)
{
    data->nid_packet = 131;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->D_RBCTR;
    stream[startAddress++] = p->NID_C;
    stream[startAddress++] = p->NID_RBC;
    stream[startAddress++] = p->NID_RADIO;
    stream[startAddress++] = p->Q_SLEEPSESSION;

    data->endAddress = startAddress-1;

    return 1;
}

int RBCTransitionOrder_DecodeInt(RBCTransitionOrder* p, const PacketInfo* data, const kcg_int* stream)
{
    if(data->nid_packet != 131)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->D_RBCTR = stream[startAddress++];
    p->NID_C = stream[startAddress++];
    p->NID_RBC = stream[startAddress++];
    p->NID_RADIO = stream[startAddress++];
    p->Q_SLEEPSESSION = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

