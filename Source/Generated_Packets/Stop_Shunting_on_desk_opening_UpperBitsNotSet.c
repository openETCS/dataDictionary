
#include "Stop_Shunting_on_desk_opening_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Stop_Shunting_on_desk_opening_UpperBitsNotSet(const Stop_Shunting_on_desk_opening_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

