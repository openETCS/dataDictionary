
#include "Movement_Authority_Request_Parameters_Core.h"
#include "Bit64.h"

int Movement_Authority_Request_Parameters_UpperBitsNotSet(const Movement_Authority_Request_Parameters_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->T_MAR,             8) ;
    status = status && UpperBitsNotSet64(p->T_TIMEOUTRQST,     10);
    status = status && UpperBitsNotSet64(p->T_CYCRQST,         8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Movement_Authority_Request_Parameters_Encode_Bit(Bitstream* stream, const Movement_Authority_Request_Parameters_Core* p)
{
    if (Bitstream_Normal(stream, MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_CORE_BITSIZE))
    {
        if (Movement_Authority_Request_Parameters_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 8,  p->T_MAR);
            Bitstream_Write(stream, 10, p->T_TIMEOUTRQST);
            Bitstream_Write(stream, 8,  p->T_CYCRQST);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert T_MAR:             EqualBits(stream, pos + 15,  pos + 23,  p->T_MAR);
            //@ assert T_TIMEOUTRQST:     EqualBits(stream, pos + 23,  pos + 33,  p->T_TIMEOUTRQST);
            //@ assert T_CYCRQST:         EqualBits(stream, pos + 33,  pos + 41,  p->T_CYCRQST);

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

int Movement_Authority_Request_Parameters_Decode_Bit(Bitstream* stream, Movement_Authority_Request_Parameters_Core* p)
{
    if (Bitstream_Normal(stream, MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_CORE_BITSIZE))
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
          requires T_MAR:          stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->T_MAR;
          ensures  T_MAR:          stream->bitpos == pos + 23;
          ensures  T_MAR:          EqualBits(stream, pos + 15, pos + 23, p->T_MAR);
          ensures  T_MAR:          UpperBitsNotSet(p->T_MAR, 8);
        */
        {
            p->T_MAR        = Bitstream_Read(stream, 8);
        }

        /*@
          requires T_TIMEOUTRQST:  stream->bitpos == pos + 23;
          assigns                  stream->bitpos;
          assigns                  p->T_TIMEOUTRQST;
          ensures  T_TIMEOUTRQST:  stream->bitpos == pos + 33;
          ensures  T_TIMEOUTRQST:  EqualBits(stream, pos + 23, pos + 33, p->T_TIMEOUTRQST);
          ensures  T_TIMEOUTRQST:  UpperBitsNotSet(p->T_TIMEOUTRQST, 10);
        */
        {
            p->T_TIMEOUTRQST        = Bitstream_Read(stream, 10);
        }

        /*@
          requires T_CYCRQST:      stream->bitpos == pos + 33;
          assigns                  stream->bitpos;
          assigns                  p->T_CYCRQST;
          ensures  T_CYCRQST:      stream->bitpos == pos + 41;
          ensures  T_CYCRQST:      EqualBits(stream, pos + 33, pos + 41, p->T_CYCRQST);
          ensures  T_CYCRQST:      UpperBitsNotSet(p->T_CYCRQST, 8);
        */
        {
            p->T_CYCRQST        = Bitstream_Read(stream, 8);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert T_MAR:             EqualBits(stream, pos + 15,  pos + 23,  p->T_MAR);
        //@ assert T_TIMEOUTRQST:     EqualBits(stream, pos + 23,  pos + 33,  p->T_TIMEOUTRQST);
        //@ assert T_CYCRQST:         EqualBits(stream, pos + 33,  pos + 41,  p->T_CYCRQST);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert T_MAR:             UpperBitsNotSet(p->T_MAR,             8);
        //@ assert T_TIMEOUTRQST:     UpperBitsNotSet(p->T_TIMEOUTRQST,     10);
        //@ assert T_CYCRQST:         UpperBitsNotSet(p->T_CYCRQST,         8);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Movement_Authority_Request_Parameters_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Movement_Authority_Request_Parameters_Core* p)
{

    return 0;
}

int Movement_Authority_Request_Parameters_Decode_Int(const Packet_Info* data, const kcg_int* stream, Movement_Authority_Request_Parameters_Core* p)
{

    return 0;
}

