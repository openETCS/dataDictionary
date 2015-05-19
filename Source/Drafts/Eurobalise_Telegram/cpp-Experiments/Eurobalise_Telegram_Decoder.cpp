
#include "Eurobalise_Telegram_Decoder.h"

Eurobalise_Telegram Eurobalise_Telegram_Decoder(Bitstream* stream)
{
    Eurobalise_Telegram    ret;
    Packet_Header          packetID;
    BasePacketPtr          ptr;

    Eurobalise_Header_Decoder(stream, &(ret.header));

    while(true)
    {
        Packet_Header_Decoder(stream, &packetID);
	ret.packets.push_back(Decoder_Branch(stream, packetID));

	if(packetID.NID_PACKET == 255)
	{
            break;
	}
    }
    return ret;
}

