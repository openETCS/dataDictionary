
#ifndef ACKNOWLEDGEMENT_OF_TRAIN_DATA_Message_H_INCLUDED
#define ACKNOWLEDGEMENT_OF_TRAIN_DATA_Message_H_INCLUDED

#include "EuroradioMessage.h"
#include "Bitstream.h"
#include <iostream>

struct Acknowledgement_of_Train_Data_Message : public EuroradioMessage
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN_0        ;  // # 32
    uint8_t  M_ACK             ;  // # 1
    uint32_t  NID_LRBG         ;  // # 24
    uint32_t  T_TRAIN_1        ;  // # 32


    Acknowledgement_of_Train_Data_Message() : EuroradioMessage(8) {}

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

    bool equals(const EuroradioMessage& p) const override
    {
        if (auto q = dynamic_cast<const Acknowledgement_of_Train_Data_Message*>(&p))
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

typedef std::shared_ptr<Acknowledgement_of_Train_Data_Message> Acknowledgement_of_Train_Data_MessagePtr;

#endif // ACKNOWLEDGEMENT_OF_TRAIN_DATA_Message_H_INCLUDED

