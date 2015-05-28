
#include "Eurobalise_Telegram.h"
#include "Telegram_Header_Encoder.h"
#include "Packet_Header_Encoder.h"
#include "Bitstream_Init.h"
#include "subsets.h"
#include <cassert>
#include <iostream>

int main ()
{
    // declare a telegram
    Eurobalise_Telegram telegram;

    // declare and initialize a telegram header
    Telegram_Header head;
    {
        head.Q_UPDOWN = 0;
        head.M_VERSION = 3;
        head.Q_MEDIA = 0;
        head.N_PIG = 4;
        head.N_TOTAL = 3;
        head.M_DUP = 3;
        head.M_MCOUNT = 34;
        head.NID_C  = 120;
        head.NID_BG = 49;
        head.Q_LINK = 1;
    }

    // write the telegram header into the telegram
    telegram.header = head;

    // declare and initialize core data packet 1
    Train_running_number_Core a;
    {
        a.L_PACKET = 53;
        a.NID_OPERATIONAL = 9;
    }

    // create a pointer to a data packet including core data packet 1
    // and push this pointer into the telegam packet vector
    auto a_packet = std::make_shared<Train_running_number>();
    a_packet->core = a;
    telegram.packets.push_back(a_packet);

    // declare and initialize core data packet 2
    Adhesion_Factor_Core b;
    {
        b.Q_DIR = 1;
        b.L_PACKET = 56;
        b.Q_SCALE = 1;
        b.D_ADHESION = 9;
        b.L_ADHESION = 24;
        b.M_ADHESION = 0;
    }

    // create a pointer to a data packet including core data packet 2
    // and push this spointer into the telegram packet vector
    auto b_packet = std::make_shared<Adhesion_Factor>();
    b_packet->core = b;
    telegram.packets.push_back(b_packet);

    // declare core data packet 3 (end of telegram)
    End_of_Information_Core c;

    // create a pointer to a data packet including core data packet 3
    // and push this pointer into the telegram packet vector
    auto c_packet = std::make_shared<End_of_Information>();
    c_packet->core = c;
    telegram.packets.push_back(c_packet);

    std::cout << telegram << std::endl;

    // declare and initialize the stream
    std::vector<uint8_t> raw_stream(1000);
    Bitstream stream;
    Bitstream_Init(&stream, &(raw_stream[0]), raw_stream.size(), 73);

    // save the old bitpos
    uint32_t init_pos = stream.bitpos;

    // *** encode the telegram to the stream ***
    telegram.encode(&stream);

    // reset to the old bitpos
    stream.bitpos = init_pos;

    // declare a new telegram
    Eurobalise_Telegram telegram_new;

    // *** decode from the stream to the new telegram ***
    telegram_new.decode(&stream);

    std::cout << telegram_new << std::endl;
    assert(telegram_new == telegram);

    std::cout << "successful test of Eurobalise_Telegram encode then decode" << std::endl;

    return EXIT_SUCCESS;
}

