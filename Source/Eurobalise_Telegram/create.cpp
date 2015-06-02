
#include "create.h"


Telegram_Header create_Telegram_Header()
{
    Telegram_Header a;
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

Train_running_number create_Train_running_number()
{
    Train_running_number a;
    {
        a.core.L_PACKET = 53;
        a.core.NID_OPERATIONAL = 9;
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

