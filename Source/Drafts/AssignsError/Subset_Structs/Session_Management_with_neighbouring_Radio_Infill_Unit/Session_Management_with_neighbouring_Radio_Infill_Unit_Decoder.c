
#include "Session_Management_with_neighbouring_Radio_Infill_Unit_Decoder.h"
#include "Bitstream_Read.h"

int Session_Management_with_neighbouring_Radio_Infill_Unit_Decoder(Bitstream* stream, Session_Management_with_neighbouring_Radio_Infill_Unit* p)
{
    if (NormalBitstream(stream, SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

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
	  requires Q_RIU:          stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_RIU;
	  ensures  Q_RIU:          stream->bitpos == pos + 16;
	  ensures  Q_RIU:          EqualBits(stream, pos + 15, pos + 16, p->Q_RIU);
	  ensures  Q_RIU:          UpperBitsNotSet(p->Q_RIU, 1);
	*/
	{ p->Q_RIU		= Bitstream_Read(stream, 1); }

	/*@
	  requires NID_C:          stream->bitpos == pos + 16;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_C;
	  ensures  NID_C:          stream->bitpos == pos + 26;
	  ensures  NID_C:          EqualBits(stream, pos + 16, pos + 26, p->NID_C);
	  ensures  NID_C:          UpperBitsNotSet(p->NID_C, 10);
	*/
	{ p->NID_C		= Bitstream_Read(stream, 10); }

	/*@
	  requires NID_RIU:        stream->bitpos == pos + 26;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_RIU;
	  ensures  NID_RIU:        stream->bitpos == pos + 40;
	  ensures  NID_RIU:        EqualBits(stream, pos + 26, pos + 40, p->NID_RIU);
	  ensures  NID_RIU:        UpperBitsNotSet(p->NID_RIU, 14);
	*/
	{ p->NID_RIU		= Bitstream_Read(stream, 14); }

	/*@
	  requires NID_RADIO:      stream->bitpos == pos + 40;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_RADIO;
	  ensures  NID_RADIO:      stream->bitpos == pos + 104;
	  ensures  NID_RADIO:      EqualBits(stream, pos + 40, pos + 104, p->NID_RADIO);
	  ensures  NID_RADIO:      UpperBitsNotSet(p->NID_RADIO, 64);
	*/
	{ p->NID_RADIO		= Bitstream_Read(stream, 64); }



        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_RIU:             EqualBits(stream, pos + 15,  pos + 16,  p->Q_RIU);
        //@ assert NID_C:             EqualBits(stream, pos + 16,  pos + 26,  p->NID_C);
        //@ assert NID_RIU:           EqualBits(stream, pos + 26,  pos + 40,  p->NID_RIU);
        //@ assert NID_RADIO:         EqualBits(stream, pos + 40,  pos + 104, p->NID_RADIO);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_RIU:             UpperBitsNotSet(p->Q_RIU,             1);
        //@ assert NID_C:             UpperBitsNotSet(p->NID_C,             10);
        //@ assert NID_RIU:           UpperBitsNotSet(p->NID_RIU,           14);
        //@ assert NID_RADIO:         UpperBitsNotSet(p->NID_RADIO,         64);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

