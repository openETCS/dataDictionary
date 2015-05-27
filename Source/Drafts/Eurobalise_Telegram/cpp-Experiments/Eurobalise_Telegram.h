
#ifndef EUROBALISE_TELEGRAM_H_INCLUDED
#define EUROBALISE_TELEGRAM_H_INCLUDED

#include "Eurobalise_Header.h"
#include "Eurobalise_Header_Decoder.h"
#include "Packet_Header_Decoder.h"
#include "Decoder_Branch.h"

typedef std::vector<BasePacketPtr> PacketSequence;

struct Eurobalise_Telegram
{
    Eurobalise_Header header;
    PacketSequence packets;

    bool Decoder(Bitstream* stream);
    bool Encoder(Bitstream* stream);
};

#endif // EUROBALISE_TELEGRAM_H_INCLUDED

