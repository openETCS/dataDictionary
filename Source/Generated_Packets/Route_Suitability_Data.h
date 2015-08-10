
#ifndef ROUTE_SUITABILITY_DATA_H_INCLUDED
#define ROUTE_SUITABILITY_DATA_H_INCLUDED

#include "Bitstream.h"
#include "Route_Suitability_Data_Core.h"
#include "BasePacket.h"

struct Route_Suitability_Data : public BasePacket
{
    Route_Suitability_Data_Core core;

    Route_Suitability_Data() : BasePacket(70) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Route_Suitability_Data*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
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

typedef std::shared_ptr<Route_Suitability_Data> Route_Suitability_DataPtr;

#endif // ROUTE_SUITABILITY_DATA_H_INCLUDED

