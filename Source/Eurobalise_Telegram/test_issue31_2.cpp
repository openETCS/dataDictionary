
#include "Eurobalise_Telegram.h"
#include "Telegram_Header_Encoder.h"
#include "Packet_Header_Encoder.h"
#include "Bitstream_Init.h"
#include "subsets.h"
#include "create.h"
#include <cassert>
#include "UpperBitsNotSet.h"
#include <iostream>

// for debug reasons
#include <bitset>


template<typename Packet>
void assert_equal(const Packet& packet, BasePacketPtr ptr)
{
    auto x = std::dynamic_pointer_cast<Packet>(ptr);
    assert(x);
    assert(packet == *x);
}

int main ()
{
    std::cout << "\n--- Testing the decode function with issue31 part 2\n";

    std::vector<uint8_t> raw_stream(1000);
    Bitstream stream;
    Bitstream_Init(&stream, &(raw_stream[0]), raw_stream.size(), 73);

    uint32_t init_pos = stream.bitpos;

    Eurobalise_Telegram telegram;

    Telegram_Header header;
    {
        header.Q_UPDOWN  = 1;
	header.M_VERSION = 32;
	header.Q_MEDIA	 = 0;
	header.N_PIG	 = 0;
	header.N_TOTAL	 = 1;
	header.M_DUP	 = 0;
	header.M_MCOUNT	 = 0;
	header.NID_C	 = 64;
	header.NID_BG	 = 3;
	header.Q_LINK	 = 1;
    }

    telegram.header = header;

    Session_Management a;
    {
        // NID_PACKET = 42;
        a.core.Q_DIR =	1;
	a.core.L_PACKET = 113;
	a.core.Q_RBC	= 1;
	a.core.NID_C	= 352;
	a.core.NID_RBC	= 1515;
	a.core.NID_RADIO = 14185023402016767;
	a.core.Q_SLEEPSESSION	= 0;
    }

    telegram.add(std::make_shared<Session_Management>(a));

    National_Values b;
    {
	// NID_PACKET = 3;
        b.core.Q_DIR = 1;
        b.core.L_PACKET = 230;
        b.core.Q_SCALE = 1;
        b.core.D_VALIDNV = 0;
        b.core.NID_C = 0;
        b.core.N_ITER_1 = 0;
        b.core.V_NVSHUNT = 6;
        b.core.V_NVSTFF = 8;
        b.core.V_NVONSIGHT = 6;
        b.core.V_NVLIMSUPERV = 20;
        b.core.V_NVUNFIT = 20;
        b.core.V_NVREL = 8;
        b.core.D_NVROLL = 2;
        b.core.Q_NVSBTSMPERM = 1;
        b.core.Q_NVEMRRLS = 0;
        b.core.Q_NVGUIPERM = 0;
        b.core.Q_NVSBFBPERM = 0;
        b.core.Q_NVINHSMICPERM = 0;
        b.core.V_NVALLOWOVTRP = 0;
        b.core.V_NVSUPOVTRP = 6;
        b.core.D_NVOVTRP = 200;
        b.core.T_NVOVTRP = 60;
        b.core.D_NVPOTRP = 200;
        b.core.M_NVCONTACT = 1;
        b.core.T_NVCONTACT = 255;
        b.core.M_NVDERUN = 1;
        b.core.D_NVSTFF = 32767;
        b.core.Q_NVDRIVER_ADHES = 0;
        b.core.A_NVMAXREDADH1 = 20;
        b.core.A_NVMAXREDADH2 = 14;
        b.core.A_NVMAXREDADH3 = 14;
        b.core.Q_NVLOCACC = 12;
        b.core.M_NVAVADH = 1;
        b.core.M_NVEBCL = 1;
        b.core.Q_NVKINT = 0;
    }
    
    telegram.add(std::make_shared<National_Values>(b));

    Level_Transition_Order c;
    {
        // NID_PACKET = 41;
	c.core.Q_DIR = 1;
	c.core.L_PACKET = 63;
	c.core.Q_SCALE = 1;
	c.core.D_LEVELTR = 300;
	c.core.M_LEVELTR = 3;
	c.core.L_ACKLEVELTR = 100;
	c.core.N_ITER_1 = 0;
    }

    telegram.add(std::make_shared<Level_Transition_Order>(c));

    End_of_Information d;

    telegram.add(std::make_shared<End_of_Information>(d));

    std::cout << " Encoder Input: " << telegram << std::endl;

    std::cout << " Encoding Eurobalise Telegram." << std::endl;
    telegram.encode(stream);

    stream.bitpos = init_pos;

    Eurobalise_Telegram new_telegram;

    std::cout << " Decoding Eurobalise Telegram." << std::endl;
    new_telegram.decode(stream);

    std::cout << " Decoder Output: " << new_telegram << std::endl;

    assert(telegram.header == new_telegram.header);
    assert(telegram.packets[0]->id == new_telegram.packets[0]->id);
    assert(telegram.packets[1]->id == new_telegram.packets[1]->id);
    assert(telegram.packets[2]->id == new_telegram.packets[2]->id);
    assert(telegram.packets[3]->id == new_telegram.packets[3]->id);
    assert(telegram == new_telegram);

    std::cout << " Test successful." << std::endl;
    std::cout << std::endl;


    
    //test bitoutput of stream
    for (int n=0; n<100; ++n)
      {
	std::cout << (int)raw_stream[n];
	std::cout << " ";
	if ((int)raw_stream[n] < 10) std::cout << " ";
	if ((int)raw_stream[n] < 100) std::cout << " ";
      }

    std::cout << "\n";

    for (int n=0; n<100; ++n)
      {
	std::cout << std::hex << (int)raw_stream[n];
	std::cout << "  ";
	if ((int)raw_stream[n] < 16) std::cout << " ";
      }

    std::cout << "\n";

    for (int n=0; n<100; ++n)
      {
	if ((n%10)==0) std::cout << "\n";
	std::cout << std::bitset<8>((int)raw_stream[n]);
	std::cout << "  ";
      }

    std::cout << "\n";


    
    return EXIT_SUCCESS;
}

