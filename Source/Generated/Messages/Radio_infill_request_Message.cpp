
#include "Radio_infill_request_Message.h"
#include "PacketHeader.h"
#include "PacketFactory.h"
#include "Bitstream.h"
#include "Bitwalker.h"
#include <iostream>
#include <cassert>

bool Radio_infill_request_Message::decode(Bitstream& stream)
{
    uint32_t old_pos = stream.bitpos;

    L_MESSAGE = Bitstream_Read(&stream, 10);
    T_TRAIN = Bitstream_Read(&stream, 32);
    NID_ENGINE = Bitstream_Read(&stream, 24);
    NID_C = Bitstream_Read(&stream, 10);
    NID_BG = Bitstream_Read(&stream, 14);
    Q_INFILL = Bitstream_Read(&stream, 1);

    PacketHeader packetID;

    ::decode(stream, packetID);
    packet_0_1 = PacketFactory_TrainToTrack(stream, packetID);
    packet_0_1->decode(stream);
    if (!packet_0_1)
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

bool Radio_infill_request_Message::encode(Bitstream& stream) const
{
    uint32_t old_pos = stream.bitpos;

    Bitstream_Write(&stream, 10, L_MESSAGE);
    Bitstream_Write(&stream, 32, T_TRAIN);
    Bitstream_Write(&stream, 24, NID_ENGINE);
    Bitstream_Write(&stream, 10, NID_C);
    Bitstream_Write(&stream, 14, NID_BG);
    Bitstream_Write(&stream, 1, Q_INFILL);

    if (::encode(stream, packet_0_1->header) != 1)
    {
        return false;
    }
    if (packet_0_1->encode(stream) != 1)
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
