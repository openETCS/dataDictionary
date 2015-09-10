
#include "Reversing_supervision_information_Core.h"
#include "Bit64.h"

int Reversing_supervision_information_UpperBitsNotSet(const Reversing_supervision_information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_REVERSE,         15);
    status = status && UpperBitsNotSet64(p->V_REVERSE,         7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Reversing_supervision_information_Encoder(Bitstream* stream, const Reversing_supervision_information_Core* p)
{
    if (Bitstream_Normal(stream, REVERSING_SUPERVISION_INFORMATION_CORE_BITSIZE))
    {
        if (Reversing_supervision_information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_REVERSE);
            Bitstream_Write(stream, 7,  p->V_REVERSE);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_REVERSE:         EqualBits(stream, pos + 17,  pos + 32,  p->D_REVERSE);
            //@ assert V_REVERSE:         EqualBits(stream, pos + 32,  pos + 39,  p->V_REVERSE);

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

int Reversing_supervision_information_Decoder(Bitstream* stream, Reversing_supervision_information_Core* p)
{
    if (Bitstream_Normal(stream, REVERSING_SUPERVISION_INFORMATION_CORE_BITSIZE))
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
          requires D_REVERSE:      stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_REVERSE;
          ensures  D_REVERSE:      stream->bitpos == pos + 32;
          ensures  D_REVERSE:      EqualBits(stream, pos + 17, pos + 32, p->D_REVERSE);
          ensures  D_REVERSE:      UpperBitsNotSet(p->D_REVERSE, 15);
        */
        {
            p->D_REVERSE        = Bitstream_Read(stream, 15);
        }

        /*@
          requires V_REVERSE:      stream->bitpos == pos + 32;
          assigns                  stream->bitpos;
          assigns                  p->V_REVERSE;
          ensures  V_REVERSE:      stream->bitpos == pos + 39;
          ensures  V_REVERSE:      EqualBits(stream, pos + 32, pos + 39, p->V_REVERSE);
          ensures  V_REVERSE:      UpperBitsNotSet(p->V_REVERSE, 7);
        */
        {
            p->V_REVERSE        = Bitstream_Read(stream, 7);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_REVERSE:         EqualBits(stream, pos + 17,  pos + 32,  p->D_REVERSE);
        //@ assert V_REVERSE:         EqualBits(stream, pos + 32,  pos + 39,  p->V_REVERSE);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_REVERSE:         UpperBitsNotSet(p->D_REVERSE,         15);
        //@ assert V_REVERSE:         UpperBitsNotSet(p->V_REVERSE,         7);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

