
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
};

inline bool operator==(const End_of_Information& a, const End_of_Information& b)
{
     return (a.core == b.core);
}
 
inline bool operator!=(const End_of_Information& a, const End_of_Information& b)
{
     return !(a == b);
}


typedef std::shared_ptr<End_of_Information> End_of_InformationPtr;

#endif // END_OF_INFORMATION_H_INCLUDED

