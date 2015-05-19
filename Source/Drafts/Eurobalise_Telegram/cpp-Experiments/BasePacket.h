
#ifndef BASEPACKET_H_INCLUDED
#define BASEPACKET_H_INCLUDED

#include <cstdlib>
#include <memory>
#include <vector>

struct BasePacket
{
    int id;

    BasePacket(int id1) : id(id1) {}
};

typedef std::shared_ptr<BasePacket> BasePacketPtr;

#endif // BASEPACKET_H_INCLUDED

