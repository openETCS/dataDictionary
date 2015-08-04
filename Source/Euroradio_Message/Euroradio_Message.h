
#ifndef EURORADIO_MESSAGE_H_INCLUDED
#define EURORADIO_MESSAGE_H_INCLUDED

#include "BasePacket.h"
#include "Bitstream.h"
#include <iostream>

struct Euroradio_Message
{
    uint8_t  NID_MESSAGE; // # 8
    uint16_t L_MESSAGE;   // # 10
    uint32_t T_TRAIN;     // # 32

    virtual void print(std::ostream& stream) const = 0;

    virtual bool equals(const Euroradio_Message& p) const = 0;
};

inline bool operator==(const Euroradio_Message& a, const Euroradio_Message& b)
{
    return a.equals(b);
}

inline bool operator!=(const Euroradio_Message& a, const Euroradio_Message& b)
{
    return !(a == b);
}

inline std::ostream& operator<< (std::ostream& stream, const Euroradio_Message& p)
{
    p.print(stream);
    return stream;
}

typedef std::shared_ptr<Euroradio_Message> Euroradio_MessagePtr;

#endif // EURORADIO_MESSAGE_H_INCLUDED

