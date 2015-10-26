
#include "ModeProfile.h"
#include "Bit64.h"

// number of xells in allocation memory
#define ModeProfileMemoryMax 32

// end-of-freelist indicator
#define ModeProfileMemoryNil (-1)

// allocation memory
static ModeProfile ModeProfileMemory[ModeProfileMemoryMax];

// lowest unused cell of allocation memory
static uint64_t ModeProfileMemoryTop = 0;

// index of first element of freelist
static uint64_t ModeProfileMemoryFreeList = ModeProfileMemoryNil;

ModeProfile* ModeProfile_New(void)
{
    ModeProfile* ptr;

    if (ModeProfileMemoryFreeList != ModeProfileMemoryNil)
    {
         // allocate from freelist
	 ptr = &ModeProfileMemory[ModeProfileMemoryFreeList];
	 ModeProfileMemoryFreeList = ModeProfileMemory[ModeProfileMemoryFreeList].header.NID_PACKET;
    }
    else if (ModeProfileMemoryTop < ModeProfileMemoryMax)
    {
         // allocate from top
	 ptr = &ModeProfileMemory[ModeProfileMemoryTop];
	 ModeProfileMemoryTop += 1;
    }
    else
    {
         // memory exhausted
	 return 0;
    }

    ModeProfile_Init(ptr);

    return ptr;
}


void ModeProfile_Delete(ModeProfile* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = ModeProfileMemoryFreeList;
    ModeProfileMemoryFreeList = ptr - ModeProfileMemory;
}


int ModeProfile_UpperBitsNotSet(const ModeProfile* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_MAMODE,          15);
    status = status && UpperBitsNotSet64(p->M_MAMODE,          2) ;
    status = status && UpperBitsNotSet64(p->V_MAMODE,          7) ;
    status = status && UpperBitsNotSet64(p->L_MAMODE,          15);
    status = status && UpperBitsNotSet64(p->L_ACKMAMODE,       15);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && ModeProfile_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int ModeProfile_EncodeBit(const ModeProfile* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, MODEPROFILE_BITSIZE))
    {
        if (ModeProfile_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_MAMODE);
            Bitstream_Write(stream, 2,  p->M_MAMODE);
            Bitstream_Write(stream, 7,  p->V_MAMODE);
            Bitstream_Write(stream, 15, p->L_MAMODE);
            Bitstream_Write(stream, 15, p->L_ACKMAMODE);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                ModeProfile_1_EncodeBit(&(p->sub_1[i]), stream);
            }


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_MAMODE:          EqualBits(stream, pos + 17,  pos + 32,  p->D_MAMODE);
            //@ assert M_MAMODE:          EqualBits(stream, pos + 32,  pos + 34,  p->M_MAMODE);
            //@ assert V_MAMODE:          EqualBits(stream, pos + 34,  pos + 41,  p->V_MAMODE);
            //@ assert L_MAMODE:          EqualBits(stream, pos + 41,  pos + 56,  p->L_MAMODE);
            //@ assert L_ACKMAMODE:       EqualBits(stream, pos + 56,  pos + 71,  p->L_ACKMAMODE);

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

int ModeProfile_DecodeBit(ModeProfile* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, MODEPROFILE_BITSIZE))
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
          requires D_MAMODE:       stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_MAMODE;
          ensures  D_MAMODE:       stream->bitpos == pos + 32;
          ensures  D_MAMODE:       EqualBits(stream, pos + 17, pos + 32, p->D_MAMODE);
          ensures  D_MAMODE:       UpperBitsNotSet(p->D_MAMODE, 15);
        */
        {
            p->D_MAMODE        = Bitstream_Read(stream, 15);
        }

        /*@
          requires M_MAMODE:       stream->bitpos == pos + 32;
          assigns                  stream->bitpos;
          assigns                  p->M_MAMODE;
          ensures  M_MAMODE:       stream->bitpos == pos + 34;
          ensures  M_MAMODE:       EqualBits(stream, pos + 32, pos + 34, p->M_MAMODE);
          ensures  M_MAMODE:       UpperBitsNotSet(p->M_MAMODE, 2);
        */
        {
            p->M_MAMODE        = Bitstream_Read(stream, 2);
        }

        /*@
          requires V_MAMODE:       stream->bitpos == pos + 34;
          assigns                  stream->bitpos;
          assigns                  p->V_MAMODE;
          ensures  V_MAMODE:       stream->bitpos == pos + 41;
          ensures  V_MAMODE:       EqualBits(stream, pos + 34, pos + 41, p->V_MAMODE);
          ensures  V_MAMODE:       UpperBitsNotSet(p->V_MAMODE, 7);
        */
        {
            p->V_MAMODE        = Bitstream_Read(stream, 7);
        }

        /*@
          requires L_MAMODE:       stream->bitpos == pos + 41;
          assigns                  stream->bitpos;
          assigns                  p->L_MAMODE;
          ensures  L_MAMODE:       stream->bitpos == pos + 56;
          ensures  L_MAMODE:       EqualBits(stream, pos + 41, pos + 56, p->L_MAMODE);
          ensures  L_MAMODE:       UpperBitsNotSet(p->L_MAMODE, 15);
        */
        {
            p->L_MAMODE        = Bitstream_Read(stream, 15);
        }

        /*@
          requires L_ACKMAMODE:    stream->bitpos == pos + 56;
          assigns                  stream->bitpos;
          assigns                  p->L_ACKMAMODE;
          ensures  L_ACKMAMODE:    stream->bitpos == pos + 71;
          ensures  L_ACKMAMODE:    EqualBits(stream, pos + 56, pos + 71, p->L_ACKMAMODE);
          ensures  L_ACKMAMODE:    UpperBitsNotSet(p->L_ACKMAMODE, 15);
        */
        {
            p->L_ACKMAMODE        = Bitstream_Read(stream, 15);
        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            ModeProfile_1_DecodeBit(&(p->sub_1[i]), stream);
        }
        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_MAMODE:          EqualBits(stream, pos + 17,  pos + 32,  p->D_MAMODE);
        //@ assert M_MAMODE:          EqualBits(stream, pos + 32,  pos + 34,  p->M_MAMODE);
        //@ assert V_MAMODE:          EqualBits(stream, pos + 34,  pos + 41,  p->V_MAMODE);
        //@ assert L_MAMODE:          EqualBits(stream, pos + 41,  pos + 56,  p->L_MAMODE);
        //@ assert L_ACKMAMODE:       EqualBits(stream, pos + 56,  pos + 71,  p->L_ACKMAMODE);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_MAMODE:          UpperBitsNotSet(p->D_MAMODE,          15);
        //@ assert M_MAMODE:          UpperBitsNotSet(p->M_MAMODE,          2);
        //@ assert V_MAMODE:          UpperBitsNotSet(p->V_MAMODE,          7);
        //@ assert L_MAMODE:          UpperBitsNotSet(p->L_MAMODE,          15);
        //@ assert L_ACKMAMODE:       UpperBitsNotSet(p->L_ACKMAMODE,       15);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int ModeProfile_EncodeInt(const ModeProfile* p, PacketInfo* data, kcg_int* stream)
{
    data->nid_packet = 80;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->D_MAMODE;
    stream[startAddress++] = p->M_MAMODE;
    stream[startAddress++] = p->V_MAMODE;
    stream[startAddress++] = p->L_MAMODE;
    stream[startAddress++] = p->L_ACKMAMODE;
    stream[startAddress++] = p->N_ITER_1;

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        ModeProfile_1_EncodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    data->endAddress = startAddress-1;

    return 1;
}

int ModeProfile_DecodeInt(ModeProfile* p, const PacketInfo* data, const kcg_int* stream)
{
    if(data->nid_packet != 80)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->D_MAMODE = stream[startAddress++];
    p->M_MAMODE = stream[startAddress++];
    p->V_MAMODE = stream[startAddress++];
    p->L_MAMODE = stream[startAddress++];
    p->L_ACKMAMODE = stream[startAddress++];
    p->N_ITER_1 = stream[startAddress++];

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        ModeProfile_1_DecodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

