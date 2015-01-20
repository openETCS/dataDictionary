
#include "TrainToTrack_Header_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int TrainToTrack_Header_UpperBitsNotSet(const TrainToTrack_Header* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,             8)   &&
        UpperBitsNotSet64(p->Q_DIR,                  2)   &&
        UpperBitsNotSet64(p->L_PACKET,               13))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

