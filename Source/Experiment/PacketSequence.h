
#ifndef PACKETSEQUENCE_H_INCLUDED
#define PACKETSEQUENCE_H_INCLUDED

#include "PacketHeader.h"
#include <assert.h>

struct PacketSequence
{
    PacketHeader* header[50];
    uint32_t size;
};

typedef struct PacketSequence PacketSequence;

void PacketSequence_Init(PacketSequence* s);

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

static inline const PacketHeader* PacketSequence_Back(const PacketSequence* s)
{
    assert(s->size > 0);
    return PacketSequence_Get(s, s->size - 1);
}

void PacketSequence_Print(FILE* stream, const PacketSequence* p);

// similiar to std::vector::clear
void PacketSequence_Clear(PacketSequence* p);

int PacketSequence_Equal(const PacketSequence* a, const PacketSequence* b);

#endif /* PACKETSEQUENCE_H_INCLUDED */

