
#ifndef PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_H_INCLUDED
#define PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "Permitted_Braking_Distance_Information_Core_1.h"

struct Permitted_Braking_Distance_Information_Core
{
    // TransmissionMedia=Any
    // This packet requests the on-board calculation of speed restrictions which ensure
    // a given permitted brake distance in case of an EB, or
    // SB, intervention         
    // Packet Number = 52

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint32_t  Q_TRACKINIT;      // # 1
    uint16_t  D_TRACKINIT;      // # 15
    uint16_t  D_PBD;            // # 15
    uint32_t  Q_GDIR;           // # 1
    uint8_t   G_PBDSR;          // # 8
    uint32_t  Q_PBDSR;          // # 1
    uint16_t  D_PBDSR;          // # 15
    uint16_t  L_PBDSR;          // # 15
    uint8_t   N_ITER_1;         // # 5
    Permitted_Braking_Distance_Information_Core_1   sub_1[31];
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Permitted_Braking_Distance_Information_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.Q_TRACKINIT << ','
       << +p.D_TRACKINIT << ','
       << +p.D_PBD << ','
       << +p.Q_GDIR << ','
       << +p.G_PBDSR << ','
       << +p.Q_PBDSR << ','
       << +p.D_PBDSR << ','
       << +p.L_PBDSR << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const Permitted_Braking_Distance_Information_Core& a, const Permitted_Braking_Distance_Information_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.Q_TRACKINIT == b.Q_TRACKINIT);
    if (a.Q_TRACKINIT == 1)
    {
    status = status && (a.D_TRACKINIT == b.D_TRACKINIT);
    }
    if (a.Q_TRACKINIT == 0)
    {
    status = status && (a.D_PBD == b.D_PBD);
    status = status && (a.Q_GDIR == b.Q_GDIR);
    status = status && (a.G_PBDSR == b.G_PBDSR);
    status = status && (a.Q_PBDSR == b.Q_PBDSR);
    status = status && (a.D_PBDSR == b.D_PBDSR);
    status = status && (a.L_PBDSR == b.L_PBDSR);
    if (a.N_ITER_1 == b.N_ITER_1)
    {
        for (uint32_t i = 0; i < a.N_ITER_1; ++i)
        {
            status = status && (a.sub_1[i] == b.sub_1[i]);
        }
    }
    else
    {
        status = false;
    }
    }

    return status;
}

inline bool operator!=(const Permitted_Braking_Distance_Information_Core& a, const Permitted_Braking_Distance_Information_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Permitted_Braking_Distance_Information_Core Permitted_Braking_Distance_Information_Core;

#define PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_BITSIZE 2067

/*@
    logic integer BitSize{L}(Permitted_Braking_Distance_Information_Core* p) = PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Permitted_Braking_Distance_Information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Permitted_Braking_Distance_Information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Permitted_Braking_Distance_Information_Core* p) = \true;

    predicate ZeroInitialized(Permitted_Braking_Distance_Information_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Permitted_Braking_Distance_Information_Core* p) = \true;

    predicate UpperBitsNotSet(Permitted_Braking_Distance_Information_Core* p) = \true;

*/

#endif // PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_H_INCLUDED

