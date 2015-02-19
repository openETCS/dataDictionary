
#include "Virtual_Balise_Cover_marker_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Virtual_Balise_Cover_marker_Data_UpperBitsNotSet(const Virtual_Balise_Cover_marker_Data* p)
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

