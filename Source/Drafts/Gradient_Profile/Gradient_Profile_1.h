
#ifndef GRADIENT_PROFILE_1_CORE_H_INCLUDED
#define GRADIENT_PROFILE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Gradient_Profile_1
{
    uint16_t  D_GRADIENT;       // # 15
    uint32_t  Q_GDIR;           // # 1
    uint8_t   G_A;              // # 8

    void print(std::ostream& stream)
    {
        stream << '['
               << +D_GRADIENT << ','
               << +Q_GDIR << ','
               << +G_A << ']';
    }
};

#ifdef __cplusplus

inline bool operator==(const Gradient_Profile_1& a, const Gradient_Profile_1& b)
{
    return
        (a.D_GRADIENT == b.D_GRADIENT) &&
	(a.Q_GDIR == b.Q_GDIR) &&
	(a.G_A == b.G_A);
}

inline bool operator!=(const Gradient_Profile_1& a, const Gradient_Profile_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Gradient_Profile_1 Gradient_Profile_1;

#define GRADIENT_PROFILE_1_BITSIZE 24

/*@
    logic integer BitSize{L}(Gradient_Profile_1* p) = GRADIENT_PROFILE_1_BITSIZE;

    logic integer MaxBitSize{L}(Gradient_Profile_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Gradient_Profile_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Gradient_Profile_1* p) = \true;

    predicate ZeroInitialized(Gradient_Profile_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Gradient_Profile_1* p) = \true;

    predicate UpperBitsNotSet(Gradient_Profile_1* p) = \true;

*/

#endif // GRADIENT_PROFILE_1_H_INCLUDED

