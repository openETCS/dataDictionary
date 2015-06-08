
#ifndef DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_H_INCLUDED
#define DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_H_INCLUDED

#include "Bitstream.h"
#include "Data_used_by_applications_outside_the_ERTMSETCS_system_Core.h"
#include "BasePacket.h"

struct Data_used_by_applications_outside_the_ERTMSETCS_system : public BasePacket
{
    Data_used_by_applications_outside_the_ERTMSETCS_system_Core core;

    Data_used_by_applications_outside_the_ERTMSETCS_system() : BasePacket(44) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
	       << +id << ','
               << +core.Q_DIR << ','
               << +core.L_PACKET << ','
               << +core.NID_XUSER << ','
               << +core.NID_NTC << ','
               << +core.Other_data_depending_on__NID_XUSER << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Data_used_by_applications_outside_the_ERTMSETCS_system*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.NID_XUSER == q->core.NID_XUSER) &&
                ((!core.NID_XUSER == 102) || (
                (core.NID_NTC == q->core.NID_NTC)
                ));
	}
	return false;
    }
};

typedef std::shared_ptr<Data_used_by_applications_outside_the_ERTMSETCS_system> Data_used_by_applications_outside_the_ERTMSETCS_systemPtr;

#endif // DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_H_INCLUDED

