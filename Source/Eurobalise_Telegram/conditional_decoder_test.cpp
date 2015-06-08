
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

    std::vector<uint8_t> raw_stream(1000);
    Bitstream stream;
    Bitstream_Init(&stream, &(raw_stream[0]), raw_stream.size(), 73);

    uint32_t init_pos = stream.bitpos;

    // Telegram_Header header = create_Telegram_Header_TrainToTrack();
    Telegram_Header header = create_Telegram_Header_TrackToTrain();
    Telegram_Header_Encoder(&stream, &header);

/*
    Train_running_number a = create_Train_running_number();
    {
        Packet_Header h {a.id};
        Packet_Header_Encoder(&stream, &h);
        Train_running_number_Encoder(&stream, &a.core);
    }

    Error_Reporting b = create_Error_Reporting();
    {
        Packet_Header h {b.id};
        Packet_Header_Encoder(&stream, &h);
        Error_Reporting_Encoder(&stream, &b.core);
    }
*/

    Temporary_Speed_Restriction a = create_Temporary_Speed_Restriction();
    {
        Packet_Header h {a.id};
	Packet_Header_Encoder(&stream, &h);
	Temporary_Speed_Restriction_Encoder(&stream, &a.core);
    }

    Adhesion_Factor b = create_Adhesion_Factor();
    {
        Packet_Header h {b.id};
	Packet_Header_Encoder(&stream, &h);
	Adhesion_Factor_Encoder(&stream, &b.core);
    }

    Infill_location_reference c = create_Infill_location_reference(1);
    {
        Packet_Header h {c.id};
	Packet_Header_Encoder(&stream, &h);
	Infill_location_reference_Encoder(&stream, &c.core);
    }

    Infill_location_reference d = create_Infill_location_reference(0);
    {
        Packet_Header h {d.id};
	Packet_Header_Encoder(&stream, &h);
	Infill_location_reference_Encoder(&stream, &d.core);
    }

    End_of_Information e;
    {
        Packet_Header h {e.id};
        Packet_Header_Encoder(&stream, &h);
        End_of_Information_Encoder(&stream, &e.core);
    }

    stream.bitpos = init_pos;

    Eurobalise_Telegram telegram;

    telegram.decode(stream);

    assert(telegram.header == header);

    assert_equal(a, telegram.packets[0]);
    assert_equal(b, telegram.packets[1]);
    assert_equal(c, telegram.packets[2]);

    std::cout << "successful conditional decoder test" << std::endl;

    return EXIT_SUCCESS;
}

