
#include "RBC_transition_order_Core.h"
#include "Bit64.h"

int RBC_transition_order_UpperBitsNotSet(const RBC_transition_order_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_RBCTR,           15);
    status = status && UpperBitsNotSet64(p->NID_C,             10);
    status = status && UpperBitsNotSet64(p->NID_RBC,           14);
    status = status && UpperBitsNotSet64(p->NID_RADIO,         64);
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

int RBC_transition_order_Encoder(Bitstream* stream, const RBC_transition_order_Core* p)
{
    if (Bitstream_Normal(stream, RBC_TRANSITION_ORDER_CORE_BITSIZE))
    {
        if (RBC_transition_order_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_RBCTR);
            Bitstream_Write(stream, 10, p->NID_C);
            Bitstream_Write(stream, 14, p->NID_RBC);
            Bitstream_Write(stream, 64, p->NID_RADIO);
            Bitstream_Write(stream, 1,  p->Q_SLEEPSESSION);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_RBCTR:           EqualBits(stream, pos + 17,  pos + 32,  p->D_RBCTR);
            //@ assert NID_C:             EqualBits(stream, pos + 32,  pos + 42,  p->NID_C);
            //@ assert NID_RBC:           EqualBits(stream, pos + 42,  pos + 56,  p->NID_RBC);
            //@ assert NID_RADIO:         EqualBits(stream, pos + 56,  pos + 120, p->NID_RADIO);
            //@ assert Q_SLEEPSESSION:    EqualBits(stream, pos + 120, pos + 121, p->Q_SLEEPSESSION);

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

int RBC_transition_order_Decoder(Bitstream* stream, RBC_transition_order_Core* p)
{
    if (Bitstream_Normal(stream, RBC_TRANSITION_ORDER_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires Q_DIR:          stream->bitpos == pos + 0;
          assigns        	   stream->bitpos;
          assigns		   p->Q_DIR;
          ensures  Q_DIR:          stream->bitpos == pos + 2;
          ensures  Q_DIR:          EqualBits(stream, pos + 0, pos + 2, p->Q_DIR);
          ensures  Q_DIR:          UpperBitsNotSet(p->Q_DIR, 2);
        */
        {
            p->Q_DIR		= Bitstream_Read(stream, 2);
        }

        /*@
          requires L_PACKET:       stream->bitpos == pos + 2;
          assigns        	   stream->bitpos;
          assigns		   p->L_PACKET;
          ensures  L_PACKET:       stream->bitpos == pos + 15;
          ensures  L_PACKET:       EqualBits(stream, pos + 2, pos + 15, p->L_PACKET);
          ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
        */
        {
            p->L_PACKET		= Bitstream_Read(stream, 13);
        }

        /*@
          requires Q_SCALE:        stream->bitpos == pos + 15;
          assigns        	   stream->bitpos;
          assigns		   p->Q_SCALE;
          ensures  Q_SCALE:        stream->bitpos == pos + 17;
          ensures  Q_SCALE:        EqualBits(stream, pos + 15, pos + 17, p->Q_SCALE);
          ensures  Q_SCALE:        UpperBitsNotSet(p->Q_SCALE, 2);
        */
        {
            p->Q_SCALE		= Bitstream_Read(stream, 2);
        }

        /*@
          requires D_RBCTR:        stream->bitpos == pos + 17;
          assigns        	   stream->bitpos;
          assigns		   p->D_RBCTR;
          ensures  D_RBCTR:        stream->bitpos == pos + 32;
          ensures  D_RBCTR:        EqualBits(stream, pos + 17, pos + 32, p->D_RBCTR);
          ensures  D_RBCTR:        UpperBitsNotSet(p->D_RBCTR, 15);
        */
        {
            p->D_RBCTR		= Bitstream_Read(stream, 15);
        }

        /*@
          requires NID_C:          stream->bitpos == pos + 32;
          assigns        	   stream->bitpos;
          assigns		   p->NID_C;
          ensures  NID_C:          stream->bitpos == pos + 42;
          ensures  NID_C:          EqualBits(stream, pos + 32, pos + 42, p->NID_C);
          ensures  NID_C:          UpperBitsNotSet(p->NID_C, 10);
        */
        {
            p->NID_C		= Bitstream_Read(stream, 10);
        }

        /*@
          requires NID_RBC:        stream->bitpos == pos + 42;
          assigns        	   stream->bitpos;
          assigns		   p->NID_RBC;
          ensures  NID_RBC:        stream->bitpos == pos + 56;
          ensures  NID_RBC:        EqualBits(stream, pos + 42, pos + 56, p->NID_RBC);
          ensures  NID_RBC:        UpperBitsNotSet(p->NID_RBC, 14);
        */
        {
            p->NID_RBC		= Bitstream_Read(stream, 14);
        }

        /*@
          requires NID_RADIO:      stream->bitpos == pos + 56;
          assigns        	   stream->bitpos;
          assigns		   p->NID_RADIO;
          ensures  NID_RADIO:      stream->bitpos == pos + 120;
          ensures  NID_RADIO:      EqualBits(stream, pos + 56, pos + 120, p->NID_RADIO);
          ensures  NID_RADIO:      UpperBitsNotSet(p->NID_RADIO, 64);
        */
        {
            p->NID_RADIO		= Bitstream_Read(stream, 64);
        }

        /*@
          requires Q_SLEEPSESSION: stream->bitpos == pos + 120;
          assigns        	   stream->bitpos;
          assigns		   p->Q_SLEEPSESSION;
          ensures  Q_SLEEPSESSION: stream->bitpos == pos + 121;
          ensures  Q_SLEEPSESSION: EqualBits(stream, pos + 120, pos + 121, p->Q_SLEEPSESSION);
          ensures  Q_SLEEPSESSION: UpperBitsNotSet(p->Q_SLEEPSESSION, 1);
        */
        {
            p->Q_SLEEPSESSION		= Bitstream_Read(stream, 1);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_RBCTR:           EqualBits(stream, pos + 17,  pos + 32,  p->D_RBCTR);
        //@ assert NID_C:             EqualBits(stream, pos + 32,  pos + 42,  p->NID_C);
        //@ assert NID_RBC:           EqualBits(stream, pos + 42,  pos + 56,  p->NID_RBC);
        //@ assert NID_RADIO:         EqualBits(stream, pos + 56,  pos + 120, p->NID_RADIO);
        //@ assert Q_SLEEPSESSION:    EqualBits(stream, pos + 120, pos + 121, p->Q_SLEEPSESSION);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_RBCTR:           UpperBitsNotSet(p->D_RBCTR,           15);
        //@ assert NID_C:             UpperBitsNotSet(p->NID_C,             10);
        //@ assert NID_RBC:           UpperBitsNotSet(p->NID_RBC,           14);
        //@ assert NID_RADIO:         UpperBitsNotSet(p->NID_RADIO,         64);
        //@ assert Q_SLEEPSESSION:    UpperBitsNotSet(p->Q_SLEEPSESSION,    1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

