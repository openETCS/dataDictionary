
#ifndef ADHESION_FACTOR_H_INCLUDED
#define ADHESION_FACTOR_H_INCLUDED

#include "Bitstream.h"
#include "Adhesion_Factor_Core.h"
#include "BasePacket.h"

struct Adhesion_Factor : public BasePacket
{
    Adhesion_Factor_Core core;

    Adhesion_Factor() : BasePacket(71) {}

    void print(std::ostream& stream) const
    {
        stream << '(' << id << ','
	<< core.Q_DIR << ','
	<< core.L_PACKET << ','
	<< core.Q_SCALE << ','
	<< core.Q_SCALE << ','
	<< core.D_ADHESION << ','
	<< core.L_ADHESION << ','
	<< core.M_ADHESION << ')';
    }
};

inline bool operator==(const Adhesion_Factor& a, const Adhesion_Factor& b)
{
    return (a.core == b.core);
}

inline bool operator!=(const Adhesion_Factor& a, const Adhesion_Factor& b)
{
    return !(a == b);
}

typedef std::shared_ptr<Adhesion_Factor> Adhesion_FactorPtr;

#endif // ADHESION_FACTOR_H_INCLUDED

