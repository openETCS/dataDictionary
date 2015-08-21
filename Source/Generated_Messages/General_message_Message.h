
#ifndef GENERAL_MESSAGE_Message_H_INCLUDED
#define GENERAL_MESSAGE_Message_H_INCLUDED

#include "Euroradio_Message.h"
#include "Bitstream.h"
#include <iostream>

struct General_message_Message : public Euroradio_Message
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN          ;  // # 32
    uint8_t  M_ACK             ;  // # 1
    uint32_t  NID_LRBG         ;  // # 24

    PacketSequence  optional_packets;

    General_message_Message() : Euroradio_Message(24) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +header.NID_MESSAGE  << ","
               << +L_MESSAGE << ","
               << +T_TRAIN << ","
               << +M_ACK << ","
               << +NID_LRBG;

        for (auto i = optional_packets.begin(); i != optional_packets.end(); ++i)
        {
            if (i == optional_packets.begin())
            {
                stream << ',';
            }
            stream << *(*i);
        }

        stream << ")";
    }

    bool equals(const Euroradio_Message& p) const override
    {
	if (auto q = dynamic_cast<const General_message_Message*>(&p))
	{
            bool status = true;
    
            status = status && (header.NID_MESSAGE == q->header.NID_MESSAGE);
            status = status && (L_MESSAGE == q->L_MESSAGE);
            status = status && (T_TRAIN == q->T_TRAIN);
            status = status && (M_ACK == q->M_ACK);
            status = status && (NID_LRBG == q->NID_LRBG);

            if (optional_packets.size() == q->optional_packets.size())
            {
                for (size_t i = 0; i < optional_packets.size(); ++i)
                {
                    status = status && (*(optional_packets[i]) == *(q->optional_packets[i]));
                }
            }
            else
            {
                return false;
            }

            return status;
        }
	return false;
    }

    bool decode(Bitstream& stream);

    bool encode(Bitstream& stream) const;
};

typedef std::shared_ptr<General_message_Message> General_message_MessagePtr;

#endif // GENERAL_MESSAGE_Message_H_INCLUDED

