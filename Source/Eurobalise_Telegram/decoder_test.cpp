
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
    std::cout << "--- Testing the decode function of Eurobalise Telegram." << std::endl;
    std::vector<uint8_t> raw_stream(1000);
    Bitstream stream;
    Bitstream_Init(&stream, &(raw_stream[0]), raw_stream.size(), 73);

    uint32_t init_pos = stream.bitpos;

    Telegram_Header header = create_Telegram_Header_TrainToTrack();
    // Telegram_Header header = create_Telegram_Header_TrackToTrain();
    std::cout << " Encoding Telegram Header: " << header << std::endl;
    Telegram_Header_Encoder(&stream, &header);

    std::cout << " Encoding data packets:" << std::endl;
    Train_running_number a = create_Train_running_number();
    {
        Packet_Header h {a.id};
        Packet_Header_Encoder(&stream, &h);
        std::cout << "    Encoding packet " << a << std::endl;
        Train_running_number_Encoder(&stream, &a.core);
    }

    Error_Reporting b = create_Error_Reporting();
    {
        Packet_Header h {b.id};
        Packet_Header_Encoder(&stream, &h);
        std::cout << "    Encoding packet " << b << std::endl;
        Error_Reporting_Encoder(&stream, &b.core);
    }

    /*

        Temporary_Speed_Restriction a = create_Temporary_Speed_Restriction();
        {
            Packet_Header h {a.id};
    	Packet_Header_Encoder(&stream, &h);
    	std::cout << "    Encoding packet " << a << std::endl;
    	Temporary_Speed_Restriction_Encoder(&stream, &a.core);
        }

        Adhesion_Factor b = create_Adhesion_Factor();
        {
            Packet_Header h {b.id};
    	Packet_Header_Encoder(&stream, &h);
    	std::cout << "    Encoding packet " << b << std::endl;
    	Adhesion_Factor_Encoder(&stream, &b.core);
        }

    */

    End_of_Information c;
    {
        Packet_Header h {c.id};
        Packet_Header_Encoder(&stream, &h);
        std::cout << "    Encoding packet " << c << std::endl;
        End_of_Information_Encoder(&stream, &c.core);
    }

    stream.bitpos = init_pos;

    Eurobalise_Telegram telegram;

    std::cout << " Decoding Eurobalise Telegram." << std::endl;
    telegram.decode(stream);

    std::cout << " Decoder Output: " << telegram << std::endl;

    assert(telegram.header == header);

    assert_equal(a, telegram.packets[0]);
    assert_equal(b, telegram.packets[1]);
    assert_equal(c, telegram.packets[2]);

    std::cout << " Test successfull.\n" << std::endl;

    return EXIT_SUCCESS;
}

