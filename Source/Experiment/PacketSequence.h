
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

void PacketSequence_Print(FILE* stream, const PacketSequence* p);

// similiar to std::vector::clear
void PacketSequence_Clear(PacketSequence* p);


#endif /* PACKETSEQUENCE_H_INCLUDED */

