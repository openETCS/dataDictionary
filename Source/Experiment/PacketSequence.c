
#include "PacketSequence.h"
#include "Packet.h"
#include "Packet_Delete.h"
#include "Packet_Equal.h"

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


void PacketSequence_Clear(PacketSequence* p)
{
    for (uint32_t i = 0; i < p->size; ++i)
    {
        Packet_Delete(p->header[i]);
    }

    p->size = 0;
}

int PacketSequence_Equal(const PacketSequence* a, const PacketSequence* b)
{
    if (a->size == b->size)
    {
        int status = 1;

        for (uint32_t i = 0; i < a->size; ++i)
        {
            status = status && Packet_Equal(a->header[i], b->header[i]);
        }

        return status;
    }
    else
    {
        return 0;
    }
}

