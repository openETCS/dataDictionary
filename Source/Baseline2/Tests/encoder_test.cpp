
#include "EurobaliseTelegram.h"
#include "create.h"
#include <cassert>
#include <iostream>

int main ()
{
    std::cout << "\n--- Testing the en-/decode bit functions of Eurobalise Telegram" << std::endl;

    // declare and initialize a telegram header
    EurobaliseTelegram telegram(create_TelegramHeader_TrainToTrack());
    //telegram.add(std::make_shared<Train_running_number>(create_Train_running_number()));
    //telegram.add(std::make_shared<Error_Reporting>(create_Error_Reporting()));
    telegram.add(std::make_shared<End_of_Information>());

    //std::cout << " Encoder Input: " << telegram << std::endl;

    // declare and initialize the stream
    std::vector<uint8_t> raw_stream(1000);
    Bitstream stream;
    Bitstream_Init(&stream, &(raw_stream[0]), raw_stream.size(), 73);

    // save the old bitpos
    uint32_t init_pos = stream.bitpos;

    // *** encode the telegram to the stream ***
    //std::cout << " Encoding Eurobalise Telegram." << std::endl;
    telegram.encode(stream);

    // reset to the old bitpos
    stream.bitpos = init_pos;

    // declare a new telegram
    EurobaliseTelegram telegram_new;

    // *** decode from the stream to the new telegram ***
    //std::cout << " Decoding Eurobalise Telegram." << std::endl;
    telegram_new.decode(stream);

    //std::cout << " Decoder Output: " << telegram_new << std::endl;
    assert(telegram_new == telegram);

    std::cout << " Test successfull." << std::endl;

    return EXIT_SUCCESS;
}

