
#ifndef ACKNOWLEDGEMENT_OF_TERMINATION_OF_A_COMMUNICATION_SESSION_Message_H_INCLUDED
#define ACKNOWLEDGEMENT_OF_TERMINATION_OF_A_COMMUNICATION_SESSION_Message_H_INCLUDED

#include "EuroradioMessage.h"
#include "Bitstream.h"
#include <iostream>

struct Acknowledgement_of_termination_of_a_communication_session_Message : public EuroradioMessage
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN          ;  // # 32
    uint8_t  M_ACK             ;  // # 1
    uint32_t  NID_LRBG         ;  // # 24


    Acknowledgement_of_termination_of_a_communication_session_Message() : EuroradioMessage(39) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +header.NID_MESSAGE  << ","
               << +L_MESSAGE << ","
               << +T_TRAIN << ","
               << +M_ACK << ","
               << +NID_LRBG << ")";
    }

    bool equals(const EuroradioMessage& p) const override
    {
        if (auto q = dynamic_cast<const Acknowledgement_of_termination_of_a_communication_session_Message*>(&p))
        {
            bool status = true;

            status = status && (header.NID_MESSAGE == q->header.NID_MESSAGE);
            status = status && (L_MESSAGE == q->L_MESSAGE);
            status = status && (T_TRAIN == q->T_TRAIN);
            status = status && (M_ACK == q->M_ACK);
            status = status && (NID_LRBG == q->NID_LRBG);

            return status;
        }

        return false;
    }

    bool decode(Bitstream& stream);

    bool encode(Bitstream& stream) const;
};

typedef std::shared_ptr<Acknowledgement_of_termination_of_a_communication_session_Message> Acknowledgement_of_termination_of_a_communication_session_MessagePtr;

#endif // ACKNOWLEDGEMENT_OF_TERMINATION_OF_A_COMMUNICATION_SESSION_Message_H_INCLUDED

