
#include "Track_Condition_Big_Metal_Masses_Core_1.h"
#include "Bit64.h"

int Track_Condition_Big_Metal_Masses_Core_1_UpperBitsNotSet(const Track_Condition_Big_Metal_Masses_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_TRACKCOND,       15);
    status = status && UpperBitsNotSet64(p->L_TRACKCOND,       15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Track_Condition_Big_Metal_Masses_Core_1_Encode_Bit(Bitstream* stream, const Track_Condition_Big_Metal_Masses_Core_1* p)
{
    if (Bitstream_Normal(stream, TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_BITSIZE))
    {
        if (Track_Condition_Big_Metal_Masses_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_TRACKCOND);
            Bitstream_Write(stream, 15, p->L_TRACKCOND);


            //@ assert D_TRACKCOND:       EqualBits(stream, pos,       pos + 15,  p->D_TRACKCOND);
            //@ assert L_TRACKCOND:       EqualBits(stream, pos + 15,  pos + 30,  p->L_TRACKCOND);

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

int Track_Condition_Big_Metal_Masses_Core_1_Decode_Bit(Bitstream* stream, Track_Condition_Big_Metal_Masses_Core_1* p)
{
    if (Bitstream_Normal(stream, TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires D_TRACKCOND:    stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->D_TRACKCOND;
          ensures  D_TRACKCOND:    stream->bitpos == pos + 15;
          ensures  D_TRACKCOND:    EqualBits(stream, pos + 0, pos + 15, p->D_TRACKCOND);
          ensures  D_TRACKCOND:    UpperBitsNotSet(p->D_TRACKCOND, 15);
        */
        {
            p->D_TRACKCOND        = Bitstream_Read(stream, 15);
        }

        /*@
          requires L_TRACKCOND:    stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->L_TRACKCOND;
          ensures  L_TRACKCOND:    stream->bitpos == pos + 30;
          ensures  L_TRACKCOND:    EqualBits(stream, pos + 15, pos + 30, p->L_TRACKCOND);
          ensures  L_TRACKCOND:    UpperBitsNotSet(p->L_TRACKCOND, 15);
        */
        {
            p->L_TRACKCOND        = Bitstream_Read(stream, 15);
        }

        //@ assert D_TRACKCOND:       EqualBits(stream, pos,       pos + 15,  p->D_TRACKCOND);
        //@ assert L_TRACKCOND:       EqualBits(stream, pos + 15,  pos + 30,  p->L_TRACKCOND);

        //@ assert D_TRACKCOND:       UpperBitsNotSet(p->D_TRACKCOND,       15);
        //@ assert L_TRACKCOND:       UpperBitsNotSet(p->L_TRACKCOND,       15);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Track_Condition_Big_Metal_Masses_Core_1_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Track_Condition_Big_Metal_Masses_Core_1* p)
{
    std::cerr << "encode int function not implemented for packet " << 67 << " yet." << std::endl;
    return 0;
}

int Track_Condition_Big_Metal_Masses_Core_1_Decode_Int(const Packet_Info* data, const kcg_int* stream, Track_Condition_Big_Metal_Masses_Core_1* p)
{
    std::cerr << "decode int function not implemented for packet " << 67 << " yet." << std::endl;
    return 0;
}

