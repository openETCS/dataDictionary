
#ifndef VALIDATED_TRAIN_DATA_Message_H_INCLUDED
#define VALIDATED_TRAIN_DATA_Message_H_INCLUDED

#include "Euroradio_Message.h"
#include "Bitstream.h"
#include <iostream>

struct Validated_Train_Data_Message : public Euroradio_Message
{
    uint16_t L_MESSAGE;   // # 10
    uint32_t T_TRAIN;     // # 32
    uint32_t NID_ENGINE;  // # 24
    BasePacketPtr packet_0_1;
    BasePacketPtr packet_11;

    Validated_Train_Data_Message() : Euroradio_Message(129) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +NID_MESSAGE << ","
               << +L_MESSAGE << ","
               << +T_TRAIN << ","
	       << +NID_ENGINE << ","
               << *(packet_0_1) << ","
               << *(packet_11) << ")";
    }

    bool equals(const Euroradio_Message& p) const override
    {
	if (auto q = dynamic_cast<const Validated_Train_Data_Message*>(&p))
	{
            bool status = true;
    
            status = status && (NID_MESSAGE == q->NID_MESSAGE);
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

