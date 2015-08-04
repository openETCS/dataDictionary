
#ifndef EURORADIO_MESSAGE_H_INCLUDED
#define EURORADIO_MESSAGE_H_INCLUDED

#include "BasePacket.h"
#include "Bitstream.h"
#include <iostream>

struct Euroradio_Message
{
    uint8_t  NID_MESSAGE; // # 8

    Euroradio_Message();

    Euroradio_Message(int nid) : NID_MESSAGE(nid) {}

    virtual void print(std::ostream& stream) const;

    virtual bool equals(const Euroradio_Message& p) const;

    bool decode(Bitstream& stream);
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

Euroradio_MessagePtr Euroradio_Message_Decoder(Bitstream& stream);

bool Euroradio_Message_Encoder(Bitstream& stream, Euroradio_MessagePtr p);

#endif // EURORADIO_MESSAGE_H_INCLUDED

