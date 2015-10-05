
#ifndef CREATE_H_INCLUDED
#define CREATE_H_INCLUDED

#include "TelegramHeader.h"
#include "Packets.h"

TelegramHeader create_TelegramHeader_TrackToTrain();
TelegramHeader create_TelegramHeader_TrainToTrack();

Error_Reporting create_Error_Reporting();
Train_running_number create_Train_running_number();

Temporary_Speed_Restriction create_Temporary_Speed_Restriction();
Adhesion_Factor create_Adhesion_Factor();
Infill_location_reference create_Infill_location_reference(int i);
Gradient_Profile create_Gradient_Profile();
Gradient_Profile_Core_1 create_Gradient_Profile_Core_1(uint16_t i, uint32_t j, uint8_t k);

#endif /* CREATE_H_INCLUDED */

