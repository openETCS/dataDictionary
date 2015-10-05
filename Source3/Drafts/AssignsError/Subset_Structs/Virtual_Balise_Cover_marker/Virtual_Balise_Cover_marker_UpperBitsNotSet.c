
#include "Virtual_Balise_Cover_marker_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Virtual_Balise_Cover_marker_UpperBitsNotSet(const Virtual_Balise_Cover_marker* p)
{
    if (UpperBitsNotSet64(p->NID_VBCMK,         6))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

