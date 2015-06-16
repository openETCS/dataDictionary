
#ifndef DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_H_INCLUDED
#define DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_H_INCLUDED

#include "Bitstream.h"
#include "Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core.h"
#include "BasePacket.h"

struct Data_used_by_applications_outside_the_ERTMS_or_ETCS_system : public BasePacket
{
    Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core core;

    Data_used_by_applications_outside_the_ERTMS_or_ETCS_system() : BasePacket(44) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Data_used_by_applications_outside_the_ERTMS_or_ETCS_system*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Data_used_by_applications_outside_the_ERTMS_or_ETCS_system> Data_used_by_applications_outside_the_ERTMS_or_ETCS_systemPtr;

#endif // DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_H_INCLUDED

