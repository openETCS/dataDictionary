
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_Linking
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

#include "Linking_1.h"
#include "Bit64.h"

int Linking_1_UpperBitsNotSet(const Linking_1* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->D_LINK,            15);
    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY,      1) ;
    if (p->Q_NEWCOUNTRY == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_C,             10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG,            14);
    status = status && UpperBitsNotSet64(p->Q_LINKORIENTATION, 1) ;
    status = status && UpperBitsNotSet64(p->Q_LINKREACTION,    2) ;
    status = status && UpperBitsNotSet64(p->Q_LOCACC,          6) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Linking_1_EncodeBit(const Linking_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, LINKING_1_BITSIZE))
    {
        if (Linking_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_LINK);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY);
            if (p->Q_NEWCOUNTRY == 1)
            {
                Bitstream_Write(stream, 10, p->NID_C);
            }

            Bitstream_Write(stream, 14, p->NID_BG);
            Bitstream_Write(stream, 1,  p->Q_LINKORIENTATION);
            Bitstream_Write(stream, 2,  p->Q_LINKREACTION);
            Bitstream_Write(stream, 6,  p->Q_LOCACC);


            //@ assert D_LINK:            EqualBits(stream, pos,       pos + 15,  p->D_LINK);
            //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos + 15,  pos + 16,  p->Q_NEWCOUNTRY);

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

int Linking_1_DecodeBit(Linking_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, LINKING_1_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires D_LINK:         stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->D_LINK;
          ensures  D_LINK:         stream->bitpos == pos + 15;
          ensures  D_LINK:         EqualBits(stream, pos + 0, pos + 15, p->D_LINK);
          ensures  D_LINK:         UpperBitsNotSet(p->D_LINK, 15);
        */
        {
            p->D_LINK        = Bitstream_Read(stream, 15);
        }

        /*@
          requires Q_NEWCOUNTRY:   stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->Q_NEWCOUNTRY;
          ensures  Q_NEWCOUNTRY:   stream->bitpos == pos + 16;
          ensures  Q_NEWCOUNTRY:   EqualBits(stream, pos + 15, pos + 16, p->Q_NEWCOUNTRY);
          ensures  Q_NEWCOUNTRY:   UpperBitsNotSet(p->Q_NEWCOUNTRY, 1);
        */
        {
            p->Q_NEWCOUNTRY        = Bitstream_Read(stream, 1);
        }

        if (p->Q_NEWCOUNTRY == 1)
        {
            {
                p->NID_C        = Bitstream_Read(stream, 10);
            }

        }

        {
            p->NID_BG        = Bitstream_Read(stream, 14);
        }

        {
            p->Q_LINKORIENTATION        = Bitstream_Read(stream, 1);
        }

        {
            p->Q_LINKREACTION        = Bitstream_Read(stream, 2);
        }

        {
            p->Q_LOCACC        = Bitstream_Read(stream, 6);
        }

        //@ assert D_LINK:            EqualBits(stream, pos,       pos + 15,  p->D_LINK);
        //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos + 15,  pos + 16,  p->Q_NEWCOUNTRY);

        //@ assert D_LINK:            UpperBitsNotSet(p->D_LINK,            15);
        //@ assert Q_NEWCOUNTRY:      UpperBitsNotSet(p->Q_NEWCOUNTRY,      1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

#ifndef FRAMAC_IGNORE

int Linking_1_EncodeInt(const Linking_1* p, kcg_int* startAddress, kcg_int* stream)
{
    stream[(*startAddress)++] = p->D_LINK;
    stream[(*startAddress)++] = p->Q_NEWCOUNTRY;
    stream[(*startAddress)++] = p->NID_C;
    stream[(*startAddress)++] = p->NID_BG;
    stream[(*startAddress)++] = p->Q_LINKORIENTATION;
    stream[(*startAddress)++] = p->Q_LINKREACTION;
    stream[(*startAddress)++] = p->Q_LOCACC;

    return 1;
}

int Linking_1_DecodeInt(Linking_1* p, kcg_int* startAddress, const kcg_int* stream)
{
    p->D_LINK = stream[(*startAddress)++];
    p->Q_NEWCOUNTRY = stream[(*startAddress)++];
    p->NID_C = stream[(*startAddress)++];
    p->NID_BG = stream[(*startAddress)++];
    p->Q_LINKORIENTATION = stream[(*startAddress)++];
    p->Q_LINKREACTION = stream[(*startAddress)++];
    p->Q_LOCACC = stream[(*startAddress)++];

    return 1;
}

#endif // FRAMAC_IGNORE

