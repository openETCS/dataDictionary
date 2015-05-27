
#ifndef BASEPACKET_H_INCLUDED
#define BASEPACKET_H_INCLUDED

#include <cstdlib>
#include <memory>
#include <vector>
#include <iostream>

struct BasePacket
{
    int id;

    BasePacket(int id1) : id(id1) {}

    virtual void print(std::ostream& stream) const = 0;
};

inline std::ostream& operator<< (std::ostream& stream, const BasePacket& p)
{
    p.print(stream);
    return stream;
}

typedef std::shared_ptr<BasePacket> BasePacketPtr;

#endif // BASEPACKET_H_INCLUDED

