
#include "System_Version_order_Core.h"
#include "Bit64.h"

int System_Version_order_UpperBitsNotSet(const System_Version_order_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->M_VERSION,         7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int System_Version_order_Encode_Bit(Bitstream* stream, const System_Version_order_Core* p)
{
    if (Bitstream_Normal(stream, SYSTEM_VERSION_ORDER_CORE_BITSIZE))
    {
        if (System_Version_order_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 7,  p->M_VERSION);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert M_VERSION:         EqualBits(stream, pos + 15,  pos + 22,  p->M_VERSION);

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

int System_Version_order_Decode_Bit(Bitstream* stream, System_Version_order_Core* p)
{
    if (Bitstream_Normal(stream, SYSTEM_VERSION_ORDER_CORE_BITSIZE))
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
          requires M_VERSION:      stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->M_VERSION;
          ensures  M_VERSION:      stream->bitpos == pos + 22;
          ensures  M_VERSION:      EqualBits(stream, pos + 15, pos + 22, p->M_VERSION);
          ensures  M_VERSION:      UpperBitsNotSet(p->M_VERSION, 7);
        */
        {
            p->M_VERSION        = Bitstream_Read(stream, 7);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert M_VERSION:         EqualBits(stream, pos + 15,  pos + 22,  p->M_VERSION);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert M_VERSION:         UpperBitsNotSet(p->M_VERSION,         7);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int System_Version_order_Encode_Int(PacketInfo* data, kcg_int* stream, const System_Version_order_Core* p)
{
    stream[data->startAddress++] = p->Q_DIR;
    stream[data->startAddress++] = p->L_PACKET;
    stream[data->startAddress++] = p->M_VERSION;

    return 1;
}

int System_Version_order_Decode_Int(PacketInfo* data, const kcg_int* stream, System_Version_order_Core* p)
{
    p->Q_DIR = stream[data->startAddress++];
    p->L_PACKET = stream[data->startAddress++];
    p->M_VERSION = stream[data->startAddress++];

    return 1;
}

