
#ifndef EUROBALISETELEGRAM_H_INCLUDED
#define EUROBALISETELEGRAM_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / EurobaliseTelegram.h
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

#include "TelegramHeader.h"
#include "PacketSequence.h"
#include "CompressedPackets.h"

struct EurobaliseTelegram
{
    TelegramHeader header;

    PacketSequence  packets;
    /*
            bool encode(FlatPackets& packetStruct) const;

            bool decode(FlatPackets& packetStruct);
    */
};

typedef struct EurobaliseTelegram EurobaliseTelegram;

static inline void EurobaliseTelegram_Init(EurobaliseTelegram* t)
{
    TelegramHeader_Init(&t->header);
    PacketSequence_Init(&t->packets);
}

static inline uint32_t EurobaliseTelegram_Size(const EurobaliseTelegram* t)
{
    return t->packets.size;
}

static inline const PacketHeader* EurobaliseTelegram_Get(const EurobaliseTelegram* t, uint32_t i)
{
    return PacketSequence_Get(&t->packets, i);
}

static inline void EurobaliseTelegram_Add(EurobaliseTelegram* t, PacketHeader* p)
{
    PacketSequence_Add(&t->packets, p);
}

void EurobaliseTelegram_Print(const EurobaliseTelegram* t, FILE* stream);

void EurobaliseTelegram_Clear(EurobaliseTelegram* t);

int EurobaliseTelegram_Equal(const EurobaliseTelegram* a, const EurobaliseTelegram* b);

int EurobaliseTelegram_EncodeBit(const EurobaliseTelegram* t, Bitstream* stream);

int EurobaliseTelegram_DecodeBit(EurobaliseTelegram* t, Bitstream* stream);

int EurobaliseTelegram_EncodeInt(const EurobaliseTelegram* t, CompressedPackets* packetStruct);

int EurobaliseTelegram_DecodeInt(EurobaliseTelegram* t, const CompressedPackets* packetStruct);

#endif /* EUROBALISETELEGRAM_H_INCLUDED */

