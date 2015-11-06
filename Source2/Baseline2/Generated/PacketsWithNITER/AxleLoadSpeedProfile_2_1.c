
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

#include "AxleLoadSpeedProfile_2_1.h"
#include "Bit64.h"

int AxleLoadSpeedProfile_2_1_UpperBitsNotSet(const AxleLoadSpeedProfile_2_1* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->M_AXLELOAD,        7) ;
    status = status && UpperBitsNotSet64(p->V_AXLELOAD,        7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int AxleLoadSpeedProfile_2_1_EncodeBit(const AxleLoadSpeedProfile_2_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, AXLELOADSPEEDPROFILE_2_1_BITSIZE))
    {
        if (AxleLoadSpeedProfile_2_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 7,  p->M_AXLELOAD);
            Bitstream_Write(stream, 7,  p->V_AXLELOAD);


            //@ assert M_AXLELOAD:        EqualBits(stream, pos,       pos + 7,   p->M_AXLELOAD);
            //@ assert V_AXLELOAD:        EqualBits(stream, pos + 7,   pos + 14,  p->V_AXLELOAD);

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

int AxleLoadSpeedProfile_2_1_DecodeBit(AxleLoadSpeedProfile_2_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, AXLELOADSPEEDPROFILE_2_1_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires M_AXLELOAD:     stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->M_AXLELOAD;
          ensures  M_AXLELOAD:     stream->bitpos == pos + 7;
          ensures  M_AXLELOAD:     EqualBits(stream, pos + 0, pos + 7, p->M_AXLELOAD);
          ensures  M_AXLELOAD:     UpperBitsNotSet(p->M_AXLELOAD, 7);
        */
        {
            p->M_AXLELOAD        = Bitstream_Read(stream, 7);
        }

        /*@
          requires V_AXLELOAD:     stream->bitpos == pos + 7;
          assigns                  stream->bitpos;
          assigns                  p->V_AXLELOAD;
          ensures  V_AXLELOAD:     stream->bitpos == pos + 14;
          ensures  V_AXLELOAD:     EqualBits(stream, pos + 7, pos + 14, p->V_AXLELOAD);
          ensures  V_AXLELOAD:     UpperBitsNotSet(p->V_AXLELOAD, 7);
        */
        {
            p->V_AXLELOAD        = Bitstream_Read(stream, 7);
        }

        //@ assert M_AXLELOAD:        EqualBits(stream, pos,       pos + 7,   p->M_AXLELOAD);
        //@ assert V_AXLELOAD:        EqualBits(stream, pos + 7,   pos + 14,  p->V_AXLELOAD);

        //@ assert M_AXLELOAD:        UpperBitsNotSet(p->M_AXLELOAD,        7);
        //@ assert V_AXLELOAD:        UpperBitsNotSet(p->V_AXLELOAD,        7);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int AxleLoadSpeedProfile_2_1_EncodeInt(const AxleLoadSpeedProfile_2_1* p, kcg_int* startAddress, kcg_int* stream)
{
    stream[(*startAddress)++] = p->M_AXLELOAD;
    stream[(*startAddress)++] = p->V_AXLELOAD;

    return 1;
}

int AxleLoadSpeedProfile_2_1_DecodeInt(AxleLoadSpeedProfile_2_1* p, kcg_int* startAddress, const kcg_int* stream)
{
    p->M_AXLELOAD = stream[(*startAddress)++];
    p->V_AXLELOAD = stream[(*startAddress)++];

    return 1;
}

