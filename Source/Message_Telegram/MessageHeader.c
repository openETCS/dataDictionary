
#include "MessageHeader.h"
#include "Bit64.h"

int MessageHeader_UpperBitsNotSet(const MessageHeader* p)
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

int MessageHeader_Decoder(Bitstream* stream, MessageHeader* p)
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

int MessageHeader_Encoder(Bitstream* stream, const MessageHeader* p)
{
    if (Bitstream_Normal(stream, MESSAGE_HEADER_BITSIZE))
    {
        if (MessageHeader_UpperBitsNotSet(p))
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

