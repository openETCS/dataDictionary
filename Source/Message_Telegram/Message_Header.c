
#include "Message_Header.h"
#include "Bit64.h"

int Message_Header_UpperBitsNotSet(const Message_Header* p)
{
    if (UpperBitsNotSet64(p->NID_MESSAGE,             8))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Message_Header_Decoder(Bitstream* stream, Message_Header* p)
{
    if (Bitstream_Normal(stream, MESSAGE_HEADER_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        p->NID_MESSAGE = Bitstream_Read(stream, 8);

        //std::cout << "writing " << int(p->NID_MESSAGE) << " into the packet header" << std::endl;

        //@ assert NID_MESSAGE:        EqualBits(stream, pos,       pos + 8,   p->NID_MESSAGE);
        //@ assert NID_MESSAGE:        UpperBitsNotSet(p->NID_MESSAGE,        8);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Message_Header_Encoder(Bitstream* stream, const Message_Header* p)
{
    if (Bitstream_Normal(stream, MESSAGE_HEADER_BITSIZE))
    {
        if (Message_Header_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 8, p->NID_MESSAGE);

            //@ assert NID_MESSAGE:           EqualBits(stream, pos,       pos + 8,  p->NID_MESSAGE);

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

