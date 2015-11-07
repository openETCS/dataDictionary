
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

#include "InternationalStaticSpeedProfile_1.h"
#include "Bit64.h"

int InternationalStaticSpeedProfile_1_UpperBitsNotSet(const InternationalStaticSpeedProfile_1* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->NC_DIFF,           4) ;
    status = status && UpperBitsNotSet64(p->V_DIFF,            7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int InternationalStaticSpeedProfile_1_EncodeBit(const InternationalStaticSpeedProfile_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, INTERNATIONALSTATICSPEEDPROFILE_1_BITSIZE))
    {
        if (InternationalStaticSpeedProfile_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 4,  p->NC_DIFF);
            Bitstream_Write(stream, 7,  p->V_DIFF);


            //@ assert NC_DIFF:           EqualBits(stream, pos,       pos + 4,   p->NC_DIFF);
            //@ assert V_DIFF:            EqualBits(stream, pos + 4,   pos + 11,  p->V_DIFF);

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

int InternationalStaticSpeedProfile_1_DecodeBit(InternationalStaticSpeedProfile_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, INTERNATIONALSTATICSPEEDPROFILE_1_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires NC_DIFF:        stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->NC_DIFF;
          ensures  NC_DIFF:        stream->bitpos == pos + 4;
          ensures  NC_DIFF:        EqualBits(stream, pos + 0, pos + 4, p->NC_DIFF);
          ensures  NC_DIFF:        UpperBitsNotSet(p->NC_DIFF, 4);
        */
        {
            p->NC_DIFF        = Bitstream_Read(stream, 4);
        }

        /*@
          requires V_DIFF:         stream->bitpos == pos + 4;
          assigns                  stream->bitpos;
          assigns                  p->V_DIFF;
          ensures  V_DIFF:         stream->bitpos == pos + 11;
          ensures  V_DIFF:         EqualBits(stream, pos + 4, pos + 11, p->V_DIFF);
          ensures  V_DIFF:         UpperBitsNotSet(p->V_DIFF, 7);
        */
        {
            p->V_DIFF        = Bitstream_Read(stream, 7);
        }

        //@ assert NC_DIFF:           EqualBits(stream, pos,       pos + 4,   p->NC_DIFF);
        //@ assert V_DIFF:            EqualBits(stream, pos + 4,   pos + 11,  p->V_DIFF);

        //@ assert NC_DIFF:           UpperBitsNotSet(p->NC_DIFF,           4);
        //@ assert V_DIFF:            UpperBitsNotSet(p->V_DIFF,            7);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

#ifndef FRAMAC_IGNORE

int InternationalStaticSpeedProfile_1_EncodeInt(const InternationalStaticSpeedProfile_1* p, kcg_int* startAddress, kcg_int* stream)
{
    stream[(*startAddress)++] = p->NC_DIFF;
    stream[(*startAddress)++] = p->V_DIFF;

    return 1;
}

int InternationalStaticSpeedProfile_1_DecodeInt(InternationalStaticSpeedProfile_1* p, kcg_int* startAddress, const kcg_int* stream)
{
    p->NC_DIFF = stream[(*startAddress)++];
    p->V_DIFF = stream[(*startAddress)++];

    return 1;
}

#endif // FRAMAC_IGNORE

