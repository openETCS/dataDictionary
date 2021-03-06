
#include "Track_Condition_Change_of_traction_power_Core.h"
#include "Bit64.h"

int Track_Condition_Change_of_traction_power_UpperBitsNotSet(const Track_Condition_Change_of_traction_power_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_TRACTION,        15);
    status = status && UpperBitsNotSet64(p->M_TRACTION,        8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Track_Condition_Change_of_traction_power_Encode_Bit(Bitstream* stream, const Track_Condition_Change_of_traction_power_Core* p)
{
    if (Bitstream_Normal(stream, TRACK_CONDITION_CHANGE_OF_TRACTION_POWER_CORE_BITSIZE))
    {
        if (Track_Condition_Change_of_traction_power_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_TRACTION);
            Bitstream_Write(stream, 8,  p->M_TRACTION);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_TRACTION:        EqualBits(stream, pos + 17,  pos + 32,  p->D_TRACTION);
            //@ assert M_TRACTION:        EqualBits(stream, pos + 32,  pos + 40,  p->M_TRACTION);

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

int Track_Condition_Change_of_traction_power_Decode_Bit(Bitstream* stream, Track_Condition_Change_of_traction_power_Core* p)
{
    if (Bitstream_Normal(stream, TRACK_CONDITION_CHANGE_OF_TRACTION_POWER_CORE_BITSIZE))
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
          requires D_TRACTION:     stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_TRACTION;
          ensures  D_TRACTION:     stream->bitpos == pos + 32;
          ensures  D_TRACTION:     EqualBits(stream, pos + 17, pos + 32, p->D_TRACTION);
          ensures  D_TRACTION:     UpperBitsNotSet(p->D_TRACTION, 15);
        */
        {
            p->D_TRACTION        = Bitstream_Read(stream, 15);
        }

        /*@
          requires M_TRACTION:     stream->bitpos == pos + 32;
          assigns                  stream->bitpos;
          assigns                  p->M_TRACTION;
          ensures  M_TRACTION:     stream->bitpos == pos + 40;
          ensures  M_TRACTION:     EqualBits(stream, pos + 32, pos + 40, p->M_TRACTION);
          ensures  M_TRACTION:     UpperBitsNotSet(p->M_TRACTION, 8);
        */
        {
            p->M_TRACTION        = Bitstream_Read(stream, 8);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_TRACTION:        EqualBits(stream, pos + 17,  pos + 32,  p->D_TRACTION);
        //@ assert M_TRACTION:        EqualBits(stream, pos + 32,  pos + 40,  p->M_TRACTION);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_TRACTION:        UpperBitsNotSet(p->D_TRACTION,        15);
        //@ assert M_TRACTION:        UpperBitsNotSet(p->M_TRACTION,        8);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Track_Condition_Change_of_traction_power_Encode_Int(PacketInfo* data, kcg_int* stream, const Track_Condition_Change_of_traction_power_Core* p)
{
    stream[data->startAddress++] = p->Q_DIR;
    stream[data->startAddress++] = p->L_PACKET;
    stream[data->startAddress++] = p->Q_SCALE;
    stream[data->startAddress++] = p->D_TRACTION;
    stream[data->startAddress++] = p->M_TRACTION;

    return 1;
}

int Track_Condition_Change_of_traction_power_Decode_Int(PacketInfo* data, const kcg_int* stream, Track_Condition_Change_of_traction_power_Core* p)
{
    p->Q_DIR = stream[data->startAddress++];
    p->L_PACKET = stream[data->startAddress++];
    p->Q_SCALE = stream[data->startAddress++];
    p->D_TRACTION = stream[data->startAddress++];
    p->M_TRACTION = stream[data->startAddress++];

    return 1;
}

