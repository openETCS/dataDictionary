
#include "Danger_for_Shunting_information_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Danger_for_Shunting_information_UpperBitsNotSet(const Danger_for_Shunting_information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_ASPECT,          1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

