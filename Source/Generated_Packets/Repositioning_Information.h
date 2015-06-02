
#ifndef REPOSITIONING_INFORMATION_H_INCLUDED
#define REPOSITIONING_INFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "Repositioning_Information_Core.h"
#include "BasePacket.h"

struct Repositioning_Information : public BasePacket
{
    Repositioning_Information_Core core;

    Repositioning_Information() : BasePacket(16) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << uint64_t(id) << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Repositioning_Information*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_SCALE == q->core.Q_SCALE) &&
                (core.L_SECTION == q->core.L_SECTION);
	}
	return false;
     }
};

typedef std::shared_ptr<Repositioning_Information> Repositioning_InformationPtr;

#endif // REPOSITIONING_INFORMATION_H_INCLUDED

