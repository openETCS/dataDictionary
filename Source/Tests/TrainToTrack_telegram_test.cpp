
#include "End_of_Information.h"
#include "Validated_train_data.h"
#include "Position_Report.h"
#include "Position_Report_based_on_two_balise_groups.h"
#include "Onboard_telephone_numbers.h"
#include "EurobaliseTelegram.h"
#include "CompressedPackets.h"
#include <cassert>
#include <iostream>

int main ()
{
    TelegramHeader header;
    {
        header.Q_UPDOWN  = 0;
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

    Validated_train_data a;
    {
        // NID_PACKET = 11;
        a.core.L_PACKET = 116;
	a.core.NC_CDTRAIN = 5;
	a.core.NC_TRAIN  = 310;
	a.core.L_TRAIN = 98;
	a.core.V_MAXTRAIN = 120;
	a.core.M_LOADINGGAUGE = 1;
	a.core.M_AXLELOADCAT = 0;
        a.core.M_AIRTIGHT = 0;
	a.core.N_AXLE = 31;
	a.core.N_ITER_1 = 2;

	a.core.sub_1[0].M_VOLTAGE = 4;
	a.core.sub_1[0].NID_CTRACTION = 1000;
	a.core.sub_1[1].M_VOLTAGE = 2;
	a.core.sub_1[1].NID_CTRACTION = 32;
	
	a.core.N_ITER_2 = 0;
    }

    Position_Report b;
    {
        // NID_PACKET = 0;
	b.core.L_PACKET = 121; 
	b.core.Q_SCALE =  0;
	b.core.NID_LRBG = 3990;
	b.core.D_LRBG = 100;
	b.core.Q_DIRLRBG = 0;
	b.core.Q_DLRBG = 1;
	b.core.L_DOUBTOVER = 400;
	b.core.L_DOUBTUNDER = 920;
	b.core.Q_LENGTH = 1;
	b.core.L_TRAININT = 3;
	b.core.V_TRAIN = 99;
	b.core.Q_DIRTRAIN = 1;
	b.core.M_MODE = 4;
	b.core.M_LEVEL = 2;
	b.core.NID_NTC = 92;
    }

    Position_Report_based_on_two_balise_groups c;
    {
        // NID_PACKET = 0;
	c.core.L_PACKET = 145; 
	c.core.Q_SCALE =  0;
	c.core.NID_LRBG = 3990;
        c.core.NID_PRVLRBG = 33928;
	c.core.D_LRBG = 100;
	c.core.Q_DIRLRBG = 0;
	c.core.Q_DLRBG = 1;
	c.core.L_DOUBTOVER = 400;
	c.core.L_DOUBTUNDER = 920;
	c.core.Q_LENGTH = 1;
	c.core.L_TRAININT = 3;
	c.core.V_TRAIN = 99;
	c.core.Q_DIRTRAIN = 1;
	c.core.M_MODE = 4;
	c.core.M_LEVEL = 2;
	c.core.NID_NTC = 92;
    }

    Onboard_telephone_numbers d;
    {
        // NID_PACKET = 3;
	d.core.L_PACKET = 142;
	d.core.N_ITER_1 = 2;
	d.core.sub_1[0].NID_RADIO = 39820;
	d.core.sub_1[1].NID_RADIO = 18310;
    }

    End_of_Information z;
    {
        // NID_PACKET = 255;
    }

    telegram.add(std::make_shared<Validated_train_data>(a));
    telegram.add(std::make_shared<Position_Report>(b));
    telegram.add(std::make_shared<Position_Report_based_on_two_balise_groups>(c));
    telegram.add(std::make_shared<Onboard_telephone_numbers>(d));
    telegram.add(std::make_shared<End_of_Information>(z));

    FlatPackets container;

    std::cout << "Expanded Telegram Test: TrainToTrack" << std::endl;

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

