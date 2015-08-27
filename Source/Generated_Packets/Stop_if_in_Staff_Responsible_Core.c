
#include "Stop_if_in_Staff_Responsible_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"
#include "Bitstream_Normal.h"

int Stop_if_in_Staff_Responsible_UpperBitsNotSet(const Stop_if_in_Staff_Responsible_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SRSTOP,          1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Stop_if_in_Staff_Responsible_Encoder(Bitstream* stream, const Stop_if_in_Staff_Responsible_Core* p)
{
    if (Bitstream_Normal(stream, STOP_IF_IN_STAFF_RESPONSIBLE_CORE_BITSIZE))
    {
        if (Stop_if_in_Staff_Responsible_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_SRSTOP);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SRSTOP:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_SRSTOP);

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

int Stop_if_in_Staff_Responsible_Decoder(Bitstream* stream, Stop_if_in_Staff_Responsible_Core* p)
{
    if (Bitstream_Normal(stream, STOP_IF_IN_STAFF_RESPONSIBLE_CORE_BITSIZE))
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
	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	/*@
	  requires L_PACKET:       stream->bitpos == pos + 2;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_PACKET;
	  ensures  L_PACKET:       stream->bitpos == pos + 15;
	  ensures  L_PACKET:       EqualBits(stream, pos + 2, pos + 15, p->L_PACKET);
	  ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
	*/
	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	/*@
	  requires Q_SRSTOP:       stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_SRSTOP;
	  ensures  Q_SRSTOP:       stream->bitpos == pos + 16;
	  ensures  Q_SRSTOP:       EqualBits(stream, pos + 15, pos + 16, p->Q_SRSTOP);
	  ensures  Q_SRSTOP:       UpperBitsNotSet(p->Q_SRSTOP, 1);
	*/
	{ p->Q_SRSTOP		= Bitstream_Read(stream, 1); }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SRSTOP:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_SRSTOP);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SRSTOP:          UpperBitsNotSet(p->Q_SRSTOP,          1);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

