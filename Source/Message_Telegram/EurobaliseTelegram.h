
#ifndef EUROBALISETELEGRAM_H_INCLUDED
#define EUROBALISETELEGRAM_H_INCLUDED

#include "TelegramHeader.h"
#include "BasePacket.h"
#include <iostream>
#include <vector>

typedef std::vector<BasePacketPtr> PacketSequence;

class EurobaliseTelegram
{
        TelegramHeader m_header;

        PacketSequence  m_packets;

    public:

        EurobaliseTelegram() : m_header(), m_packets()
        {
            m_packets.reserve(32);
        }

        EurobaliseTelegram(const TelegramHeader& h) : m_header(h), m_packets()
        {
            m_packets.reserve(32);
        }

        const TelegramHeader& header() const
        {
            return m_header;
        }

        size_t  numberPackets() const
        {
            return m_packets.size();
        }

        BasePacketPtr packet(size_t i) const
        {
            return m_packets[i];
        }

        void add(BasePacketPtr p)
        {
            m_packets.push_back(p);
        }

        bool decode(Bitstream& stream);

        bool encode(Bitstream& stream) const;
};

std::ostream& operator<<(std::ostream& stream, const EurobaliseTelegram& p);

bool operator==(const EurobaliseTelegram& a, const EurobaliseTelegram& b);

bool operator!=(const EurobaliseTelegram& a, const EurobaliseTelegram& b);

#endif // EUROBALISETELEGRAM_H_INCLUDED

