
#include "Eurobalise_Telegram.h"
#include "Telegram_Header_Encoder.h"
#include "Packet_Header_Encoder.h"
#include "Bitstream_Init.h"
#include "subsets.h"
#include "create.h"
#include <cassert>
#include <iostream>

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

    std::cout << " Encoding Telegram Header: " << header << std::endl;
    Telegram_Header_Encoder(&stream, &header);

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

        Packet_Header h {a.id};
        Packet_Header_Encoder(&stream, &h);
	std::cout << "    Encoding packet " << a << std::endl;
        Session_Management_Encoder(&stream, &a.core);
    }

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
        b.core.M_NVCONTACT = 10;
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

        Packet_Header h {b.id};
        Packet_Header_Encoder(&stream, &h);
	std::cout << "    Encoding packet " << b << std::endl;
        National_Values_Encoder(&stream, &b.core);
    }

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

        Packet_Header h {c.id};
        Packet_Header_Encoder(&stream, &h);
	std::cout << "    Encoding packet " << c << std::endl;
        Level_Transition_Order_Encoder(&stream, &c.core);
    }


    End_of_Information f;
    {
        Packet_Header h {f.id};
        Packet_Header_Encoder(&stream, &h);
	std::cout << "    Encoding packet " << f << std::endl;
        End_of_Information_Encoder(&stream, &f.core);
    }

    stream.bitpos = init_pos;

    Eurobalise_Telegram telegram;

    std::cout << " Decoding Eurobalise Telegram." << std::endl;
    telegram.decode(stream);

    std::cout << " Decoder Output: " << telegram << std::endl;

    assert(telegram.header == header);

    std::cout << " Test successful." << std::endl;
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

