
#ifndef END_OF_INFORMATION_H_INCLUDED
#define END_OF_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "BasePacket.h"
#include "End_of_Information_Core.h"

struct End_of_Information : public BasePacket
{
    End_of_Information_Core core;

    End_of_Information() : BasePacket(255) {}
};

typedef std::shared_ptr<End_of_Information> End_of_InformationPtr;

#endif // END_OF_INFORMATION_H_INCLUDED

