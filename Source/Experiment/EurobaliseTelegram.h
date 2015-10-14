
#ifndef EUROBALISETELEGRAM_H_INCLUDED
#define EUROBALISETELEGRAM_H_INCLUDED

#include "TelegramHeader.h"
#include "PacketSequence.h"
#include "Packet.h"

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

void EurobaliseTelegram_Print(FILE* stream, const EurobaliseTelegram* t);

void EurobaliseTelegram_Clear(EurobaliseTelegram* t);

int EurobaliseTelegram_EncodeBit(const EurobaliseTelegram* t, Bitstream* stream);

int EurobaliseTelegram_DecodeBit(EurobaliseTelegram* t, Bitstream* stream);

#endif /* EUROBALISETELEGRAM_H_INCLUDED */

