
#include "End_of_Information_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int End_of_Information_UpperBitsNotSet(const End_of_Information* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

