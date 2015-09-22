
#include "Axle_Load_Speed_Profile_Core_2_1.h"
#include "Bit64.h"

int Axle_Load_Speed_Profile_Core_2_1_UpperBitsNotSet(const Axle_Load_Speed_Profile_Core_2_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->M_AXLELOADCAT,     7) ;
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

int Axle_Load_Speed_Profile_Core_2_1_Encode_Bit(Bitstream* stream, const Axle_Load_Speed_Profile_Core_2_1* p)
{
    if (Bitstream_Normal(stream, AXLE_LOAD_SPEED_PROFILE_CORE_2_1_CORE_BITSIZE))
    {
        if (Axle_Load_Speed_Profile_Core_2_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 7,  p->M_AXLELOADCAT);
            Bitstream_Write(stream, 7,  p->V_AXLELOAD);


            //@ assert M_AXLELOADCAT:     EqualBits(stream, pos,       pos + 7,   p->M_AXLELOADCAT);
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

int Axle_Load_Speed_Profile_Core_2_1_Decode_Bit(Bitstream* stream, Axle_Load_Speed_Profile_Core_2_1* p)
{
    if (Bitstream_Normal(stream, AXLE_LOAD_SPEED_PROFILE_CORE_2_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires M_AXLELOADCAT:  stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->M_AXLELOADCAT;
          ensures  M_AXLELOADCAT:  stream->bitpos == pos + 7;
          ensures  M_AXLELOADCAT:  EqualBits(stream, pos + 0, pos + 7, p->M_AXLELOADCAT);
          ensures  M_AXLELOADCAT:  UpperBitsNotSet(p->M_AXLELOADCAT, 7);
        */
        {
            p->M_AXLELOADCAT        = Bitstream_Read(stream, 7);
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

        //@ assert M_AXLELOADCAT:     EqualBits(stream, pos,       pos + 7,   p->M_AXLELOADCAT);
        //@ assert V_AXLELOAD:        EqualBits(stream, pos + 7,   pos + 14,  p->V_AXLELOAD);

        //@ assert M_AXLELOADCAT:     UpperBitsNotSet(p->M_AXLELOADCAT,     7);
        //@ assert V_AXLELOAD:        UpperBitsNotSet(p->V_AXLELOAD,        7);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Axle_Load_Speed_Profile_Core_2_1_Encode_Int(PacketInfo* data, kcg_int* stream, const Axle_Load_Speed_Profile_Core_2_1* p)
{
    return 0;
}

int Axle_Load_Speed_Profile_Core_2_1_Decode_Int(PacketInfo* data, const kcg_int* stream, Axle_Load_Speed_Profile_Core_2_1* p)
{
    return 0;
}

