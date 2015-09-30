
#include "International_Static_Speed_Profile_Core_1.h"
#include "Bit64.h"

int International_Static_Speed_Profile_Core_1_UpperBitsNotSet(const International_Static_Speed_Profile_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIFF,            2) ;

    if (p->Q_DIFF == 0)
    {
        status = status && UpperBitsNotSet64(p->NC_CDDIFF,         4) ;
    }

    if ((p->Q_DIFF == 1) || (p->Q_DIFF == 2))
    {
        status = status && UpperBitsNotSet64(p->NC_DIFF,           4) ;
    }

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

int International_Static_Speed_Profile_Core_1_Encode_Bit(Bitstream* stream, const International_Static_Speed_Profile_Core_1* p)
{
    if (Bitstream_Normal(stream, INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_1_CORE_BITSIZE))
    {
        if (International_Static_Speed_Profile_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIFF);

            if (p->Q_DIFF == 0)
            {
                Bitstream_Write(stream, 4,  p->NC_CDDIFF);
            }

            if ((p->Q_DIFF == 1) || (p->Q_DIFF == 2))
            {
                Bitstream_Write(stream, 4,  p->NC_DIFF);
            }

            Bitstream_Write(stream, 7,  p->V_DIFF);


            //@ assert Q_DIFF:            EqualBits(stream, pos,       pos + 2,   p->Q_DIFF);

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

int International_Static_Speed_Profile_Core_1_Decode_Bit(Bitstream* stream, International_Static_Speed_Profile_Core_1* p)
{
    if (Bitstream_Normal(stream, INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires Q_DIFF:         stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->Q_DIFF;
          ensures  Q_DIFF:         stream->bitpos == pos + 2;
          ensures  Q_DIFF:         EqualBits(stream, pos + 0, pos + 2, p->Q_DIFF);
          ensures  Q_DIFF:         UpperBitsNotSet(p->Q_DIFF, 2);
        */
        {
            p->Q_DIFF        = Bitstream_Read(stream, 2);
        }

        if (p->Q_DIFF == 0)
        {
            {
                p->NC_CDDIFF        = Bitstream_Read(stream, 4);
            }

        }

        if ((p->Q_DIFF == 1) || (p->Q_DIFF == 2))
        {
            {
                p->NC_DIFF        = Bitstream_Read(stream, 4);
            }

        }

        {
            p->V_DIFF        = Bitstream_Read(stream, 7);
        }

        //@ assert Q_DIFF:            EqualBits(stream, pos,       pos + 2,   p->Q_DIFF);

        //@ assert Q_DIFF:            UpperBitsNotSet(p->Q_DIFF,            2);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int International_Static_Speed_Profile_Core_1_Encode_Int(PacketInfo* data, kcg_int* stream, const International_Static_Speed_Profile_Core_1* p)
{
    stream[data->startAddress++] = p->Q_DIFF;
    stream[data->startAddress++] = p->NC_CDDIFF;
    stream[data->startAddress++] = p->NC_DIFF;
    stream[data->startAddress++] = p->V_DIFF;

    return 1;
}

int International_Static_Speed_Profile_Core_1_Decode_Int(PacketInfo* data, const kcg_int* stream, International_Static_Speed_Profile_Core_1* p)
{
    p->Q_DIFF = stream[data->startAddress++];
    p->NC_CDDIFF = stream[data->startAddress++];
    p->NC_DIFF = stream[data->startAddress++];
    p->V_DIFF = stream[data->startAddress++];

    return 1;
}

