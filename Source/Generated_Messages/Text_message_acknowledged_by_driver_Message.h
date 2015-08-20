
#ifndef TEXT_MESSAGE_ACKNOWLEDGED_BY_DRIVER_Message_H_INCLUDED
#define TEXT_MESSAGE_ACKNOWLEDGED_BY_DRIVER_Message_H_INCLUDED

#include "Euroradio_Message.h"
#include "Bitstream.h"
#include <iostream>

struct Text_message_acknowledged_by_driver_Message : public Euroradio_Message
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN          ;  // # 32
    uint32_t  NID_ENGINE       ;  // # 24
    uint8_t  NID_TEXTMESSAGE   ;  // # 8


    Packet_Header packetID;
    BasePacketPtr  packet_0_1;

    Text_message_acknowledged_by_driver_Message() : Euroradio_Message(158) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +header.NID_MESSAGE  << ","
               << +L_MESSAGE << ","
               << +T_TRAIN << ","
               << +NID_ENGINE << ","
               << +NID_TEXTMESSAGE << ","
               << *(packet_0_1) << ")";
    }

    bool equals(const Euroradio_Message& p) const override
    {
	if (auto q = dynamic_cast<const Text_message_acknowledged_by_driver_Message*>(&p))
	{
            bool status = true;
    
            status = status && (header.NID_MESSAGE == q->header.NID_MESSAGE);
            status = status && (L_MESSAGE == q->L_MESSAGE);
            status = status && (T_TRAIN == q->T_TRAIN);
            status = status && (NID_ENGINE == q->NID_ENGINE);
            status = status && (NID_TEXTMESSAGE == q->NID_TEXTMESSAGE);
            status = status && (*packet_0_1 == *(q->packet_0_1));

            return status;
        }
	return false;
    }

    bool decode(Bitstream& stream);

    bool encode(Bitstream& stream) const;
};

typedef std::shared_ptr<Text_message_acknowledged_by_driver_Message> Text_message_acknowledged_by_driver_MessagePtr;

#endif // TEXT_MESSAGE_ACKNOWLEDGED_BY_DRIVER_Message_H_INCLUDED

