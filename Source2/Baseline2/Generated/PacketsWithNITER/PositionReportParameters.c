
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_PositionReportParameters
- Description: UNISIG SUBSET-026-7, ISSUE : 3.3.0, 3.5 ERTMS/ETCS language) 
- Copyright (c) 

- Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl )
- Gist URL: none
- Cryptography: No
- Author(s): Fraunhofer FOKUS

Disclaimer:

The use of this software is limited to NON-vital applications. 
It has NOT been developed for vital operation purposes and MUST NOT be used for applications 
which may cause harm to people, physical accidents or financial loss. 

THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OTHER KIND OF USE.       
============================================================================= */


#include "PositionReportParameters.h"
#include "Bit64.h"


int PositionReportParameters_UpperBitsNotSet(const PositionReportParameters* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->T_CYCLOC,          8) ;
    status = status && UpperBitsNotSet64(p->D_CYCLOC,          15);
    status = status && UpperBitsNotSet64(p->M_LOC,             3) ;
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && PositionReportParameters_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int PositionReportParameters_EncodeBit(const PositionReportParameters* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, POSITIONREPORTPARAMETERS_BITSIZE))
    {
        if (PositionReportParameters_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 8,  p->T_CYCLOC);
            Bitstream_Write(stream, 15, p->D_CYCLOC);
            Bitstream_Write(stream, 3,  p->M_LOC);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                PositionReportParameters_1_EncodeBit(&(p->sub_1[i]), stream);
            }


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert T_CYCLOC:          EqualBits(stream, pos + 17,  pos + 25,  p->T_CYCLOC);
            //@ assert D_CYCLOC:          EqualBits(stream, pos + 25,  pos + 40,  p->D_CYCLOC);
            //@ assert M_LOC:             EqualBits(stream, pos + 40,  pos + 43,  p->M_LOC);

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

int PositionReportParameters_DecodeBit(PositionReportParameters* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, POSITIONREPORTPARAMETERS_BITSIZE))
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
          requires T_CYCLOC:       stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->T_CYCLOC;
          ensures  T_CYCLOC:       stream->bitpos == pos + 25;
          ensures  T_CYCLOC:       EqualBits(stream, pos + 17, pos + 25, p->T_CYCLOC);
          ensures  T_CYCLOC:       UpperBitsNotSet(p->T_CYCLOC, 8);
        */
        {
            p->T_CYCLOC        = Bitstream_Read(stream, 8);
        }

        /*@
          requires D_CYCLOC:       stream->bitpos == pos + 25;
          assigns                  stream->bitpos;
          assigns                  p->D_CYCLOC;
          ensures  D_CYCLOC:       stream->bitpos == pos + 40;
          ensures  D_CYCLOC:       EqualBits(stream, pos + 25, pos + 40, p->D_CYCLOC);
          ensures  D_CYCLOC:       UpperBitsNotSet(p->D_CYCLOC, 15);
        */
        {
            p->D_CYCLOC        = Bitstream_Read(stream, 15);
        }

        /*@
          requires M_LOC:          stream->bitpos == pos + 40;
          assigns                  stream->bitpos;
          assigns                  p->M_LOC;
          ensures  M_LOC:          stream->bitpos == pos + 43;
          ensures  M_LOC:          EqualBits(stream, pos + 40, pos + 43, p->M_LOC);
          ensures  M_LOC:          UpperBitsNotSet(p->M_LOC, 3);
        */
        {
            p->M_LOC        = Bitstream_Read(stream, 3);
        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            PositionReportParameters_1_DecodeBit(&(p->sub_1[i]), stream);
        }
        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert T_CYCLOC:          EqualBits(stream, pos + 17,  pos + 25,  p->T_CYCLOC);
        //@ assert D_CYCLOC:          EqualBits(stream, pos + 25,  pos + 40,  p->D_CYCLOC);
        //@ assert M_LOC:             EqualBits(stream, pos + 40,  pos + 43,  p->M_LOC);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert T_CYCLOC:          UpperBitsNotSet(p->T_CYCLOC,          8);
        //@ assert D_CYCLOC:          UpperBitsNotSet(p->D_CYCLOC,          15);
        //@ assert M_LOC:             UpperBitsNotSet(p->M_LOC,             3);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

#ifndef FRAMAC_IGNORE

int PositionReportParameters_EncodeInt(const PositionReportParameters* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 58;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->T_CYCLOC;
    stream[startAddress++] = p->D_CYCLOC;
    stream[startAddress++] = p->M_LOC;
    stream[startAddress++] = p->N_ITER_1;

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        PositionReportParameters_1_EncodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    data->endAddress = startAddress-1;

    return 1;
}

int PositionReportParameters_DecodeInt(PositionReportParameters* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 58)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->T_CYCLOC = stream[startAddress++];
    p->D_CYCLOC = stream[startAddress++];
    p->M_LOC = stream[startAddress++];
    p->N_ITER_1 = stream[startAddress++];

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        PositionReportParameters_1_DecodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

// number of cells in allocation memory
#define PositionReportParametersMemoryMax		8

// end-of-freelist indicator
#define PositionReportParametersMemoryNil		(-1)

// allocation memory
static PositionReportParameters PositionReportParametersMemory[PositionReportParametersMemoryMax];

// lowest unused cell of allocation memory
static uint64_t PositionReportParametersMemoryTop = 0;

// index of first element of freelist
static uint64_t PositionReportParametersMemoryFreeList = PositionReportParametersMemoryNil;

PositionReportParameters* PositionReportParameters_New(void)
{
    PositionReportParameters* ptr;

    if (PositionReportParametersMemoryFreeList != PositionReportParametersMemoryNil)
    {
        // allocate from freelist
        ptr = &PositionReportParametersMemory[PositionReportParametersMemoryFreeList];
        PositionReportParametersMemoryFreeList = PositionReportParametersMemory[PositionReportParametersMemoryFreeList].header.NID_PACKET;
    }
    else if (PositionReportParametersMemoryTop < PositionReportParametersMemoryMax)
    {
        // allocate from top
        ptr = &PositionReportParametersMemory[PositionReportParametersMemoryTop];
        PositionReportParametersMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    PositionReportParameters_Init(ptr);

    return ptr;
}


void PositionReportParameters_Delete(PositionReportParameters* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = PositionReportParametersMemoryFreeList;
    PositionReportParametersMemoryFreeList = ptr - PositionReportParametersMemory;
}

#endif // FRAMAC_IGNORE

