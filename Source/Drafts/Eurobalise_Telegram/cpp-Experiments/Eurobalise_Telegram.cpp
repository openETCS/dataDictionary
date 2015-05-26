
#include "Eurobalise_Telegram.h"
//#include <iostream>

void Eurobalise_Telegram::Decoder(Bitstream* stream)
{
    Packet_Header packetID;

    int error = Eurobalise_Header_Decoder(stream, &(header));

    //std::cout << stream->bitpos << std::endl;

    uint32_t old_pos = stream->bitpos;

    while(stream->bitpos <= 1023 + old_pos)
    {
    	//std::cout << stream->bitpos << std::endl;

        Packet_Header_Decoder(stream, &packetID);
	//std::cout << "decoding packet number " << packetID.NID_PACKET << std::endl;
	packets.push_back(Decoder_Branch(stream, packetID));

	if(packetID.NID_PACKET == 255)
	{
            break;
	}
    }
}

