
#include "Train_running_number_Core.h"
#include "Bit64.h"

int Train_running_number_UpperBitsNotSet(const Train_running_number_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_OPERATIONAL,   32);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Train_running_number_Encode_Bit(Bitstream* stream, const Train_running_number_Core* p)
{
    if (Bitstream_Normal(stream, TRAIN_RUNNING_NUMBER_CORE_BITSIZE))
    {
        if (Train_running_number_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 32, p->NID_OPERATIONAL);


            //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
            //@ assert NID_OPERATIONAL:   EqualBits(stream, pos + 13,  pos + 45,  p->NID_OPERATIONAL);

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

int Train_running_number_Decode_Bit(Bitstream* stream, Train_running_number_Core* p)
{
    if (Bitstream_Normal(stream, TRAIN_RUNNING_NUMBER_CORE_BITSIZE))
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
          requires NID_OPERATIONAL: stream->bitpos == pos + 13;
          assigns                  stream->bitpos;
          assigns                  p->NID_OPERATIONAL;
          ensures  NID_OPERATIONAL: stream->bitpos == pos + 45;
          ensures  NID_OPERATIONAL: EqualBits(stream, pos + 13, pos + 45, p->NID_OPERATIONAL);
          ensures  NID_OPERATIONAL: UpperBitsNotSet(p->NID_OPERATIONAL, 32);
        */
        {
            p->NID_OPERATIONAL        = Bitstream_Read(stream, 32);
        }

        //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
        //@ assert NID_OPERATIONAL:   EqualBits(stream, pos + 13,  pos + 45,  p->NID_OPERATIONAL);

        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert NID_OPERATIONAL:   UpperBitsNotSet(p->NID_OPERATIONAL,   32);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Train_running_number_Encode_Int(Packet_Info* data, kcg_int* stream, const Train_running_number_Core* p)
{
    stream[data->startAddress++] = p->L_PACKET;
    stream[data->startAddress++] = p->NID_OPERATIONAL;

    return 1;
}

int Train_running_number_Decode_Int(Packet_Info* data, const kcg_int* stream, Train_running_number_Core* p)
{
    p->L_PACKET = stream[data->startAddress++];
    p->NID_OPERATIONAL = stream[data->startAddress++];

    return 1;
}

