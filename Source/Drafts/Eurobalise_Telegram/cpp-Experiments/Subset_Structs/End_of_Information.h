
#ifndef END_OF_INFORMATION_H_INCLUDED
#define END_OF_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "BasePacket.h"
#include "End_of_Information_Core.h"

struct End_of_Information : public BasePacket
{
    End_of_Information_Core core;

    End_of_Information() : BasePacket(255) {}

    void print(std::ostream& stream) const
    {
        stream << '(' << id << ')';
    }

    bool equals(const BasePacket& p) const
    {
        auto q = dynamic_cast< const End_of_Information*>(&p);
	if(q)
	{
	    return true;
	}
	return false;
     }
};

typedef std::shared_ptr<End_of_Information> End_of_InformationPtr;

#endif // END_OF_INFORMATION_H_INCLUDED

