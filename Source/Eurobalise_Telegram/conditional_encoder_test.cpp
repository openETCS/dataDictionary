
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
    // telegram.header = create_Telegram_Header_TrainToTrack();
    telegram.header = create_Telegram_Header_TrackToTrain();

    // create a pointer to a data packet including core data packet 1
    // and push this pointer into the telegam packet vector
    // telegram.add(std::make_shared<Train_running_number>(create_Train_running_number()));
    // telegram.add(std::make_shared<Error_Reporting>(create_Error_Reporting()));

    telegram.add(std::make_shared<Temporary_Speed_Restriction>(create_Temporary_Speed_Restriction()));
    telegram.add(std::make_shared<Adhesion_Factor>(create_Adhesion_Factor()));
    telegram.add(std::make_shared<Infill_location_reference>(create_Infill_location_reference(1)));
    telegram.add(std::make_shared<Infill_location_reference>(create_Infill_location_reference(0)));

    // add end of information package to packet sequence
    telegram.add(std::make_shared<End_of_Information>());

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

    std::cout << "successful conditional encoder test" << std::endl;

    return EXIT_SUCCESS;
}
