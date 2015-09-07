
#ifndef ACKNOWLEDGEMENT_OF_EMERGENCY_STOP_Message_H_INCLUDED
#define ACKNOWLEDGEMENT_OF_EMERGENCY_STOP_Message_H_INCLUDED

#include "EuroradioMessage.h"
#include "Bitstream.h"
#include <iostream>

struct Acknowledgement_of_Emergency_Stop_Message : public EuroradioMessage
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN          ;  // # 32
    uint32_t  NID_ENGINE       ;  // # 24
    uint8_t  NID_EM            ;  // # 4
    uint8_t  Q_EMERGENCYSTOP   ;  // # 2

    BasePacketPtr  packet_0_1;

    Acknowledgement_of_Emergency_Stop_Message() : EuroradioMessage(147) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +header.NID_MESSAGE  << ","
               << +L_MESSAGE << ","
               << +T_TRAIN << ","
               << +NID_ENGINE << ","
               << +NID_EM << ","
               << +Q_EMERGENCYSTOP << ","
               << *(packet_0_1) << ")";
    }

    bool equals(const EuroradioMessage& p) const override
    {
        if (auto q = dynamic_cast<const Acknowledgement_of_Emergency_Stop_Message*>(&p))
        {
            bool status = true;

            status = status && (header.NID_MESSAGE == q->header.NID_MESSAGE);
            status = status && (L_MESSAGE == q->L_MESSAGE);
            status = status && (T_TRAIN == q->T_TRAIN);
            status = status && (NID_ENGINE == q->NID_ENGINE);
            status = status && (NID_EM == q->NID_EM);
            status = status && (Q_EMERGENCYSTOP == q->Q_EMERGENCYSTOP);
            status = status && (*packet_0_1 == *(q->packet_0_1));

            return status;
        }

        return false;
    }

    bool decode(Bitstream& stream);

    bool encode(Bitstream& stream) const;
};

typedef std::shared_ptr<Acknowledgement_of_Emergency_Stop_Message> Acknowledgement_of_Emergency_Stop_MessagePtr;

#endif // ACKNOWLEDGEMENT_OF_EMERGENCY_STOP_Message_H_INCLUDED

