
#include "GeographicalPositionInformation_1.h"
#include "Bit64.h"

int GeographicalPositionInformation_1_UpperBitsNotSet(const GeographicalPositionInformation_1* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY,      1) ;
    if (p->Q_NEWCOUNTRY == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_C,             10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG,            14);
    status = status && UpperBitsNotSet64(p->D_POSOFF,          15);
    status = status && UpperBitsNotSet64(p->Q_MPOSITION,       1) ;
    status = status && UpperBitsNotSet64(p->M_POSITION,        20);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int GeographicalPositionInformation_1_EncodeBit(const GeographicalPositionInformation_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, GEOGRAPHICALPOSITIONINFORMATION_1_BITSIZE))
    {
        if (GeographicalPositionInformation_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY);
            if (p->Q_NEWCOUNTRY == 1)
            {
                Bitstream_Write(stream, 10, p->NID_C);
            }

            Bitstream_Write(stream, 14, p->NID_BG);
            Bitstream_Write(stream, 15, p->D_POSOFF);
            Bitstream_Write(stream, 1,  p->Q_MPOSITION);
            Bitstream_Write(stream, 20, p->M_POSITION);


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

int GeographicalPositionInformation_1_DecodeBit(GeographicalPositionInformation_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, GEOGRAPHICALPOSITIONINFORMATION_1_BITSIZE))
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

        {
            p->D_POSOFF        = Bitstream_Read(stream, 15);
        }

        {
            p->Q_MPOSITION        = Bitstream_Read(stream, 1);
        }

        {
            p->M_POSITION        = Bitstream_Read(stream, 20);
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

int GeographicalPositionInformation_1_EncodeInt(const GeographicalPositionInformation_1* p, kcg_int* startAddress, kcg_int* stream)
{
    stream[(*startAddress)++] = p->Q_NEWCOUNTRY;
    stream[(*startAddress)++] = p->NID_C;
    stream[(*startAddress)++] = p->NID_BG;
    stream[(*startAddress)++] = p->D_POSOFF;
    stream[(*startAddress)++] = p->Q_MPOSITION;
    stream[(*startAddress)++] = p->M_POSITION;

    return 1;
}

int GeographicalPositionInformation_1_DecodeInt(GeographicalPositionInformation_1* p, kcg_int* startAddress, const kcg_int* stream)
{
    p->Q_NEWCOUNTRY = stream[(*startAddress)++];
    p->NID_C = stream[(*startAddress)++];
    p->NID_BG = stream[(*startAddress)++];
    p->D_POSOFF = stream[(*startAddress)++];
    p->Q_MPOSITION = stream[(*startAddress)++];
    p->M_POSITION = stream[(*startAddress)++];

    return 1;
}

