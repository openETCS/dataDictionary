
#include "Header_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Header_UpperBitsNotSet(const Header* p)
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

