
#include "Encoder_Branch.h"
//#include <iostream>

bool Encoder_Branch(Bitstream* stream, BasePacketPtr packet)
{
    switch(packet.id)
    {
       case 5 :
       {
	   Packet_Header head;
	   head.NID_PACKET = 5;

	   if(Packet_Header_Encoder(&stream, &head) != 1)
	   {
	       return false;
	   }

	   if(Train_running_number_Encoder(stream, &(packet->core) != 1)
	   {
	       return false;
	   }

	   return true;
       }
       case 71 :
       {
	   Packet_Header head;
	   head.NID_PACKET = 71;

	   if(Packet_Header_Encoder(&stream, &head) != 1)
	   {
	       return false;
	   }

	   if(Adhesion_Factor_Encoder(stream, &(packet->core) != 1)
	   {
	       return false;
	   }

	   return true;
       }
       case 255 :
       {
	   Packet_Header head;
	   head.NID_PACKET = 255;

	   if(Packet_Header_Encoder(&stream, &head) != 1)
	   {
	       return false;
	   }

	   if(End_of_Information_Encoder(stream, &(packet->core) != 1)
	   {
	       return false;
	   }

	   return true;
       }
       default :
       {
           return false;
       }
    };
}

