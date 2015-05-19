
#ifndef ADHESION_FACTOR_H_INCLUDED
#define ADHESION_FACTOR_H_INCLUDED

#include "Bitstream.h"
#include "BasePacket.h"
#include "Adhesion_Factor_Core.h"

struct Adhesion_Factor : public BasePacket
{
    Adhesion_Factor_Core core;

    Adhesion_Factor() : BasePacket(71) {}
};

typedef std::shared_ptr<Adhesion_Factor> Adhesion_FactorPtr;

#endif // ADHESION_FACTOR_H_INCLUDED

