
#include "Eurobalise_Telegram.h"
#include "Telegram_Header_Encoder.h"
#include "Packet_Header_Encoder.h"
#include "Bitstream_Init.h"
#include "subsets.h"
#include "create.h"
#include <cassert>
#include <iostream>

// for debug reasons
#include <bitset>

int main ()
{
    std::cout << "--- Testing the encode and decode functions of Eurobalise Telegram consecutively." << std::endl;
    // declare a telegram
    Eurobalise_Telegram telegram;

    // declare and initialize a telegram header
    telegram.header = create_Telegram_Header_TrainToTrack();
    // telegram.header = create_Telegram_Header_TrackToTrain();
// create a pointer to a data packet including core data packet 1
    // and push this pointer into the telegam packet vector
    telegram.add(std::make_shared<Train_running_number>(create_Train_running_number()));
    telegram.add(std::make_shared<Error_Reporting>(create_Error_Reporting()));

    // telegram.add(std::make_shared<Temporary_Speed_Restriction>(create_Temporary_Speed_Restriction()));
    // telegram.add(std::make_shared<Adhesion_Factor>(create_Adhesion_Factor()));

    // add end of information package to packet sequence
    telegram.add(std::make_shared<End_of_Information>());

    std::cout << " Encoder Input: " << telegram << std::endl;

    // declare and initialize the stream
    std::vector<uint8_t> raw_stream(1000);
    Bitstream stream;
    Bitstream_Init(&stream, &(raw_stream[0]), raw_stream.size(), 73);

    // save the old bitpos
    uint32_t init_pos = stream.bitpos;

    // *** encode the telegram to the stream ***
    std::cout << " Encoding Eurobalise Telegram." << std::endl;
    telegram.encode(stream);

    
    //test bitoutput of stream
    for (int n=0; n<30; ++n)
    {
        std::cout << (int)raw_stream[n];
        std::cout << " ";      
        if ((int)raw_stream[n] < 10) std::cout << " ";
        if ((int)raw_stream[n] < 100) std::cout << " ";
    }    
    
    std::cout << "\n";
    
    for (int n=0; n<30; ++n)
    {
        std::cout << std::hex << (int)raw_stream[n];
        std::cout << "  ";       
        if ((int)raw_stream[n] < 16) std::cout << " ";
    }  

    std::cout << "\n";
   
    for (int n=0; n<30; ++n)
    {
        if ((n%10)==0) std::cout << "\n";
        std::cout << std::bitset<8>((int)raw_stream[n]);
        std::cout << "  ";      
    }  

    std::cout << "\n";




    // reset to the old bitpos
    stream.bitpos = init_pos;

    // declare a new telegram
    Eurobalise_Telegram telegram_new;

    // *** decode from the stream to the new telegram ***
    std::cout << " Decoding Eurobalise Telegram." << std::endl;
    telegram_new.decode(stream);

    std::cout << " Decoder Output: " << telegram_new << std::endl;
    assert(telegram_new == telegram);

    std::cout << " Test successfull.\n" << std::endl;

    return EXIT_SUCCESS;
}

