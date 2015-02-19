
#include "Stop_Shunting_on_desk_opening_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Stop_Shunting_on_desk_opening_Data_UpperBitsNotSet(const Stop_Shunting_on_desk_opening_Data* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

