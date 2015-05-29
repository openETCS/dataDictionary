
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
    // declare a telegram
    Eurobalise_Telegram telegram;

    // declare and initialize a telegram header
    telegram.header = create_Telegram_Header();


    // create a pointer to a data packet including core data packet 1
    // and push this pointer into the telegam packet vector
    {
        auto a_packet = std::make_shared<Train_running_number>();
        *a_packet  = create_Train_running_number();
        telegram.packets.push_back(a_packet);
    }


    // create a pointer to a data packet including core data packet 2
    // and push this spointer into the telegram packet vector
    {
        auto b_packet = std::make_shared<Adhesion_Factor>();
        *b_packet = create_Adhesion_Factor();
        telegram.packets.push_back(b_packet);
    }

    // add end of information package to packet sequence
    telegram.packets.push_back(std::make_shared<End_of_Information>());

    std::cout << telegram << std::endl;

    // declare and initialize the stream
    std::vector<uint8_t> raw_stream(1000);
    Bitstream stream;
    Bitstream_Init(&stream, &(raw_stream[0]), raw_stream.size(), 73);

    // save the old bitpos
    uint32_t init_pos = stream.bitpos;

    // *** encode the telegram to the stream ***
    telegram.encode(stream);

    // reset to the old bitpos
    stream.bitpos = init_pos;

    // declare a new telegram
    Eurobalise_Telegram telegram_new;

    // *** decode from the stream to the new telegram ***
    telegram_new.decode(stream);

    std::cout << telegram_new << std::endl;
    assert(telegram_new == telegram);

    std::cout << "successful test of Eurobalise_Telegram encode then decode" << std::endl;

    return EXIT_SUCCESS;
}

