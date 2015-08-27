
#ifndef REQUEST_TO_SHORTEN_MA_IS_REJECTED_Message_H_INCLUDED
#define REQUEST_TO_SHORTEN_MA_IS_REJECTED_Message_H_INCLUDED

#include "Euroradio_Message.h"
#include "Bitstream.h"
#include <iostream>

struct Request_to_shorten_MA_is_rejected_Message : public Euroradio_Message
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN          ;  // # 32
    uint32_t  NID_ENGINE       ;  // # 24

    BasePacketPtr  packet_0_1;

    Request_to_shorten_MA_is_rejected_Message() : Euroradio_Message(138) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +header.NID_MESSAGE  << ","
               << +L_MESSAGE << ","
               << +T_TRAIN << ","
               << +NID_ENGINE << ","
               << *(packet_0_1) << ")";
    }

    bool equals(const Euroradio_Message& p) const override
    {
	if (auto q = dynamic_cast<const Request_to_shorten_MA_is_rejected_Message*>(&p))
	{
            bool status = true;
    
            status = status && (header.NID_MESSAGE == q->header.NID_MESSAGE);
            status = status && (L_MESSAGE == q->L_MESSAGE);
            status = status && (T_TRAIN == q->T_TRAIN);
            status = status && (NID_ENGINE == q->NID_ENGINE);
            status = status && (*packet_0_1 == *(q->packet_0_1));

            return status;
        }
	return false;
    }

    bool decode(Bitstream& stream);

    bool encode(Bitstream& stream) const;
};

typedef std::shared_ptr<Request_to_shorten_MA_is_rejected_Message> Request_to_shorten_MA_is_rejected_MessagePtr;

#endif // REQUEST_TO_SHORTEN_MA_IS_REJECTED_Message_H_INCLUDED

