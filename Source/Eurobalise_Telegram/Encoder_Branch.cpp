
#include "Encoder_Branch.h"

bool Encoder_Branch(Bitstream* stream, BasePacketPtr packet)
{

    switch (packet->id)
    {

    case 5 :
    {
        auto ptr = std::static_pointer_cast<Train_running_number>(packet);

        return Train_running_number_Encoder(stream, &(ptr->core)) == 1;
    }

    case 71 :
    {
        auto ptr = std::static_pointer_cast<Adhesion_Factor>(packet);

        return Adhesion_Factor_Encoder(stream, &(ptr->core)) == 1;
    }

    case 255 :
    {
        auto ptr = std::static_pointer_cast<End_of_Information>(packet);

        return End_of_Information_Encoder(stream, &(ptr->core)) == 1;
    }

    default :
    {
        return false;
    }

    };

}

