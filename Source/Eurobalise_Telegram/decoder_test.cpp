
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
    assert(packet == *std::static_pointer_cast<Packet>(ptr));
}

int main ()
{

    std::vector<uint8_t> raw_stream(1000);
    Bitstream stream;
    Bitstream_Init(&stream, &(raw_stream[0]), raw_stream.size(), 73);

    uint32_t init_pos = stream.bitpos;

    Telegram_Header header = create_Telegram_Header();
    Telegram_Header_Encoder(&stream, &header);

    Train_running_number a = create_Train_running_number();
    {
        Packet_Header h {a.id};
        Packet_Header_Encoder(&stream, &h);
        Train_running_number_Encoder(&stream, &a.core);
    }

    Adhesion_Factor b = create_Adhesion_Factor();
    {
        Packet_Header h {b.id};
        Packet_Header_Encoder(&stream, &h);
        Adhesion_Factor_Encoder(&stream, &b.core);
    }

    End_of_Information c;
    {
        Packet_Header h {c.id};
        Packet_Header_Encoder(&stream, &h);
        End_of_Information_Encoder(&stream, &c.core);
    }

    stream.bitpos = init_pos;

    Eurobalise_Telegram telegram;

    telegram.decode(stream);

    assert(telegram.header == header);

    assert_equal(a, telegram.packets[0]);
    assert_equal(b, telegram.packets[1]);
    assert_equal(c, telegram.packets[2]);

    std::cout << "successful test of Eurobalise_Telegram_Decoder" << std::endl;

    return EXIT_SUCCESS;
}

