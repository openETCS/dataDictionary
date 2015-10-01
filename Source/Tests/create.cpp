
#include "create.h"


// Telegram header

TelegramHeader create_TelegramHeader_TrackToTrain()
{
    TelegramHeader a;
    {
        a.Q_UPDOWN = 1;
        a.M_VERSION = 3;
        a.Q_MEDIA = 0;
        a.N_PIG = 4;
        a.N_TOTAL = 3;
        a.M_DUP = 3;
        a.M_MCOUNT = 34;
        a.NID_C  = 120;
        a.NID_BG = 49;
        a.Q_LINK = 1;
    }

    return a;
}

TelegramHeader create_TelegramHeader_TrainToTrack()
{
    TelegramHeader a;
    {
        a.Q_UPDOWN = 0;
        a.M_VERSION = 3;
        a.Q_MEDIA = 0;
        a.N_PIG = 4;
        a.N_TOTAL = 3;
        a.M_DUP = 3;
        a.M_MCOUNT = 34;
        a.NID_C  = 120;
        a.NID_BG = 49;
        a.Q_LINK = 1;
    }

    return a;
}

// TrainToTrack Packets

/*Error_Reporting create_Error_Reporting()
{
    Error_Reporting a;
    {
        a.core.L_PACKET = 29;
        a.core.M_ERROR = 18;
    }

    return a;
}*/

/*Train_running_number create_Train_running_number()
{
    Train_running_number a;
    {
        a.core.L_PACKET = 53;
        a.core.NID_OPERATIONAL = 9;
    }

    return a;
}*/

// TrackToTrain Packets

Temporary_Speed_Restriction create_Temporary_Speed_Restriction()
{
    Temporary_Speed_Restriction a;
    {
        a.core.Q_DIR = 1;
        a.core.L_PACKET = 71;
        a.core.Q_SCALE = 1;
        a.core.NID_TSR = 45;
        a.core.D_TSR = 120;
        a.core.L_TSR = 39;
        a.core.Q_FRONT = 0;
        a.core.V_TSR = 12;
    }

    return a;
}

Adhesion_Factor create_Adhesion_Factor()
{
    Adhesion_Factor a;
    {
        a.core.Q_DIR = 1;
        a.core.L_PACKET = 56;
        a.core.Q_SCALE = 1;
        a.core.D_ADHESION = 9;
        a.core.L_ADHESION = 24;
        a.core.M_ADHESION = 0;
    }

    return a;
}

Infill_location_reference create_Infill_location_reference(int i)
{
    Infill_location_reference a;
    {
        a.core.Q_DIR = 1;
        a.core.L_PACKET = 38 + (10 * i);
        a.core.Q_NEWCOUNTRY = i;
        a.core.NID_C = 123;
        a.core.NID_BG = 258;
    }

    return a;
}
/*
Gradient_Profile_Core_1 create_Gradient_Profile_Core_1(uint16_t i, uint32_t j, uint8_t k)
{
    Gradient_Profile_Core_1 a;
    {
      a.D_GRADIENT = i;
      a.Q_GDIR = j;
      a.G_A = k;
    }

    return a;
}

Gradient_Profile create_Gradient_Profile()
{
    Gradient_Profile a;
    {
        a.core.Q_DIR = 1;
	a.core.L_PACKET = 48;
	a.core.Q_SCALE = 1;
	a.core.D_GRADIENT = 123;
	a.core.Q_GDIR = 0;
	a.core.G_A = 4;
	a.core.N_ITER = 4;
	a.core.sub_1[0] = create_Gradient_Profile_Core_1(328, 1, 36);
	a.core.sub_1[1] = create_Gradient_Profile_Core_1(65, 0, 89);
	a.core.sub_1[2] = create_Gradient_Profile_Core_1(19, 0, 129);
	a.core.sub_1[3] = create_Gradient_Profile_Core_1(889, 1, 201);
    }

    return a;
}
*/
