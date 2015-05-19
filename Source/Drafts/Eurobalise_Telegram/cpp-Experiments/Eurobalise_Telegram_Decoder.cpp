
#include "Eurobalise_Telegram.h"
#include "Decoder_Branch.h"
#include "Packet_Header.h"

typedef std::vector<BasePacketPtr> PacketSequence;

Eurobalise_Telegram Eurobalise_Telegram_Decoder(Bitstream* stream)
{
    Eurobalise_Telegram ret;

    Eurobalise_Header_Decoder(stream, &(ret.header));

    Packet_Header packetID;
    BasePacketPtr ptr;

    while(true)
    {
        // Read the NID_PACKET from the stream
        Header_Decoder(stream, &packetID);

	// Create a new BasePacket for the new ID
	ptr = BasePacketPtr(new BasePacket(packetID.NID_PACKET));

        // Read the correct packet with the decoder branch
	ptr = BasePacketPtr(Decoder_Branch(stream, ptr));

	// Append the newly read packet to the sequence
	ret.packets.push_back(ptr);

	if(packetID.NID_PACKET == 255)
	{
	    // End of information packet read
            break;
	}
    }

    return ret;
}

