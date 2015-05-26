
#ifndef ADHESION_FACTOR_H_INCLUDED
#define ADHESION_FACTOR_H_INCLUDED

#include "Bitstream.h"
#include "Adhesion_Factor_Core.h"
#include "BasePacket.h"

struct Adhesion_Factor : public BasePacket
{
    Adhesion_Factor_Core core;

    Adhesion_Factor() : BasePacket(71) {}
};

#ifdef __cplusplus

inline bool operator==(const Adhesion_Factor& a, const Adhesion_Factor& b)
{
    return (a.core == b.core);
}

inline bool operator!=(const Adhesion_Factor& a, const Adhesion_Factor& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef std::shared_ptr<Adhesion_Factor> Adhesion_FactorPtr;

#endif // ADHESION_FACTOR_H_INCLUDED

