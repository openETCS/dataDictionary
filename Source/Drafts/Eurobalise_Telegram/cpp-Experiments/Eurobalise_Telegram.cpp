
#include "Eurobalise_Telegram.h"

void Eurobalise_Telegram::Decoder(Bitstream* stream)
{
    Packet_Header packetID;

    int error = Eurobalise_Header_Decoder(stream, &(header));

    while(true)
    {
        Packet_Header_Decoder(stream, &packetID);
	packets.push_back(Decoder_Branch(stream, packetID));

	if(packetID.NID_PACKET == 255)
	{
            break;
	}
    }
}

