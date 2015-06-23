
#include "Eurobalise_Telegram.h"
#include "Telegram_Header_Encoder.h"
#include "Packet_Header_Encoder.h"
#include "Bitstream_Init.h"
#include "subsets.h"
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
    std::cout << "\n--- Testing the decode function with issue31\n";

    std::vector<uint8_t> raw_stream(1000);
    Bitstream stream;
    Bitstream_Init(&stream, &(raw_stream[0]), raw_stream.size(), 73);

    uint32_t init_pos = stream.bitpos;

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

    std::cout << " Encoding Telegram Header: " << header << std::endl;
    Telegram_Header_Encoder(&stream, &header);

    End_of_Information f;
    {
        Packet_Header h {f.id};
        Packet_Header_Encoder(&stream, &h);
	std::cout << "    Encoding packet " << f << std::endl;
        End_of_Information_Encoder(&stream, &f.core);
    }

    stream.bitpos = init_pos;

    Eurobalise_Telegram telegram;

    std::cout << " Decoding Eurobalise Telegram." << std::endl;
    telegram.decode(stream);

    std::cout << " Decoder Output: " << telegram << std::endl;

    assert(telegram.header == header);

    std::cout << " Test successful." << std::endl;
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

