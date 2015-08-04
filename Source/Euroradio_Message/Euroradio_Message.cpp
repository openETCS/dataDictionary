
#include "Euroradio_Message.h"
#include "Validated_Train_Data_Message.h"
#include "MA_Request_Message.h"
#include "Bitstream_Read.h"
#include <iostream>
#include <cassert>

Euroradio_Message::Euroradio_Message() {}

bool Euroradio_Message::decode(Bitstream& stream)
{
    NID_MESSAGE = Bitstream_Read(&stream, 8);

    return true;
}

Euroradio_MessagePtr Euroradio_Message_Decoder(Bitstream& stream)
{
    Euroradio_MessagePtr message = std::make_shared<Euroradio_Message>();
    (*message).decode(stream);

    switch(message->NID_MESSAGE)
    {
        case 129 :
	{
            auto ret = std::make_shared<Validated_Train_Data_Message>();

	    if ((*ret).decode(stream) == 1)
	    {
	        return ret;
            }
	    else
	    {
	        return Euroradio_MessagePtr();
	    }
	}

	case 132 :
	{
            auto ret = std::make_shared<MA_Request_Message>();

	    if ((*ret).decode(stream) == 1)
	    {
	        return ret;
	    }
	    else
	    {
	        return Euroradio_MessagePtr();
	    }
	}

	default :
	{
	    std::cout << "NID_MESSAGE " << +message->NID_MESSAGE << std::endl;
	    std::cerr << "Error, unrecognized Euroradio Message in " << __FILE__ << std::endl;
	    return Euroradio_MessagePtr();
	}
    }

    return Euroradio_MessagePtr();
}

bool Euroradio_Message_Encoder(Bitstream& stream, Euroradio_MessagePtr p)
{
    switch(p->NID_MESSAGE)
    {
        case 129 :
	{
	    auto ptr = std::dynamic_pointer_cast<Validated_Train_Data_Message>(p);
	    assert(ptr);

	    return (*ptr).encode(stream) == 1;
	}

        case 132 :
	{
	    auto ptr = std::dynamic_pointer_cast<MA_Request_Message>(p);
	    assert(ptr);

	    return (*ptr).encode(stream) == 1;
	}

	default :
	{
	    std::cout << "NID_MESSAGE " << +p->NID_MESSAGE << std::endl;
	    std::cerr << "Error, unrecognized Euroradio Message in " << __FILE__ << std::endl;
	    return false;
	}
    }

    return false;
}

