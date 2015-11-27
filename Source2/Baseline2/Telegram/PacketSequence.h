
#ifndef PACKETSEQUENCE_H_INCLUDED
#define PACKETSEQUENCE_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / PacketSequence.h
- Description: UNISIG SUBSET-026-7, ISSUE : 3.3.0, 3.5 ERTMS/ETCS language) 
- Copyright (c) 

- Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl )
- Gist URL: none
- Cryptography: No
- Author(s): Fraunhofer FOKUS

Disclaimer:

The use of this software is limited to NON-vital applications. 
It has NOT been developed for vital operation purposes and MUST NOT be used for applications 
which may cause harm to people, physical accidents or financial loss. 

THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OTHER KIND OF USE.       
============================================================================= */

#include "PacketHeader.h"
#include "CompressedPackets.h"
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

void PacketSequence_Print(const PacketSequence* p, FILE* stream);

// similiar to std::vector::clear
void PacketSequence_Clear(PacketSequence* p);

int PacketSequence_Equal(const PacketSequence* a, const PacketSequence* b);

int PacketSequence_EncodeInt(const PacketSequence* p, CompressedPackets* packetStruct);

int PacketSequence_DecodeInt(PacketSequence* p, uint64_t q_updown, const CompressedPackets* packetStruct);

#endif /* PACKETSEQUENCE_H_INCLUDED */

