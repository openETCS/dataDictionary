
#ifndef TERMINATION_OF_A_COMMUNICATION_SESSION_Message_H_INCLUDED
#define TERMINATION_OF_A_COMMUNICATION_SESSION_Message_H_INCLUDED

#include "Euroradio_Message.h"
#include "Bitstream.h"
#include <iostream>

struct Termination_of_a_communication_session_Message : public Euroradio_Message
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN          ;  // # 32
    uint32_t  NID_ENGINE       ;  // # 24


    Termination_of_a_communication_session_Message() : Euroradio_Message(156) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +header.NID_MESSAGE  << ","
               << +L_MESSAGE << ","
               << +T_TRAIN << ","
               << +NID_ENGINE << ")";
    }

    bool equals(const Euroradio_Message& p) const override
    {
        if (auto q = dynamic_cast<const Termination_of_a_communication_session_Message*>(&p))
        {
            bool status = true;

            status = status && (header.NID_MESSAGE == q->header.NID_MESSAGE);
            status = status && (L_MESSAGE == q->L_MESSAGE);
            status = status && (T_TRAIN == q->T_TRAIN);
            status = status && (NID_ENGINE == q->NID_ENGINE);

            return status;
        }

        return false;
    }

    bool decode(Bitstream& stream);

    bool encode(Bitstream& stream) const;
};

typedef std::shared_ptr<Termination_of_a_communication_session_Message> Termination_of_a_communication_session_MessagePtr;

#endif // TERMINATION_OF_A_COMMUNICATION_SESSION_Message_H_INCLUDED

