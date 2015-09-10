
#ifndef INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_H_INCLUDED
#define INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_H_INCLUDED

#include "Bitstream.h"
#include "Inhibition_of_revocable_TSRs_from_balises_in_L23_Core.h"
#include "BasePacket.h"

struct Inhibition_of_revocable_TSRs_from_balises_in_L23 : public BasePacket
{
    Inhibition_of_revocable_TSRs_from_balises_in_L23_Core core;

    Inhibition_of_revocable_TSRs_from_balises_in_L23() : BasePacket(64) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Inhibition_of_revocable_TSRs_from_balises_in_L23*>(&p))
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

typedef std::shared_ptr<Inhibition_of_revocable_TSRs_from_balises_in_L23> Inhibition_of_revocable_TSRs_from_balises_in_L23Ptr;

#endif // INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_H_INCLUDED

