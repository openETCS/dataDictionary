
#ifndef SOM_POSITION_REPORT_Message_H_INCLUDED
#define SOM_POSITION_REPORT_Message_H_INCLUDED

#include "EuroradioMessage.h"
#include "Bitstream.h"
#include <iostream>

struct SoM_Position_Report_Message : public EuroradioMessage
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN          ;  // # 32
    uint32_t  NID_ENGINE       ;  // # 24
    uint8_t  Q_STATUS          ;  // # 2

    BasePacketPtr  packet_0_1;
    PacketSequence  optional_packets;

    SoM_Position_Report_Message() : EuroradioMessage(157) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +header.NID_MESSAGE  << ","
               << +L_MESSAGE << ","
               << +T_TRAIN << ","
               << +NID_ENGINE << ","
               << +Q_STATUS << ","
               << *(packet_0_1);

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
        if (auto q = dynamic_cast<const SoM_Position_Report_Message*>(&p))
        {
            bool status = true;

            status = status && (header.NID_MESSAGE == q->header.NID_MESSAGE);
            status = status && (L_MESSAGE == q->L_MESSAGE);
            status = status && (T_TRAIN == q->T_TRAIN);
            status = status && (NID_ENGINE == q->NID_ENGINE);
            status = status && (Q_STATUS == q->Q_STATUS);
            status = status && (*packet_0_1 == *(q->packet_0_1));

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

typedef std::shared_ptr<SoM_Position_Report_Message> SoM_Position_Report_MessagePtr;

#endif // SOM_POSITION_REPORT_Message_H_INCLUDED

