
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

#include "GradientProfile_1.h"
#include "Bit64.h"

int GradientProfile_1_UpperBitsNotSet(const GradientProfile_1* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->D_GRADIENT,        15);
    status = status && UpperBitsNotSet64(p->Q_GDIR,            1) ;
    status = status && UpperBitsNotSet64(p->G_A,               8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int GradientProfile_1_EncodeBit(const GradientProfile_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, GRADIENTPROFILE_1_BITSIZE))
    {
        if (GradientProfile_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_GRADIENT);
            Bitstream_Write(stream, 1,  p->Q_GDIR);
            Bitstream_Write(stream, 8,  p->G_A);


            //@ assert D_GRADIENT:        EqualBits(stream, pos,       pos + 15,  p->D_GRADIENT);
            //@ assert Q_GDIR:            EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR);
            //@ assert G_A:               EqualBits(stream, pos + 16,  pos + 24,  p->G_A);

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

int GradientProfile_1_DecodeBit(GradientProfile_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, GRADIENTPROFILE_1_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires D_GRADIENT:     stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->D_GRADIENT;
          ensures  D_GRADIENT:     stream->bitpos == pos + 15;
          ensures  D_GRADIENT:     EqualBits(stream, pos + 0, pos + 15, p->D_GRADIENT);
          ensures  D_GRADIENT:     UpperBitsNotSet(p->D_GRADIENT, 15);
        */
        {
            p->D_GRADIENT        = Bitstream_Read(stream, 15);
        }

        /*@
          requires Q_GDIR:         stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->Q_GDIR;
          ensures  Q_GDIR:         stream->bitpos == pos + 16;
          ensures  Q_GDIR:         EqualBits(stream, pos + 15, pos + 16, p->Q_GDIR);
          ensures  Q_GDIR:         UpperBitsNotSet(p->Q_GDIR, 1);
        */
        {
            p->Q_GDIR        = Bitstream_Read(stream, 1);
        }

        /*@
          requires G_A:            stream->bitpos == pos + 16;
          assigns                  stream->bitpos;
          assigns                  p->G_A;
          ensures  G_A:            stream->bitpos == pos + 24;
          ensures  G_A:            EqualBits(stream, pos + 16, pos + 24, p->G_A);
          ensures  G_A:            UpperBitsNotSet(p->G_A, 8);
        */
        {
            p->G_A        = Bitstream_Read(stream, 8);
        }

        //@ assert D_GRADIENT:        EqualBits(stream, pos,       pos + 15,  p->D_GRADIENT);
        //@ assert Q_GDIR:            EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR);
        //@ assert G_A:               EqualBits(stream, pos + 16,  pos + 24,  p->G_A);

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

#ifndef FRAMAC_IGNORE

int GradientProfile_1_EncodeInt(const GradientProfile_1* p, kcg_int* startAddress, kcg_int* stream)
{
    stream[(*startAddress)++] = p->D_GRADIENT;
    stream[(*startAddress)++] = p->Q_GDIR;
    stream[(*startAddress)++] = p->G_A;

    return 1;
}

int GradientProfile_1_DecodeInt(GradientProfile_1* p, kcg_int* startAddress, const kcg_int* stream)
{
    p->D_GRADIENT = stream[(*startAddress)++];
    p->Q_GDIR = stream[(*startAddress)++];
    p->G_A = stream[(*startAddress)++];

    return 1;
}

#endif // FRAMAC_IGNORE

