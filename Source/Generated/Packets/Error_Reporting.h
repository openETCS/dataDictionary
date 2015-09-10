
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
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Error_Reporting*>(&p))
        {
            return header == q->header && core == q->core;
        }

        return false;
    }

    uint16_t length() const override
    {
        return  core.L_PACKET;
    }

    int encode(Bitstream& stream) const override
    {
        return ::encode(stream, core);
    }

    int decode(Bitstream& stream) override
    {
        return ::decode(stream, core);
    }

};

typedef std::shared_ptr<Error_Reporting> Error_ReportingPtr;

#endif // ERROR_REPORTING_H_INCLUDED

