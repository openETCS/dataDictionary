
#include "Decoder_Branch.h"

BasePacketPtr Decoder_Branch(Bitstream* stream, Packet_Header header)
{
    switch(header.NID_PACKET)
    {
       case 71: // Adhesion_Factor
       {
           BasePacketPtr ret(new Adhesion_Factor());
	   Adhesion_Factor_Decoder(stream, &(ret->core));
	   return ret;
       }
       default :
       {
           return BasePacketPtr(); 
       }

    };
}

