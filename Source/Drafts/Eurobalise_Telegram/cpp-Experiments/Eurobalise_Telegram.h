
#ifndef EUROBALISE_TELEGRAM_H_INCLUDED
#define EUROBALISE_TELEGRAM_H_INCLUDED

#include "BasePacket.h"
#include "Eurobalise_Header.h"

typedef std::vector<BasePacketPtr> PacketSequence;

struct Eurobalise_Telegram
{
    Eurobalise_Header header;
    PacketSequence packets;
};

#endif // EUROBALISE_TELEGRAM_H_INCLUDED

