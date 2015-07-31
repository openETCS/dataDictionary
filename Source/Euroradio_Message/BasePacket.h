
#ifndef BASEPACKET_H_INCLUDED
#define BASEPACKET_H_INCLUDED

#include <cstdlib>
#include <cstdint>
#include <memory>
#include <vector>
#include <iostream>

struct BasePacket
{
    uint8_t id;

    BasePacket(int id1) : id(id1) {}

    virtual void print(std::ostream& stream) const = 0;

    virtual bool equals(const BasePacket& p) const = 0;
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

#endif // BASEPACKET_H_INCLUDED

