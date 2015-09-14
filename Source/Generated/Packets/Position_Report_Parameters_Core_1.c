
#include "Position_Report_Parameters_Core_1.h"
#include "Bit64.h"

int Position_Report_Parameters_Core_1_UpperBitsNotSet(const Position_Report_Parameters_Core_1* p)
{
    bool status = true;

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

int Position_Report_Parameters_Core_1_Encode_Bit(Bitstream* stream, const Position_Report_Parameters_Core_1* p)
{
    if (Bitstream_Normal(stream, POSITION_REPORT_PARAMETERS_CORE_1_CORE_BITSIZE))
    {
        if (Position_Report_Parameters_Core_1_UpperBitsNotSet(p))
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

int Position_Report_Parameters_Core_1_Decode_Bit(Bitstream* stream, Position_Report_Parameters_Core_1* p)
{
    if (Bitstream_Normal(stream, POSITION_REPORT_PARAMETERS_CORE_1_CORE_BITSIZE))
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

int Position_Report_Parameters_Core_1_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Position_Report_Parameters_Core_1* p)
{

    return 0;
}

int Position_Report_Parameters_Core_1_Decode_Int(const Packet_Info* data, const kcg_int* stream, Position_Report_Parameters_Core_1* p)
{

    return 0;
}

