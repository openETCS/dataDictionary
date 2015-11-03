
#include "NationalValues.h"
#include "Bit64.h"

// number of cells in allocation memory
#define NationalValuesMemoryMax		32

// end-of-freelist indicator
#define NationalValuesMemoryNil		(-1)

// allocation memory
static NationalValues NationalValuesMemory[NationalValuesMemoryMax];

// lowest unused cell of allocation memory
static uint64_t NationalValuesMemoryTop = 0;

// index of first element of freelist
static uint64_t NationalValuesMemoryFreeList = NationalValuesMemoryNil;

NationalValues* NationalValues_New(void)
{
    NationalValues* ptr;

    if (NationalValuesMemoryFreeList != NationalValuesMemoryNil)
    {
        // allocate from freelist
        ptr = &NationalValuesMemory[NationalValuesMemoryFreeList];
        NationalValuesMemoryFreeList = NationalValuesMemory[NationalValuesMemoryFreeList].header.NID_PACKET;
    }
    else if (NationalValuesMemoryTop < NationalValuesMemoryMax)
    {
        // allocate from top
        ptr = &NationalValuesMemory[NationalValuesMemoryTop];
        NationalValuesMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    NationalValues_Init(ptr);

    return ptr;
}


void NationalValues_Delete(NationalValues* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = NationalValuesMemoryFreeList;
    NationalValuesMemoryFreeList = ptr - NationalValuesMemory;
}


int NationalValues_UpperBitsNotSet(const NationalValues* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_VALIDNV,         15);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && NationalValues_1_UpperBitsNotSet(&(p->sub_1[i]));
    }
    status = status && UpperBitsNotSet64(p->V_NVSHUNT,         7) ;
    status = status && UpperBitsNotSet64(p->V_NVSTFF,          7) ;
    status = status && UpperBitsNotSet64(p->V_NVONSIGHT,       7) ;
    status = status && UpperBitsNotSet64(p->V_NVUNFIT,         7) ;
    status = status && UpperBitsNotSet64(p->V_NVREL,           7) ;
    status = status && UpperBitsNotSet64(p->D_NVROLL,          15);
    status = status && UpperBitsNotSet64(p->Q_NVSRBKTRG,       1) ;
    status = status && UpperBitsNotSet64(p->Q_NVEMRRLS,        1) ;
    status = status && UpperBitsNotSet64(p->V_NVALLOWOVTRP,    7) ;
    status = status && UpperBitsNotSet64(p->V_NVSUPOVTRP,      7) ;
    status = status && UpperBitsNotSet64(p->D_NVOVTRP,         15);
    status = status && UpperBitsNotSet64(p->T_NVOVTRP,         8) ;
    status = status && UpperBitsNotSet64(p->D_NVPOTRP,         15);
    status = status && UpperBitsNotSet64(p->M_NVCONTACT,       2) ;
    status = status && UpperBitsNotSet64(p->T_NVCONTACT,       8) ;
    status = status && UpperBitsNotSet64(p->M_NVDERUN,         1) ;
    status = status && UpperBitsNotSet64(p->D_NVSTFF,          15);
    status = status && UpperBitsNotSet64(p->Q_NVDRIVER_ADHES,  1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int NationalValues_EncodeBit(const NationalValues* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, NATIONALVALUES_BITSIZE))
    {
        if (NationalValues_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_VALIDNV);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                NationalValues_1_EncodeBit(&(p->sub_1[i]), stream);
            }
            Bitstream_Write(stream, 7,  p->V_NVSHUNT);
            Bitstream_Write(stream, 7,  p->V_NVSTFF);
            Bitstream_Write(stream, 7,  p->V_NVONSIGHT);
            Bitstream_Write(stream, 7,  p->V_NVUNFIT);
            Bitstream_Write(stream, 7,  p->V_NVREL);
            Bitstream_Write(stream, 15, p->D_NVROLL);
            Bitstream_Write(stream, 1,  p->Q_NVSRBKTRG);
            Bitstream_Write(stream, 1,  p->Q_NVEMRRLS);
            Bitstream_Write(stream, 7,  p->V_NVALLOWOVTRP);
            Bitstream_Write(stream, 7,  p->V_NVSUPOVTRP);
            Bitstream_Write(stream, 15, p->D_NVOVTRP);
            Bitstream_Write(stream, 8,  p->T_NVOVTRP);
            Bitstream_Write(stream, 15, p->D_NVPOTRP);
            Bitstream_Write(stream, 2,  p->M_NVCONTACT);
            Bitstream_Write(stream, 8,  p->T_NVCONTACT);
            Bitstream_Write(stream, 1,  p->M_NVDERUN);
            Bitstream_Write(stream, 15, p->D_NVSTFF);
            Bitstream_Write(stream, 1,  p->Q_NVDRIVER_ADHES);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_VALIDNV:         EqualBits(stream, pos + 17,  pos + 32,  p->D_VALIDNV);

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

int NationalValues_DecodeBit(NationalValues* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, NATIONALVALUES_BITSIZE))
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
          requires D_VALIDNV:      stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_VALIDNV;
          ensures  D_VALIDNV:      stream->bitpos == pos + 32;
          ensures  D_VALIDNV:      EqualBits(stream, pos + 17, pos + 32, p->D_VALIDNV);
          ensures  D_VALIDNV:      UpperBitsNotSet(p->D_VALIDNV, 15);
        */
        {
            p->D_VALIDNV        = Bitstream_Read(stream, 15);
        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            NationalValues_1_DecodeBit(&(p->sub_1[i]), stream);
        }
        {
            p->V_NVSHUNT        = Bitstream_Read(stream, 7);
        }

        {
            p->V_NVSTFF        = Bitstream_Read(stream, 7);
        }

        {
            p->V_NVONSIGHT        = Bitstream_Read(stream, 7);
        }

        {
            p->V_NVUNFIT        = Bitstream_Read(stream, 7);
        }

        {
            p->V_NVREL        = Bitstream_Read(stream, 7);
        }

        {
            p->D_NVROLL        = Bitstream_Read(stream, 15);
        }

        {
            p->Q_NVSRBKTRG        = Bitstream_Read(stream, 1);
        }

        {
            p->Q_NVEMRRLS        = Bitstream_Read(stream, 1);
        }

        {
            p->V_NVALLOWOVTRP        = Bitstream_Read(stream, 7);
        }

        {
            p->V_NVSUPOVTRP        = Bitstream_Read(stream, 7);
        }

        {
            p->D_NVOVTRP        = Bitstream_Read(stream, 15);
        }

        {
            p->T_NVOVTRP        = Bitstream_Read(stream, 8);
        }

        {
            p->D_NVPOTRP        = Bitstream_Read(stream, 15);
        }

        {
            p->M_NVCONTACT        = Bitstream_Read(stream, 2);
        }

        {
            p->T_NVCONTACT        = Bitstream_Read(stream, 8);
        }

        {
            p->M_NVDERUN        = Bitstream_Read(stream, 1);
        }

        {
            p->D_NVSTFF        = Bitstream_Read(stream, 15);
        }

        {
            p->Q_NVDRIVER_ADHES        = Bitstream_Read(stream, 1);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_VALIDNV:         EqualBits(stream, pos + 17,  pos + 32,  p->D_VALIDNV);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_VALIDNV:         UpperBitsNotSet(p->D_VALIDNV,         15);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int NationalValues_EncodeInt(const NationalValues* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 3;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->D_VALIDNV;
    stream[startAddress++] = p->N_ITER_1;

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        NationalValues_1_EncodeInt(&(p->sub_1[i]), &startAddress, stream);
    }

    stream[startAddress++] = p->V_NVSHUNT;
    stream[startAddress++] = p->V_NVSTFF;
    stream[startAddress++] = p->V_NVONSIGHT;
    stream[startAddress++] = p->V_NVUNFIT;
    stream[startAddress++] = p->V_NVREL;
    stream[startAddress++] = p->D_NVROLL;
    stream[startAddress++] = p->Q_NVSRBKTRG;
    stream[startAddress++] = p->Q_NVEMRRLS;
    stream[startAddress++] = p->V_NVALLOWOVTRP;
    stream[startAddress++] = p->V_NVSUPOVTRP;
    stream[startAddress++] = p->D_NVOVTRP;
    stream[startAddress++] = p->T_NVOVTRP;
    stream[startAddress++] = p->D_NVPOTRP;
    stream[startAddress++] = p->M_NVCONTACT;
    stream[startAddress++] = p->T_NVCONTACT;
    stream[startAddress++] = p->M_NVDERUN;
    stream[startAddress++] = p->D_NVSTFF;
    stream[startAddress++] = p->Q_NVDRIVER_ADHES;

    data->endAddress = startAddress-1;

    return 1;
}

int NationalValues_DecodeInt(NationalValues* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 3)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->D_VALIDNV = stream[startAddress++];
    p->N_ITER_1 = stream[startAddress++];

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        NationalValues_1_DecodeInt(&(p->sub_1[i]), &startAddress, stream);
    }

    p->V_NVSHUNT = stream[startAddress++];
    p->V_NVSTFF = stream[startAddress++];
    p->V_NVONSIGHT = stream[startAddress++];
    p->V_NVUNFIT = stream[startAddress++];
    p->V_NVREL = stream[startAddress++];
    p->D_NVROLL = stream[startAddress++];
    p->Q_NVSRBKTRG = stream[startAddress++];
    p->Q_NVEMRRLS = stream[startAddress++];
    p->V_NVALLOWOVTRP = stream[startAddress++];
    p->V_NVSUPOVTRP = stream[startAddress++];
    p->D_NVOVTRP = stream[startAddress++];
    p->T_NVOVTRP = stream[startAddress++];
    p->D_NVPOTRP = stream[startAddress++];
    p->M_NVCONTACT = stream[startAddress++];
    p->T_NVCONTACT = stream[startAddress++];
    p->M_NVDERUN = stream[startAddress++];
    p->D_NVSTFF = stream[startAddress++];
    p->Q_NVDRIVER_ADHES = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

