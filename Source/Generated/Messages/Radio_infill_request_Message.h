
#ifndef RADIO_INFILL_REQUEST_Message_H_INCLUDED
#define RADIO_INFILL_REQUEST_Message_H_INCLUDED

#include "EuroradioMessage.h"
#include "Bitstream.h"
#include <iostream>

struct Radio_infill_request_Message : public EuroradioMessage
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN          ;  // # 32
    uint32_t  NID_ENGINE       ;  // # 24
    uint16_t  NID_C            ;  // # 10
    uint16_t  NID_BG           ;  // # 14
    uint8_t  Q_INFILL          ;  // # 1

    BasePacketPtr  packet_0_1;

    Radio_infill_request_Message() : EuroradioMessage(153) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +header.NID_MESSAGE  << ","
               << +L_MESSAGE << ","
               << +T_TRAIN << ","
               << +NID_ENGINE << ","
               << +NID_C << ","
               << +NID_BG << ","
               << +Q_INFILL << ","
               << *(packet_0_1) << ")";
    }

    bool equals(const EuroradioMessage& p) const override
    {
        if (auto q = dynamic_cast<const Radio_infill_request_Message*>(&p))
        {
            bool status = true;

            status = status && (header.NID_MESSAGE == q->header.NID_MESSAGE);
            status = status && (L_MESSAGE == q->L_MESSAGE);
            status = status && (T_TRAIN == q->T_TRAIN);
            status = status && (NID_ENGINE == q->NID_ENGINE);
            status = status && (NID_C == q->NID_C);
            status = status && (NID_BG == q->NID_BG);
            status = status && (Q_INFILL == q->Q_INFILL);
            status = status && (*packet_0_1 == *(q->packet_0_1));

            return status;
        }

        return false;
    }

    bool decode(Bitstream& stream);

    bool encode(Bitstream& stream) const;
};

typedef std::shared_ptr<Radio_infill_request_Message> Radio_infill_request_MessagePtr;

#endif // RADIO_INFILL_REQUEST_Message_H_INCLUDED

