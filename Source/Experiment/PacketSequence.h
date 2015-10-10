
#ifndef PACKETSEQUENCE_H_INCLUDED
#define PACKETSEQUENCE_H_INCLUDED

#include <assert.h>
#include "PacketHeader.h"

struct PacketSequence
{
    PacketHeader* header[50];
    uint32_t size;
};

typedef struct PacketSequence PacketSequence;

static inline void PacketSequence_Init(PacketSequence* s)
{
    for (uint32_t i = 0; i < 50; ++i)
    {
        s->header[i] = 0;
    }

    s->size = 0;
}

static inline void PacketSequence_Add(PacketSequence* s, PacketHeader* h)
{
    assert(s->size < 50);
    s->header[s->size++] = h;
}

static inline const PacketHeader* PacketSequence_Get(const PacketSequence* s, uint32_t i)
{
    assert(s->size < 50);
    assert(i < s->size);

    return s->header[i];
}

#endif /* PACKETSEQUENCE_H_INCLUDED */

