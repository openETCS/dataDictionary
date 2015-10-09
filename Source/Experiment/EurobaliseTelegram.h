
#ifndef EUROBALISETELEGRAM_H_INCLUDED
#define EUROBALISETELEGRAM_H_INCLUDED

#include "TelegramHeader.h"
#include "PacketSequence.h"

struct EurobaliseTelegram
{
        TelegramHeader header;

        PacketSequence  packets;
/*
        bool encode(FlatPackets& packetStruct) const;

        bool decode(FlatPackets& packetStruct);
*/
};

static inline void EurobaliseTelegram_Init(EurobaliseTelegram* t)
{
    t->header.NID_PACKET = 0;
    PacketSequence_Init(&packets);
}

static inline uint32_t EurobaliseTelegram_Size(const EurobaliseTelegram* t)
{
    return packets.size;
}

static inline const PacketHeader* EurobaliseTelegram_Get(const EurobaliseTelegram* t, uint32_t i)
{
    return PacketSequence_Get(&t->packets, i);
}

static inline void EurobaliseTelegram_Add(EurobaliseTelegram* t, PacketHeader* p)
{
    PacketSequence_Add(&t->packets, p);
}

int EurobaliseTelegram_Encode_Bit(const EurobaliseTelegram* t, Bitstream* stream);

int EurobaliseTelegram_Decode_Bit(EurobaliseTelegram* t, Bitstream* stream);

#ifdef __cplusplus

std::ostream& operator<<(std::ostream& stream, const EurobaliseTelegram& p);

bool operator==(const EurobaliseTelegram& a, const EurobaliseTelegram& b);

bool operator!=(const EurobaliseTelegram& a, const EurobaliseTelegram& b);

#endif

#endif /* EUROBALISETELEGRAM_H_INCLUDED */

