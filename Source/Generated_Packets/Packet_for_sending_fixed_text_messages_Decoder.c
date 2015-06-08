
#include "Packet_for_sending_fixed_text_messages_Decoder.h"
#include "Bitstream_Read.h"

int Packet_for_sending_fixed_text_messages_Decoder(Bitstream* stream, Packet_for_sending_fixed_text_messages_Core* p)
{
    if (NormalBitstream(stream, PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_CORE_BITSIZE))
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
	  requires Q_SCALE:        stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_SCALE;
	  ensures  Q_SCALE:        stream->bitpos == pos + 17;
	  ensures  Q_SCALE:        EqualBits(stream, pos + 15, pos + 17, p->Q_SCALE);
	  ensures  Q_SCALE:        UpperBitsNotSet(p->Q_SCALE, 2);
	*/
	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	/*@
	  requires Q_TEXTCLASS:    stream->bitpos == pos + 17;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_TEXTCLASS;
	  ensures  Q_TEXTCLASS:    stream->bitpos == pos + 19;
	  ensures  Q_TEXTCLASS:    EqualBits(stream, pos + 17, pos + 19, p->Q_TEXTCLASS);
	  ensures  Q_TEXTCLASS:    UpperBitsNotSet(p->Q_TEXTCLASS, 2);
	*/
	{ p->Q_TEXTCLASS		= Bitstream_Read(stream, 2); }

	/*@
	  requires Q_TEXTDISPLAY:  stream->bitpos == pos + 19;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_TEXTDISPLAY;
	  ensures  Q_TEXTDISPLAY:  stream->bitpos == pos + 20;
	  ensures  Q_TEXTDISPLAY:  EqualBits(stream, pos + 19, pos + 20, p->Q_TEXTDISPLAY);
	  ensures  Q_TEXTDISPLAY:  UpperBitsNotSet(p->Q_TEXTDISPLAY, 1);
	*/
	{ p->Q_TEXTDISPLAY		= Bitstream_Read(stream, 1); }

	/*@
	  requires D_TEXTDISPLAY:  stream->bitpos == pos + 20;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_TEXTDISPLAY;
	  ensures  D_TEXTDISPLAY:  stream->bitpos == pos + 35;
	  ensures  D_TEXTDISPLAY:  EqualBits(stream, pos + 20, pos + 35, p->D_TEXTDISPLAY);
	  ensures  D_TEXTDISPLAY:  UpperBitsNotSet(p->D_TEXTDISPLAY, 15);
	*/
	{ p->D_TEXTDISPLAY		= Bitstream_Read(stream, 15); }

	/*@
	  requires M_MODETEXTDISPLAY0: stream->bitpos == pos + 35;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_MODETEXTDISPLAY0;
	  ensures  M_MODETEXTDISPLAY0: stream->bitpos == pos + 39;
	  ensures  M_MODETEXTDISPLAY0: EqualBits(stream, pos + 35, pos + 39, p->M_MODETEXTDISPLAY0);
	  ensures  M_MODETEXTDISPLAY0: UpperBitsNotSet(p->M_MODETEXTDISPLAY0, 4);
	*/
	{ p->M_MODETEXTDISPLAY0		= Bitstream_Read(stream, 4); }

	/*@
	  requires M_LEVELTEXTDISPLAY0: stream->bitpos == pos + 39;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_LEVELTEXTDISPLAY0;
	  ensures  M_LEVELTEXTDISPLAY0: stream->bitpos == pos + 42;
	  ensures  M_LEVELTEXTDISPLAY0: EqualBits(stream, pos + 39, pos + 42, p->M_LEVELTEXTDISPLAY0);
	  ensures  M_LEVELTEXTDISPLAY0: UpperBitsNotSet(p->M_LEVELTEXTDISPLAY0, 3);
	*/
	{ p->M_LEVELTEXTDISPLAY0		= Bitstream_Read(stream, 3); }

        if (p->M_LEVELTEXTDISPLAY0 == 1)
        {
	{ p->NID_NTC0		= Bitstream_Read(stream, 8); }
        }

	{ p->L_TEXTDISPLAY		= Bitstream_Read(stream, 15); }

	{ p->T_TEXTDISPLAY		= Bitstream_Read(stream, 10); }

	{ p->M_MODETEXTDISPLAY1		= Bitstream_Read(stream, 4); }

	{ p->M_LEVELTEXTDISPLAY1		= Bitstream_Read(stream, 3); }

        if (p->M_LEVELTEXTDISPLAY1 == 1)
        {
	{ p->NID_NTC1		= Bitstream_Read(stream, 8); }
        }

	{ p->Q_TEXTCONFIRM		= Bitstream_Read(stream, 2); }

        if (p->Q_TEXTCONFIRM != 0)
        {
	{ p->Q_CONFTEXTDISPLAY		= Bitstream_Read(stream, 1); }

	{ p->Q_TEXTREPORT		= Bitstream_Read(stream, 1); }
        }

        if ((p->|| (p->))
        {
	{ p->NID_TEXTMESSAGE		= Bitstream_Read(stream, 8); }

	{ p->NID_C		= Bitstream_Read(stream, 10); }

	{ p->NID_RBC		= Bitstream_Read(stream, 14); }
        }

	{ p->Q_TEXT		= Bitstream_Read(stream, 8); }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert Q_TEXTCLASS:       EqualBits(stream, pos + 17,  pos + 19,  p->Q_TEXTCLASS);
        //@ assert Q_TEXTDISPLAY:     EqualBits(stream, pos + 19,  pos + 20,  p->Q_TEXTDISPLAY);
        //@ assert D_TEXTDISPLAY:     EqualBits(stream, pos + 20,  pos + 35,  p->D_TEXTDISPLAY);
        //@ assert M_MODETEXTDISPLAY0: EqualBits(stream, pos + 35,  pos + 39,  p->M_MODETEXTDISPLAY0);
        //@ assert M_LEVELTEXTDISPLAY0: EqualBits(stream, pos + 39,  pos + 42,  p->M_LEVELTEXTDISPLAY0);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert Q_TEXTCLASS:       UpperBitsNotSet(p->Q_TEXTCLASS,       2);
        //@ assert Q_TEXTDISPLAY:     UpperBitsNotSet(p->Q_TEXTDISPLAY,     1);
        //@ assert D_TEXTDISPLAY:     UpperBitsNotSet(p->D_TEXTDISPLAY,     15);
        //@ assert M_MODETEXTDISPLAY0: UpperBitsNotSet(p->M_MODETEXTDISPLAY0, 4);
        //@ assert M_LEVELTEXTDISPLAY0: UpperBitsNotSet(p->M_LEVELTEXTDISPLAY0, 3);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

