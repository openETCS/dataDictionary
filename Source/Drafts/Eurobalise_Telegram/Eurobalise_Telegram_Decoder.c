
#include "Decoder_Branch.c"
#include "Header_Decoder.h"

/*
    Reads a complete telegram from the stream.
    The function starts with reading a Eurobalise_Header and finished 
    after reading an End_of_informatik packet (NID_PACKET = 255).
*/
void Eurobalise_Telegram_Decoder(Bitstream* stream, Packet_Counter* counter)
{
    Packet_Counter_Init(counter);

    // Read the Eurobalise Header
    // TODO This Header has to be returnes somehow
    Eurobalise_Header_Decoder(stream, &(counter->Header));

    // We use this instance to store the packet ID for the next packet to read. 
    Header packetID;

    while(true)
    {
        // Read the NID_PACKET from the stream.
        Header_Decoder(stream, &packetID);

	// Read the packet. Since we are using global ringbuffers to store the packets data
	// we don't need to list it as a parameter.
	Decoder_Branch(stream, &packetID);

	if(packetID->NID_PACKET == 255)
	{
	    // We just read the End_of_information packet
	    // which does always mark the end of an Eurobalise telegram
            break;
	}
	// TODO The counter for the packet has to increment here.
    }
}

