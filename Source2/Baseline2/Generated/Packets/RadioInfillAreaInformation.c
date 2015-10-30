
#include "RadioInfillAreaInformation.h"
#include "Bit64.h"

// number of cells in allocation memory
#define RadioInfillAreaInformationMemoryMax		32

// end-of-freelist indicator
#define RadioInfillAreaInformationMemoryNil		(-1)

// allocation memory
static RadioInfillAreaInformation RadioInfillAreaInformationMemory[RadioInfillAreaInformationMemoryMax];

// lowest unused cell of allocation memory
static uint64_t RadioInfillAreaInformationMemoryTop = 0;

// index of first element of freelist
static uint64_t RadioInfillAreaInformationMemoryFreeList = RadioInfillAreaInformationMemoryNil;

RadioInfillAreaInformation* RadioInfillAreaInformation_New(void)
{
    RadioInfillAreaInformation* ptr;

    if (RadioInfillAreaInformationMemoryFreeList != RadioInfillAreaInformationMemoryNil)
    {
        // allocate from freelist
        ptr = &RadioInfillAreaInformationMemory[RadioInfillAreaInformationMemoryFreeList];
        RadioInfillAreaInformationMemoryFreeList = RadioInfillAreaInformationMemory[RadioInfillAreaInformationMemoryFreeList].header.NID_PACKET;
    }
    else if (RadioInfillAreaInformationMemoryTop < RadioInfillAreaInformationMemoryMax)
    {
        // allocate from top
        ptr = &RadioInfillAreaInformationMemory[RadioInfillAreaInformationMemoryTop];
        RadioInfillAreaInformationMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    RadioInfillAreaInformation_Init(ptr);

    return ptr;
}


void RadioInfillAreaInformation_Delete(RadioInfillAreaInformation* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = RadioInfillAreaInformationMemoryFreeList;
    RadioInfillAreaInformationMemoryFreeList = ptr - RadioInfillAreaInformationMemory;
}


int RadioInfillAreaInformation_UpperBitsNotSet(const RadioInfillAreaInformation* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->Q_RIU,             1) ;
    status = status && UpperBitsNotSet64(p->NID_C_0,           10);
    status = status && UpperBitsNotSet64(p->NID_RIU,           14);
    status = status && UpperBitsNotSet64(p->NID_RADIO,         64);
    status = status && UpperBitsNotSet64(p->D_INFILL,          15);
    status = status && UpperBitsNotSet64(p->NID_C_1,           10);
    status = status && UpperBitsNotSet64(p->NID_BG,            14);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int RadioInfillAreaInformation_EncodeBit(const RadioInfillAreaInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, RADIOINFILLAREAINFORMATION_BITSIZE))
    {
        if (RadioInfillAreaInformation_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 1,  p->Q_RIU);
            Bitstream_Write(stream, 10, p->NID_C_0);
            Bitstream_Write(stream, 14, p->NID_RIU);
            Bitstream_Write(stream, 64, p->NID_RADIO);
            Bitstream_Write(stream, 15, p->D_INFILL);
            Bitstream_Write(stream, 10, p->NID_C_1);
            Bitstream_Write(stream, 14, p->NID_BG);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert Q_RIU:             EqualBits(stream, pos + 17,  pos + 18,  p->Q_RIU);
            //@ assert NID_C_0:           EqualBits(stream, pos + 18,  pos + 28,  p->NID_C_0);
            //@ assert NID_RIU:           EqualBits(stream, pos + 28,  pos + 42,  p->NID_RIU);
            //@ assert NID_RADIO:         EqualBits(stream, pos + 42,  pos + 106, p->NID_RADIO);
            //@ assert D_INFILL:          EqualBits(stream, pos + 106, pos + 121, p->D_INFILL);
            //@ assert NID_C_1:           EqualBits(stream, pos + 121, pos + 131, p->NID_C_1);
            //@ assert NID_BG:            EqualBits(stream, pos + 131, pos + 145, p->NID_BG);

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

int RadioInfillAreaInformation_DecodeBit(RadioInfillAreaInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, RADIOINFILLAREAINFORMATION_BITSIZE))
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
          requires Q_RIU:          stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->Q_RIU;
          ensures  Q_RIU:          stream->bitpos == pos + 18;
          ensures  Q_RIU:          EqualBits(stream, pos + 17, pos + 18, p->Q_RIU);
          ensures  Q_RIU:          UpperBitsNotSet(p->Q_RIU, 1);
        */
        {
            p->Q_RIU        = Bitstream_Read(stream, 1);
        }

        /*@
          requires NID_C_0:        stream->bitpos == pos + 18;
          assigns                  stream->bitpos;
          assigns                  p->NID_C_0;
          ensures  NID_C_0:        stream->bitpos == pos + 28;
          ensures  NID_C_0:        EqualBits(stream, pos + 18, pos + 28, p->NID_C_0);
          ensures  NID_C_0:        UpperBitsNotSet(p->NID_C_0, 10);
        */
        {
            p->NID_C_0        = Bitstream_Read(stream, 10);
        }

        /*@
          requires NID_RIU:        stream->bitpos == pos + 28;
          assigns                  stream->bitpos;
          assigns                  p->NID_RIU;
          ensures  NID_RIU:        stream->bitpos == pos + 42;
          ensures  NID_RIU:        EqualBits(stream, pos + 28, pos + 42, p->NID_RIU);
          ensures  NID_RIU:        UpperBitsNotSet(p->NID_RIU, 14);
        */
        {
            p->NID_RIU        = Bitstream_Read(stream, 14);
        }

        /*@
          requires NID_RADIO:      stream->bitpos == pos + 42;
          assigns                  stream->bitpos;
          assigns                  p->NID_RADIO;
          ensures  NID_RADIO:      stream->bitpos == pos + 106;
          ensures  NID_RADIO:      EqualBits(stream, pos + 42, pos + 106, p->NID_RADIO);
          ensures  NID_RADIO:      UpperBitsNotSet(p->NID_RADIO, 64);
        */
        {
            p->NID_RADIO        = Bitstream_Read(stream, 64);
        }

        /*@
          requires D_INFILL:       stream->bitpos == pos + 106;
          assigns                  stream->bitpos;
          assigns                  p->D_INFILL;
          ensures  D_INFILL:       stream->bitpos == pos + 121;
          ensures  D_INFILL:       EqualBits(stream, pos + 106, pos + 121, p->D_INFILL);
          ensures  D_INFILL:       UpperBitsNotSet(p->D_INFILL, 15);
        */
        {
            p->D_INFILL        = Bitstream_Read(stream, 15);
        }

        /*@
          requires NID_C_1:        stream->bitpos == pos + 121;
          assigns                  stream->bitpos;
          assigns                  p->NID_C_1;
          ensures  NID_C_1:        stream->bitpos == pos + 131;
          ensures  NID_C_1:        EqualBits(stream, pos + 121, pos + 131, p->NID_C_1);
          ensures  NID_C_1:        UpperBitsNotSet(p->NID_C_1, 10);
        */
        {
            p->NID_C_1        = Bitstream_Read(stream, 10);
        }

        /*@
          requires NID_BG:         stream->bitpos == pos + 131;
          assigns                  stream->bitpos;
          assigns                  p->NID_BG;
          ensures  NID_BG:         stream->bitpos == pos + 145;
          ensures  NID_BG:         EqualBits(stream, pos + 131, pos + 145, p->NID_BG);
          ensures  NID_BG:         UpperBitsNotSet(p->NID_BG, 14);
        */
        {
            p->NID_BG        = Bitstream_Read(stream, 14);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert Q_RIU:             EqualBits(stream, pos + 17,  pos + 18,  p->Q_RIU);
        //@ assert NID_C_0:           EqualBits(stream, pos + 18,  pos + 28,  p->NID_C_0);
        //@ assert NID_RIU:           EqualBits(stream, pos + 28,  pos + 42,  p->NID_RIU);
        //@ assert NID_RADIO:         EqualBits(stream, pos + 42,  pos + 106, p->NID_RADIO);
        //@ assert D_INFILL:          EqualBits(stream, pos + 106, pos + 121, p->D_INFILL);
        //@ assert NID_C_1:           EqualBits(stream, pos + 121, pos + 131, p->NID_C_1);
        //@ assert NID_BG:            EqualBits(stream, pos + 131, pos + 145, p->NID_BG);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert Q_RIU:             UpperBitsNotSet(p->Q_RIU,             1);
        //@ assert NID_C_0:           UpperBitsNotSet(p->NID_C_0,           10);
        //@ assert NID_RIU:           UpperBitsNotSet(p->NID_RIU,           14);
        //@ assert NID_RADIO:         UpperBitsNotSet(p->NID_RADIO,         64);
        //@ assert D_INFILL:          UpperBitsNotSet(p->D_INFILL,          15);
        //@ assert NID_C_1:           UpperBitsNotSet(p->NID_C_1,           10);
        //@ assert NID_BG:            UpperBitsNotSet(p->NID_BG,            14);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int RadioInfillAreaInformation_EncodeInt(const RadioInfillAreaInformation* p, PacketInfo* data, kcg_int* stream)
{
    data->nid_packet = 133;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->Q_RIU;
    stream[startAddress++] = p->NID_C_0;
    stream[startAddress++] = p->NID_RIU;
    stream[startAddress++] = p->NID_RADIO;
    stream[startAddress++] = p->D_INFILL;
    stream[startAddress++] = p->NID_C_1;
    stream[startAddress++] = p->NID_BG;

    data->endAddress = startAddress-1;

    return 1;
}

int RadioInfillAreaInformation_DecodeInt(RadioInfillAreaInformation* p, const PacketInfo* data, const kcg_int* stream)
{
    if(data->nid_packet != 133)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->Q_RIU = stream[startAddress++];
    p->NID_C_0 = stream[startAddress++];
    p->NID_RIU = stream[startAddress++];
    p->NID_RADIO = stream[startAddress++];
    p->D_INFILL = stream[startAddress++];
    p->NID_C_1 = stream[startAddress++];
    p->NID_BG = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

