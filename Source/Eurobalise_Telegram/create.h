
#ifndef CREATE_H_INCLUDED
#define CREATE_H_INCLUDED

#include "Telegram_Header.h"
#include "subsets.h"

Telegram_Header create_Telegram_Header_TrackToTrain();
Telegram_Header create_Telegram_Header_TrainToTrack();

Error_Reporting create_Error_Reporting();
Train_running_number create_Train_running_number();

Temporary_Speed_Restriction create_Temporary_Speed_Restriction();
Adhesion_Factor create_Adhesion_Factor();
Infill_location_reference create_Infill_location_reference(int i);
Gradient_Profile create_Gradient_Profile();

#endif /* CREATE_H_INCLUDED */

