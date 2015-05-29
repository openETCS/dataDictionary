
#include "Eurobalise_Telegram.h"
#include "Telegram_Header_Encoder.h"
#include "Packet_Header_Encoder.h"
#include "Bitstream_Init.h"
#include "subsets.h"
#include "create.h"
#include <cassert>
#include <iostream>

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
        Packet_Header h{5};
        Packet_Header_Encoder(&stream, &h);
        Train_running_number_Encoder(&stream, &a.core);
    }

    Adhesion_Factor b = create_Adhesion_Factor();
    {
        Packet_Header h{71};
        Packet_Header_Encoder(&stream, &h);
        Adhesion_Factor_Encoder(&stream, &b.core);
    }


    End_of_Information c;
    {
        Packet_Header h{255};
        Packet_Header_Encoder(&stream, &h);
        End_of_Information_Encoder(&stream, &c.core);
    }

    stream.bitpos = init_pos;

    Eurobalise_Telegram telegram;

    telegram.decode(stream);

    assert(telegram.header == header);

    assert(a == *std::static_pointer_cast<Train_running_number>(telegram.packets[0]));
    assert(b == *std::static_pointer_cast<Adhesion_Factor>(telegram.packets[1]));
    assert(c == *std::static_pointer_cast<End_of_Information>(telegram.packets[2]));

    std::cout << "successful test of Eurobalise_Telegram_Decoder" << std::endl;

    return EXIT_SUCCESS;
}

