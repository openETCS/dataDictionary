
#include "PositionReportParameters_1.h"
#include "Bit64.h"

PositionReportParameters_1* PositionReportParameters_1_New(void)
{
    void* raw = malloc(sizeof(PositionReportParameters_1));
    PositionReportParameters_1* ptr = (PositionReportParameters_1*)raw;
    PositionReportParameters_1_Init(ptr);
    return ptr;
}


void PositionReportParameters_1_Delete(PositionReportParameters_1* ptr)
{
    free(ptr);
}


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

int PositionReportParameters_1_EncodeInt(const PositionReportParameters_1* p, PacketInfo* data, kcg_int* stream)
{
    return 0;
}

int PositionReportParameters_1_DecodeInt(PositionReportParameters_1* p, PacketInfo* data, kcg_int* stream)
{
    return 0;
}

