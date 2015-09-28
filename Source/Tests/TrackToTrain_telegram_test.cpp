
#include "Adhesion_Factor.h"
#include "Gradient_Profile.h"
#include "End_of_Information.h"
#include "Level_23_Movement_Authority.h"
#include "Level_Transition_Order.h"
#include "List_of_balises_for_SH_Area.h"
#include "Mode_profile.h"
#include "Packet_for_sending_plain_text_messages.h"
#include "Level_Crossing_information.h"
#include "Linking.h"
#include "Data_used_by_applications_outside_the_ERTMSETCS_system.h"
#include "Track_Condition_Change_of_traction_system.h"
#include "Packet_for_sending_fixed_text_messages.h"
#include "Axle_Load_Speed_Profile.h"
#include "Permitted_Braking_Distance_Information.h"
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

    List_of_balises_for_SH_Area e;
    {
        // NID_PACKET = 49;
	e.core.Q_DIR = 1;
	e.core.L_PACKET = 50;
	e.core.N_ITER_1 = 2;

	e.core.sub_1[0].Q_NEWCOUNTRY = 0;
	e.core.sub_1[0].NID_C = 399;
	e.core.sub_1[0].NID_BG = 1000;
	e.core.sub_1[1].Q_NEWCOUNTRY = 1;
	e.core.sub_1[1].NID_C = 4;
	e.core.sub_1[1].NID_BG = 3000;
    }

    Mode_profile f;
    {
        f.core.Q_DIR = 1;
        f.core.L_PACKET = 132;
        f.core.Q_SCALE = 0;
        f.core.D_MAMODE = 600;
        f.core.M_MAMODE = 0;
        f.core.V_MAMODE = 2;
        f.core.L_MAMODE = 23;
        f.core.L_ACKMAMODE = 23;
        f.core.Q_MAMODE = 1;
        f.core.N_ITER_1 = 1;

        f.core.sub_1[0].D_MAMODE = 400;
        f.core.sub_1[0].M_MAMODE = 2;
        f.core.sub_1[0].V_MAMODE = 2;
        f.core.sub_1[0].L_MAMODE = 399;
        f.core.sub_1[0].L_ACKMAMODE = 1000;
        f.core.sub_1[0].Q_MAMODE = 0;
    }

    Packet_for_sending_plain_text_messages g;
    {
        g.core.Q_DIR = 1;
        g.core.L_PACKET = 142;
        g.core.Q_SCALE = 1;
        g.core.Q_TEXTCLASS = 0;
        g.core.Q_TEXTDISPLAY = 0;
        g.core.D_TEXTDISPLAY = 400;
        g.core.M_MODETEXTDISPLAY_0 = 3;
        g.core.M_LEVELTEXTDISPLAY_0 = 1;
        g.core.NID_NTC_0 = 200;
        g.core.L_TEXTDISPLAY = 700;
        g.core.T_TEXTDISPLAY = 80;
        g.core.M_MODETEXTDISPLAY_1 = 3;
        g.core.M_LEVELTEXTDISPLAY_1 = 1;
        g.core.NID_NTC_1 = 23;
        g.core.Q_TEXTCONFIRM = 1;
        g.core.Q_CONFTEXTDISPLAY = 0;
        g.core.Q_TEXTREPORT = 1;
        g.core.NID_TEXTMESSAGE = 100;
        g.core.NID_C = 333;
        g.core.NID_RBC = 1200;
        g.core.L_TEXT = 2;
        g.core.X_TEXT = 30;
    }

    Level_Crossing_information h;
    {
        h.core.Q_DIR = 1;
	h.core.L_PACKET = 64;
	h.core.Q_SCALE = 0;
	h.core.NID_LX = 256;
	h.core.D_LX = 100;
	h.core.L_LX = 9;
	h.core.Q_LXSTATUS = 1;
	h.core.V_LX = 15;
	h.core.Q_STOPLX = 0;
	h.core.L_STOPLX = 99;
    }

    Linking i;
    {
	i.core.Q_DIR = 1;
	i.core.L_PACKET = 61;
	i.core.Q_SCALE = 0;
        i.core.D_LINK = 792;
        i.core.Q_NEWCOUNTRY = 1;
        i.core.NID_C = 1000;
        i.core.NID_BG = 4;
        i.core.Q_LINKORIENTATION = 1;
        i.core.Q_LINKREACTION = 2;
        i.core.Q_LOCACC = 41;
	i.core.N_ITER_1 = 0;
    }

    Data_used_by_applications_outside_the_ERTMSETCS_system j;
    {
        j.core.Q_DIR = 1;
	j.core.L_PACKET = 96;
	j.core.NID_XUSER = 102;
	j.core.NID_NTC = 100;
	j.core.Other_data_depending_on__NID_XUSER = 32928;
    }

    Track_Condition_Change_of_traction_system k;
    {
        k.core.Q_DIR = 1;
        k.core.L_PACKET = 46;
        k.core.Q_SCALE = 2;
        k.core.D_TRACTION = 100;
        k.core.M_VOLTAGE = 5;
        k.core.NID_CTRACTION = 761;
    }

    Packet_for_sending_fixed_text_messages l;
    {
        l.core.Q_DIR = 2;
        l.core.L_PACKET = 84;
        l.core.Q_SCALE = 2;
        l.core.Q_TEXTCLASS = 0;
        l.core.Q_TEXTDISPLAY = 0;
        l.core.D_TEXTDISPLAY = 100;
        l.core.M_MODETEXTDISPLAY_0 = 0;
        l.core.M_LEVELTEXTDISPLAY_0 = 0;
        l.core.NID_NTC_0 = 142;
        l.core.L_TEXTDISPLAY = 400;
        l.core.T_TEXTDISPLAY = 300;
        l.core.M_MODETEXTDISPLAY_1 = 0;
        l.core.M_LEVELTEXTDISPLAY_1 = 0;
        l.core.NID_NTC_1 = 38;
        l.core.Q_TEXTCONFIRM = 0;
        l.core.Q_CONFTEXTDISPLAY = 0;
        l.core.Q_TEXTREPORT = 0;
        l.core.NID_TEXTMESSAGE = 99;
        l.core.NID_C = 100;
        l.core.NID_RBC = 16;
        l.core.Q_TEXT = 1;
    }

    Axle_Load_Speed_Profile m;
    {
        m.core.Q_DIR = 1;
        m.core.L_PACKET = 82;
        m.core.Q_SCALE = 1;
        m.core.Q_TRACKINIT = 0;
        m.core.D_TRACKINIT = 100;
        m.core.D_AXLELOAD = 77;
        m.core.L_AXLELOAD = 10;
        m.core.Q_FRONT = 0;
        m.core.N_ITER_1 = 0;

        m.core.N_ITER_2 = 1;

	m.core.sub_2[0].D_AXLELOAD = 15;
	m.core.sub_2[0].L_AXLELOAD = 12;
	m.core.sub_2[0].Q_FRONT = 0;
	m.core.sub_2[0].N_ITER_2_1 = 2;
	m.core.sub_2[0].sub_2_1[0].M_AXLELOADCAT = 120;
	m.core.sub_2[0].sub_2_1[0].V_AXLELOAD = 0;
	m.core.sub_2[0].sub_2_1[1].M_AXLELOADCAT = 36;
	m.core.sub_2[0].sub_2_1[1].V_AXLELOAD = 13;
    }

    Permitted_Braking_Distance_Information n;
    {
        n.core.Q_DIR = 2;
        n.core.L_PACKET = 33;
        n.core.Q_SCALE = 1;
        n.core.Q_TRACKINIT = 1;
        n.core.D_TRACKINIT = 100;
        n.core.D_PBD = 80;
        n.core.Q_GDIR = 0;
        n.core.G_PBDSR = 16;
        n.core.Q_PBDSR = 1;
        n.core.D_PBDSR = 70;
        n.core.L_PBDSR = 4;
        n.core.N_ITER_1 = 0;
    }

    End_of_Information z;
    {
        // NID_PACKET = 255;
    }

    telegram.add(std::make_shared<Adhesion_Factor>(a));
    telegram.add(std::make_shared<Gradient_Profile>(b));
    telegram.add(std::make_shared<Level_23_Movement_Authority>(c));
    telegram.add(std::make_shared<Level_Transition_Order>(d));
    telegram.add(std::make_shared<List_of_balises_for_SH_Area>(e));
    telegram.add(std::make_shared<Mode_profile>(f));
    telegram.add(std::make_shared<Packet_for_sending_plain_text_messages>(g));
    telegram.add(std::make_shared<Level_Crossing_information>(h));
    telegram.add(std::make_shared<Linking>(i));
    telegram.add(std::make_shared<Data_used_by_applications_outside_the_ERTMSETCS_system>(j));
    telegram.add(std::make_shared<Track_Condition_Change_of_traction_system>(k));
    telegram.add(std::make_shared<Packet_for_sending_fixed_text_messages>(l));
    telegram.add(std::make_shared<Axle_Load_Speed_Profile>(m));
    telegram.add(std::make_shared<Permitted_Braking_Distance_Information>(n));
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

