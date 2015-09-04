
#include "EurobaliseTelegram.h"
#include "TelegramHeader.h"
#include "Packet_Header.h"
#include "Decoder_Branch.h"
#include "Encoder_Branch.h"
#include <iostream>
#include <cassert>

std::ostream& operator<< (std::ostream& stream, const EurobaliseTelegram& telegram)
{
    stream << '(' << telegram.header() << ",";

    for (size_t i = 0; i != telegram.numberPackets(); ++i)
    {
        stream << *telegram.packet(i);

        if (i + 1 != telegram.numberPackets())
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

bool operator==(const EurobaliseTelegram& a, const EurobaliseTelegram& b)
{
    if (a.header() == b.header())
    {
        if (a.numberPackets() == b.numberPackets())
        {
            bool result = true;

            for (size_t i = 0; i < a.numberPackets(); ++i)
            {
                result = result && (*(a.packet(i)) == *(b.packet(i)));
            }

            return result;
        }
    }

    return false;
}

bool operator!=(const EurobaliseTelegram& a, const EurobaliseTelegram& b)
{
    return !(a == b);
}

bool EurobaliseTelegram::decode(Bitstream& stream)
{
    if (TelegramHeader_Decoder(&stream, &m_header) != 1)
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
            std::cerr << stream.bitpos << " != " << current_pos << std::endl;
            return false;
        }

        Packet_Header packet_header;
        Packet_Header_Decoder(&stream, &packet_header);

        BasePacketPtr ptr;

        if (header().Q_UPDOWN == 1)
        {
            ptr = Decoder_Branch_TrackToTrain(stream, packet_header);
        }
        else
        {
            assert(header().Q_UPDOWN == 0);
            ptr = Decoder_Branch_TrainToTrack(stream, packet_header);
        }

        if (ptr)
        {
            m_packets.push_back(ptr);

            if (ptr->header.NID_PACKET == 255)
            {
                break;
            }
        }
        else
        {
            return false;
        }

        current_pos += ptr->length();
    }

    return true;
}

bool EurobaliseTelegram::encode(Bitstream& stream) const
{
    if (TelegramHeader_Encoder(&stream, &header()) != 1)
    {
        return false;
    }

    uint32_t old_pos = stream.bitpos;

    // check that last packet denotes end of message
    assert(m_packets.back()->header.NID_PACKET == 255);

    for (auto p = m_packets.begin(); p != m_packets.end(); ++p)
    {
        if (stream.bitpos > 1023 + old_pos)
        {
            return false;
        }

        if (Packet_Header_Encoder(&stream, &((*p)->header)) != 1)
        {
            return false;
        }

        if (header().Q_UPDOWN == 0)
        {
            if (Encoder_Branch_TrainToTrack(stream, *p) != 1)
            {
                return false;
            }
        }
        else if (header().Q_UPDOWN == 1)
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

