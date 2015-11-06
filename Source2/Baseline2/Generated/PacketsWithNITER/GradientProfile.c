
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_GradientProfile
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

#include "GradientProfile.h"
#include "Bit64.h"

// number of cells in allocation memory
#define GradientProfileMemoryMax		8

// end-of-freelist indicator
#define GradientProfileMemoryNil		(-1)

// allocation memory
static GradientProfile GradientProfileMemory[GradientProfileMemoryMax];

// lowest unused cell of allocation memory
static uint64_t GradientProfileMemoryTop = 0;

// index of first element of freelist
static uint64_t GradientProfileMemoryFreeList = GradientProfileMemoryNil;

GradientProfile* GradientProfile_New(void)
{
    GradientProfile* ptr;

    if (GradientProfileMemoryFreeList != GradientProfileMemoryNil)
    {
        // allocate from freelist
        ptr = &GradientProfileMemory[GradientProfileMemoryFreeList];
        GradientProfileMemoryFreeList = GradientProfileMemory[GradientProfileMemoryFreeList].header.NID_PACKET;
    }
    else if (GradientProfileMemoryTop < GradientProfileMemoryMax)
    {
        // allocate from top
        ptr = &GradientProfileMemory[GradientProfileMemoryTop];
        GradientProfileMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    GradientProfile_Init(ptr);

    return ptr;
}


void GradientProfile_Delete(GradientProfile* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = GradientProfileMemoryFreeList;
    GradientProfileMemoryFreeList = ptr - GradientProfileMemory;
}


int GradientProfile_UpperBitsNotSet(const GradientProfile* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_GRADIENT,        15);
    status = status && UpperBitsNotSet64(p->Q_GDIR,            1) ;
    status = status && UpperBitsNotSet64(p->G_A,               8) ;
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && GradientProfile_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int GradientProfile_EncodeBit(const GradientProfile* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, GRADIENTPROFILE_BITSIZE))
    {
        if (GradientProfile_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_GRADIENT);
            Bitstream_Write(stream, 1,  p->Q_GDIR);
            Bitstream_Write(stream, 8,  p->G_A);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                GradientProfile_1_EncodeBit(&(p->sub_1[i]), stream);
            }


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_GRADIENT:        EqualBits(stream, pos + 17,  pos + 32,  p->D_GRADIENT);
            //@ assert Q_GDIR:            EqualBits(stream, pos + 32,  pos + 33,  p->Q_GDIR);
            //@ assert G_A:               EqualBits(stream, pos + 33,  pos + 41,  p->G_A);

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

int GradientProfile_DecodeBit(GradientProfile* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, GRADIENTPROFILE_BITSIZE))
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
          requires D_GRADIENT:     stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_GRADIENT;
          ensures  D_GRADIENT:     stream->bitpos == pos + 32;
          ensures  D_GRADIENT:     EqualBits(stream, pos + 17, pos + 32, p->D_GRADIENT);
          ensures  D_GRADIENT:     UpperBitsNotSet(p->D_GRADIENT, 15);
        */
        {
            p->D_GRADIENT        = Bitstream_Read(stream, 15);
        }

        /*@
          requires Q_GDIR:         stream->bitpos == pos + 32;
          assigns                  stream->bitpos;
          assigns                  p->Q_GDIR;
          ensures  Q_GDIR:         stream->bitpos == pos + 33;
          ensures  Q_GDIR:         EqualBits(stream, pos + 32, pos + 33, p->Q_GDIR);
          ensures  Q_GDIR:         UpperBitsNotSet(p->Q_GDIR, 1);
        */
        {
            p->Q_GDIR        = Bitstream_Read(stream, 1);
        }

        /*@
          requires G_A:            stream->bitpos == pos + 33;
          assigns                  stream->bitpos;
          assigns                  p->G_A;
          ensures  G_A:            stream->bitpos == pos + 41;
          ensures  G_A:            EqualBits(stream, pos + 33, pos + 41, p->G_A);
          ensures  G_A:            UpperBitsNotSet(p->G_A, 8);
        */
        {
            p->G_A        = Bitstream_Read(stream, 8);
        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            GradientProfile_1_DecodeBit(&(p->sub_1[i]), stream);
        }
        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_GRADIENT:        EqualBits(stream, pos + 17,  pos + 32,  p->D_GRADIENT);
        //@ assert Q_GDIR:            EqualBits(stream, pos + 32,  pos + 33,  p->Q_GDIR);
        //@ assert G_A:               EqualBits(stream, pos + 33,  pos + 41,  p->G_A);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_GRADIENT:        UpperBitsNotSet(p->D_GRADIENT,        15);
        //@ assert Q_GDIR:            UpperBitsNotSet(p->Q_GDIR,            1);
        //@ assert G_A:               UpperBitsNotSet(p->G_A,               8);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int GradientProfile_EncodeInt(const GradientProfile* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 21;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->N_ITER_1 + 1;
    stream[startAddress++] = p->D_GRADIENT;
    stream[startAddress++] = p->Q_GDIR;
    stream[startAddress++] = p->G_A;

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        GradientProfile_1_EncodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    data->endAddress = startAddress-1;

    return 1;
}

int GradientProfile_DecodeInt(GradientProfile* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 21)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->N_ITER_1 = stream[startAddress++] - 1;
    p->D_GRADIENT = stream[startAddress++];
    p->Q_GDIR = stream[startAddress++];
    p->G_A = stream[startAddress++];

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        GradientProfile_1_DecodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

