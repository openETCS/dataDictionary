
#include "RepositioningInformation.h"
#include "Bit64.h"

// number of cells in allocation memory
#define RepositioningInformationMemoryMax		32

// end-of-freelist indicator
#define RepositioningInformationMemoryNil		(-1)

// allocation memory
static RepositioningInformation RepositioningInformationMemory[RepositioningInformationMemoryMax];

// lowest unused cell of allocation memory
static uint64_t RepositioningInformationMemoryTop = 0;

// index of first element of freelist
static uint64_t RepositioningInformationMemoryFreeList = RepositioningInformationMemoryNil;

RepositioningInformation* RepositioningInformation_New(void)
{
    RepositioningInformation* ptr;

    if (RepositioningInformationMemoryFreeList != RepositioningInformationMemoryNil)
    {
        // allocate from freelist
        ptr = &RepositioningInformationMemory[RepositioningInformationMemoryFreeList];
        RepositioningInformationMemoryFreeList = RepositioningInformationMemory[RepositioningInformationMemoryFreeList].header.NID_PACKET;
    }
    else if (RepositioningInformationMemoryTop < RepositioningInformationMemoryMax)
    {
        // allocate from top
        ptr = &RepositioningInformationMemory[RepositioningInformationMemoryTop];
        RepositioningInformationMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    RepositioningInformation_Init(ptr);

    return ptr;
}


void RepositioningInformation_Delete(RepositioningInformation* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = RepositioningInformationMemoryFreeList;
    RepositioningInformationMemoryFreeList = ptr - RepositioningInformationMemory;
}


int RepositioningInformation_UpperBitsNotSet(const RepositioningInformation* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->L_SECTION,         15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int RepositioningInformation_EncodeBit(const RepositioningInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, REPOSITIONINGINFORMATION_BITSIZE))
    {
        if (RepositioningInformation_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->L_SECTION);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert L_SECTION:         EqualBits(stream, pos + 17,  pos + 32,  p->L_SECTION);

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

int RepositioningInformation_DecodeBit(RepositioningInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, REPOSITIONINGINFORMATION_BITSIZE))
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
          requires L_SECTION:      stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->L_SECTION;
          ensures  L_SECTION:      stream->bitpos == pos + 32;
          ensures  L_SECTION:      EqualBits(stream, pos + 17, pos + 32, p->L_SECTION);
          ensures  L_SECTION:      UpperBitsNotSet(p->L_SECTION, 15);
        */
        {
            p->L_SECTION        = Bitstream_Read(stream, 15);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert L_SECTION:         EqualBits(stream, pos + 17,  pos + 32,  p->L_SECTION);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert L_SECTION:         UpperBitsNotSet(p->L_SECTION,         15);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int RepositioningInformation_EncodeInt(const RepositioningInformation* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 16;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->L_SECTION;

    data->endAddress = startAddress-1;

    return 1;
}

int RepositioningInformation_DecodeInt(RepositioningInformation* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 16)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->L_SECTION = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

