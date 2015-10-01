
#include "EurobaliseTelegram.h"
#include "create.h"
#include <cassert>
#include <iostream>

template<typename Packet>
void assert_equal(const Packet& packet, BasePacketPtr ptr)
{
    auto x = std::dynamic_pointer_cast<Packet>(ptr);
    assert(x);
    assert(packet == *x);
}

int main ()
{
    std::cout << "\n--- Testing the decode bit function of Eurobalise Telegram" << std::endl;
    std::vector<uint8_t> raw_stream(1000);
    Bitstream stream;
    Bitstream_Init(&stream, &(raw_stream[0]), raw_stream.size(), 73);

    uint32_t init_pos = stream.bitpos;

    TelegramHeader header = create_TelegramHeader_TrainToTrack();
    // TelegramHeader header = create_TelegramHeader_TrackToTrain();
    //std::cout << " Encoding Telegram Header: " << header << std::endl;
    encode(stream, header);

    //std::cout << " Encoding data packets:" << std::endl;
    /*Train_running_number a = create_Train_running_number();
    {
        //std::cout << "    Encoding packet " << a << std::endl;
        encode(stream, a.header);
        encode(stream, a.core);
    }

    Error_Reporting b = create_Error_Reporting();
    {
        //std::cout << "    Encoding packet " << b << std::endl;
        encode(stream, b.header);
        encode(stream, b.core);
    }*/


    End_of_Information c;
    {
        //std::cout << "    Encoding packet " << c << std::endl;
        encode(stream, c.header);
        encode(stream, c.core);
    }

    stream.bitpos = init_pos;

    EurobaliseTelegram telegram;

    //std::cout << " Decoding Eurobalise Telegram." << std::endl;
    telegram.decode(stream);

    //std::cout << " Decoder Output: " << telegram << std::endl;

    assert(telegram.header() == header);

    assert_equal(a, telegram.packet(0));
    assert_equal(b, telegram.packet(1));
    assert_equal(c, telegram.packet(2));

    std::cout << " Test successfull." << std::endl;

    return EXIT_SUCCESS;
}

