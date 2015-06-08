
#include "Packet_Header_Encoder.h"
#include "Packet_Header_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Packet_Header_Encoder(Bitstream* stream, const Packet_Header* p)
{
    if (NormalBitstream(stream, PACKET_HEADER_BITSIZE))
    {
        if (Packet_Header_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

	    Bitstream_Write(stream, 8, p->NID_PACKET);

            //@ assert NID_PACKET:           EqualBits(stream, pos,       pos + 8,  p->NID_PACKET);

            return 1;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
}

