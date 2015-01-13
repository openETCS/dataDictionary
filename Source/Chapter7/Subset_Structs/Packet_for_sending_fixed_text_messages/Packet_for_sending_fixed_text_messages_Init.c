
#include "Packet_for_sending_fixed_text_messages_Init.h"

void Packet_for_sending_fixed_text_messages_Init(Packet_for_sending_fixed_text_messages* p)
{
    p->NID_PACKET        = 0;
    p->Q_DIR             = 0;
    p->L_PACKET          = 0;
    p->Q_SCALE           = 0;
    p->Q_TEXTCLASS       = 0;
    p->Q_TEXTDISPLAY     = 0;
    p->D_TEXTDISPLAY     = 0;
    p->L_TEXTDISPLAY     = 0;
    p->T_TEXTDISPLAY     = 0;
    p->Q_TEXTCONFIRM     = 0;
    p->Q_CONFTEXTDISPLAY = 0;
    p->Q_TEXTREPORT      = 0;
    p->NID_TEXTMESSAGE   = 0;
    p->NID_C             = 0;
    p->NID_RBC           = 0;
    p->Q_TEXT            = 0;
}

