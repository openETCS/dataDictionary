
#include "EurobaliseTelegram.h"
#include "create.h"
#include <cassert>
#include <iostream>

int main ()
{
    std::cout << "--- Testing the encode and decode functions of Eurobalise Telegram consecutively with N_ITER packets." << std::endl;
    // declare a telegram
    EurobaliseTelegram telegram;

    // declare and initialize a telegram header
    telegram.header = create_TelegramHeader_TrackToTrain();

    telegram.add(std::make_shared<Temporary_Speed_Restriction>(create_Temporary_Speed_Restriction()));
    telegram.add(std::make_shared<Adhesion_Factor>(create_Adhesion_Factor()));
    telegram.add(std::make_shared<Infill_location_reference>(create_Infill_location_reference(1)));
    telegram.add(std::make_shared<Infill_location_reference>(create_Infill_location_reference(0)));
    telegram.add(std::make_shared<Gradient_Profile>(create_Gradient_Profile()));

    // add end of information package to packet sequence
    telegram.add(std::make_shared<End_of_Information>());

    std::cout << " Encoder Input: " << telegram << std::endl;

    // declare and initialize the stream
    std::vector<uint8_t> raw_stream(1000);
    Bitstream stream;
    Bitstream_Init(&stream, &(raw_stream[0]), raw_stream.size(), 73);

    // save the old bitpos
    uint32_t init_pos = stream.bitpos;

    std::cout << " Encoding Eurobalise Telegram." << std::endl;
    telegram.encode(stream);

    // reset to the old bitpos
    stream.bitpos = init_pos;

    // declare a new telegram
    EurobaliseTelegram telegram_new;

    std::cout << " Decoding Eurobalise Telegram." << std::endl;
    telegram_new.decode(stream);

    std::cout << " Decoder Output: " << telegram_new << std::endl;
    assert(telegram_new == telegram);

    std::cout << " Test successful.\n" << std::endl;

    return EXIT_SUCCESS;
}

