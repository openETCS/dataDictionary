
#include "Validated_Train_Data_Message.h"
#include "Bitstream_Init.h"
#include "subsets.h"
#include <cassert>
#include "UpperBitsNotSet.h"
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
    std::cout << "\n--- Testing the decode function with issue31 part 3\n";

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
        b.core.NC_CDTRAIN = 0;
        b.core.NC_TRAIN = 0;
        b.core.L_TRAIN = 0;
        b.core.V_MAXTRAIN = 0;
        b.core.M_LOADINGGAUGE = 1;
        b.core.M_AXLELOADCAT = 0;
        b.core.M_AIRTIGHT = 0;
        b.core.N_AXLE = 0;
        b.core.N_ITER_1 = 0;
        b.core.N_ITER_2 = 0;
    }

    Validated_Train_Data_Message message;
    {
        message.NID_MESSAGE = 129;
	message.L_MESSAGE = 36;
	message.T_TRAIN = 0;
	message.NID_ENGINE = 0;
	message.packet_0_1 = std::make_shared<Position_Report>(a);
	message.packet_11 = std::make_shared<Validated_train_data>(b);
    }

    std::cout << " Encoder Input: " << message << std::endl;

    std::cout << " Encoding Valid_Train_Data message." << std::endl;
    message.encode(stream);

    stream.bitpos = init_pos;

    Validated_Train_Data_Message new_message;

    std::cout << " Decoding Valid_Train_Data message." << std::endl;
    new_message.decode(stream);

    std::cout << " Decoder Output: " << new_message << std::endl;

    assert(message == new_message);

    std::cout << " Test successful." << std::endl;
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

