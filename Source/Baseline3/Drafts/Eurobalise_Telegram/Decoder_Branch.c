
#include "Ring_Buffer.h"

/*
    Reads a packet from the stream and writes the data into the
    correct ringbuffer.
*/
void Decoder_Branch(Bitstream* stream, Header packetID)
{
    switch(packetID->NID_PACKET)
    {
    	// Adhesion_Factor
        case 71 :
	{
           // TODO Read the Adhesion_Factor packet from the stream and write it into the ringbuffer.
	}
    };

    return;
}

