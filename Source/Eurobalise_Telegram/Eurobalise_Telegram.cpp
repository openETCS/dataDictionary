
#include "Eurobalise_Telegram.h"
#include "Telegram_Header_Decoder.h"
#include "Telegram_Header_Encoder.h"
#include "Packet_Header_Decoder.h"
#include "Packet_Header_Encoder.h"
#include "Decoder_Branch.h"
#include "Encoder_Branch.h"

#include <cassert>

bool Eurobalise_Telegram::Decoder(Bitstream* stream)
{
    Packet_Header packetID;

    if (Telegram_Header_Decoder(stream, &(header)) != 1)
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
    Packet_Header packetID;

    if(Telegram_Header_Encoder(stream, &header) != 1)
    {
        return false;
    }

    // check that last packet denotes end of message
    assert(packets.back()->id == 255);

    for(auto p = packets.begin(); p != packets.end(); ++p)
    {
        packetID.NID_PACKET = (*p)->id;
	if(Packet_Header_Encoder(stream, &packetID) != 1)
	{
	    return false;
	}
        if(Encoder_Branch(stream, *p) != 1)
	{
	    return false;
	}
    }

    return true;
}

