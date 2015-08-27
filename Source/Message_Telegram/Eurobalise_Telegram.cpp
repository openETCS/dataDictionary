
#include "Eurobalise_Telegram.h"
#include "Telegram_Header_Decoder.h"
#include "Telegram_Header_Encoder.h"
#include "Packet_Header.h"
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
    if (Telegram_Header_Decoder(&stream, &(header)) != 1)
    {
        return false;
    }

    //std::cout << stream->bitpos << std::endl;

    const uint32_t old_pos = stream.bitpos;
    uint32_t current_pos = stream.bitpos;

    while (stream.bitpos <= 1023 + old_pos)
    {
        if (current_pos != stream.bitpos)
        {
            std::cout << stream.bitpos << " != " << current_pos << std::endl;
            return false;
        }

        Packet_Header packet_header;
        Packet_Header_Decoder(&stream, &packet_header);

        BasePacketPtr ptr;

        if (header.Q_UPDOWN == 1)
        {
            ptr = Decoder_Branch_TrackToTrain(stream, packet_header);
        }
        else
        {
            assert(header.Q_UPDOWN == 0);
            ptr = Decoder_Branch_TrainToTrack(stream, packet_header);
        }

        if (ptr)
        {
            packets.push_back(ptr);

            if (ptr->header.NID_PACKET == 255)
            {
                break;
            }
        }
        else
        {
            return false;
        }

        current_pos += (*ptr).length();
    }

    return true;
}

bool Eurobalise_Telegram::encode(Bitstream& stream) const
{
    if (Telegram_Header_Encoder(&stream, &header) != 1)
    {
        return false;
    }

    uint32_t old_pos = stream.bitpos;

    // check that last packet denotes end of message
    assert(packets.back()->header.NID_PACKET == 255);

    for (auto p = packets.begin(); p != packets.end(); ++p)
    {
        if (stream.bitpos > 1023 + old_pos)
        {
            return false;
        }

        if (Packet_Header_Encoder(&stream, &((*p)->header)) != 1)
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

