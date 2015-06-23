
#include "Packet_for_sending_fixed_text_messages_Decoder.h"
#include "Bitstream_Read.h"

int Packet_for_sending_fixed_text_messages_Decoder(Bitstream* stream, Packet_for_sending_fixed_text_messages_Core* p)
{
    if (NormalBitstream(stream, PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->Q_TEXTCLASS		= Bitstream_Read(stream, 2); }

	{ p->Q_TEXTDISPLAY		= Bitstream_Read(stream, 1); }

	{ p->D_TEXTDISPLAY		= Bitstream_Read(stream, 15); }

	{ p->M_MODETEXTDISPLAY_0		= Bitstream_Read(stream, 4); }

	{ p->M_LEVELTEXTDISPLAY_0		= Bitstream_Read(stream, 3); }

        if (p->M_LEVELTEXTDISPLAY_0 == 1)
        {
	{ p->NID_NTC_0		= Bitstream_Read(stream, 8); }
        }

	{ p->L_TEXTDISPLAY		= Bitstream_Read(stream, 15); }

	{ p->T_TEXTDISPLAY		= Bitstream_Read(stream, 10); }

	{ p->M_MODETEXTDISPLAY_1		= Bitstream_Read(stream, 4); }

	{ p->M_LEVELTEXTDISPLAY_1		= Bitstream_Read(stream, 3); }

        if (p->M_LEVELTEXTDISPLAY_1 == 1)
        {
	{ p->NID_NTC_1		= Bitstream_Read(stream, 8); }
        }

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

	{ p->Q_TEXT		= Bitstream_Read(stream, 8); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

