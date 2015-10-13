
#include "EurobaliseTelegram.h"
#include "PacketFactory.h"
#include "Packet.h"

#ifdef __cplusplus

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

#endif

int EurobaliseTelegram_DecodeBit(EurobaliseTelegram* t, Bitstream* stream)
{
    printf("EurobaliseTelegram_DecodeBit::enter\n");

    if (TelegramHeader_DecodeBit(stream, &t->header) != 1)
    {
        return 0;
    }

    printf("EurobaliseTelegram_DecodeBit::t->header.Q_UPDOWN = %d\n", t->header.Q_UPDOWN);

    //std::cout << stream->bitpos << std::endl;

    const uint32_t old_pos = stream->bitpos;
    uint32_t current_pos = stream->bitpos;

    while (stream->bitpos <= 1023 + old_pos)
    {
        if (current_pos != stream->bitpos)
        {
	    printf("problem here %llu is not %llu\n", current_pos, stream->bitpos);
            //std::cerr << stream->bitpos << " != " << current_pos << std::endl;
            return 0;
        }

        PacketHeader packet_header = {0};
        PacketHeader_DecodeBit(&packet_header, stream);
        printf("EurobaliseTelegram_DecodeBit::packet_header = %d\n", packet_header.NID_PACKET);

        PacketHeader* ptr = 0;

        if(packet_header.NID_PACKET == 255)
        {
            ptr = PacketFactory_BothWays(packet_header);
            assert(ptr);

            // beware: no need to decode further fields 
            EurobaliseTelegram_Add(t, ptr);
            printf("EurobaliseTelegram_DecodeBit size after add = %d\n", EurobaliseTelegram_Size(t));
            break;
        }

        if (t->header.Q_UPDOWN == 1)
        {

            PacketHeader* ptr = PacketFactory_TrackToTrain(packet_header);
            if (ptr)
            {
                TrackToTrain_DecodeBit(ptr, stream);
                EurobaliseTelegram_Add(t, ptr);
                printf("EurobaliseTelegram_DecodeBit size after add = %d\n", EurobaliseTelegram_Size(t));
                current_pos += Packet_Length(ptr);
            }
            else
            {
                return 0;
            }
        }
        else
        {
            assert(t->header.Q_UPDOWN == 0);
            PacketHeader* ptr = PacketFactory_TrainToTrack(packet_header);
            if (ptr)
            {
                TrainToTrack_DecodeBit(ptr, stream);
                EurobaliseTelegram_Add(t, ptr);
	        printf("EurobaliseTelegram_DecodeBit size after add = %d\n", EurobaliseTelegram_Size(t));
                current_pos += Packet_Length(ptr);
            }
            else
            {
                return 0;
            }
        }

	if (ptr)
	{
            //current_pos += Packet_Length(ptr);
	}
    }

    return 1;
}

/*
bool EurobaliseTelegram::encode(Bitstream& stream) const
{
    if (::encode(stream, header()) != 1)
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

        if (::encode(stream, (*p)->header) != 1)
        {
            return false;
        }

        if ((*p)->encode(stream) != 1)
        {
            return false;
        }

    }

    return true;
}

bool EurobaliseTelegram::encode(FlatPackets& packetStruct) const
{
    kcg_int startAddress = 0;
    unsigned int i;

    for (i = 0; i < m_packets.size(); ++i)
    {
        packetStruct.PacketHeaders[i].startAddress = startAddress;
        m_packets[i]->encode(packetStruct.PacketHeaders[i], packetStruct.PacketData);
        startAddress = packetStruct.PacketHeaders[i].endAddress + 1;
    }

    if (packetStruct.PacketHeaders[i - 1].nid_packet != 255)
    {
        return false;
    }

    return true;
}

bool EurobaliseTelegram::decode(FlatPackets& packetStruct)
{
    for (unsigned int i = 0; i < 50; ++i)
    {
        if (packetStruct.PacketHeaders[i].valid == 1)
        {
            BasePacketPtr ptr;

            if (m_header.Q_UPDOWN == 0)
            {
                ptr = PacketFactory_TrainToTrack(packetStruct.PacketHeaders[i].nid_packet);
            }
            else if (m_header.Q_UPDOWN == 1)
            {
                ptr = PacketFactory_TrackToTrain(packetStruct.PacketHeaders[i].nid_packet);
            }
            else
            {
                std::cout << "wrong q_updown" << std::endl;
                return false;
            }

            if (ptr)
            {
                ptr->decode(packetStruct.PacketHeaders[i], packetStruct.PacketData);

                m_packets.push_back(ptr);
            }
            else
            {
                return false;
            }

            if (ptr->header.NID_PACKET == 255)
            {
                break;
            }
        }
    }

    return true;
}

*/
