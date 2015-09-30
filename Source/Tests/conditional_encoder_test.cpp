
#include "EurobaliseTelegram.h"
#include "create.h"
#include <cassert>
#include <iostream>

int main ()
{
    std::cout << "\n--- Testing the en-/decode bit functions of Eurobalise Telegram with conditional packets" << std::endl;

    // construct telegram from header
    // telegram.header = create_TelegramHeader_TrainToTrack();
    EurobaliseTelegram telegram(create_TelegramHeader_TrackToTrain());

    telegram.add(std::make_shared<Temporary_Speed_Restriction>(create_Temporary_Speed_Restriction()));
    telegram.add(std::make_shared<Adhesion_Factor>(create_Adhesion_Factor()));
    telegram.add(std::make_shared<Infill_location_reference>(create_Infill_location_reference(1)));
    telegram.add(std::make_shared<Infill_location_reference>(create_Infill_location_reference(0)));

    // add end of information package to packet sequence
    telegram.add(std::make_shared<End_of_Information>());

    //std::cout << " Encoder Input: " << telegram << std::endl;

    // declare and initialize the stream
    std::vector<uint8_t> raw_stream(1000);
    Bitstream stream;
    Bitstream_Init(&stream, &(raw_stream[0]), raw_stream.size(), 73);

    // save the old bitpos
    uint32_t init_pos = stream.bitpos;

    //std::cout << " Encoding Eurobalise Telegram." << std::endl;
    telegram.encode(stream);

    // reset to the old bitpos
    stream.bitpos = init_pos;

    // declare a new telegram
    EurobaliseTelegram telegram_new;
    //std::cout << " Decoding Eurobalise Telegram." << std::endl;
    telegram_new.decode(stream);

    //std::cout << " Decoder Ouput: " << telegram_new << std::endl;
    assert(telegram_new == telegram);

    std::cout << " Test successfull." << std::endl;

    return EXIT_SUCCESS;
}

