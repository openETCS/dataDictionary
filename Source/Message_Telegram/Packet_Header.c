
#include "Packet_Header.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Read.h"
#include "Bitstream_Write.h"
#include "Bitstream_Normal.h"
//#include <iostream>

int Packet_Header_UpperBitsNotSet(const Packet_Header* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,             8))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Packet_Header_Decoder(Bitstream* stream, Packet_Header* p)
{
    if (Bitstream_Normal(stream, PACKET_HEADER_BITSIZE))
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

int Packet_Header_Encoder(Bitstream* stream, const Packet_Header* p)
{
    if (Bitstream_Normal(stream, PACKET_HEADER_BITSIZE))
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

