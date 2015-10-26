
#include "Linking.h"
#include "Bit64.h"

// number of xells in allocation memory
#define LinkingMemoryMax 32

// end-of-freelist indicator
#define LinkingMemoryNil (-1)

// allocation memory
static Linking LinkingMemory[LinkingMemoryMax];

// lowest unused cell of allocation memory
static uint64_t LinkingMemoryTop = 0;

// index of first element of freelist
static uint64_t LinkingMemoryFreeList = LinkingMemoryNil;

Linking* Linking_New(void)
{
    Linking* ptr;

    if (LinkingMemoryFreeList != LinkingMemoryNil)
    {
         // allocate from freelist
	 ptr = &LinkingMemory[LinkingMemoryFreeList];
	 LinkingMemoryFreeList = LinkingMemory[LinkingMemoryFreeList].header.NID_PACKET;
    }
    else if (LinkingMemoryTop < LinkingMemoryMax)
    {
         // allocate from top
	 ptr = &LinkingMemory[LinkingMemoryTop];
	 LinkingMemoryTop += 1;
    }
    else
    {
         // memory exhausted
	 return 0;
    }

    Linking_Init(ptr);

    return ptr;
}


void Linking_Delete(Linking* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = LinkingMemoryFreeList;
    LinkingMemoryFreeList = ptr - LinkingMemory;
}


int Linking_UpperBitsNotSet(const Linking* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_LINK,            15);
    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY,      1) ;
    if (p->Q_NEWCOUNTRY == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_C,             10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG,            14);
    status = status && UpperBitsNotSet64(p->Q_LINKORIENTATION, 1) ;
    status = status && UpperBitsNotSet64(p->Q_LINKREACTION,    2) ;
    status = status && UpperBitsNotSet64(p->Q_LOCACC,          6) ;
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Linking_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int Linking_EncodeBit(const Linking* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, LINKING_BITSIZE))
    {
        if (Linking_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_LINK);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY);
            if (p->Q_NEWCOUNTRY == 1)
            {
                Bitstream_Write(stream, 10, p->NID_C);
            }

            Bitstream_Write(stream, 14, p->NID_BG);
            Bitstream_Write(stream, 1,  p->Q_LINKORIENTATION);
            Bitstream_Write(stream, 2,  p->Q_LINKREACTION);
            Bitstream_Write(stream, 6,  p->Q_LOCACC);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Linking_1_EncodeBit(&(p->sub_1[i]), stream);
            }


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_LINK:            EqualBits(stream, pos + 17,  pos + 32,  p->D_LINK);
            //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos + 32,  pos + 33,  p->Q_NEWCOUNTRY);

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

int Linking_DecodeBit(Linking* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, LINKING_BITSIZE))
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
          requires D_LINK:         stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_LINK;
          ensures  D_LINK:         stream->bitpos == pos + 32;
          ensures  D_LINK:         EqualBits(stream, pos + 17, pos + 32, p->D_LINK);
          ensures  D_LINK:         UpperBitsNotSet(p->D_LINK, 15);
        */
        {
            p->D_LINK        = Bitstream_Read(stream, 15);
        }

        /*@
          requires Q_NEWCOUNTRY:   stream->bitpos == pos + 32;
          assigns                  stream->bitpos;
          assigns                  p->Q_NEWCOUNTRY;
          ensures  Q_NEWCOUNTRY:   stream->bitpos == pos + 33;
          ensures  Q_NEWCOUNTRY:   EqualBits(stream, pos + 32, pos + 33, p->Q_NEWCOUNTRY);
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

        {
            p->Q_LINKORIENTATION        = Bitstream_Read(stream, 1);
        }

        {
            p->Q_LINKREACTION        = Bitstream_Read(stream, 2);
        }

        {
            p->Q_LOCACC        = Bitstream_Read(stream, 6);
        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Linking_1_DecodeBit(&(p->sub_1[i]), stream);
        }
        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_LINK:            EqualBits(stream, pos + 17,  pos + 32,  p->D_LINK);
        //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos + 32,  pos + 33,  p->Q_NEWCOUNTRY);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_LINK:            UpperBitsNotSet(p->D_LINK,            15);
        //@ assert Q_NEWCOUNTRY:      UpperBitsNotSet(p->Q_NEWCOUNTRY,      1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Linking_EncodeInt(const Linking* p, PacketInfo* data, kcg_int* stream)
{
    data->nid_packet = 5;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->D_LINK;
    stream[startAddress++] = p->Q_NEWCOUNTRY;
    stream[startAddress++] = p->NID_C;
    stream[startAddress++] = p->NID_BG;
    stream[startAddress++] = p->Q_LINKORIENTATION;
    stream[startAddress++] = p->Q_LINKREACTION;
    stream[startAddress++] = p->Q_LOCACC;
    stream[startAddress++] = p->N_ITER_1;

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        Linking_1_EncodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    data->endAddress = startAddress-1;

    return 1;
}

int Linking_DecodeInt(Linking* p, const PacketInfo* data, const kcg_int* stream)
{
    if(data->nid_packet != 5)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->D_LINK = stream[startAddress++];
    p->Q_NEWCOUNTRY = stream[startAddress++];
    p->NID_C = stream[startAddress++];
    p->NID_BG = stream[startAddress++];
    p->Q_LINKORIENTATION = stream[startAddress++];
    p->Q_LINKREACTION = stream[startAddress++];
    p->Q_LOCACC = stream[startAddress++];
    p->N_ITER_1 = stream[startAddress++];

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        Linking_1_DecodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

