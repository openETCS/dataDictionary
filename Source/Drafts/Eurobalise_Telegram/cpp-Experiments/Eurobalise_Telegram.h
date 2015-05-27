
#ifndef EUROBALISE_TELEGRAM_H_INCLUDED
#define EUROBALISE_TELEGRAM_H_INCLUDED

#include "Eurobalise_Header.h"
#include "BasePacket.h"
#include <iostream>

typedef std::vector<BasePacketPtr> PacketSequence;

struct Eurobalise_Telegram
{
    Eurobalise_Header header;
    PacketSequence packets;

    bool Decoder(Bitstream* stream);
    bool Encoder(Bitstream* stream);
};

inline std::ostream& operator<< (std::ostream& stream, const Eurobalise_Telegram& p)
{
    stream << p.header << "\n";
    for(auto i = p.packets.begin(); i != p.packets.end(); ++i)
    {
        stream << *(*i) << "\n";
    }
    return stream;
}

inline bool operator==(const Eurobalise_Telegram& a, const Eurobalise_Telegram& b)
{
    if(a.header == b.header)
    {
        if(a.packets.size() == b.packets.size())
	{
           bool result = true;   	
	   for(size_t i = 0; i < a.packets.size(); ++i)
	   {
               result = result && (*(a.packets[i]) == *(b.packets[i]));
	   }
	   return result;
	}
    }
    return false;
}

inline bool operator!=(const Eurobalise_Telegram& a, const Eurobalise_Telegram& b)
{
    return !(a == b);
}

#endif // EUROBALISE_TELEGRAM_H_INCLUDED

