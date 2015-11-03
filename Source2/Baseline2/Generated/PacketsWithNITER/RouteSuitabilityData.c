
#include "RouteSuitabilityData.h"
#include "Bit64.h"

// number of cells in allocation memory
#define RouteSuitabilityDataMemoryMax		32

// end-of-freelist indicator
#define RouteSuitabilityDataMemoryNil		(-1)

// allocation memory
static RouteSuitabilityData RouteSuitabilityDataMemory[RouteSuitabilityDataMemoryMax];

// lowest unused cell of allocation memory
static uint64_t RouteSuitabilityDataMemoryTop = 0;

// index of first element of freelist
static uint64_t RouteSuitabilityDataMemoryFreeList = RouteSuitabilityDataMemoryNil;

RouteSuitabilityData* RouteSuitabilityData_New(void)
{
    RouteSuitabilityData* ptr;

    if (RouteSuitabilityDataMemoryFreeList != RouteSuitabilityDataMemoryNil)
    {
        // allocate from freelist
        ptr = &RouteSuitabilityDataMemory[RouteSuitabilityDataMemoryFreeList];
        RouteSuitabilityDataMemoryFreeList = RouteSuitabilityDataMemory[RouteSuitabilityDataMemoryFreeList].header.NID_PACKET;
    }
    else if (RouteSuitabilityDataMemoryTop < RouteSuitabilityDataMemoryMax)
    {
        // allocate from top
        ptr = &RouteSuitabilityDataMemory[RouteSuitabilityDataMemoryTop];
        RouteSuitabilityDataMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    RouteSuitabilityData_Init(ptr);

    return ptr;
}


void RouteSuitabilityData_Delete(RouteSuitabilityData* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = RouteSuitabilityDataMemoryFreeList;
    RouteSuitabilityDataMemoryFreeList = ptr - RouteSuitabilityDataMemory;
}


int RouteSuitabilityData_UpperBitsNotSet(const RouteSuitabilityData* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->Q_TRACKINIT,       1) ;
    if (p->Q_TRACKINIT == 1)
    {
        status = status && UpperBitsNotSet64(p->D_TRACKINIT,       15);
    }
    if (p->Q_TRACKINIT == 0)
    {
        status = status && UpperBitsNotSet64(p->D_SUITABILITY,     15);
    }
    status = status && UpperBitsNotSet64(p->Q_SUITABILITY,     2) ;
    if (p->Q_SUITABILITY == 0)
    {
        status = status && UpperBitsNotSet64(p->M_LOADINGGAUGE,    8) ;
    }
    if (p->Q_SUITABILITY == 1)
    {
        status = status && UpperBitsNotSet64(p->M_AXLELOAD,        7) ;
    }
    if (p->Q_SUITABILITY == 2)
    {
        status = status && UpperBitsNotSet64(p->M_TRACTION,        8) ;
    }
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && RouteSuitabilityData_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int RouteSuitabilityData_EncodeBit(const RouteSuitabilityData* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, ROUTESUITABILITYDATA_BITSIZE))
    {
        if (RouteSuitabilityData_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 1,  p->Q_TRACKINIT);
            if (p->Q_TRACKINIT == 1)
            {
                Bitstream_Write(stream, 15, p->D_TRACKINIT);
            }

            if (p->Q_TRACKINIT == 0)
            {
                Bitstream_Write(stream, 15, p->D_SUITABILITY);
            }

            Bitstream_Write(stream, 2,  p->Q_SUITABILITY);
            if (p->Q_SUITABILITY == 0)
            {
                Bitstream_Write(stream, 8,  p->M_LOADINGGAUGE);
            }

            if (p->Q_SUITABILITY == 1)
            {
                Bitstream_Write(stream, 7,  p->M_AXLELOAD);
            }

            if (p->Q_SUITABILITY == 2)
            {
                Bitstream_Write(stream, 8,  p->M_TRACTION);
            }

            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                RouteSuitabilityData_1_EncodeBit(&(p->sub_1[i]), stream);
            }


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert Q_TRACKINIT:       EqualBits(stream, pos + 17,  pos + 18,  p->Q_TRACKINIT);

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

int RouteSuitabilityData_DecodeBit(RouteSuitabilityData* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, ROUTESUITABILITYDATA_BITSIZE))
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
          requires Q_TRACKINIT:    stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->Q_TRACKINIT;
          ensures  Q_TRACKINIT:    stream->bitpos == pos + 18;
          ensures  Q_TRACKINIT:    EqualBits(stream, pos + 17, pos + 18, p->Q_TRACKINIT);
          ensures  Q_TRACKINIT:    UpperBitsNotSet(p->Q_TRACKINIT, 1);
        */
        {
            p->Q_TRACKINIT        = Bitstream_Read(stream, 1);
        }

        if (p->Q_TRACKINIT == 1)
        {
            {
                p->D_TRACKINIT        = Bitstream_Read(stream, 15);
            }

        }

        if (p->Q_TRACKINIT == 0)
        {
            {
                p->D_SUITABILITY        = Bitstream_Read(stream, 15);
            }

        }

        {
            p->Q_SUITABILITY        = Bitstream_Read(stream, 2);
        }

        if (p->Q_SUITABILITY == 0)
        {
            {
                p->M_LOADINGGAUGE        = Bitstream_Read(stream, 8);
            }

        }

        if (p->Q_SUITABILITY == 1)
        {
            {
                p->M_AXLELOAD        = Bitstream_Read(stream, 7);
            }

        }

        if (p->Q_SUITABILITY == 2)
        {
            {
                p->M_TRACTION        = Bitstream_Read(stream, 8);
            }

        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            RouteSuitabilityData_1_DecodeBit(&(p->sub_1[i]), stream);
        }
        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert Q_TRACKINIT:       EqualBits(stream, pos + 17,  pos + 18,  p->Q_TRACKINIT);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert Q_TRACKINIT:       UpperBitsNotSet(p->Q_TRACKINIT,       1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int RouteSuitabilityData_EncodeInt(const RouteSuitabilityData* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 70;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->Q_TRACKINIT;
    stream[startAddress++] = p->D_TRACKINIT;
    stream[startAddress++] = p->D_SUITABILITY;
    stream[startAddress++] = p->Q_SUITABILITY;
    stream[startAddress++] = p->M_LOADINGGAUGE;
    stream[startAddress++] = p->M_AXLELOAD;
    stream[startAddress++] = p->M_TRACTION;
    stream[startAddress++] = p->N_ITER_1;

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        RouteSuitabilityData_1_EncodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    data->endAddress = startAddress-1;

    return 1;
}

int RouteSuitabilityData_DecodeInt(RouteSuitabilityData* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 70)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->Q_TRACKINIT = stream[startAddress++];
    p->D_TRACKINIT = stream[startAddress++];
    p->D_SUITABILITY = stream[startAddress++];
    p->Q_SUITABILITY = stream[startAddress++];
    p->M_LOADINGGAUGE = stream[startAddress++];
    p->M_AXLELOAD = stream[startAddress++];
    p->M_TRACTION = stream[startAddress++];
    p->N_ITER_1 = stream[startAddress++];

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        RouteSuitabilityData_1_DecodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

