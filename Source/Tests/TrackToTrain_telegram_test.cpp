
#include "Adhesion_Factor.h"
#include "Gradient_Profile.h"
#include "End_of_Information.h"
#include "Level_23_Movement_Authority.h"
#include "Level_Transition_Order.h"
#include "EurobaliseTelegram.h"
#include "CompressedPackets.h"
#include <cassert>
#include <iostream>

int main ()
{
    TelegramHeader header;
    {
        header.Q_UPDOWN  = 1;
        header.M_VERSION = 32;
        header.Q_MEDIA	 = 0;
        header.N_PIG	 = 1;
        header.N_TOTAL	 = 1;
        header.M_DUP	 = 0;
        header.M_MCOUNT	 = 0;
        header.NID_C	 = 64;
        header.NID_BG	 = 3;
        header.Q_LINK	 = 1;
    }

    EurobaliseTelegram telegram = EurobaliseTelegram(header);

    Adhesion_Factor a;
    {
        // NID_PACKET = 71;
        a.core.Q_DIR = 1;
        a.core.L_PACKET = 56;
	a.core.Q_SCALE = 1;
	a.core.D_ADHESION = 9;
	a.core.L_ADHESION = 24;
	a.core.M_ADHESION = 0;
    }

    Gradient_Profile b;
    {
        // NID_PACKET = 21;
	b.core.Q_DIR = 1;
	b.core.L_PACKET = 102;
	b.core.Q_SCALE = 1;
	b.core.D_GRADIENT = 2393;
	b.core.Q_GDIR = 0;
	b.core.G_A = 210;
	b.core.N_ITER_1 = 2;

	b.core.sub_1[0].D_GRADIENT = 1999;
	b.core.sub_1[0].Q_GDIR = 1;
	b.core.sub_1[0].G_A = 98;
	b.core.sub_1[1].D_GRADIENT = 938;
	b.core.sub_1[1].Q_GDIR = 0;
	b.core.sub_1[1].G_A = 8;
    }

    Level_23_Movement_Authority c;
    {
        // NID_PACKEET = 15;
	c.core.Q_DIR = 1;
	c.core.L_PACKET = 218; 
	c.core.Q_SCALE = 0;
	c.core.V_LOA = 110;
	c.core.T_LOA = 5;
	c.core.N_ITER_1 = 1;

	c.core.sub_1[0].L_SECTION = 245;
	c.core.sub_1[0].Q_SECTIONTIMER = 0;
	c.core.sub_1[0].T_SECTIONTIMER = 23;
	c.core.sub_1[0].D_SECTIONTIMERSTOPLOC = 990;

	c.core.L_ENDSECTION = 8739;
	c.core.Q_SECTIONTIMER = 0;
	c.core.T_SECTIONTIMER = 93;
	c.core.D_SECTIONTIMERSTOPLOC = 99;
	c.core.Q_ENDTIMER = 1;
	c.core.T_ENDTIMER = 138;
	c.core.D_ENDTIMERSTARTLOC = 7368;
	c.core.Q_DANGERPOINT = 0;
	c.core.D_DP = 933;
	c.core.V_RELEASEDP = 100;
	c.core.Q_OVERLAP = 0;
	c.core.D_STARTOL = 4;
	c.core.T_OL = 9;
	c.core.D_OL =  445;
	c.core.V_RELEASEOL = 45;
    }

    Level_Transition_Order d;
    {
        // NID_PACKET = 41;
        d.core.Q_DIR = 1;
	d.core.L_PACKET = 73; 
	d.core.Q_SCALE = 1;
	d.core.D_LEVELTR = 389;
	d.core.M_LEVELTR = 2;
	d.core.NID_NTC = 234;
	d.core.L_ACKLEVELTR = 873;
	d.core.N_ITER_1 = 1;

	d.core.sub_1[0].M_LEVELTR = 3;
	d.core.sub_1[0].NID_NTC = 200;
	d.core.sub_1[0].L_ACKLEVELTR = 9210;
    }

    End_of_Information z;
    {
        // NID_PACKET = 255;
    }

    telegram.add(std::make_shared<Adhesion_Factor>(a));
    telegram.add(std::make_shared<Gradient_Profile>(b));
    telegram.add(std::make_shared<Level_23_Movement_Authority>(c));
    telegram.add(std::make_shared<Level_Transition_Order>(d));
    telegram.add(std::make_shared<End_of_Information>(z));

    FlatPackets container;

    std::cout << "Expanded Telegram Test: TrackToTrain" << std::endl;

    std::cout << "\n\nEncoding the telegram: " << telegram << std::endl;

    if (telegram.encode(container))
    {
        std::cout << "The telegram was encoded into the int stream." << std::endl;
    }
    else
    {
        std::cout << "An error occured during the encoding process of the telegram." << std::endl;
    }

    //std::cout << "The int stream contains this data: ";
    //std::cout << "0:" << container.PacketData[0];

    //for (unsigned int i = 1; i < 500; ++i)
    //{
        //std::cout << ", " << i << ":" << container.PacketData[i];
    //}

    std::cout << std::endl;

    EurobaliseTelegram new_telegram = EurobaliseTelegram(header);

    if (new_telegram.decode(container))
    {
        std::cout << "The telegram was decoded from the int stream." << std::endl;
    }
    else
    {
        std::cout << "An error occured during the decoding process of the telegram." << std::endl;
    }

    std::cout << "Decoded the telegram: " << new_telegram << std::endl;

    assert(telegram == new_telegram);

    std::cout << "Test successfull.\n" << std::endl;
}

