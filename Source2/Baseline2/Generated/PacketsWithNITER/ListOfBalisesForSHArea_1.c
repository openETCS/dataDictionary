
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_ListOfBalisesForSHArea
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

#include "ListOfBalisesForSHArea_1.h"
#include "Bit64.h"

int ListOfBalisesForSHArea_1_UpperBitsNotSet(const ListOfBalisesForSHArea_1* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY,      1) ;
    if (p->Q_NEWCOUNTRY == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_C,             10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG,            14);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ListOfBalisesForSHArea_1_EncodeBit(const ListOfBalisesForSHArea_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, LISTOFBALISESFORSHAREA_1_BITSIZE))
    {
        if (ListOfBalisesForSHArea_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY);
            if (p->Q_NEWCOUNTRY == 1)
            {
                Bitstream_Write(stream, 10, p->NID_C);
            }

            Bitstream_Write(stream, 14, p->NID_BG);


            //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos,       pos + 1,   p->Q_NEWCOUNTRY);

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

int ListOfBalisesForSHArea_1_DecodeBit(ListOfBalisesForSHArea_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, LISTOFBALISESFORSHAREA_1_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires Q_NEWCOUNTRY:   stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->Q_NEWCOUNTRY;
          ensures  Q_NEWCOUNTRY:   stream->bitpos == pos + 1;
          ensures  Q_NEWCOUNTRY:   EqualBits(stream, pos + 0, pos + 1, p->Q_NEWCOUNTRY);
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

        //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos,       pos + 1,   p->Q_NEWCOUNTRY);

        //@ assert Q_NEWCOUNTRY:      UpperBitsNotSet(p->Q_NEWCOUNTRY,      1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int ListOfBalisesForSHArea_1_EncodeInt(const ListOfBalisesForSHArea_1* p, kcg_int* startAddress, kcg_int* stream)
{
    stream[(*startAddress)++] = p->Q_NEWCOUNTRY;
    stream[(*startAddress)++] = p->NID_C;
    stream[(*startAddress)++] = p->NID_BG;

    return 1;
}

int ListOfBalisesForSHArea_1_DecodeInt(ListOfBalisesForSHArea_1* p, kcg_int* startAddress, const kcg_int* stream)
{
    p->Q_NEWCOUNTRY = stream[(*startAddress)++];
    p->NID_C = stream[(*startAddress)++];
    p->NID_BG = stream[(*startAddress)++];

    return 1;
}

