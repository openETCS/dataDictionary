
#include "PacketSequence.h"
#include "Packet.h"

void PacketSequence_Init(PacketSequence* s)
{
    for (uint32_t i = 0; i < 50; ++i)
    {
        s->header[i] = 0;
    }

    s->size = 0;
}

void PacketSequence_Print(FILE* stream, const PacketSequence* p)
{
    fprintf(stream, "[");

    for (uint32_t i = 0; i < p->size; ++i)
    {
        if (i == 0)
        {
            Packet_Print(stream, p->header[i]);
        }
        else
        {
            fprintf(stream, ",");
            Packet_Print(stream, p->header[i]);
        }
    }

    fprintf(stream, "]\n");
}

