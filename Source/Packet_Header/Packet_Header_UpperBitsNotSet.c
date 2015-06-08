
#include "Packet_Header_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Packet_Header_UpperBitsNotSet(const Packet_Header* p)
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

