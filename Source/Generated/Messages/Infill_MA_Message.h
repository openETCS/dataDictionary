
#ifndef INFILL_MA_Message_H_INCLUDED
#define INFILL_MA_Message_H_INCLUDED

#include "EuroradioMessage.h"
#include "Bitstream.h"
#include <iostream>

struct Infill_MA_Message : public EuroradioMessage
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN          ;  // # 32
    uint8_t  M_ACK             ;  // # 1
    uint32_t  NID_LRBG         ;  // # 24

    BasePacketPtr  packet_136;
    BasePacketPtr  packet_12;
    PacketSequence  optional_packets;

    Infill_MA_Message() : EuroradioMessage(37) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +header.NID_MESSAGE  << ","
               << +L_MESSAGE << ","
               << +T_TRAIN << ","
               << +M_ACK << ","
               << +NID_LRBG << ","
               << *(packet_136) << ","
               << *(packet_12);

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

    bool equals(const EuroradioMessage& p) const override
    {
        if (auto q = dynamic_cast<const Infill_MA_Message*>(&p))
        {
            bool status = true;

            status = status && (header.NID_MESSAGE == q->header.NID_MESSAGE);
            status = status && (L_MESSAGE == q->L_MESSAGE);
            status = status && (T_TRAIN == q->T_TRAIN);
            status = status && (M_ACK == q->M_ACK);
            status = status && (NID_LRBG == q->NID_LRBG);
            status = status && (*packet_136 == *(q->packet_136));
            status = status && (*packet_12 == *(q->packet_12));

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

typedef std::shared_ptr<Infill_MA_Message> Infill_MA_MessagePtr;

#endif // INFILL_MA_Message_H_INCLUDED

