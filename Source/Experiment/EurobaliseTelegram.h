
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

static inline void EurobaliseTelegram_Print(FILE* stream, EurobaliseTelegram* p)
{
    TelegramHeader_Print(stream, &p->header);
    fprintf(stream, "[");
    for(uint32_t i = 0; i < p->packets.size; ++i)
    {
	if(i == 0)
	{
             Packet_Print(stream, p->packets.header[i]);
	}
	else
	{
	     fprintf(stream, ",");
             Packet_Print(stream, p->packets.header[i]);
	}
    }
    fprintf(stream, "]\n");
}

int EurobaliseTelegram_EncodeBit(const EurobaliseTelegram* t, Bitstream* stream);

int EurobaliseTelegram_DecodeBit(EurobaliseTelegram* t, Bitstream* stream);

#ifdef __cplusplus

std::ostream& operator<<(std::ostream& stream, const EurobaliseTelegram& p);

bool operator==(const EurobaliseTelegram& a, const EurobaliseTelegram& b);

bool operator!=(const EurobaliseTelegram& a, const EurobaliseTelegram& b);

#endif

#endif /* EUROBALISETELEGRAM_H_INCLUDED */

