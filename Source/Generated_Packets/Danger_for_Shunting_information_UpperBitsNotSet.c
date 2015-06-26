
#include "Danger_for_Shunting_information_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Danger_for_Shunting_information_UpperBitsNotSet(const Danger_for_Shunting_information_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_ASPECT,          1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

