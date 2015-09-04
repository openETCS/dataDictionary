
#ifndef EUROBALISE_TELEGRAM_H_INCLUDED
#define EUROBALISE_TELEGRAM_H_INCLUDED

#include "Telegram_Header.h"
#include "BasePacket.h"
#include <iostream>
#include <vector>

typedef std::vector<BasePacketPtr> PacketSequence;

class Eurobalise_Telegram
{
        Telegram_Header m_header;

        PacketSequence  m_packets;

    public:

        Eurobalise_Telegram() : m_header(), m_packets()
        {
            m_packets.reserve(32);
        }

        Eurobalise_Telegram(const Telegram_Header& h) : m_header(h), m_packets()
        {
            m_packets.reserve(32);
        }

        const Telegram_Header& header() const
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

std::ostream& operator<<(std::ostream& stream, const Eurobalise_Telegram& p);

bool operator==(const Eurobalise_Telegram& a, const Eurobalise_Telegram& b);

bool operator!=(const Eurobalise_Telegram& a, const Eurobalise_Telegram& b);

#endif // EUROBALISE_TELEGRAM_H_INCLUDED

