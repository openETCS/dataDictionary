
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
               << +core.N_ITER;
	for (uint32_t i = 0; i < core.N_ITER; ++i)
	{
            stream << &core.GRADIENT_PROFILE_1[i];
	}
	stream << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Gradient_Profile*>(&p))
	{
	    bool status = true;

	    (core.Q_DIR == q->core.Q_DIR)? status = status : status = false;
	    (core.L_PACKET == q->core.L_PACKET)? status = status : status = false;
	    (core.Q_SCALE == q->core.Q_SCALE)? status = status : status = false;
	    (core.D_GRADIENT == q->core.D_GRADIENT)? status = status : status = false;
	    (core.Q_GDIR == q->core.Q_GDIR)? status = status : status = false;
	    (core.G_A == q->core.G_A)? status = status : status = false;
	    (core.N_ITER == q->core.N_ITER)? status = status : status = false;
	    for (uint32_t i = 0; i < core.N_ITER; ++i)
	    {
	        (core.GRADIENT_PROFILE_1[i] == q->core.GRADIENT_PROFILE_1[i])? status = status : status = false;
	    }

	    return status;

	    /*
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_SCALE == q->core.Q_SCALE) &&
                (core.D_GRADIENT == q->core.D_GRADIENT) &&
                (core.Q_GDIR == q->core.Q_GDIR) &&
                (core.G_A == q->core.G_A) &&
		(core.N_ITER == q->core.N_ITER);
            */
	}
	return false;
    }
};

typedef std::shared_ptr<Gradient_Profile> Gradient_ProfilePtr;

#endif // GRADIENT_PROFILE_H_INCLUDED

