
#include "Session_Management_Core.h"
#include "Bit64.h"

int Session_Management_UpperBitsNotSet(const Session_Management_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_RBC,             1) ;
    if (p->NID_RBC != 16383)
    {
        status = status && UpperBitsNotSet64(p->NID_C,             10);
    }
    status = status && UpperBitsNotSet64(p->NID_RBC,           14);
    if (p->NID_RBC != 16383)
    {
        status = status && UpperBitsNotSet64(p->NID_RADIO,         64);
    }
    status = status && UpperBitsNotSet64(p->Q_SLEEPSESSION,    1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Session_Management_Encode_Bit(Bitstream* stream, const Session_Management_Core* p)
{
    if (Bitstream_Normal(stream, SESSION_MANAGEMENT_CORE_BITSIZE))
    {
        if (Session_Management_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_RBC);
            if (p->NID_RBC != 16383)
            {
                Bitstream_Write(stream, 10, p->NID_C);
            }

            Bitstream_Write(stream, 14, p->NID_RBC);
            if (p->NID_RBC != 16383)
            {
                Bitstream_Write(stream, 64, p->NID_RADIO);
            }

            Bitstream_Write(stream, 1,  p->Q_SLEEPSESSION);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_RBC:             EqualBits(stream, pos + 15,  pos + 16,  p->Q_RBC);

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

int Session_Management_Decode_Bit(Bitstream* stream, Session_Management_Core* p)
{
    if (Bitstream_Normal(stream, SESSION_MANAGEMENT_CORE_BITSIZE))
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
          requires Q_RBC:          stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->Q_RBC;
          ensures  Q_RBC:          stream->bitpos == pos + 16;
          ensures  Q_RBC:          EqualBits(stream, pos + 15, pos + 16, p->Q_RBC);
          ensures  Q_RBC:          UpperBitsNotSet(p->Q_RBC, 1);
        */
        {
            p->Q_RBC        = Bitstream_Read(stream, 1);
        }

        if (p->NID_RBC != 16383)
        {
            {
                p->NID_C        = Bitstream_Read(stream, 10);
            }

        }

        {
            p->NID_RBC        = Bitstream_Read(stream, 14);
        }

        if (p->NID_RBC != 16383)
        {
            {
                p->NID_RADIO        = Bitstream_Read(stream, 64);
            }

        }

        {
            p->Q_SLEEPSESSION        = Bitstream_Read(stream, 1);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_RBC:             EqualBits(stream, pos + 15,  pos + 16,  p->Q_RBC);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_RBC:             UpperBitsNotSet(p->Q_RBC,             1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Session_Management_Encode_Int(PacketInfo* data, kcg_int* stream, const Session_Management_Core* p)
{
    return 0;
}

int Session_Management_Decode_Int(PacketInfo* data, const kcg_int* stream, Session_Management_Core* p)
{
    return 0;
}

