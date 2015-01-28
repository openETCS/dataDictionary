
#include "Stop_Shunting_on_desk_opening_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Stop_Shunting_on_desk_opening_UpperBitsNotSet(const Stop_Shunting_on_desk_opening* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

