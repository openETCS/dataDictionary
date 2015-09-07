
#ifndef REVOCATION_OF_EMERGENCY_STOP_Message_H_INCLUDED
#define REVOCATION_OF_EMERGENCY_STOP_Message_H_INCLUDED

#include "Euroradio_Message.h"
#include "Bitstream.h"
#include <iostream>

struct Revocation_of_Emergency_Stop_Message : public Euroradio_Message
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN          ;  // # 32
    uint8_t  M_ACK             ;  // # 1
    uint32_t  NID_LRBG         ;  // # 24
    uint8_t  NID_EM            ;  // # 4


    Revocation_of_Emergency_Stop_Message() : Euroradio_Message(18) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +header.NID_MESSAGE  << ","
               << +L_MESSAGE << ","
               << +T_TRAIN << ","
               << +M_ACK << ","
               << +NID_LRBG << ","
               << +NID_EM << ")";
    }

    bool equals(const Euroradio_Message& p) const override
    {
        if (auto q = dynamic_cast<const Revocation_of_Emergency_Stop_Message*>(&p))
        {
            bool status = true;

            status = status && (header.NID_MESSAGE == q->header.NID_MESSAGE);
            status = status && (L_MESSAGE == q->L_MESSAGE);
            status = status && (T_TRAIN == q->T_TRAIN);
            status = status && (M_ACK == q->M_ACK);
            status = status && (NID_LRBG == q->NID_LRBG);
            status = status && (NID_EM == q->NID_EM);

            return status;
        }

        return false;
    }

    bool decode(Bitstream& stream);

    bool encode(Bitstream& stream) const;
};

typedef std::shared_ptr<Revocation_of_Emergency_Stop_Message> Revocation_of_Emergency_Stop_MessagePtr;

#endif // REVOCATION_OF_EMERGENCY_STOP_Message_H_INCLUDED

