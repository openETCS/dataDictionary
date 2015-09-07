
#ifndef RBC_OR_RIU_SYSTEM_VERSION_Message_H_INCLUDED
#define RBC_OR_RIU_SYSTEM_VERSION_Message_H_INCLUDED

#include "EuroradioMessage.h"
#include "Bitstream.h"
#include <iostream>

struct RBC_or_RIU_System_Version_Message : public EuroradioMessage
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN          ;  // # 32
    uint8_t  M_ACK             ;  // # 1
    uint32_t  NID_LRBG         ;  // # 24
    uint8_t  M_VERSION         ;  // # 7


    RBC_or_RIU_System_Version_Message() : EuroradioMessage(32) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +header.NID_MESSAGE  << ","
               << +L_MESSAGE << ","
               << +T_TRAIN << ","
               << +M_ACK << ","
               << +NID_LRBG << ","
               << +M_VERSION << ")";
    }

    bool equals(const EuroradioMessage& p) const override
    {
        if (auto q = dynamic_cast<const RBC_or_RIU_System_Version_Message*>(&p))
        {
            bool status = true;

            status = status && (header.NID_MESSAGE == q->header.NID_MESSAGE);
            status = status && (L_MESSAGE == q->L_MESSAGE);
            status = status && (T_TRAIN == q->T_TRAIN);
            status = status && (M_ACK == q->M_ACK);
            status = status && (NID_LRBG == q->NID_LRBG);
            status = status && (M_VERSION == q->M_VERSION);

            return status;
        }

        return false;
    }

    bool decode(Bitstream& stream);

    bool encode(Bitstream& stream) const;
};

typedef std::shared_ptr<RBC_or_RIU_System_Version_Message> RBC_or_RIU_System_Version_MessagePtr;

#endif // RBC_OR_RIU_SYSTEM_VERSION_Message_H_INCLUDED

