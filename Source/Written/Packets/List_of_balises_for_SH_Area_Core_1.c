
#include "List_of_balises_for_SH_Area_Core_1.h"
#include "Bit64.h"

int List_of_balises_for_SH_Area_Core_1_UpperBitsNotSet(const List_of_balises_for_SH_Area_Core_1* p)
{
    bool status = true;

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

int List_of_balises_for_SH_Area_Core_1_Encode_Bit(Bitstream* stream, const List_of_balises_for_SH_Area_Core_1* p)
{
    if (Bitstream_Normal(stream, LIST_OF_BALISES_FOR_SH_AREA_CORE_1_CORE_BITSIZE))
    {
        if (List_of_balises_for_SH_Area_Core_1_UpperBitsNotSet(p))
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

int List_of_balises_for_SH_Area_Core_1_Decode_Bit(Bitstream* stream, List_of_balises_for_SH_Area_Core_1* p)
{
    if (Bitstream_Normal(stream, LIST_OF_BALISES_FOR_SH_AREA_CORE_1_CORE_BITSIZE))
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

int List_of_balises_for_SH_Area_Core_1_Encode_Int(PacketInfo* data, kcg_int* stream, const List_of_balises_for_SH_Area_Core_1* p)
{
    stream[data->startAddress++] = p->Q_NEWCOUNTRY;
    stream[data->startAddress++] = p->NID_C;
    stream[data->startAddress++] = p->NID_BG;

    return 1;
}

int List_of_balises_for_SH_Area_Core_1_Decode_Int(PacketInfo* data, const kcg_int* stream, List_of_balises_for_SH_Area_Core_1* p)
{
    p->Q_NEWCOUNTRY = stream[data->startAddress++];
    p->NID_C = stream[data->startAddress++];
    p->NID_BG = stream[data->startAddress++];

    return 1;
}

