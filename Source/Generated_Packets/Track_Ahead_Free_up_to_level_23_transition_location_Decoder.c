
#include "Track_Ahead_Free_up_to_level_23_transition_location_Decoder.h"
#include "Bitstream_Read.h"

int Track_Ahead_Free_up_to_level_23_transition_location_Decoder(Bitstream* stream, Track_Ahead_Free_up_to_level_23_transition_location_Core* p)
{
    if (NormalBitstream(stream, TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_CORE_BITSIZE))
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
	  requires Q_NEWCOUNTRY:   stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NEWCOUNTRY;
	  ensures  Q_NEWCOUNTRY:   stream->bitpos == pos + 16;
	  ensures  Q_NEWCOUNTRY:   EqualBits(stream, pos + 15, pos + 16, p->Q_NEWCOUNTRY);
	  ensures  Q_NEWCOUNTRY:   UpperBitsNotSet(p->Q_NEWCOUNTRY, 1);
	*/
	{ p->Q_NEWCOUNTRY		= Bitstream_Read(stream, 1); }

        if (p->Q_NEWCOUNTRY == 1)
        {
	{ p->NID_C		= Bitstream_Read(stream, 10); }
        }

	/*@
	  requires NID_BG:         stream->bitpos == pos + 26;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_BG;
	  ensures  NID_BG:         stream->bitpos == pos + 40;
	  ensures  NID_BG:         EqualBits(stream, pos + 26, pos + 40, p->NID_BG);
	  ensures  NID_BG:         UpperBitsNotSet(p->NID_BG, 14);
	*/
	{ p->NID_BG		= Bitstream_Read(stream, 14); }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos + 15,  pos + 16,  p->Q_NEWCOUNTRY);
        //@ assert NID_BG:            EqualBits(stream, pos + 26,  pos + 40,  p->NID_BG);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_NEWCOUNTRY:      UpperBitsNotSet(p->Q_NEWCOUNTRY,      1);
        //@ assert NID_BG:            UpperBitsNotSet(p->NID_BG,            14);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

