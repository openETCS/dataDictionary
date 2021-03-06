
#include "Geographical_Position_Information_Core_1.h"
#include "Bit64.h"

int Geographical_Position_Information_Core_1_UpperBitsNotSet(const Geographical_Position_Information_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY,      1) ;

    if (p->Q_NEWCOUNTRY == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_C,             10);
    }

    status = status && UpperBitsNotSet64(p->NID_BG,            14);
    status = status && UpperBitsNotSet64(p->D_POSOFF,          15);
    status = status && UpperBitsNotSet64(p->Q_MPOSITION,       1) ;
    status = status && UpperBitsNotSet64(p->M_POSITION,        24);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Geographical_Position_Information_Core_1_Encode_Bit(Bitstream* stream, const Geographical_Position_Information_Core_1* p)
{
    if (Bitstream_Normal(stream, GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_CORE_BITSIZE))
    {
        if (Geographical_Position_Information_Core_1_UpperBitsNotSet(p))
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
            Bitstream_Write(stream, 24, p->M_POSITION);


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

int Geographical_Position_Information_Core_1_Decode_Bit(Bitstream* stream, Geographical_Position_Information_Core_1* p)
{
    if (Bitstream_Normal(stream, GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_CORE_BITSIZE))
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
            p->M_POSITION        = Bitstream_Read(stream, 24);
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

int Geographical_Position_Information_Core_1_Encode_Int(PacketInfo* data, kcg_int* stream, const Geographical_Position_Information_Core_1* p)
{
    stream[data->startAddress++] = p->Q_NEWCOUNTRY;
    stream[data->startAddress++] = p->NID_C;
    stream[data->startAddress++] = p->NID_BG;
    stream[data->startAddress++] = p->D_POSOFF;
    stream[data->startAddress++] = p->Q_MPOSITION;
    stream[data->startAddress++] = p->M_POSITION;

    return 1;
}

int Geographical_Position_Information_Core_1_Decode_Int(PacketInfo* data, const kcg_int* stream, Geographical_Position_Information_Core_1* p)
{
    p->Q_NEWCOUNTRY = stream[data->startAddress++];
    p->NID_C = stream[data->startAddress++];
    p->NID_BG = stream[data->startAddress++];
    p->D_POSOFF = stream[data->startAddress++];
    p->Q_MPOSITION = stream[data->startAddress++];
    p->M_POSITION = stream[data->startAddress++];

    return 1;
}

