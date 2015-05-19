
#include "Decoder_Branch.h"

BasePacketPtr Decoder_Branch(Bitstream* stream, Packet_Header header)
{
    switch(header.NID_PACKET)
    {
       case 71 :
       {
           Adhesion_FactorPtr ret(new Adhesion_Factor());

	   if(Adhesion_Factor_Decoder(stream, &(ret->core)) == 1)
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

