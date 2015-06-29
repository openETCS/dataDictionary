
#include "Packet_for_sending_plain_text_messages_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

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

