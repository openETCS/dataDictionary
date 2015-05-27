
#include "Eurobalise_Telegram.h"
#include "Eurobalise_Header_Decoder.h"
#include "Eurobalise_Header_Encoder.h"
#include "Packet_Header_Decoder.h"
#include "Packet_Header_Encoder.h"
#include "Decoder_Branch.h"
#include "Encoder_Branch.h"

//#include <iostream>

bool Eurobalise_Telegram::Decoder(Bitstream* stream)
{
    Packet_Header packetID;

    if (Eurobalise_Header_Decoder(stream, &(header)) != 1)
    {
        return false;
    }

    //std::cout << stream->bitpos << std::endl;

    uint32_t old_pos = stream->bitpos;

    while(stream->bitpos <= 1023 + old_pos)
    {
    	//std::cout << stream->bitpos << std::endl;

        Packet_Header_Decoder(stream, &packetID);
	//std::cout << "decoding packet number " << packetID.NID_PACKET << std::endl;
        auto packet = Decoder_Branch(stream, packetID);
        if(!packet)
        {
           return false;
        }

	packets.push_back(packet);

	if(packetID.NID_PACKET == 255)
	{
            break;
	}
    }

    return true;
}

bool Eurobalise_Telegram::Encoder(Bitstream* stream)
{
    uint32_t old_pos = stream->bitpos;

    if(Eurobalise_Header_Encoder(stream, &header) != 1)
    {
        return false;
    }

    int i = 0;

    while(packets[i] && (stream->bitpos <= 1023 + old_pos))
    {
        if(Encoder_Branch(stream, packets[i]) != 1)
	{
	    return false;
	}
        ++i;
    }

    if(packets[i-1]->id != 255)
    {
        return false;
    }

    return true;
}

