
#ifndef EUROBALISE_TELEGRAM_H_INCLUDED
#define EUROBALISE_TELEGRAM_H_INCLUDED

#include "Telegram_Header.h"
#include "BasePacket.h"
#include <iostream>

typedef std::vector<BasePacketPtr> PacketSequence;

struct Eurobalise_Telegram
{
    Telegram_Header header;
    PacketSequence packets;

    bool Decoder(Bitstream* stream);
    bool Encoder(Bitstream* stream);
};

std::ostream& operator<< (std::ostream& stream, const Eurobalise_Telegram& p);

bool operator==(const Eurobalise_Telegram& a, const Eurobalise_Telegram& b);

inline bool operator!=(const Eurobalise_Telegram& a, const Eurobalise_Telegram& b)
{
    return !(a == b);
}

#endif // EUROBALISE_TELEGRAM_H_INCLUDED

