
#include "Packet_for_sending_plain_text_messages_Encoder.h"
#include "Packet_for_sending_plain_text_messages_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

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

