
#include <cassert>
#include <iostream>
#include "Validated_Train_Data_Message.h"
#include "MA_Request_Message.h"
#include "EuroradioMessage.h"
#include "Packets.h"

template<typename Packet>
void assert_equal(const Packet& packet, BasePacketPtr ptr)
{
    auto x = std::dynamic_pointer_cast<Packet>(ptr);
    assert(x);
    assert(packet == *x);
}

int main ()
{
    std::cout << "\n--- Testing en-/decode bit functions with for Euroradio Messages" << std::endl;

    std::vector<uint8_t> raw_stream(1000);
    Bitstream stream;
    Bitstream_Init(&stream, &(raw_stream[0]), raw_stream.size(), 73);

    uint32_t init_pos = stream.bitpos;

    Position_Report a;
    {
        // NID_PACKET = 0;
        a.core.L_PACKET = 114;
        a.core.Q_SCALE = 1;
        a.core.NID_LRBG = 0;
        a.core.D_LRBG = 0;
        a.core.Q_DIRLRBG = 1;
        a.core.Q_DLRBG = 1;
        a.core.L_DOUBTOVER = 0;
        a.core.L_DOUBTUNDER = 0;
        a.core.Q_LENGTH = 0;
        a.core.V_TRAIN = 0;
        a.core.Q_DIRTRAIN = 1;
        a.core.M_MODE = 6;
        a.core.M_LEVEL = 0;
    }

    Validated_train_data b;
    {
        // NID_PACKET = 11;
        b.core.L_PACKET = 96;
        //b.core.NC_CDTRAIN = 0;
        b.core.NC_TRAIN = 0;
        b.core.L_TRAIN = 0;
        b.core.V_MAXTRAIN = 0;
        b.core.M_LOADINGGAUGE = 1;
        //b.core.M_AXLELOADCAT = 0;
        b.core.M_AIRTIGHT = 0;
        //b.core.N_AXLE = 0;
        b.core.N_ITER_1 = 0;
        b.core.N_ITER_2 = 0;
    }

    Validated_Train_Data_Message message;
    {
        // NID_MESSAGE = 129;
        message.L_MESSAGE = 36;
        message.T_TRAIN = 0;
        message.NID_ENGINE = 0;
        message.packet_0_1 = std::make_shared<Position_Report>(a);
        message.packet_11 = std::make_shared<Validated_train_data>(b);
    }

    MA_Request_Message message2;
    {
        // NID_MESSAGE = 132;
        message2.L_MESSAGE = 25; // (50 + 29 + 114 + 7) / 8
        message2.T_TRAIN = 1;
        message2.NID_ENGINE = 923;
        message2.Q_MARQSTREASON = 23;
        message2.packet_0_1 = std::make_shared<Position_Report>(a);
    }

    Level_23_transition_information c;
    {
        // NID_PACKET = 9;
        c.core.L_PACKET = 45;
        c.core.NID_LTRBG = 23983;
    }

    MA_Request_Message message3;
    {
        // NID_MESSAGE = 132;
        message3.L_MESSAGE = 30; // (50 + 29 + 114 + 45 + 7) / 8
        message3.T_TRAIN = 0;
        message3.NID_ENGINE = 0;
        message3.Q_MARQSTREASON = 23;
        message3.packet_0_1 = std::make_shared<Position_Report>(a);
        message3.optional_packets.push_back(std::make_shared<Level_23_transition_information>(c));
    }

    std::cout << " Encoder Input:  " << message << std::endl;
    std::cout << " Encoding Validated_Train_Data message." << std::endl;
    EuroradioMessage_Encoder(stream, std::make_shared<Validated_Train_Data_Message>(message));
    stream.bitpos = init_pos;
    std::cout << " Decoding Validated_Train_Data message." << std::endl;
    EuroradioMessagePtr new_message = EuroradioMessage_Decoder(stream);
    std::cout << " Decoder Output: " << (*new_message) << "\n" << std::endl;
    assert(message == *new_message);

    init_pos = stream.bitpos;
    std::cout << " Encoder Input:  " << message2 << std::endl;
    std::cout << " Encoding MA_Request message." << std::endl;
    EuroradioMessage_Encoder(stream, std::make_shared<MA_Request_Message>(message2));
    stream.bitpos = init_pos;
    std::cout << " Decoding MA_Request message." << std::endl;
    EuroradioMessagePtr new_message2 = EuroradioMessage_Decoder(stream);
    std::cout << " Decoder Output: " << (*new_message2) << "\n" << std::endl;
    assert(message2 == *new_message2);

    init_pos = stream.bitpos;
    std::cout << " Encoder Input:  " << message3 << std::endl;
    std::cout << " Encoding MA_Request message." << std::endl;
    EuroradioMessage_Encoder(stream, std::make_shared<MA_Request_Message>(message3));
    stream.bitpos = init_pos;
    std::cout << " Decoding MA_Request message." << std::endl;
    EuroradioMessagePtr new_message3 = EuroradioMessage_Decoder(stream);
    std::cout << " Decoder Output: " << (*new_message3) << "\n" << std::endl;
    assert(message3 == *new_message3);

    std::cout << " Test successful." << std::endl;

    return EXIT_SUCCESS;
}

