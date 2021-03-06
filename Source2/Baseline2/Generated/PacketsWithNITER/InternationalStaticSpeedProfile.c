
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_InternationalStaticSpeedProfile
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


#include "InternationalStaticSpeedProfile.h"
#include "Bit64.h"


int InternationalStaticSpeedProfile_UpperBitsNotSet(const InternationalStaticSpeedProfile* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_STATIC,          15);
    status = status && UpperBitsNotSet64(p->V_STATIC,          7) ;
    status = status && UpperBitsNotSet64(p->Q_FRONT,           1) ;
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && InternationalStaticSpeedProfile_1_UpperBitsNotSet(&(p->sub_1[i]));
    }
    status = status && UpperBitsNotSet64(p->N_ITER_2,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_2; ++i)
    {
        status = status && InternationalStaticSpeedProfile_2_UpperBitsNotSet(&(p->sub_2[i]));
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

int InternationalStaticSpeedProfile_EncodeBit(const InternationalStaticSpeedProfile* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, INTERNATIONALSTATICSPEEDPROFILE_BITSIZE))
    {
        if (InternationalStaticSpeedProfile_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_STATIC);
            Bitstream_Write(stream, 7,  p->V_STATIC);
            Bitstream_Write(stream, 1,  p->Q_FRONT);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                InternationalStaticSpeedProfile_1_EncodeBit(&(p->sub_1[i]), stream);
            }
            Bitstream_Write(stream, 5,  p->N_ITER_2);
            for (uint32_t i = 0; i < p->N_ITER_2; ++i)
            {
                InternationalStaticSpeedProfile_2_EncodeBit(&(p->sub_2[i]), stream);
            }


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_STATIC:          EqualBits(stream, pos + 17,  pos + 32,  p->D_STATIC);
            //@ assert V_STATIC:          EqualBits(stream, pos + 32,  pos + 39,  p->V_STATIC);
            //@ assert Q_FRONT:           EqualBits(stream, pos + 39,  pos + 40,  p->Q_FRONT);

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

int InternationalStaticSpeedProfile_DecodeBit(InternationalStaticSpeedProfile* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, INTERNATIONALSTATICSPEEDPROFILE_BITSIZE))
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
          requires D_STATIC:       stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_STATIC;
          ensures  D_STATIC:       stream->bitpos == pos + 32;
          ensures  D_STATIC:       EqualBits(stream, pos + 17, pos + 32, p->D_STATIC);
          ensures  D_STATIC:       UpperBitsNotSet(p->D_STATIC, 15);
        */
        {
            p->D_STATIC        = Bitstream_Read(stream, 15);
        }

        /*@
          requires V_STATIC:       stream->bitpos == pos + 32;
          assigns                  stream->bitpos;
          assigns                  p->V_STATIC;
          ensures  V_STATIC:       stream->bitpos == pos + 39;
          ensures  V_STATIC:       EqualBits(stream, pos + 32, pos + 39, p->V_STATIC);
          ensures  V_STATIC:       UpperBitsNotSet(p->V_STATIC, 7);
        */
        {
            p->V_STATIC        = Bitstream_Read(stream, 7);
        }

        /*@
          requires Q_FRONT:        stream->bitpos == pos + 39;
          assigns                  stream->bitpos;
          assigns                  p->Q_FRONT;
          ensures  Q_FRONT:        stream->bitpos == pos + 40;
          ensures  Q_FRONT:        EqualBits(stream, pos + 39, pos + 40, p->Q_FRONT);
          ensures  Q_FRONT:        UpperBitsNotSet(p->Q_FRONT, 1);
        */
        {
            p->Q_FRONT        = Bitstream_Read(stream, 1);
        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            InternationalStaticSpeedProfile_1_DecodeBit(&(p->sub_1[i]), stream);
        }
    {
            p->N_ITER_2        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_2; ++i)
        {
            InternationalStaticSpeedProfile_2_DecodeBit(&(p->sub_2[i]), stream);
        }
        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_STATIC:          EqualBits(stream, pos + 17,  pos + 32,  p->D_STATIC);
        //@ assert V_STATIC:          EqualBits(stream, pos + 32,  pos + 39,  p->V_STATIC);
        //@ assert Q_FRONT:           EqualBits(stream, pos + 39,  pos + 40,  p->Q_FRONT);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_STATIC:          UpperBitsNotSet(p->D_STATIC,          15);
        //@ assert V_STATIC:          UpperBitsNotSet(p->V_STATIC,          7);
        //@ assert Q_FRONT:           UpperBitsNotSet(p->Q_FRONT,           1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

#ifndef FRAMAC_IGNORE

int InternationalStaticSpeedProfile_EncodeInt(const InternationalStaticSpeedProfile* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 27;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->N_ITER_2 + 1;

    stream[startAddress++] = p->D_STATIC;
    stream[startAddress++] = p->V_STATIC;
    stream[startAddress++] = p->Q_FRONT;
    stream[startAddress++] = p->N_ITER_1;

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        InternationalStaticSpeedProfile_1_EncodeInt(&(p->sub_1[i]), &startAddress, stream);
    }

    for (uint32_t i = 0; i < p->N_ITER_2; ++i)
    {
        InternationalStaticSpeedProfile_2_EncodeInt(&(p->sub_2[i]), &startAddress, stream);
    }


    data->endAddress = startAddress-1;

    return 1;
}

int InternationalStaticSpeedProfile_DecodeInt(InternationalStaticSpeedProfile* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 27)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->N_ITER_2 = stream[startAddress++] - 1;

    p->D_STATIC = stream[startAddress++];
    p->V_STATIC = stream[startAddress++];
    p->Q_FRONT = stream[startAddress++];
    p->N_ITER_1 = stream[startAddress++];

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        InternationalStaticSpeedProfile_1_DecodeInt(&(p->sub_1[i]), &startAddress, stream);
    }

    for (uint32_t i = 0; i < p->N_ITER_2; ++i)
    {
        InternationalStaticSpeedProfile_2_DecodeInt(&(p->sub_2[i]), &startAddress, stream);
    }


    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

// number of cells in allocation memory
#define InternationalStaticSpeedProfileMemoryMax		8

// end-of-freelist indicator
#define InternationalStaticSpeedProfileMemoryNil		(-1)

// allocation memory
static InternationalStaticSpeedProfile InternationalStaticSpeedProfileMemory[InternationalStaticSpeedProfileMemoryMax];

// lowest unused cell of allocation memory
static uint64_t InternationalStaticSpeedProfileMemoryTop = 0;

// index of first element of freelist
static uint64_t InternationalStaticSpeedProfileMemoryFreeList = InternationalStaticSpeedProfileMemoryNil;

InternationalStaticSpeedProfile* InternationalStaticSpeedProfile_New(void)
{
    InternationalStaticSpeedProfile* ptr;

    if (InternationalStaticSpeedProfileMemoryFreeList != InternationalStaticSpeedProfileMemoryNil)
    {
        // allocate from freelist
        ptr = &InternationalStaticSpeedProfileMemory[InternationalStaticSpeedProfileMemoryFreeList];
        InternationalStaticSpeedProfileMemoryFreeList = InternationalStaticSpeedProfileMemory[InternationalStaticSpeedProfileMemoryFreeList].header.NID_PACKET;
    }
    else if (InternationalStaticSpeedProfileMemoryTop < InternationalStaticSpeedProfileMemoryMax)
    {
        // allocate from top
        ptr = &InternationalStaticSpeedProfileMemory[InternationalStaticSpeedProfileMemoryTop];
        InternationalStaticSpeedProfileMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    InternationalStaticSpeedProfile_Init(ptr);

    return ptr;
}


void InternationalStaticSpeedProfile_Delete(InternationalStaticSpeedProfile* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = InternationalStaticSpeedProfileMemoryFreeList;
    InternationalStaticSpeedProfileMemoryFreeList = ptr - InternationalStaticSpeedProfileMemory;
}

#endif // FRAMAC_IGNORE

