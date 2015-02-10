
#include "BothWays_Header_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int BothWays_Header_UpperBitsNotSet(const BothWays_Header* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,             8))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

