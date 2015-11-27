
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_PositionReportParameters
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

#include "PositionReportParameters_1.h"
#include "Bit64.h"

int PositionReportParameters_1_UpperBitsNotSet(const PositionReportParameters_1* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->D_LOC,             15);
    status = status && UpperBitsNotSet64(p->Q_LGTLOC,          1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int PositionReportParameters_1_EncodeBit(const PositionReportParameters_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, POSITIONREPORTPARAMETERS_1_BITSIZE))
    {
        if (PositionReportParameters_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_LOC);
            Bitstream_Write(stream, 1,  p->Q_LGTLOC);


            //@ assert D_LOC:             EqualBits(stream, pos,       pos + 15,  p->D_LOC);
            //@ assert Q_LGTLOC:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_LGTLOC);

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

int PositionReportParameters_1_DecodeBit(PositionReportParameters_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, POSITIONREPORTPARAMETERS_1_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires D_LOC:          stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->D_LOC;
          ensures  D_LOC:          stream->bitpos == pos + 15;
          ensures  D_LOC:          EqualBits(stream, pos + 0, pos + 15, p->D_LOC);
          ensures  D_LOC:          UpperBitsNotSet(p->D_LOC, 15);
        */
        {
            p->D_LOC        = Bitstream_Read(stream, 15);
        }

        /*@
          requires Q_LGTLOC:       stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->Q_LGTLOC;
          ensures  Q_LGTLOC:       stream->bitpos == pos + 16;
          ensures  Q_LGTLOC:       EqualBits(stream, pos + 15, pos + 16, p->Q_LGTLOC);
          ensures  Q_LGTLOC:       UpperBitsNotSet(p->Q_LGTLOC, 1);
        */
        {
            p->Q_LGTLOC        = Bitstream_Read(stream, 1);
        }

        //@ assert D_LOC:             EqualBits(stream, pos,       pos + 15,  p->D_LOC);
        //@ assert Q_LGTLOC:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_LGTLOC);

        //@ assert D_LOC:             UpperBitsNotSet(p->D_LOC,             15);
        //@ assert Q_LGTLOC:          UpperBitsNotSet(p->Q_LGTLOC,          1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

#ifndef FRAMAC_IGNORE

int PositionReportParameters_1_EncodeInt(const PositionReportParameters_1* p, kcg_int* startAddress, kcg_int* stream)
{
    stream[(*startAddress)++] = p->D_LOC;
    stream[(*startAddress)++] = p->Q_LGTLOC;

    return 1;
}

int PositionReportParameters_1_DecodeInt(PositionReportParameters_1* p, kcg_int* startAddress, const kcg_int* stream)
{
    p->D_LOC = stream[(*startAddress)++];
    p->Q_LGTLOC = stream[(*startAddress)++];

    return 1;
}

#endif // FRAMAC_IGNORE

