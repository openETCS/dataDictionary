
#include "Level_23_transition_information_Core.h"
#include "Bit64.h"

int Level_23_transition_information_UpperBitsNotSet(const Level_23_transition_information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_LTRBG,         24);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Level_23_transition_information_Encode_Bit(Bitstream* stream, const Level_23_transition_information_Core* p)
{
    if (Bitstream_Normal(stream, LEVEL_23_TRANSITION_INFORMATION_CORE_BITSIZE))
    {
        if (Level_23_transition_information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 24, p->NID_LTRBG);


            //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
            //@ assert NID_LTRBG:         EqualBits(stream, pos + 13,  pos + 37,  p->NID_LTRBG);

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

int Level_23_transition_information_Decode_Bit(Bitstream* stream, Level_23_transition_information_Core* p)
{
    if (Bitstream_Normal(stream, LEVEL_23_TRANSITION_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires L_PACKET:       stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->L_PACKET;
          ensures  L_PACKET:       stream->bitpos == pos + 13;
          ensures  L_PACKET:       EqualBits(stream, pos + 0, pos + 13, p->L_PACKET);
          ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
        */
        {
            p->L_PACKET        = Bitstream_Read(stream, 13);
        }

        /*@
          requires NID_LTRBG:      stream->bitpos == pos + 13;
          assigns                  stream->bitpos;
          assigns                  p->NID_LTRBG;
          ensures  NID_LTRBG:      stream->bitpos == pos + 37;
          ensures  NID_LTRBG:      EqualBits(stream, pos + 13, pos + 37, p->NID_LTRBG);
          ensures  NID_LTRBG:      UpperBitsNotSet(p->NID_LTRBG, 24);
        */
        {
            p->NID_LTRBG        = Bitstream_Read(stream, 24);
        }

        //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
        //@ assert NID_LTRBG:         EqualBits(stream, pos + 13,  pos + 37,  p->NID_LTRBG);

        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert NID_LTRBG:         UpperBitsNotSet(p->NID_LTRBG,         24);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Level_23_transition_information_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Level_23_transition_information_Core* p)
{

    return 0;
}

int Level_23_transition_information_Decode_Int(const Packet_Info* data, const kcg_int* stream, Level_23_transition_information_Core* p)
{

    return 0;
}

