
#include "Telegram_Header_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Telegram_Header_UpperBitsNotSet(const Telegram_Header* p)
{
    if (UpperBitsNotSet64(p->Q_UPDOWN,      1)  &&
        UpperBitsNotSet64(p->M_VERSION,     7)  &&
        UpperBitsNotSet64(p->Q_MEDIA,       1)  &&
        UpperBitsNotSet64(p->N_PIG,         3)  &&
        UpperBitsNotSet64(p->N_TOTAL,       3)  &&
        UpperBitsNotSet64(p->M_DUP,         2)  &&
        UpperBitsNotSet64(p->M_MCOUNT,      8)  &&
        UpperBitsNotSet64(p->NID_C,         10) &&
        UpperBitsNotSet64(p->NID_BG,        14) &&
        UpperBitsNotSet64(p->Q_LINK,        1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

