
#include "Axle_Load_Speed_Profile_Core_1.h"
#include "Bit64.h"

int Axle_Load_Speed_Profile_Core_1_UpperBitsNotSet(const Axle_Load_Speed_Profile_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->M_AXLELOAD,        7) ;
    status = status && UpperBitsNotSet64(p->V_AXLELOAD,        7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Axle_Load_Speed_Profile_Core_1_Encode_Bit(Bitstream* stream, const Axle_Load_Speed_Profile_Core_1* p)
{
    if (Bitstream_Normal(stream, AXLE_LOAD_SPEED_PROFILE_CORE_1_CORE_BITSIZE))
    {
        if (Axle_Load_Speed_Profile_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 7,  p->M_AXLELOAD);
            Bitstream_Write(stream, 7,  p->V_AXLELOAD);


            //@ assert M_AXLELOAD:        EqualBits(stream, pos,       pos + 7,   p->M_AXLELOAD);
            //@ assert V_AXLELOAD:        EqualBits(stream, pos + 7,   pos + 14,  p->V_AXLELOAD);

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

int Axle_Load_Speed_Profile_Core_1_Decode_Bit(Bitstream* stream, Axle_Load_Speed_Profile_Core_1* p)
{
    if (Bitstream_Normal(stream, AXLE_LOAD_SPEED_PROFILE_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires M_AXLELOAD:     stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->M_AXLELOAD;
          ensures  M_AXLELOAD:     stream->bitpos == pos + 7;
          ensures  M_AXLELOAD:     EqualBits(stream, pos + 0, pos + 7, p->M_AXLELOAD);
          ensures  M_AXLELOAD:     UpperBitsNotSet(p->M_AXLELOAD, 7);
        */
        {
            p->M_AXLELOAD        = Bitstream_Read(stream, 7);
        }

        /*@
          requires V_AXLELOAD:     stream->bitpos == pos + 7;
          assigns                  stream->bitpos;
          assigns                  p->V_AXLELOAD;
          ensures  V_AXLELOAD:     stream->bitpos == pos + 14;
          ensures  V_AXLELOAD:     EqualBits(stream, pos + 7, pos + 14, p->V_AXLELOAD);
          ensures  V_AXLELOAD:     UpperBitsNotSet(p->V_AXLELOAD, 7);
        */
        {
            p->V_AXLELOAD        = Bitstream_Read(stream, 7);
        }

        //@ assert M_AXLELOAD:        EqualBits(stream, pos,       pos + 7,   p->M_AXLELOAD);
        //@ assert V_AXLELOAD:        EqualBits(stream, pos + 7,   pos + 14,  p->V_AXLELOAD);

        //@ assert M_AXLELOAD:        UpperBitsNotSet(p->M_AXLELOAD,        7);
        //@ assert V_AXLELOAD:        UpperBitsNotSet(p->V_AXLELOAD,        7);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Axle_Load_Speed_Profile_Core_1_Encode_Int(PacketInfo* data, kcg_int* stream, const Axle_Load_Speed_Profile_Core_1* p)
{
    return 0;
}

int Axle_Load_Speed_Profile_Core_1_Decode_Int(PacketInfo* data, const kcg_int* stream, Axle_Load_Speed_Profile_Core_1* p)
{
    return 0;
}

