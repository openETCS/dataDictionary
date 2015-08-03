
#ifndef VALIDATED_TRAIN_DATA_Message_H_INCLUDED
#define VALIDATED_TRAIN_DATA_Message_H_INCLUDED

#include "BasePacket.h"
#include "Bitstream.h"
#include <iostream>

struct Validated_Train_Data_Message
{
    uint8_t  NID_MESSAGE; // # 8
    uint16_t L_MESSAGE;   // # 10
    uint32_t T_TRAIN;     // # 32
    uint32_t NID_ENGINE;  // # 24
    BasePacketPtr packet_0_1;
    BasePacketPtr packet_11;

    bool decode(Bitstream& stream);

    bool encode(Bitstream& stream) const;
};

std::ostream& operator<<(std::ostream& stream, const Validated_Train_Data_Message& p);

bool operator==(const Validated_Train_Data_Message& a, const Validated_Train_Data_Message& b);

bool operator!=(const Validated_Train_Data_Message& a, const Validated_Train_Data_Message& b);

#endif // VALIDATED_TRAIN_DATA_Message_H_INCLUDED

