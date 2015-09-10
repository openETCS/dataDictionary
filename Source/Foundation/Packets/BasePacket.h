
#ifndef BASEPACKET_H_INCLUDED
#define BASEPACKET_H_INCLUDED

#include <cstdlib>
#include <cstdint>
#include <memory>
#include <vector>
#include <iostream>

#include "PacketHeader.h"

struct BasePacket
{
    PacketHeader header;

    BasePacket(uint8_t nid)
    {
        header.NID_PACKET = nid;
    }

    virtual void print(std::ostream& stream) const = 0;

    virtual bool equals(const BasePacket& p) const = 0;

    virtual uint16_t length() const = 0;

    virtual int encode(Bitstream&) const = 0;

};

inline bool operator== (const BasePacket& a, const BasePacket& b)
{
    return a.equals(b);
}

inline bool operator!= (const BasePacket& a, const BasePacket& b)
{
    return !(a == b);
}

inline std::ostream& operator<< (std::ostream& stream, const BasePacket& p)
{
    p.print(stream);
    return stream;
}

typedef std::shared_ptr<BasePacket> BasePacketPtr;

typedef std::vector<BasePacketPtr> PacketSequence;

#endif // BASEPACKET_H_INCLUDED

