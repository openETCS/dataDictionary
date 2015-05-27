
#include "Encoder_Branch.h"
#include "Packet_Header_Encoder.h"
//#include <iostream>

bool Encoder_Branch(Bitstream* stream, BasePacketPtr packet)
{
    Packet_Header header;
    header.NID_PACKET = packet->id;
    if(Packet_Header_Encoder(stream, &header) != 1)
    {
       return false;
    } 

    switch(packet->id)
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

