
#ifndef GRADIENT_PROFILE_H_INCLUDED
#define GRADIENT_PROFILE_H_INCLUDED

#include "Bitstream.h"
#include "Gradient_Profile_Core.h"
#include "BasePacket.h"

struct Gradient_Profile : public BasePacket
{
    Gradient_Profile_Core core;

    Gradient_Profile() : BasePacket(21) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
	       << +id << ','
               << +core.Q_DIR << ','
               << +core.L_PACKET << ','
               << +core.Q_SCALE << ','
               << +core.D_GRADIENT << ','
               << +core.Q_GDIR << ','
               << +core.G_A << ','
               << +core.N_ITER << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Gradient_Profile*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_SCALE == q->core.Q_SCALE) &&
                (core.D_GRADIENT == q->core.D_GRADIENT) &&
                (core.Q_GDIR == q->core.Q_GDIR) &&
                (core.G_A == q->core.G_A) &&
		(core.N_ITER == q->core.N_ITER);
	}
	return false;
    }
};

typedef std::shared_ptr<Gradient_Profile> Gradient_ProfilePtr;

#endif // GRADIENT_PROFILE_H_INCLUDED

