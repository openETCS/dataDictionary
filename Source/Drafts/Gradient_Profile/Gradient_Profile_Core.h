
#ifndef GRADIENT_PROFILE_CORE_H_INCLUDED
#define GRADIENT_PROFILE_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Gradient_Profile_Core_1.h"

struct Gradient_Profile_Core
{
    // TransmissionMedia=Any
    // Transmission of the gradient.D_GRADIENT gives the distance to the next change
    // of the gradient value. The gradient value is the minimum gradient for the given distance.
    // Packet Number = 21

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint16_t  D_GRADIENT;       // # 15
    uint32_t  Q_GDIR;           // # 1
    uint8_t   G_A;              // # 8
    uint8_t   N_ITER;		// # 5
    Gradient_Profile_Core_1 sub_1[31];
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Gradient_Profile_Core& p)
{
    stream << +p.Q_DIR << ','
	   << +p.L_PACKET << ','
	   << +p.Q_SCALE << ','
           << +p.D_GRADIENT << ','
           << +p.Q_GDIR << ','
	   << +p.G_A << ','
	   << +p.N_ITER;
    for (uint32_t i = 0; i < p.N_ITER; ++i)
    {
        stream << ',' << p.sub_1[i];
    }

    return stream;
}

inline bool operator==(const Gradient_Profile_Core& a, const Gradient_Profile_Core& b)
{
    bool status = true;

    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_GRADIENT == b.D_GRADIENT);
    status = status && (a.Q_GDIR == b.Q_GDIR);
    status = status && (a.G_A == b.G_A);
    if (a.N_ITER == b.N_ITER) {
        for (uint32_t i = 0; i < a.N_ITER; ++i)
        {
            status = status && (a.sub_1[i] == b.sub_1[i]);
        }
    }
    else
    {
        status = false;
    }

    return status;
}

inline bool operator!=(const Gradient_Profile_Core& a, const Gradient_Profile_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Gradient_Profile_Core Gradient_Profile_Core;

#define GRADIENT_PROFILE_CORE_BITSIZE 785

/*@
    logic integer BitSize{L}(Gradient_Profile_Core* p) = GRADIENT_PROFILE_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Gradient_Profile_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Gradient_Profile_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Gradient_Profile_Core* p) = \true;

    predicate ZeroInitialized(Gradient_Profile_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Gradient_Profile_Core* p) = \true;

    predicate UpperBitsNotSet(Gradient_Profile_Core* p) = \true;

*/

#endif // GRADIENT_PROFILE_CORE_H_INCLUDED

