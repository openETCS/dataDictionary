
#include "Acknowledgement_of_Emergency_Stop_Message.h"
#include "PacketHeader.h"
#include "PacketFactory.h"
#include "Bitstream.h"
#include "Bitwalker.h"
#include <iostream>
#include <cassert>

bool Acknowledgement_of_Emergency_Stop_Message::decode(Bitstream& stream)
{
    uint32_t old_pos = stream.bitpos;

    L_MESSAGE = Bitstream_Read(&stream, 10);
    T_TRAIN = Bitstream_Read(&stream, 32);
    NID_ENGINE = Bitstream_Read(&stream, 24);
    NID_EM = Bitstream_Read(&stream, 4);
    Q_EMERGENCYSTOP = Bitstream_Read(&stream, 2);

    PacketHeader packetID;

    ::decode(stream, packetID);
    packet_0_1 = PacketFactory_TrainToTrack(packetID.NID_PACKET);
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

bool Acknowledgement_of_Emergency_Stop_Message::encode(Bitstream& stream) const
{
    uint32_t old_pos = stream.bitpos;

    Bitstream_Write(&stream, 10, L_MESSAGE);
    Bitstream_Write(&stream, 32, T_TRAIN);
    Bitstream_Write(&stream, 24, NID_ENGINE);
    Bitstream_Write(&stream, 4, NID_EM);
    Bitstream_Write(&stream, 2, Q_EMERGENCYSTOP);

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
