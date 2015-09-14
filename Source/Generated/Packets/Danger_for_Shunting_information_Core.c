
#include "Danger_for_Shunting_information_Core.h"
#include "Bit64.h"

int Danger_for_Shunting_information_UpperBitsNotSet(const Danger_for_Shunting_information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_ASPECT,          1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Danger_for_Shunting_information_Encode_Bit(Bitstream* stream, const Danger_for_Shunting_information_Core* p)
{
    if (Bitstream_Normal(stream, DANGER_FOR_SHUNTING_INFORMATION_CORE_BITSIZE))
    {
        if (Danger_for_Shunting_information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_ASPECT);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_ASPECT:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_ASPECT);

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

int Danger_for_Shunting_information_Decode_Bit(Bitstream* stream, Danger_for_Shunting_information_Core* p)
{
    if (Bitstream_Normal(stream, DANGER_FOR_SHUNTING_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires Q_DIR:          stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->Q_DIR;
          ensures  Q_DIR:          stream->bitpos == pos + 2;
          ensures  Q_DIR:          EqualBits(stream, pos + 0, pos + 2, p->Q_DIR);
          ensures  Q_DIR:          UpperBitsNotSet(p->Q_DIR, 2);
        */
        {
            p->Q_DIR        = Bitstream_Read(stream, 2);
        }

        /*@
          requires L_PACKET:       stream->bitpos == pos + 2;
          assigns                  stream->bitpos;
          assigns                  p->L_PACKET;
          ensures  L_PACKET:       stream->bitpos == pos + 15;
          ensures  L_PACKET:       EqualBits(stream, pos + 2, pos + 15, p->L_PACKET);
          ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
        */
        {
            p->L_PACKET        = Bitstream_Read(stream, 13);
        }

        /*@
          requires Q_ASPECT:       stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->Q_ASPECT;
          ensures  Q_ASPECT:       stream->bitpos == pos + 16;
          ensures  Q_ASPECT:       EqualBits(stream, pos + 15, pos + 16, p->Q_ASPECT);
          ensures  Q_ASPECT:       UpperBitsNotSet(p->Q_ASPECT, 1);
        */
        {
            p->Q_ASPECT        = Bitstream_Read(stream, 1);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_ASPECT:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_ASPECT);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_ASPECT:          UpperBitsNotSet(p->Q_ASPECT,          1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Danger_for_Shunting_information_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Danger_for_Shunting_information_Core* p)
{

    return 0;
}

int Danger_for_Shunting_information_Decode_Int(const Packet_Info* data, const kcg_int* stream, Danger_for_Shunting_information_Core* p)
{

    return 0;
}

