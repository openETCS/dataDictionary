
#include "Decoder_Branch.h"

BasePacketPtr Decoder_Branch(Bitstream* stream, Packet_Header header)
{
    switch (header.NID_PACKET)
    {
    case 5 :
    {
        auto ret = std::make_shared<Train_running_number>();

        if (Train_running_number_Decoder(stream, &(ret->core)) == 1)
        {
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
            return ret;
        }
        else
        {
            return BasePacketPtr();
        }
    }

    default :
    {
        return BasePacketPtr();
    }
    };
}

