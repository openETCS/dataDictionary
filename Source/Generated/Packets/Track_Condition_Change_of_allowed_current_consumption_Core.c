
#include "Track_Condition_Change_of_allowed_current_consumption_Core.h"
#include "Bit64.h"

int Track_Condition_Change_of_allowed_current_consumption_UpperBitsNotSet(const Track_Condition_Change_of_allowed_current_consumption_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_CURRENT,         15);
    status = status && UpperBitsNotSet64(p->M_CURRENT,         10);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Track_Condition_Change_of_allowed_current_consumption_Encode_Bit(Bitstream* stream, const Track_Condition_Change_of_allowed_current_consumption_Core* p)
{
    if (Bitstream_Normal(stream, TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_CORE_BITSIZE))
    {
        if (Track_Condition_Change_of_allowed_current_consumption_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_CURRENT);
            Bitstream_Write(stream, 10, p->M_CURRENT);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_CURRENT:         EqualBits(stream, pos + 17,  pos + 32,  p->D_CURRENT);
            //@ assert M_CURRENT:         EqualBits(stream, pos + 32,  pos + 42,  p->M_CURRENT);

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

int Track_Condition_Change_of_allowed_current_consumption_Decode_Bit(Bitstream* stream, Track_Condition_Change_of_allowed_current_consumption_Core* p)
{
    if (Bitstream_Normal(stream, TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_CORE_BITSIZE))
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
          requires Q_SCALE:        stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->Q_SCALE;
          ensures  Q_SCALE:        stream->bitpos == pos + 17;
          ensures  Q_SCALE:        EqualBits(stream, pos + 15, pos + 17, p->Q_SCALE);
          ensures  Q_SCALE:        UpperBitsNotSet(p->Q_SCALE, 2);
        */
        {
            p->Q_SCALE        = Bitstream_Read(stream, 2);
        }

        /*@
          requires D_CURRENT:      stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_CURRENT;
          ensures  D_CURRENT:      stream->bitpos == pos + 32;
          ensures  D_CURRENT:      EqualBits(stream, pos + 17, pos + 32, p->D_CURRENT);
          ensures  D_CURRENT:      UpperBitsNotSet(p->D_CURRENT, 15);
        */
        {
            p->D_CURRENT        = Bitstream_Read(stream, 15);
        }

        /*@
          requires M_CURRENT:      stream->bitpos == pos + 32;
          assigns                  stream->bitpos;
          assigns                  p->M_CURRENT;
          ensures  M_CURRENT:      stream->bitpos == pos + 42;
          ensures  M_CURRENT:      EqualBits(stream, pos + 32, pos + 42, p->M_CURRENT);
          ensures  M_CURRENT:      UpperBitsNotSet(p->M_CURRENT, 10);
        */
        {
            p->M_CURRENT        = Bitstream_Read(stream, 10);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_CURRENT:         EqualBits(stream, pos + 17,  pos + 32,  p->D_CURRENT);
        //@ assert M_CURRENT:         EqualBits(stream, pos + 32,  pos + 42,  p->M_CURRENT);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_CURRENT:         UpperBitsNotSet(p->D_CURRENT,         15);
        //@ assert M_CURRENT:         UpperBitsNotSet(p->M_CURRENT,         10);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Track_Condition_Change_of_allowed_current_consumption_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Track_Condition_Change_of_allowed_current_consumption_Core* p)
{
    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->D_CURRENT;
    stream[startAddress++] = p->M_CURRENT;

    data->endAddress = startAddress-1;

    return 1;
}

int Track_Condition_Change_of_allowed_current_consumption_Decode_Int(const Packet_Info* data, const kcg_int* stream, Track_Condition_Change_of_allowed_current_consumption_Core* p)
{
    kcg_int startAddress = data->startAddress+1;

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->D_CURRENT = stream[startAddress++];
    p->M_CURRENT = stream[startAddress++];

    if(data->endAddress != startAddress-1)
    {
        return false;
    }

    return 1;
}

