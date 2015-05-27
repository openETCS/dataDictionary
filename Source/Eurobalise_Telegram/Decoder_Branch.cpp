
#include "Decoder_Branch.h"
//#include <iostream>

BasePacketPtr Decoder_Branch(Bitstream* stream, Packet_Header header)
{
    switch (header.NID_PACKET)
    {
    case 5 :
    {
        auto ret = std::make_shared<Train_running_number>();

        if (Train_running_number_Decoder(stream, &(ret->core)) == 1)
        {
            //std::cout << "packet 5" << std::endl;
            return ret;
        }
        else
        {
            return BasePacketPtr();
        }
    }

    case 71 :
    {
        auto ret = std::make_shared<Adhesion_Factor>();

        if (Adhesion_Factor_Decoder(stream, &(ret->core)) == 1)
        {
            //std::cout << "packet 71" << std::endl;
            return ret;
        }
        else
        {
            return BasePacketPtr();
        }
    }

    case 255 :
    {
        auto ret = std::make_shared<End_of_Information>();

        if (End_of_Information_Decoder(stream, &(ret->core)) == 1)
        {
            //std::cout << "packet 255" << std::endl;
            return ret;
        }
        else
        {
            return BasePacketPtr();
        }
    }

    default :
    {
        //std::cout << "No packet for " << header.NID_PACKET << std::endl;
        return BasePacketPtr();
    }
    };
}

