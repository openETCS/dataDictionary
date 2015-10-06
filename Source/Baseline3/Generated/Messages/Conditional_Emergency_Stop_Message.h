
#ifndef CONDITIONAL_EMERGENCY_STOP_Message_H_INCLUDED
#define CONDITIONAL_EMERGENCY_STOP_Message_H_INCLUDED

#include "EuroradioMessage.h"
#include "Bitstream.h"
#include <iostream>

struct Conditional_Emergency_Stop_Message : public EuroradioMessage
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN          ;  // # 32
    uint8_t  M_ACK             ;  // # 1
    uint32_t  NID_LRBG         ;  // # 24
    uint8_t  NID_EM            ;  // # 4
    uint8_t  Q_SCALE           ;  // # 2
    uint16_t  D_REF            ;  // # 16
    uint8_t  Q_DIR             ;  // # 2
    uint16_t  D_EMERGENCYSTOP  ;  // # 15


    Conditional_Emergency_Stop_Message() : EuroradioMessage(15) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +header.NID_MESSAGE  << ","
               << +L_MESSAGE << ","
               << +T_TRAIN << ","
               << +M_ACK << ","
               << +NID_LRBG << ","
               << +NID_EM << ","
               << +Q_SCALE << ","
               << +D_REF << ","
               << +Q_DIR << ","
               << +D_EMERGENCYSTOP << ")";
    }

    bool equals(const EuroradioMessage& p) const override
    {
	if (auto q = dynamic_cast<const Conditional_Emergency_Stop_Message*>(&p))
	{
            bool status = true;
    
            status = status && (header.NID_MESSAGE == q->header.NID_MESSAGE);
            status = status && (L_MESSAGE == q->L_MESSAGE);
            status = status && (T_TRAIN == q->T_TRAIN);
            status = status && (M_ACK == q->M_ACK);
            status = status && (NID_LRBG == q->NID_LRBG);
            status = status && (NID_EM == q->NID_EM);
            status = status && (Q_SCALE == q->Q_SCALE);
            status = status && (D_REF == q->D_REF);
            status = status && (Q_DIR == q->Q_DIR);
            status = status && (D_EMERGENCYSTOP == q->D_EMERGENCYSTOP);

            return status;
        }
	return false;
    }

    bool decode(Bitstream& stream);

    bool encode(Bitstream& stream) const;
};

typedef std::shared_ptr<Conditional_Emergency_Stop_Message> Conditional_Emergency_Stop_MessagePtr;

#endif // CONDITIONAL_EMERGENCY_STOP_Message_H_INCLUDED

