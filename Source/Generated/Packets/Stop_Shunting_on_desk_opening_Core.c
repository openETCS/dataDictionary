
#include "Stop_Shunting_on_desk_opening_Core.h"
#include "Bit64.h"

int Stop_Shunting_on_desk_opening_UpperBitsNotSet(const Stop_Shunting_on_desk_opening_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Stop_Shunting_on_desk_opening_Encode_Bit(Bitstream* stream, const Stop_Shunting_on_desk_opening_Core* p)
{
    if (Bitstream_Normal(stream, STOP_SHUNTING_ON_DESK_OPENING_CORE_BITSIZE))
    {
        if (Stop_Shunting_on_desk_opening_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

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

int Stop_Shunting_on_desk_opening_Decode_Bit(Bitstream* stream, Stop_Shunting_on_desk_opening_Core* p)
{
    if (Bitstream_Normal(stream, STOP_SHUNTING_ON_DESK_OPENING_CORE_BITSIZE))
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

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Stop_Shunting_on_desk_opening_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Stop_Shunting_on_desk_opening_Core* p)
{
    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;

    data->endAddress = startAddress-1;

    return 1;
}

int Stop_Shunting_on_desk_opening_Decode_Int(const Packet_Info* data, const kcg_int* stream, Stop_Shunting_on_desk_opening_Core* p)
{
    kcg_int startAddress = data->startAddress+1;

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];

    if(data->endAddress != startAddress-1)
    {
        return false;
    }

    return 1;
}

