
#include "GeographicalPositionInformation.h"
#include "Bit64.h"

// number of xells in allocation memory
#define GeographicalPositionInformationMemoryMax 32

// end-of-freelist indicator
#define GeographicalPositionInformationMemoryNil (-1)

// allocation memory
static GeographicalPositionInformation GeographicalPositionInformationMemory[GeographicalPositionInformationMemoryMax];

// lowest unused cell of allocation memory
static uint64_t GeographicalPositionInformationMemoryTop = 0;

// index of first element of freelist
static uint64_t GeographicalPositionInformationMemoryFreeList = GeographicalPositionInformationMemoryNil;

GeographicalPositionInformation* GeographicalPositionInformation_New(void)
{
    GeographicalPositionInformation* ptr;

    if (GeographicalPositionInformationMemoryFreeList != GeographicalPositionInformationMemoryNil)
    {
         // allocate from freelist
	 ptr = &GeographicalPositionInformationMemory[GeographicalPositionInformationMemoryFreeList];
	 GeographicalPositionInformationMemoryFreeList = GeographicalPositionInformationMemory[GeographicalPositionInformationMemoryFreeList].header.NID_PACKET;
    }
    else if (GeographicalPositionInformationMemoryTop < GeographicalPositionInformationMemoryMax)
    {
         // allocate from top
	 ptr = &GeographicalPositionInformationMemory[GeographicalPositionInformationMemoryTop];
	 GeographicalPositionInformationMemoryTop += 1;
    }
    else
    {
         // memory exhausted
	 return 0;
    }

    GeographicalPositionInformation_Init(ptr);

    return ptr;
}


void GeographicalPositionInformation_Delete(GeographicalPositionInformation* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = GeographicalPositionInformationMemoryFreeList;
    GeographicalPositionInformationMemoryFreeList = ptr - GeographicalPositionInformationMemory;
}


int GeographicalPositionInformation_UpperBitsNotSet(const GeographicalPositionInformation* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY,      1) ;
    if (p->Q_NEWCOUNTRY == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_C,             10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG,            14);
    status = status && UpperBitsNotSet64(p->D_POSOFF,          15);
    status = status && UpperBitsNotSet64(p->Q_MPOSITION,       1) ;
    status = status && UpperBitsNotSet64(p->M_POSITION,        20);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && GeographicalPositionInformation_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int GeographicalPositionInformation_EncodeBit(const GeographicalPositionInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, GEOGRAPHICALPOSITIONINFORMATION_BITSIZE))
    {
        if (GeographicalPositionInformation_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY);
            if (p->Q_NEWCOUNTRY == 1)
            {
                Bitstream_Write(stream, 10, p->NID_C);
            }

            Bitstream_Write(stream, 14, p->NID_BG);
            Bitstream_Write(stream, 15, p->D_POSOFF);
            Bitstream_Write(stream, 1,  p->Q_MPOSITION);
            Bitstream_Write(stream, 20, p->M_POSITION);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                GeographicalPositionInformation_1_EncodeBit(&(p->sub_1[i]), stream);
            }


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos + 17,  pos + 18,  p->Q_NEWCOUNTRY);

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

int GeographicalPositionInformation_DecodeBit(GeographicalPositionInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, GEOGRAPHICALPOSITIONINFORMATION_BITSIZE))
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
          requires Q_NEWCOUNTRY:   stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->Q_NEWCOUNTRY;
          ensures  Q_NEWCOUNTRY:   stream->bitpos == pos + 18;
          ensures  Q_NEWCOUNTRY:   EqualBits(stream, pos + 17, pos + 18, p->Q_NEWCOUNTRY);
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
            p->D_POSOFF        = Bitstream_Read(stream, 15);
        }

        {
            p->Q_MPOSITION        = Bitstream_Read(stream, 1);
        }

        {
            p->M_POSITION        = Bitstream_Read(stream, 20);
        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            GeographicalPositionInformation_1_DecodeBit(&(p->sub_1[i]), stream);
        }
        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos + 17,  pos + 18,  p->Q_NEWCOUNTRY);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert Q_NEWCOUNTRY:      UpperBitsNotSet(p->Q_NEWCOUNTRY,      1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int GeographicalPositionInformation_EncodeInt(const GeographicalPositionInformation* p, PacketInfo* data, kcg_int* stream)
{
    data->nid_packet = 79;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->Q_NEWCOUNTRY;
    stream[startAddress++] = p->NID_C;
    stream[startAddress++] = p->NID_BG;
    stream[startAddress++] = p->D_POSOFF;
    stream[startAddress++] = p->Q_MPOSITION;
    stream[startAddress++] = p->M_POSITION;
    stream[startAddress++] = p->N_ITER_1;

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        GeographicalPositionInformation_1_EncodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    data->endAddress = startAddress-1;

    return 1;
}

int GeographicalPositionInformation_DecodeInt(GeographicalPositionInformation* p, const PacketInfo* data, const kcg_int* stream)
{
    if(data->nid_packet != 79)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->Q_NEWCOUNTRY = stream[startAddress++];
    p->NID_C = stream[startAddress++];
    p->NID_BG = stream[startAddress++];
    p->D_POSOFF = stream[startAddress++];
    p->Q_MPOSITION = stream[startAddress++];
    p->M_POSITION = stream[startAddress++];
    p->N_ITER_1 = stream[startAddress++];

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        GeographicalPositionInformation_1_DecodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

