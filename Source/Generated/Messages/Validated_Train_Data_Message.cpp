
#include "Validated_Train_Data_Message.h"
#include "PacketHeader.h"
#include "PacketFactory.h"
#include "Bitstream.h"
#include "Bitwalker.h"
#include <iostream>
#include <cassert>

bool Validated_Train_Data_Message::decode(Bitstream& stream)
{
    uint32_t old_pos = stream.bitpos;

    L_MESSAGE = Bitstream_Read(&stream, 10);
    T_TRAIN = Bitstream_Read(&stream, 32);
    NID_ENGINE = Bitstream_Read(&stream, 24);

    PacketHeader packetID{0};

    ::decode(stream, packetID);
    packet_0_1 = PacketFactory_TrainToTrack(packetID.NID_PACKET);
    packet_0_1->decode(stream);
    if (!packet_0_1)
    {
        return false;
    }

    ::decode(stream, packetID);
    packet_11 = PacketFactory_TrainToTrack(packetID.NID_PACKET);
    packet_11->decode(stream);
    if (!packet_11)
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

bool Validated_Train_Data_Message::encode(Bitstream& stream) const
{
    uint32_t old_pos = stream.bitpos;

    Bitstream_Write(&stream, 10, L_MESSAGE);
    Bitstream_Write(&stream, 32, T_TRAIN);
    Bitstream_Write(&stream, 24, NID_ENGINE);

    if (::encode(stream, packet_0_1->header) != 1)
    {
        return false;
    }
    if (packet_0_1->encode(stream) != 1)
    {
        return false;
    }

    if (::encode(stream, packet_11->header) != 1)
    {
        return false;
    }
    if (packet_11->encode(stream) != 1)
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
