
#include "Packet_for_sending_fixed_text_messages_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Packet_for_sending_fixed_text_messages_Decoder(Bitstream* stream, Packet_for_sending_fixed_text_messages* p)
{
    if (NormalBitstream(stream, PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 23,  2);
        p->Q_TEXTCLASS        = Bitwalker_Peek_Normal(addr, size, pos + 25,  2);
        p->Q_TEXTDISPLAY      = Bitwalker_Peek_Normal(addr, size, pos + 27,  1);
        p->D_TEXTDISPLAY      = Bitwalker_Peek_Normal(addr, size, pos + 28,  15);
        p->M_MODETEXTDISPLAY(0) = Bitwalker_Peek_Normal(addr, size, pos + 43,  4);
        p->M_LEVELTEXTDISPLAY(0) = Bitwalker_Peek_Normal(addr, size, pos + 47,  3);
        p->NID_NTC(0)         = Bitwalker_Peek_Normal(addr, size, pos + 50,  8);
        p->L_TEXTDISPLAY      = Bitwalker_Peek_Normal(addr, size, pos + 58,  15);
        p->T_TEXTDISPLAY      = Bitwalker_Peek_Normal(addr, size, pos + 73,  10);
        p->M_MODETEXTDISPLAY(1) = Bitwalker_Peek_Normal(addr, size, pos + 83,  4);
        p->M_LEVELTEXTDISPLAY(1) = Bitwalker_Peek_Normal(addr, size, pos + 87,  3);
        p->NID_NTC(1)         = Bitwalker_Peek_Normal(addr, size, pos + 90,  8);
        p->Q_TEXTCONFIRM      = Bitwalker_Peek_Normal(addr, size, pos + 98,  2);
        p->Q_CONFTEXTDISPLAY  = Bitwalker_Peek_Normal(addr, size, pos + 100, 1);
        p->Q_TEXTREPORT       = Bitwalker_Peek_Normal(addr, size, pos + 101, 1);
        p->NID_TEXTMESSAGE    = Bitwalker_Peek_Normal(addr, size, pos + 102, 8);
        p->NID_C              = Bitwalker_Peek_Normal(addr, size, pos + 110, 10);
        p->NID_RBC            = Bitwalker_Peek_Normal(addr, size, pos + 120, 14);
        p->Q_TEXT             = Bitwalker_Peek_Normal(addr, size, pos + 134, 8);

        stream->bitpos += PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
        //@ assert Q_TEXTCLASS:       EqualBits(stream, pos + 25,  pos + 27,  p->Q_TEXTCLASS);
        //@ assert Q_TEXTDISPLAY:     EqualBits(stream, pos + 27,  pos + 28,  p->Q_TEXTDISPLAY);
        //@ assert D_TEXTDISPLAY:     EqualBits(stream, pos + 28,  pos + 43,  p->D_TEXTDISPLAY);
        //@ assert M_MODETEXTDISPLAY(0): EqualBits(stream, pos + 43,  pos + 47,  p->M_MODETEXTDISPLAY(0));
        //@ assert M_LEVELTEXTDISPLAY(0): EqualBits(stream, pos + 47,  pos + 50,  p->M_LEVELTEXTDISPLAY(0));
        //@ assert NID_NTC(0):        EqualBits(stream, pos + 50,  pos + 58,  p->NID_NTC(0));
        //@ assert L_TEXTDISPLAY:     EqualBits(stream, pos + 58,  pos + 73,  p->L_TEXTDISPLAY);
        //@ assert T_TEXTDISPLAY:     EqualBits(stream, pos + 73,  pos + 83,  p->T_TEXTDISPLAY);
        //@ assert M_MODETEXTDISPLAY(1): EqualBits(stream, pos + 83,  pos + 87,  p->M_MODETEXTDISPLAY(1));
        //@ assert M_LEVELTEXTDISPLAY(1): EqualBits(stream, pos + 87,  pos + 90,  p->M_LEVELTEXTDISPLAY(1));
        //@ assert NID_NTC(1):        EqualBits(stream, pos + 90,  pos + 98,  p->NID_NTC(1));
        //@ assert Q_TEXTCONFIRM:     EqualBits(stream, pos + 98,  pos + 100, p->Q_TEXTCONFIRM);
        //@ assert Q_CONFTEXTDISPLAY: EqualBits(stream, pos + 100, pos + 101, p->Q_CONFTEXTDISPLAY);
        //@ assert Q_TEXTREPORT:      EqualBits(stream, pos + 101, pos + 102, p->Q_TEXTREPORT);
        //@ assert NID_TEXTMESSAGE:   EqualBits(stream, pos + 102, pos + 110, p->NID_TEXTMESSAGE);
        //@ assert NID_C:             EqualBits(stream, pos + 110, pos + 120, p->NID_C);
        //@ assert NID_RBC:           EqualBits(stream, pos + 120, pos + 134, p->NID_RBC);
        //@ assert Q_TEXT:            EqualBits(stream, pos + 134, pos + 142, p->Q_TEXT);

        return 1;
    }
    else
    {
        return 0;
    }
}

