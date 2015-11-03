
#ifndef EUROBALISETELEGRAM_H_INCLUDED
#define EUROBALISETELEGRAM_H_INCLUDED

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

