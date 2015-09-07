
#ifndef RECOGNITION_OF_EXIT_FROM_TRIP_MODE_Message_H_INCLUDED
#define RECOGNITION_OF_EXIT_FROM_TRIP_MODE_Message_H_INCLUDED

#include "Euroradio_Message.h"
#include "Bitstream.h"
#include <iostream>

struct Recognition_of_exit_from_TRIP_mode_Message : public Euroradio_Message
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN          ;  // # 32
    uint8_t  M_ACK             ;  // # 1
    uint32_t  NID_LRBG         ;  // # 24


    Recognition_of_exit_from_TRIP_mode_Message() : Euroradio_Message(6) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +header.NID_MESSAGE  << ","
               << +L_MESSAGE << ","
               << +T_TRAIN << ","
               << +M_ACK << ","
               << +NID_LRBG << ")";
    }

    bool equals(const Euroradio_Message& p) const override
    {
        if (auto q = dynamic_cast<const Recognition_of_exit_from_TRIP_mode_Message*>(&p))
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

typedef std::shared_ptr<Recognition_of_exit_from_TRIP_mode_Message> Recognition_of_exit_from_TRIP_mode_MessagePtr;

#endif // RECOGNITION_OF_EXIT_FROM_TRIP_MODE_Message_H_INCLUDED

