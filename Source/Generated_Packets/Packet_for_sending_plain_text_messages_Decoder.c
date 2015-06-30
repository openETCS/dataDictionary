
#include "Packet_for_sending_plain_text_messages_Decoder.h"
#include "Bitstream_Read.h"

int Packet_for_sending_plain_text_messages_Decoder(Bitstream* stream, Packet_for_sending_plain_text_messages_Core* p)
{
    if (NormalBitstream(stream, PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_CORE_BITSIZE))
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

	/*@
	  requires L_TEXTDISPLAY:  stream->bitpos == pos + 50;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_TEXTDISPLAY;
	  ensures  L_TEXTDISPLAY:  stream->bitpos == pos + 65;
	  ensures  L_TEXTDISPLAY:  EqualBits(stream, pos + 50, pos + 65, p->L_TEXTDISPLAY);
	  ensures  L_TEXTDISPLAY:  UpperBitsNotSet(p->L_TEXTDISPLAY, 15);
	*/
	{ p->L_TEXTDISPLAY		= Bitstream_Read(stream, 15); }

	/*@
	  requires T_TEXTDISPLAY:  stream->bitpos == pos + 65;
	  assigns        	   stream->bitpos;
	  assigns		   p->T_TEXTDISPLAY;
	  ensures  T_TEXTDISPLAY:  stream->bitpos == pos + 75;
	  ensures  T_TEXTDISPLAY:  EqualBits(stream, pos + 65, pos + 75, p->T_TEXTDISPLAY);
	  ensures  T_TEXTDISPLAY:  UpperBitsNotSet(p->T_TEXTDISPLAY, 10);
	*/
	{ p->T_TEXTDISPLAY		= Bitstream_Read(stream, 10); }

	/*@
	  requires M_MODETEXTDISPLAY1: stream->bitpos == pos + 75;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_MODETEXTDISPLAY1;
	  ensures  M_MODETEXTDISPLAY1: stream->bitpos == pos + 79;
	  ensures  M_MODETEXTDISPLAY1: EqualBits(stream, pos + 75, pos + 79, p->M_MODETEXTDISPLAY1);
	  ensures  M_MODETEXTDISPLAY1: UpperBitsNotSet(p->M_MODETEXTDISPLAY1, 4);
	*/
	{ p->M_MODETEXTDISPLAY1		= Bitstream_Read(stream, 4); }

	/*@
	  requires M_LEVELTEXTDISPLAY1: stream->bitpos == pos + 79;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_LEVELTEXTDISPLAY1;
	  ensures  M_LEVELTEXTDISPLAY1: stream->bitpos == pos + 82;
	  ensures  M_LEVELTEXTDISPLAY1: EqualBits(stream, pos + 79, pos + 82, p->M_LEVELTEXTDISPLAY1);
	  ensures  M_LEVELTEXTDISPLAY1: UpperBitsNotSet(p->M_LEVELTEXTDISPLAY1, 3);
	*/
	{ p->M_LEVELTEXTDISPLAY1		= Bitstream_Read(stream, 3); }

        if (p->M_LEVELTEXTDISPLAY1 == 1)
        {
	{ p->NID_NTC1		= Bitstream_Read(stream, 8); }
        }

	/*@
	  requires Q_TEXTCONFIRM:  stream->bitpos == pos + 90;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_TEXTCONFIRM;
	  ensures  Q_TEXTCONFIRM:  stream->bitpos == pos + 92;
	  ensures  Q_TEXTCONFIRM:  EqualBits(stream, pos + 90, pos + 92, p->Q_TEXTCONFIRM);
	  ensures  Q_TEXTCONFIRM:  UpperBitsNotSet(p->Q_TEXTCONFIRM, 2);
	*/
	{ p->Q_TEXTCONFIRM		= Bitstream_Read(stream, 2); }

        if (p->Q_TEXTCONFIRM != 0)
        {
	{ p->Q_CONFTEXTDISPLAY		= Bitstream_Read(stream, 1); }

	{ p->Q_TEXTREPORT		= Bitstream_Read(stream, 1); }
        }

        if (p->Q_TEXTREPORT == 1)
        {
	{ p->NID_TEXTMESSAGE		= Bitstream_Read(stream, 8); }

	{ p->NID_C		= Bitstream_Read(stream, 10); }

	{ p->NID_RBC		= Bitstream_Read(stream, 14); }
        }

	/*@
	  requires L_TEXT:         stream->bitpos == pos + 126;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_TEXT;
	  ensures  L_TEXT:         stream->bitpos == pos + 134;
	  ensures  L_TEXT:         EqualBits(stream, pos + 126, pos + 134, p->L_TEXT);
	  ensures  L_TEXT:         UpperBitsNotSet(p->L_TEXT, 8);
	*/
	{ p->L_TEXT		= Bitstream_Read(stream, 8); }

	/*@
	  requires X_TEXT:         stream->bitpos == pos + 134;
	  assigns        	   stream->bitpos;
	  assigns		   p->X_TEXT;
	  ensures  X_TEXT:         stream->bitpos == pos + 142;
	  ensures  X_TEXT:         EqualBits(stream, pos + 134, pos + 142, p->X_TEXT);
	  ensures  X_TEXT:         UpperBitsNotSet(p->X_TEXT, 8);
	*/
	{ p->X_TEXT		= Bitstream_Read(stream, 8); }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert Q_TEXTCLASS:       EqualBits(stream, pos + 17,  pos + 19,  p->Q_TEXTCLASS);
        //@ assert Q_TEXTDISPLAY:     EqualBits(stream, pos + 19,  pos + 20,  p->Q_TEXTDISPLAY);
        //@ assert D_TEXTDISPLAY:     EqualBits(stream, pos + 20,  pos + 35,  p->D_TEXTDISPLAY);
        //@ assert M_MODETEXTDISPLAY0: EqualBits(stream, pos + 35,  pos + 39,  p->M_MODETEXTDISPLAY0);
        //@ assert M_LEVELTEXTDISPLAY0: EqualBits(stream, pos + 39,  pos + 42,  p->M_LEVELTEXTDISPLAY0);
        //@ assert L_TEXTDISPLAY:     EqualBits(stream, pos + 50,  pos + 65,  p->L_TEXTDISPLAY);
        //@ assert T_TEXTDISPLAY:     EqualBits(stream, pos + 65,  pos + 75,  p->T_TEXTDISPLAY);
        //@ assert M_MODETEXTDISPLAY1: EqualBits(stream, pos + 75,  pos + 79,  p->M_MODETEXTDISPLAY1);
        //@ assert M_LEVELTEXTDISPLAY1: EqualBits(stream, pos + 79,  pos + 82,  p->M_LEVELTEXTDISPLAY1);
        //@ assert Q_TEXTCONFIRM:     EqualBits(stream, pos + 90,  pos + 92,  p->Q_TEXTCONFIRM);
        //@ assert L_TEXT:            EqualBits(stream, pos + 126, pos + 134, p->L_TEXT);
        //@ assert X_TEXT:            EqualBits(stream, pos + 134, pos + 142, p->X_TEXT);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert Q_TEXTCLASS:       UpperBitsNotSet(p->Q_TEXTCLASS,       2);
        //@ assert Q_TEXTDISPLAY:     UpperBitsNotSet(p->Q_TEXTDISPLAY,     1);
        //@ assert D_TEXTDISPLAY:     UpperBitsNotSet(p->D_TEXTDISPLAY,     15);
        //@ assert M_MODETEXTDISPLAY0: UpperBitsNotSet(p->M_MODETEXTDISPLAY0, 4);
        //@ assert M_LEVELTEXTDISPLAY0: UpperBitsNotSet(p->M_LEVELTEXTDISPLAY0, 3);
        //@ assert L_TEXTDISPLAY:     UpperBitsNotSet(p->L_TEXTDISPLAY,     15);
        //@ assert T_TEXTDISPLAY:     UpperBitsNotSet(p->T_TEXTDISPLAY,     10);
        //@ assert M_MODETEXTDISPLAY1: UpperBitsNotSet(p->M_MODETEXTDISPLAY1, 4);
        //@ assert M_LEVELTEXTDISPLAY1: UpperBitsNotSet(p->M_LEVELTEXTDISPLAY1, 3);
        //@ assert Q_TEXTCONFIRM:     UpperBitsNotSet(p->Q_TEXTCONFIRM,     2);
        //@ assert L_TEXT:            UpperBitsNotSet(p->L_TEXT,            8);
        //@ assert X_TEXT:            UpperBitsNotSet(p->X_TEXT,            8);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

