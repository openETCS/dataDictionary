
#include "Packet_for_sending_plain_text_messages_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Packet_for_sending_plain_text_messages_UpperBitsNotSet(const Packet_for_sending_plain_text_messages_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->Q_TEXTCLASS,       2) ;
    status = status && UpperBitsNotSet64(p->Q_TEXTDISPLAY,     1) ;
    status = status && UpperBitsNotSet64(p->D_TEXTDISPLAY,     15);
    status = status && UpperBitsNotSet64(p->M_MODETEXTDISPLAY_0, 4) ;
    status = status && UpperBitsNotSet64(p->M_LEVELTEXTDISPLAY_0, 3) ;
    if (p->M_LEVELTEXTDISPLAY_0 == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_NTC_0,         8) ;
    }
    status = status && UpperBitsNotSet64(p->L_TEXTDISPLAY,     15);
    status = status && UpperBitsNotSet64(p->T_TEXTDISPLAY,     10);
    status = status && UpperBitsNotSet64(p->M_MODETEXTDISPLAY_1, 4) ;
    status = status && UpperBitsNotSet64(p->M_LEVELTEXTDISPLAY_1, 3) ;
    if (p->M_LEVELTEXTDISPLAY_1 == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_NTC_1,         8) ;
    }
    status = status && UpperBitsNotSet64(p->Q_TEXTCONFIRM,     2) ;
    if (p->Q_TEXTCONFIRM != 0)
    {
    status = status && UpperBitsNotSet64(p->Q_CONFTEXTDISPLAY, 1) ;
    status = status && UpperBitsNotSet64(p->Q_TEXTREPORT,      1) ;
    }
    if (p->Q_TEXTREPORT == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_TEXTMESSAGE,   8) ;
    status = status && UpperBitsNotSet64(p->NID_C,             10);
    status = status && UpperBitsNotSet64(p->NID_RBC,           14);
    }
    status = status && UpperBitsNotSet64(p->L_TEXT,            8) ;
    status = status && UpperBitsNotSet64(p->X_TEXT,            8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Packet_for_sending_plain_text_messages_Encoder(Bitstream* stream, const Packet_for_sending_plain_text_messages_Core* p)
{
    if (NormalBitstream(stream, PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_CORE_BITSIZE))
    {
        if (Packet_for_sending_plain_text_messages_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 2,  p->Q_TEXTCLASS);
            Bitstream_Write(stream, 1,  p->Q_TEXTDISPLAY);
            Bitstream_Write(stream, 15, p->D_TEXTDISPLAY);
            Bitstream_Write(stream, 4,  p->M_MODETEXTDISPLAY_0);
            Bitstream_Write(stream, 3,  p->M_LEVELTEXTDISPLAY_0);
            if (p->M_LEVELTEXTDISPLAY_0 == 1)
            {
            Bitstream_Write(stream, 8,  p->NID_NTC_0);
            }

            Bitstream_Write(stream, 15, p->L_TEXTDISPLAY);
            Bitstream_Write(stream, 10, p->T_TEXTDISPLAY);
            Bitstream_Write(stream, 4,  p->M_MODETEXTDISPLAY_1);
            Bitstream_Write(stream, 3,  p->M_LEVELTEXTDISPLAY_1);
            if (p->M_LEVELTEXTDISPLAY_1 == 1)
            {
            Bitstream_Write(stream, 8,  p->NID_NTC_1);
            }

            Bitstream_Write(stream, 2,  p->Q_TEXTCONFIRM);
            if (p->Q_TEXTCONFIRM != 0)
            {
            Bitstream_Write(stream, 1,  p->Q_CONFTEXTDISPLAY);
            Bitstream_Write(stream, 1,  p->Q_TEXTREPORT);
            }

            if (p->Q_TEXTREPORT == 1)
            {
            Bitstream_Write(stream, 8,  p->NID_TEXTMESSAGE);
            Bitstream_Write(stream, 10, p->NID_C);
            Bitstream_Write(stream, 14, p->NID_RBC);
            }

            Bitstream_Write(stream, 8,  p->L_TEXT);
            Bitstream_Write(stream, 8,  p->X_TEXT);



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

int Packet_for_sending_plain_text_messages_Decoder(Bitstream* stream, Packet_for_sending_plain_text_messages_Core* p)
{
    if (NormalBitstream(stream, PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_CORE_BITSIZE))
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

	{ p->L_TEXT		= Bitstream_Read(stream, 8); }

	{ p->X_TEXT		= Bitstream_Read(stream, 8); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

