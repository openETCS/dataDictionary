

#ifndef GENERICPACKET_H_INCLUDED
#define GENERICPACKET_H_INCLUDED

#include "BasePacket.h"

template<typename T>
class GenericPacket : public BasePacket 
{

    T core;

public:

    GenericPacket() : BasePacket(packet_id(&core)), core() {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }


    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const GenericPacket<T>*>(&p))
        {
            return (header == q->header) && (core == q->core);
        }

        return false;
    }

    uint16_t length() const override
    {
        return  core.L_PACKET;
    }


};

#endif // GENERICPACKET_H_INCLUDED

