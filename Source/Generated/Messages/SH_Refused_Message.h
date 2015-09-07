
#ifndef SH_REFUSED_Message_H_INCLUDED
#define SH_REFUSED_Message_H_INCLUDED

#include "Euroradio_Message.h"
#include "Bitstream.h"
#include <iostream>

struct SH_Refused_Message : public Euroradio_Message
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN_0        ;  // # 32
    uint8_t  M_ACK             ;  // # 1
    uint32_t  NID_LRBG         ;  // # 24
    uint32_t  T_TRAIN_1        ;  // # 32


    SH_Refused_Message() : Euroradio_Message(27) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +header.NID_MESSAGE  << ","
               << +L_MESSAGE << ","
               << +T_TRAIN_0 << ","
               << +M_ACK << ","
               << +NID_LRBG << ","
               << +T_TRAIN_1 << ")";
    }

    bool equals(const Euroradio_Message& p) const override
    {
        if (auto q = dynamic_cast<const SH_Refused_Message*>(&p))
        {
            bool status = true;

            status = status && (header.NID_MESSAGE == q->header.NID_MESSAGE);
            status = status && (L_MESSAGE == q->L_MESSAGE);
            status = status && (T_TRAIN_0 == q->T_TRAIN_0);
            status = status && (M_ACK == q->M_ACK);
            status = status && (NID_LRBG == q->NID_LRBG);
            status = status && (T_TRAIN_1 == q->T_TRAIN_1);

            return status;
        }

        return false;
    }

    bool decode(Bitstream& stream);

    bool encode(Bitstream& stream) const;
};

typedef std::shared_ptr<SH_Refused_Message> SH_Refused_MessagePtr;

#endif // SH_REFUSED_Message_H_INCLUDED

