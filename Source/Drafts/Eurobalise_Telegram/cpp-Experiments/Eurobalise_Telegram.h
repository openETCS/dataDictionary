
#ifndef EUROBALISE_TELEGRAM_H_INCLUDED
#define EUROBALISE_TELEGRAM_H_INCLUDED

#include "Eurobalise_Header.h"
#include "Eurobalise_Header_Decoder.h"
#include "Decoder_Branch.h"
#include "Packet_Header_Decoder.h"

typedef std::vector<BasePacketPtr> PacketSequence;

struct Eurobalise_Telegram
{
    Eurobalise_Header header;
    PacketSequence packets;

    void Decoder(Bitstream* stream);
};

#endif // EUROBALISE_TELEGRAM_H_INCLUDED

