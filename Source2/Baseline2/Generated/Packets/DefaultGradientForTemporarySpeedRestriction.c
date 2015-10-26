
#include "DefaultGradientForTemporarySpeedRestriction.h"
#include "Bit64.h"

// number of xells in allocation memory
#define DefaultGradientForTemporarySpeedRestrictionMemoryMax 32

// end-of-freelist indicator
#define DefaultGradientForTemporarySpeedRestrictionMemoryNil (-1)

// allocation memory
static DefaultGradientForTemporarySpeedRestriction DefaultGradientForTemporarySpeedRestrictionMemory[DefaultGradientForTemporarySpeedRestrictionMemoryMax];

// lowest unused cell of allocation memory
static uint64_t DefaultGradientForTemporarySpeedRestrictionMemoryTop = 0;

// index of first element of freelist
static uint64_t DefaultGradientForTemporarySpeedRestrictionMemoryFreeList = DefaultGradientForTemporarySpeedRestrictionMemoryNil;

DefaultGradientForTemporarySpeedRestriction* DefaultGradientForTemporarySpeedRestriction_New(void)
{
    DefaultGradientForTemporarySpeedRestriction* ptr;

    if (DefaultGradientForTemporarySpeedRestrictionMemoryFreeList != DefaultGradientForTemporarySpeedRestrictionMemoryNil)
    {
         // allocate from freelist
	 ptr = &DefaultGradientForTemporarySpeedRestrictionMemory[DefaultGradientForTemporarySpeedRestrictionMemoryFreeList];
	 DefaultGradientForTemporarySpeedRestrictionMemoryFreeList = DefaultGradientForTemporarySpeedRestrictionMemory[DefaultGradientForTemporarySpeedRestrictionMemoryFreeList].header.NID_PACKET;
    }
    else if (DefaultGradientForTemporarySpeedRestrictionMemoryTop < DefaultGradientForTemporarySpeedRestrictionMemoryMax)
    {
         // allocate from top
	 ptr = &DefaultGradientForTemporarySpeedRestrictionMemory[DefaultGradientForTemporarySpeedRestrictionMemoryTop];
	 DefaultGradientForTemporarySpeedRestrictionMemoryTop += 1;
    }
    else
    {
         // memory exhausted
	 return 0;
    }

    DefaultGradientForTemporarySpeedRestriction_Init(ptr);

    return ptr;
}


void DefaultGradientForTemporarySpeedRestriction_Delete(DefaultGradientForTemporarySpeedRestriction* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = DefaultGradientForTemporarySpeedRestrictionMemoryFreeList;
    DefaultGradientForTemporarySpeedRestrictionMemoryFreeList = ptr - DefaultGradientForTemporarySpeedRestrictionMemory;
}


int DefaultGradientForTemporarySpeedRestriction_UpperBitsNotSet(const DefaultGradientForTemporarySpeedRestriction* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_GDIR,            1) ;
    status = status && UpperBitsNotSet64(p->G_TSR,             8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int DefaultGradientForTemporarySpeedRestriction_EncodeBit(const DefaultGradientForTemporarySpeedRestriction* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, DEFAULTGRADIENTFORTEMPORARYSPEEDRESTRICTION_BITSIZE))
    {
        if (DefaultGradientForTemporarySpeedRestriction_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_GDIR);
            Bitstream_Write(stream, 8,  p->G_TSR);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_GDIR:            EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR);
            //@ assert G_TSR:             EqualBits(stream, pos + 16,  pos + 24,  p->G_TSR);

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

int DefaultGradientForTemporarySpeedRestriction_DecodeBit(DefaultGradientForTemporarySpeedRestriction* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, DEFAULTGRADIENTFORTEMPORARYSPEEDRESTRICTION_BITSIZE))
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
          requires Q_GDIR:         stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->Q_GDIR;
          ensures  Q_GDIR:         stream->bitpos == pos + 16;
          ensures  Q_GDIR:         EqualBits(stream, pos + 15, pos + 16, p->Q_GDIR);
          ensures  Q_GDIR:         UpperBitsNotSet(p->Q_GDIR, 1);
        */
        {
            p->Q_GDIR        = Bitstream_Read(stream, 1);
        }

        /*@
          requires G_TSR:          stream->bitpos == pos + 16;
          assigns                  stream->bitpos;
          assigns                  p->G_TSR;
          ensures  G_TSR:          stream->bitpos == pos + 24;
          ensures  G_TSR:          EqualBits(stream, pos + 16, pos + 24, p->G_TSR);
          ensures  G_TSR:          UpperBitsNotSet(p->G_TSR, 8);
        */
        {
            p->G_TSR        = Bitstream_Read(stream, 8);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_GDIR:            EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR);
        //@ assert G_TSR:             EqualBits(stream, pos + 16,  pos + 24,  p->G_TSR);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_GDIR:            UpperBitsNotSet(p->Q_GDIR,            1);
        //@ assert G_TSR:             UpperBitsNotSet(p->G_TSR,             8);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int DefaultGradientForTemporarySpeedRestriction_EncodeInt(const DefaultGradientForTemporarySpeedRestriction* p, PacketInfo* data, kcg_int* stream)
{
    data->nid_packet = 141;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_GDIR;
    stream[startAddress++] = p->G_TSR;

    data->endAddress = startAddress-1;

    return 1;
}

int DefaultGradientForTemporarySpeedRestriction_DecodeInt(DefaultGradientForTemporarySpeedRestriction* p, const PacketInfo* data, const kcg_int* stream)
{
    if(data->nid_packet != 141)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_GDIR = stream[startAddress++];
    p->G_TSR = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

