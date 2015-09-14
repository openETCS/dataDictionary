
#include "Adhesion_Factor.h"
#include "End_of_Information.h"
#include "EurobaliseTelegram.h"
#include "Compressed_Packets.h"
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

    End_of_Information b;
    {
        // NID_PACKET = 255;
    }

    telegram.add(std::make_shared<Adhesion_Factor>(a));
    telegram.add(std::make_shared<End_of_Information>(b));

    Flat_Packets container;

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

