
#include "Eurobalise_Telegram.h"
#include "Telegram_Header_Decoder.h"
#include "Telegram_Header_Encoder.h"
#include "Packet_Header_Decoder.h"
#include "Packet_Header_Encoder.h"
#include "Decoder_Branch.h"
#include "Encoder_Branch.h"

#include <iostream>
#include <cassert>


std::ostream& operator<< (std::ostream& stream, const Eurobalise_Telegram& p)
{
    stream << '(' << p.header << ",";

    for (auto i = p.packets.begin(); i != p.packets.end(); ++i)
    {
        stream << *(*i);

        if (i + 1 != p.packets.end())
        {
            stream << ',';
        }
        else
        {
            stream << ')';
        }

    }

    return stream;
}

bool operator==(const Eurobalise_Telegram& a, const Eurobalise_Telegram& b)
{
    if (a.header == b.header)
    {
        if (a.packets.size() == b.packets.size())
        {
            bool result = true;

            for (size_t i = 0; i < a.packets.size(); ++i)
            {
                result = result && (*(a.packets[i]) == *(b.packets[i]));
            }

            return result;
        }
    }

    return false;
}

bool operator!=(const Eurobalise_Telegram& a, const Eurobalise_Telegram& b)
{
    return !(a == b);
}

bool Eurobalise_Telegram::decode(Bitstream& stream)
{
    Packet_Header packetID;

    if (Telegram_Header_Decoder(&stream, &(header)) != 1)
    {
        return false;
    }

    //std::cout << stream->bitpos << std::endl;

    uint32_t old_pos = stream.bitpos;

    while (stream.bitpos <= 1023 + old_pos)
    {
        Packet_Header_Decoder(&stream, &packetID);

        BasePacketPtr packet;

        if (header.Q_UPDOWN == 1)
        {
            packet = Decoder_Branch_TrackToTrain(stream, packetID);
        }
        else
        {
            assert(header.Q_UPDOWN == 0);
            packet = Decoder_Branch_TrainToTrack(stream, packetID);
        }

        if (packet)
        {
            packets.push_back(packet);

            if (packetID.NID_PACKET == 255)
            {
                break;
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool Eurobalise_Telegram::encode(Bitstream& stream) const
{
    uint32_t old_pos = stream.bitpos;
    Packet_Header packetID;

    if (Telegram_Header_Encoder(&stream, &header) != 1)
    {
        return false;
    }

    // check that last packet denotes end of message
    assert(packets.back()->id == 255);

    for (auto p = packets.begin(); p != packets.end(); ++p)
    {
        packetID.NID_PACKET = (*p)->id;

        if (Packet_Header_Encoder(&stream, &packetID) != 1)
        {
            return false;
        }

        if (header.Q_UPDOWN == 0)
        {
            if (Encoder_Branch_TrainToTrack(stream, *p) != 1)
            {
                return false;
            }
        }
        else if (header.Q_UPDOWN == 1)
        {
	    if (Encoder_Branch_TrackToTrain(stream, *p) != 1)
	    {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

