
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
        UpperBitsNotSet64(p->M_MODETEXTDISPLAY0, 4)   &&
        UpperBitsNotSet64(p->M_LEVELTEXTDISPLAY0, 3))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

