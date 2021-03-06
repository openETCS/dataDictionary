
#include "Request_to_Shorten_MA_Message.h"
#include "PacketHeader.h"
#include "PacketFactory.h"
#include "Bitstream.h"
#include "Bitwalker.h"
#include <iostream>
#include <cassert>

bool Request_to_Shorten_MA_Message::decode(Bitstream& stream)
{
    uint32_t old_pos = stream.bitpos;

    L_MESSAGE = Bitstream_Read(&stream, 10);
    T_TRAIN = Bitstream_Read(&stream, 32);
    M_ACK = Bitstream_Read(&stream, 1);
    NID_LRBG = Bitstream_Read(&stream, 24);

    PacketHeader packetID{0};

    ::decode(stream, packetID);
    packet_15 = PacketFactory_TrackToTrain(packetID.NID_PACKET);
    packet_15->decode(stream);
    if (!packet_15)
    {
        return false;
    }

    ::decode(stream, packetID);
    packet_80 = PacketFactory_TrackToTrain(packetID.NID_PACKET);
    packet_80->decode(stream);
    if (!packet_80)
    {
        return false;
    }

    if (stream.bitpos > old_pos + (8 * L_MESSAGE))
    {
        return false;
    }

    stream.bitpos = old_pos + (8 * L_MESSAGE);

    return true;
}

bool Request_to_Shorten_MA_Message::encode(Bitstream& stream) const
{
    uint32_t old_pos = stream.bitpos;

    Bitstream_Write(&stream, 10, L_MESSAGE);
    Bitstream_Write(&stream, 32, T_TRAIN);
    Bitstream_Write(&stream, 1, M_ACK);
    Bitstream_Write(&stream, 24, NID_LRBG);

    if (::encode(stream, packet_15->header) != 1)
    {
        return false;
    }
    if (packet_15->encode(stream) != 1)
    {
        return false;
    }

    if (::encode(stream, packet_80->header) != 1)
    {
        return false;
    }
    if (packet_80->encode(stream) != 1)
    {
        return false;
    }

    if (stream.bitpos > old_pos + (8 * L_MESSAGE))
    {
        return false;
    }

    stream.bitpos = old_pos + (8 * L_MESSAGE);

    return true;
} 
