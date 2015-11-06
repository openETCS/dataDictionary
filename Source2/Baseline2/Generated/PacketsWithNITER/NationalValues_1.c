
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_NationalValues
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

#include "NationalValues_1.h"
#include "Bit64.h"

int NationalValues_1_UpperBitsNotSet(const NationalValues_1* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->NID_C,             10);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int NationalValues_1_EncodeBit(const NationalValues_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, NATIONALVALUES_1_BITSIZE))
    {
        if (NationalValues_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 10, p->NID_C);


            //@ assert NID_C:             EqualBits(stream, pos,       pos + 10,  p->NID_C);

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

int NationalValues_1_DecodeBit(NationalValues_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, NATIONALVALUES_1_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires NID_C:          stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->NID_C;
          ensures  NID_C:          stream->bitpos == pos + 10;
          ensures  NID_C:          EqualBits(stream, pos + 0, pos + 10, p->NID_C);
          ensures  NID_C:          UpperBitsNotSet(p->NID_C, 10);
        */
        {
            p->NID_C        = Bitstream_Read(stream, 10);
        }

        //@ assert NID_C:             EqualBits(stream, pos,       pos + 10,  p->NID_C);

        //@ assert NID_C:             UpperBitsNotSet(p->NID_C,             10);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int NationalValues_1_EncodeInt(const NationalValues_1* p, kcg_int* startAddress, kcg_int* stream)
{
    stream[(*startAddress)++] = p->NID_C;

    return 1;
}

int NationalValues_1_DecodeInt(NationalValues_1* p, kcg_int* startAddress, const kcg_int* stream)
{
    p->NID_C = stream[(*startAddress)++];

    return 1;
}

