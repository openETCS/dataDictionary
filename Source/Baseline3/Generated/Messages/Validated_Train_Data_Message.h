
#ifndef VALIDATED_TRAIN_DATA_Message_H_INCLUDED
#define VALIDATED_TRAIN_DATA_Message_H_INCLUDED

#include "EuroradioMessage.h"
#include "Bitstream.h"
#include <iostream>

struct Validated_Train_Data_Message : public EuroradioMessage
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN          ;  // # 32
    uint32_t  NID_ENGINE       ;  // # 24

    BasePacketPtr  packet_0_1;
    BasePacketPtr  packet_11;

    Validated_Train_Data_Message() : EuroradioMessage(129) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +header.NID_MESSAGE  << ","
               << +L_MESSAGE << ","
               << +T_TRAIN << ","
               << +NID_ENGINE << ","
               << *(packet_0_1) << ","
               << *(packet_11) << ")";
    }

    bool equals(const EuroradioMessage& p) const override
    {
	if (auto q = dynamic_cast<const Validated_Train_Data_Message*>(&p))
	{
            bool status = true;
    
            status = status && (header.NID_MESSAGE == q->header.NID_MESSAGE);
            status = status && (L_MESSAGE == q->L_MESSAGE);
            status = status && (T_TRAIN == q->T_TRAIN);
            status = status && (NID_ENGINE == q->NID_ENGINE);
            status = status && (*packet_0_1 == *(q->packet_0_1));
            status = status && (*packet_11 == *(q->packet_11));

            return status;
        }
	return false;
    }

    bool decode(Bitstream& stream);

    bool encode(Bitstream& stream) const;
};

typedef std::shared_ptr<Validated_Train_Data_Message> Validated_Train_Data_MessagePtr;

#endif // VALIDATED_TRAIN_DATA_Message_H_INCLUDED

