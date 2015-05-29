
#include "create.h"


Telegram_Header create_Telegram_Header()
{
    Telegram_Header a;
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

Train_running_number_Core create_Train_running_number_Core()
{
    Train_running_number_Core a;
    {
        a.L_PACKET = 53;
        a.NID_OPERATIONAL = 9;
    }

    return a;
}


Adhesion_Factor_Core create_Adhesion_Factor_Core()
{
    Adhesion_Factor_Core a;
    {
        a.Q_DIR = 1;
        a.L_PACKET = 56;
        a.Q_SCALE = 1;
        a.D_ADHESION = 9;
        a.L_ADHESION = 24;
        a.M_ADHESION = 0;
    }

    return a;
}

