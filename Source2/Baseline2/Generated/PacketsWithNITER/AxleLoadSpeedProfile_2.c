
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_AxleLoadSpeedProfile
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

#include "AxleLoadSpeedProfile_2.h"
#include "Bit64.h"

int AxleLoadSpeedProfile_2_UpperBitsNotSet(const AxleLoadSpeedProfile_2* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->D_AXLELOAD,        15);
    status = status && UpperBitsNotSet64(p->L_AXLELOAD,        15);
    status = status && UpperBitsNotSet64(p->Q_FRONT,           1) ;
    status = status && UpperBitsNotSet64(p->N_ITER_2_1,        5) ;
    for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
    {
        status = status && AxleLoadSpeedProfile_2_1_UpperBitsNotSet(&(p->sub_2_1[i]));
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

int AxleLoadSpeedProfile_2_EncodeBit(const AxleLoadSpeedProfile_2* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, AXLELOADSPEEDPROFILE_2_BITSIZE))
    {
        if (AxleLoadSpeedProfile_2_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_AXLELOAD);
            Bitstream_Write(stream, 15, p->L_AXLELOAD);
            Bitstream_Write(stream, 1,  p->Q_FRONT);
            Bitstream_Write(stream, 5,  p->N_ITER_2_1);
            for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
            {
                AxleLoadSpeedProfile_2_1_EncodeBit(&(p->sub_2_1[i]), stream);
            }


            //@ assert D_AXLELOAD:        EqualBits(stream, pos,       pos + 15,  p->D_AXLELOAD);
            //@ assert L_AXLELOAD:        EqualBits(stream, pos + 15,  pos + 30,  p->L_AXLELOAD);
            //@ assert Q_FRONT:           EqualBits(stream, pos + 30,  pos + 31,  p->Q_FRONT);

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

int AxleLoadSpeedProfile_2_DecodeBit(AxleLoadSpeedProfile_2* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, AXLELOADSPEEDPROFILE_2_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires D_AXLELOAD:     stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->D_AXLELOAD;
          ensures  D_AXLELOAD:     stream->bitpos == pos + 15;
          ensures  D_AXLELOAD:     EqualBits(stream, pos + 0, pos + 15, p->D_AXLELOAD);
          ensures  D_AXLELOAD:     UpperBitsNotSet(p->D_AXLELOAD, 15);
        */
        {
            p->D_AXLELOAD        = Bitstream_Read(stream, 15);
        }

        /*@
          requires L_AXLELOAD:     stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->L_AXLELOAD;
          ensures  L_AXLELOAD:     stream->bitpos == pos + 30;
          ensures  L_AXLELOAD:     EqualBits(stream, pos + 15, pos + 30, p->L_AXLELOAD);
          ensures  L_AXLELOAD:     UpperBitsNotSet(p->L_AXLELOAD, 15);
        */
        {
            p->L_AXLELOAD        = Bitstream_Read(stream, 15);
        }

        /*@
          requires Q_FRONT:        stream->bitpos == pos + 30;
          assigns                  stream->bitpos;
          assigns                  p->Q_FRONT;
          ensures  Q_FRONT:        stream->bitpos == pos + 31;
          ensures  Q_FRONT:        EqualBits(stream, pos + 30, pos + 31, p->Q_FRONT);
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
            AxleLoadSpeedProfile_2_1_DecodeBit(&(p->sub_2_1[i]), stream);
        }
        //@ assert D_AXLELOAD:        EqualBits(stream, pos,       pos + 15,  p->D_AXLELOAD);
        //@ assert L_AXLELOAD:        EqualBits(stream, pos + 15,  pos + 30,  p->L_AXLELOAD);
        //@ assert Q_FRONT:           EqualBits(stream, pos + 30,  pos + 31,  p->Q_FRONT);

        //@ assert D_AXLELOAD:        UpperBitsNotSet(p->D_AXLELOAD,        15);
        //@ assert L_AXLELOAD:        UpperBitsNotSet(p->L_AXLELOAD,        15);
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

int AxleLoadSpeedProfile_2_EncodeInt(const AxleLoadSpeedProfile_2* p, kcg_int* startAddress, kcg_int* stream)
{
    stream[(*startAddress)++] = p->D_AXLELOAD;
    stream[(*startAddress)++] = p->L_AXLELOAD;
    stream[(*startAddress)++] = p->Q_FRONT;
    stream[(*startAddress)++] = p->N_ITER_2_1;

    for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
    {
        AxleLoadSpeedProfile_2_1_EncodeInt(&(p->sub_2_1[i]), startAddress, stream);
    }


    return 1;
}

int AxleLoadSpeedProfile_2_DecodeInt(AxleLoadSpeedProfile_2* p, kcg_int* startAddress, const kcg_int* stream)
{
    p->D_AXLELOAD = stream[(*startAddress)++];
    p->L_AXLELOAD = stream[(*startAddress)++];
    p->Q_FRONT = stream[(*startAddress)++];
    p->N_ITER_2_1 = stream[(*startAddress)++];

    for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
    {
        AxleLoadSpeedProfile_2_1_DecodeInt(&(p->sub_2_1[i]), startAddress, stream);
    }


    return 1;
}

#endif // FRAMAC_IGNORE

