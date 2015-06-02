
#ifndef END_OF_INFORMATION_H_INCLUDED
#define END_OF_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "End_of_Information_Core.h"
#include "BasePacket.h"

struct End_of_Information : public BasePacket
{
    End_of_Information_Core core;

    End_of_Information() : BasePacket(255) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << uint64_t(id) << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	return dynamic_cast<const End_of_Information*>(&p);
    }
};

typedef std::shared_ptr<End_of_Information> End_of_InformationPtr;

#endif // END_OF_INFORMATION_H_INCLUDED

