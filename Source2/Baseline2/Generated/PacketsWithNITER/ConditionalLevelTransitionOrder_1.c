
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_ConditionalLevelTransitionOrder
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

#include "ConditionalLevelTransitionOrder_1.h"
#include "Bit64.h"

int ConditionalLevelTransitionOrder_1_UpperBitsNotSet(const ConditionalLevelTransitionOrder_1* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->M_LEVELTR,         3) ;
    if (p->M_LEVELTR == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_STM,           8) ;
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

int ConditionalLevelTransitionOrder_1_EncodeBit(const ConditionalLevelTransitionOrder_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, CONDITIONALLEVELTRANSITIONORDER_1_BITSIZE))
    {
        if (ConditionalLevelTransitionOrder_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 3,  p->M_LEVELTR);
            if (p->M_LEVELTR == 1)
            {
                Bitstream_Write(stream, 8,  p->NID_STM);
            }



            //@ assert M_LEVELTR:         EqualBits(stream, pos,       pos + 3,   p->M_LEVELTR);

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

int ConditionalLevelTransitionOrder_1_DecodeBit(ConditionalLevelTransitionOrder_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, CONDITIONALLEVELTRANSITIONORDER_1_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires M_LEVELTR:      stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->M_LEVELTR;
          ensures  M_LEVELTR:      stream->bitpos == pos + 3;
          ensures  M_LEVELTR:      EqualBits(stream, pos + 0, pos + 3, p->M_LEVELTR);
          ensures  M_LEVELTR:      UpperBitsNotSet(p->M_LEVELTR, 3);
        */
        {
            p->M_LEVELTR        = Bitstream_Read(stream, 3);
        }

        if (p->M_LEVELTR == 1)
        {
            {
                p->NID_STM        = Bitstream_Read(stream, 8);
            }

        }

        //@ assert M_LEVELTR:         EqualBits(stream, pos,       pos + 3,   p->M_LEVELTR);

        //@ assert M_LEVELTR:         UpperBitsNotSet(p->M_LEVELTR,         3);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

#ifndef FRAMAC_IGNORE

int ConditionalLevelTransitionOrder_1_EncodeInt(const ConditionalLevelTransitionOrder_1* p, kcg_int* startAddress, kcg_int* stream)
{
    stream[(*startAddress)++] = p->M_LEVELTR;
    stream[(*startAddress)++] = p->NID_STM;

    return 1;
}

int ConditionalLevelTransitionOrder_1_DecodeInt(ConditionalLevelTransitionOrder_1* p, kcg_int* startAddress, const kcg_int* stream)
{
    p->M_LEVELTR = stream[(*startAddress)++];
    p->NID_STM = stream[(*startAddress)++];

    return 1;
}

#endif // FRAMAC_IGNORE

