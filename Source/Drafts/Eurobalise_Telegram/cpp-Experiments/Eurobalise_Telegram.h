
#ifndef EUROBALISE_TELEGRAM_H_INCLUDED
#define EUROBALISE_TELEGRAM_H_INCLUDED

#include "Eurobalise_Header.h"
#include "BasePacket.h"

typedef std::vector<BasePacketPtr> PacketSequence;

struct Eurobalise_Telegram
{
    Eurobalise_Header header;
    PacketSequence packets;

    bool Decoder(Bitstream* stream);
    bool Encoder(Bitstream* stream);
};

#endif // EUROBALISE_TELEGRAM_H_INCLUDED

