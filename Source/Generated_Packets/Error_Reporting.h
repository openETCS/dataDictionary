
#ifndef ERROR_REPORTING_H_INCLUDED
#define ERROR_REPORTING_H_INCLUDED

#include "Bitstream.h"
#include "Error_Reporting_Core.h"
#include "BasePacket.h"

struct Error_Reporting : public BasePacket
{
    Error_Reporting_Core core;

    Error_Reporting() : BasePacket(4) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +header.NID_PACKET << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Error_Reporting*>(&p))
	{
	    bool status = true;

	    status = status && (header.NID_PACKET == q->header.NID_PACKET);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
    
    uint16_t length() const override
    {
        return  core.L_PACKET;
    }
};

typedef std::shared_ptr<Error_Reporting> Error_ReportingPtr;

#endif // ERROR_REPORTING_H_INCLUDED

