
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
    std::cout << "--- Testing the decode function of Eurobalise Telegram with N_ITER packets." << std::endl;
    std::vector<uint8_t> raw_stream(1000);
    Bitstream stream;
    Bitstream_Init(&stream, &(raw_stream[0]), raw_stream.size(), 73);

    uint32_t init_pos = stream.bitpos;

    // TelegramHeader header = create_TelegramHeader_TrainToTrack();
    TelegramHeader header = create_TelegramHeader_TrackToTrain();
    std::cout << " Encoding Telegram Header: " << header << std::endl;
    TelegramHeader_Encoder(&stream, &header);

    Temporary_Speed_Restriction a = create_Temporary_Speed_Restriction();
    {
        PacketHeader_Encoder(&stream, &(a.header));
        std::cout << "    Encoding packet " << a << std::endl;
        Temporary_Speed_Restriction_Encoder(&stream, &a.core);
    }

    Adhesion_Factor b = create_Adhesion_Factor();
    {
        PacketHeader_Encoder(&stream, &(b.header));
        std::cout << "    Encoding packet " << b << std::endl;
        Adhesion_Factor_Encoder(&stream, &b.core);
    }

    Infill_location_reference c = create_Infill_location_reference(1);
    {
        PacketHeader_Encoder(&stream, &(c.header));
        std::cout << "    Encoding packet " << c << std::endl;
        Infill_location_reference_Encoder(&stream, &c.core);
    }

    Infill_location_reference d = create_Infill_location_reference(0);
    {
        PacketHeader_Encoder(&stream, &(d.header));
        std::cout << "    Encoding packet " << d << std::endl;
        Infill_location_reference_Encoder(&stream, &d.core);
    }

    Gradient_Profile e = create_Gradient_Profile();
    {
        PacketHeader_Encoder(&stream, &(e.header));
        std::cout << "    Encoding packet " << e << std::endl;
        Gradient_Profile_Encoder(&stream, &e.core);
    }

    End_of_Information f;
    {
        PacketHeader_Encoder(&stream, &(f.header));
        std::cout << "    Encoding packet " << f << std::endl;
        End_of_Information_Encoder(&stream, &f.core);
    }

    stream.bitpos = init_pos;

    EurobaliseTelegram telegram;

    std::cout << " Decoding Eurobalise Telegram." << std::endl;
    telegram.decode(stream);

    std::cout << " Decoder Output: " << telegram << std::endl;

    assert(telegram.header == header);

    assert_equal(a, telegram.packets[0]);
    assert_equal(b, telegram.packets[1]);
    assert_equal(c, telegram.packets[2]);

    std::cout << " Test successful." << std::endl;

    return EXIT_SUCCESS;
}

