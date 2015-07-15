
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


template<typename Packet>
void assert_equal(const Packet& packet, BasePacketPtr ptr)
{
    auto x = std::dynamic_pointer_cast<Packet>(ptr);
    assert(x);
    assert(packet == *x);
}

int main ()
{
    std::cout << "\n--- Testing the decode function with issue31\n";

    std::vector<uint8_t> raw_stream(1000);
    Bitstream stream;
    Bitstream_Init(&stream, &(raw_stream[0]), raw_stream.size(), 73);

    uint32_t init_pos = stream.bitpos;

    Eurobalise_Telegram telegram;

    Telegram_Header header;
    {
        header.Q_UPDOWN  = 1;
	header.M_VERSION = 32;
	header.Q_MEDIA	 = 0;
	header.N_PIG	 = 1;
	header.N_TOTAL	 = 1;
	header.M_DUP	 = 0;
	header.M_MCOUNT	 = 0;
	header.NID_C	 = 64;
	header.NID_BG	 = 3;
	header.Q_LINK	 = 1;
    }

    telegram.header = header;

    End_of_Information f;

    telegram.add(std::make_shared<End_of_Information>(f));

    std::cout << " Encoder Input: " << telegram << std::endl;

    std::cout << " Encoding Eurobalise Telegram." << std::endl;
    telegram.encode(stream);

    stream.bitpos = init_pos;

    Eurobalise_Telegram new_telegram;

    std::cout << " Decoding Eurobalise Telegram." << std::endl;
    new_telegram.decode(stream);

    std::cout << " Decoder Output: " << telegram << std::endl;

    assert(telegram == new_telegram);

    std::cout << " Test successful." << std::endl;
    std::cout << std::endl;



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




    return EXIT_SUCCESS;
}

