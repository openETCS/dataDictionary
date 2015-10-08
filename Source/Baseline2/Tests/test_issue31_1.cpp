
#include "EurobaliseTelegram.h"
#include "Packets.h"
#include "print_bits.h"
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
    std::cout << "\n--- test issue31 part 1" << std::endl;

    std::vector<uint8_t> raw_stream(1000);
    Bitstream stream;
    Bitstream_Init(&stream, &(raw_stream[0]), raw_stream.size(), 0);

    uint32_t init_pos = stream.bitpos;

    TelegramHeader header;
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

    EurobaliseTelegram telegram(header);

    End_of_Information f;

    telegram.add(std::make_shared<End_of_Information>(f));

    //std::cout << " Encoder Input: " << telegram << std::endl;

    //std::cout << " Encoding Eurobalise Telegram." << std::endl;
    telegram.encode(stream);

    //std::cout << " print from position " << init_pos << " to " << stream.bitpos <<  std::endl;
    //print(stream, init_pos, stream.bitpos);
    //std::cout << std::endl;
    //std::cout << std::endl;

    stream.bitpos = init_pos;

    EurobaliseTelegram new_telegram;

    //std::cout << " Decoding Eurobalise Telegram." << std::endl;
    new_telegram.decode(stream);

    //std::cout << " Decoder Output: " << telegram << std::endl;

    assert(telegram == new_telegram);

    std::cout << " Test successful." << std::endl;
    //std::cout << std::endl;

    return EXIT_SUCCESS;
}

