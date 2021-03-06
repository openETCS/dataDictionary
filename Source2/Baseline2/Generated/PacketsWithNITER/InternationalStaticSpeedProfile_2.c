
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

#include "InternationalStaticSpeedProfile_2.h"
#include "Bit64.h"

int InternationalStaticSpeedProfile_2_UpperBitsNotSet(const InternationalStaticSpeedProfile_2* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->D_STATIC,          15);
    status = status && UpperBitsNotSet64(p->V_STATIC,          7) ;
    status = status && UpperBitsNotSet64(p->Q_FRONT,           1) ;
    status = status && UpperBitsNotSet64(p->N_ITER_2_1,        5) ;
    for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
    {
        status = status && InternationalStaticSpeedProfile_2_1_UpperBitsNotSet(&(p->sub_2_1[i]));
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

int InternationalStaticSpeedProfile_2_EncodeBit(const InternationalStaticSpeedProfile_2* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, INTERNATIONALSTATICSPEEDPROFILE_2_BITSIZE))
    {
        if (InternationalStaticSpeedProfile_2_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_STATIC);
            Bitstream_Write(stream, 7,  p->V_STATIC);
            Bitstream_Write(stream, 1,  p->Q_FRONT);
            Bitstream_Write(stream, 5,  p->N_ITER_2_1);
            for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
            {
                InternationalStaticSpeedProfile_2_1_EncodeBit(&(p->sub_2_1[i]), stream);
            }


            //@ assert D_STATIC:          EqualBits(stream, pos,       pos + 15,  p->D_STATIC);
            //@ assert V_STATIC:          EqualBits(stream, pos + 15,  pos + 22,  p->V_STATIC);
            //@ assert Q_FRONT:           EqualBits(stream, pos + 22,  pos + 23,  p->Q_FRONT);

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

int InternationalStaticSpeedProfile_2_DecodeBit(InternationalStaticSpeedProfile_2* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, INTERNATIONALSTATICSPEEDPROFILE_2_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires D_STATIC:       stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->D_STATIC;
          ensures  D_STATIC:       stream->bitpos == pos + 15;
          ensures  D_STATIC:       EqualBits(stream, pos + 0, pos + 15, p->D_STATIC);
          ensures  D_STATIC:       UpperBitsNotSet(p->D_STATIC, 15);
        */
        {
            p->D_STATIC        = Bitstream_Read(stream, 15);
        }

        /*@
          requires V_STATIC:       stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->V_STATIC;
          ensures  V_STATIC:       stream->bitpos == pos + 22;
          ensures  V_STATIC:       EqualBits(stream, pos + 15, pos + 22, p->V_STATIC);
          ensures  V_STATIC:       UpperBitsNotSet(p->V_STATIC, 7);
        */
        {
            p->V_STATIC        = Bitstream_Read(stream, 7);
        }

        /*@
          requires Q_FRONT:        stream->bitpos == pos + 22;
          assigns                  stream->bitpos;
          assigns                  p->Q_FRONT;
          ensures  Q_FRONT:        stream->bitpos == pos + 23;
          ensures  Q_FRONT:        EqualBits(stream, pos + 22, pos + 23, p->Q_FRONT);
          ensures  Q_FRONT:        UpperBitsNotSet(p->Q_FRONT, 1);
        */
        {
            p->Q_FRONT        = Bitstream_Read(stream, 1);
        }

    {
            p->N_ITER_2_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
        {
            InternationalStaticSpeedProfile_2_1_DecodeBit(&(p->sub_2_1[i]), stream);
        }
        //@ assert D_STATIC:          EqualBits(stream, pos,       pos + 15,  p->D_STATIC);
        //@ assert V_STATIC:          EqualBits(stream, pos + 15,  pos + 22,  p->V_STATIC);
        //@ assert Q_FRONT:           EqualBits(stream, pos + 22,  pos + 23,  p->Q_FRONT);

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

int InternationalStaticSpeedProfile_2_EncodeInt(const InternationalStaticSpeedProfile_2* p, kcg_int* startAddress, kcg_int* stream)
{
    stream[(*startAddress)++] = p->D_STATIC;
    stream[(*startAddress)++] = p->V_STATIC;
    stream[(*startAddress)++] = p->Q_FRONT;
    stream[(*startAddress)++] = p->N_ITER_2_1;

    for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
    {
        InternationalStaticSpeedProfile_2_1_EncodeInt(&(p->sub_2_1[i]), startAddress, stream);
    }


    return 1;
}

int InternationalStaticSpeedProfile_2_DecodeInt(InternationalStaticSpeedProfile_2* p, kcg_int* startAddress, const kcg_int* stream)
{
    p->D_STATIC = stream[(*startAddress)++];
    p->V_STATIC = stream[(*startAddress)++];
    p->Q_FRONT = stream[(*startAddress)++];
    p->N_ITER_2_1 = stream[(*startAddress)++];

    for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
    {
        InternationalStaticSpeedProfile_2_1_DecodeInt(&(p->sub_2_1[i]), startAddress, stream);
    }


    return 1;
}

#endif // FRAMAC_IGNORE

