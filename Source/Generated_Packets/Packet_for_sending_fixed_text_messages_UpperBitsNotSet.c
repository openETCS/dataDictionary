
#include "Packet_for_sending_fixed_text_messages_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Packet_for_sending_fixed_text_messages_UpperBitsNotSet(const Packet_for_sending_fixed_text_messages_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->Q_TEXTCLASS,       2)   &&
        UpperBitsNotSet64(p->Q_TEXTDISPLAY,     1)   &&
        UpperBitsNotSet64(p->D_TEXTDISPLAY,     15)  &&
        UpperBitsNotSet64(p->M_MODETEXTDISPLAY_0, 4)   &&
        UpperBitsNotSet64(p->M_LEVELTEXTDISPLAY_0, 3)   &&
        UpperBitsNotSet64(p->NID_NTC_0,         8)   &&
        UpperBitsNotSet64(p->L_TEXTDISPLAY,     15)  &&
        UpperBitsNotSet64(p->T_TEXTDISPLAY,     10)  &&
        UpperBitsNotSet64(p->M_MODETEXTDISPLAY_1, 4)   &&
        UpperBitsNotSet64(p->M_LEVELTEXTDISPLAY_1, 3)   &&
        UpperBitsNotSet64(p->NID_NTC_1,         8)   &&
        UpperBitsNotSet64(p->Q_TEXTCONFIRM,     2)   &&
        UpperBitsNotSet64(p->Q_CONFTEXTDISPLAY, 1)   &&
        UpperBitsNotSet64(p->Q_TEXTREPORT,      1)   &&
        UpperBitsNotSet64(p->NID_TEXTMESSAGE,   8)   &&
        UpperBitsNotSet64(p->NID_C,             10)  &&
        UpperBitsNotSet64(p->NID_RBC,           14)  &&
        UpperBitsNotSet64(p->Q_TEXT,            8))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

