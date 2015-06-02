
#include "Packet_Header_Decoder.h"
#include "Bitstream_Read.h"
//#include <iostream>

int Packet_Header_Decoder(Bitstream* stream, Packet_Header* p)
{
    if (NormalBitstream(stream, PACKET_HEADER_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	p->NID_PACKET = Bitstream_Read(stream, 8);

	//std::cout << "writing " << int(p->NID_PACKET) << " into the packet header" << std::endl;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
	//@ assert NID_PACKET:        UpperBitsNotSet(p->NID_PACKET,        8);

        return 1;
    }
    else
    {
        return 0;
    }
}

