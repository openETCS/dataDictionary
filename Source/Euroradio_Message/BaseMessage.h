
#ifndef BASEMESSAGE_H_INCLUDED
#define BASEMESSAGE_H_INCLUDED

#include "BasePacket.h"
#include "Bitstream.h"
#include <iostream>

struct BaseMessage
{
    uint8_t  NID_MESSAGE; // # 8
    uint16_t L_MESSAGE;   // # 10
    uint32_t T_TRAIN;     // # 32

    virtual void print(std::ostream& stream) const = 0;

    virtual bool equals(const BaseMessage& p) const = 0;
};

inline bool operator==(const BaseMessage& a, const BaseMessage& b)
{
    return a.equals(b);
}

inline bool operator!=(const BaseMessage& a, const BaseMessage& b)
{
    return !(a == b);
}

inline std::ostream& operator<< (std::ostream& stream, const BaseMessage& p)
{
    p.print(stream);
    return stream;
}

typedef std::shared_ptr<BaseMessage> BaseMessagePtr;

#endif // BASEMESSAGE_H_INCLUDED

