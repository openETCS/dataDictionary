
#ifndef EURORADIO_MESSAGE_H_INCLUDED
#define EURORADIO_MESSAGE_H_INCLUDED

#include <iostream>
#include "BasePacket.h"
#include "MessageHeader.h"


struct EuroradioMessage
{
    MessageHeader header;

    EuroradioMessage(uint8_t nid)
    {
        header.NID_MESSAGE = nid;
    }

    virtual void print(std::ostream& stream) const = 0;

    virtual bool equals(const EuroradioMessage& p) const = 0;
};

inline bool operator==(const EuroradioMessage& a, const EuroradioMessage& b)
{
    return a.equals(b);
}

inline bool operator!=(const EuroradioMessage& a, const EuroradioMessage& b)
{
    return !(a == b);
}

inline std::ostream& operator<< (std::ostream& stream, const EuroradioMessage& p)
{
    p.print(stream);
    return stream;
}

typedef std::shared_ptr<EuroradioMessage> EuroradioMessagePtr;

EuroradioMessagePtr EuroradioMessage_Decoder(Bitstream& stream);

bool EuroradioMessage_Encoder(Bitstream& stream, EuroradioMessagePtr p);


#endif // EURORADIO_MESSAGE_H_INCLUDED

