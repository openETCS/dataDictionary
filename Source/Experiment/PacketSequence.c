
#include "PacketSequence.h"

void PacketSequence_Init(PacketSequence* s)
{
    for (uint32_t i = 0; i < 50; ++i)
    {
        s->header[i] = 0;
    }

    s->size = 0;
}

