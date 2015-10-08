
#include "International_Static_Speed_Profile_Core_2_1.h"
#include "Bit64.h"

int International_Static_Speed_Profile_Core_2_1_UpperBitsNotSet(const International_Static_Speed_Profile_Core_2_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->NC_DIFF,           4) ;
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

int International_Static_Speed_Profile_Core_2_1_Encode_Bit(Bitstream* stream, const International_Static_Speed_Profile_Core_2_1* p)
{
    if (Bitstream_Normal(stream, INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_1_CORE_BITSIZE))
    {
        if (International_Static_Speed_Profile_Core_2_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 4,  p->NC_DIFF);
            Bitstream_Write(stream, 7,  p->V_DIFF);


            //@ assert NC_DIFF:           EqualBits(stream, pos,       pos + 4,   p->NC_DIFF);
            //@ assert V_DIFF:            EqualBits(stream, pos + 4,   pos + 11,  p->V_DIFF);

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

int International_Static_Speed_Profile_Core_2_1_Decode_Bit(Bitstream* stream, International_Static_Speed_Profile_Core_2_1* p)
{
    if (Bitstream_Normal(stream, INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires NC_DIFF:        stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->NC_DIFF;
          ensures  NC_DIFF:        stream->bitpos == pos + 4;
          ensures  NC_DIFF:        EqualBits(stream, pos + 0, pos + 4, p->NC_DIFF);
          ensures  NC_DIFF:        UpperBitsNotSet(p->NC_DIFF, 4);
        */
        {
            p->NC_DIFF        = Bitstream_Read(stream, 4);
        }

        /*@
          requires V_DIFF:         stream->bitpos == pos + 4;
          assigns                  stream->bitpos;
          assigns                  p->V_DIFF;
          ensures  V_DIFF:         stream->bitpos == pos + 11;
          ensures  V_DIFF:         EqualBits(stream, pos + 4, pos + 11, p->V_DIFF);
          ensures  V_DIFF:         UpperBitsNotSet(p->V_DIFF, 7);
        */
        {
            p->V_DIFF        = Bitstream_Read(stream, 7);
        }

        //@ assert NC_DIFF:           EqualBits(stream, pos,       pos + 4,   p->NC_DIFF);
        //@ assert V_DIFF:            EqualBits(stream, pos + 4,   pos + 11,  p->V_DIFF);

        //@ assert NC_DIFF:           UpperBitsNotSet(p->NC_DIFF,           4);
        //@ assert V_DIFF:            UpperBitsNotSet(p->V_DIFF,            7);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int International_Static_Speed_Profile_Core_2_1_Encode_Int(PacketInfo* data, kcg_int* stream, const International_Static_Speed_Profile_Core_2_1* p)
{
    return 0;
}

int International_Static_Speed_Profile_Core_2_1_Decode_Int(PacketInfo* data, const kcg_int* stream, International_Static_Speed_Profile_Core_2_1* p)
{
    return 0;
}

