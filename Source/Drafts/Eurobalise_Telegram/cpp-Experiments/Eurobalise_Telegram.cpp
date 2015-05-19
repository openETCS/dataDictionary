
#include "BasePacket.cpp"
#include "Eurobalise_Header.h"

typedef std::vector<BasePacketPtr> PacketSequence;

struct Eurobalise_Telegram
{
    Eurobalise_Header header;
    PacketSequence packets;
}

