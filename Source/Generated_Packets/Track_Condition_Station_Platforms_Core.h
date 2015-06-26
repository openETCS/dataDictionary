
#ifndef TRACK_CONDITION_STATION_PLATFORMS_CORE_H_INCLUDED
#define TRACK_CONDITION_STATION_PLATFORMS_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "Track_Condition_Station_Platforms_Core_1.h"

struct Track_Condition_Station_Platforms_Core
{
    // TransmissionMedia=Any
    // The packet gives details concerning the location and height of station
    // platforms for use by the train door control system  
    // Packet Number = 69

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint32_t  Q_TRACKINIT;      // # 1
    uint16_t  D_TRACKINIT;      // # 15
    uint16_t  D_TRACKCOND;      // # 15
    uint16_t  L_TRACKCOND;      // # 15
    uint32_t  M_PLATFORM;       // # 4
    uint32_t  Q_PLATFORM;       // # 2
    uint8_t   N_ITER_1;         // # 5
    Track_Condition_Station_Platforms_Core_1   sub_1[31];
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Track_Condition_Station_Platforms_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.Q_TRACKINIT << ','
       << +p.D_TRACKINIT << ','
       << +p.D_TRACKCOND << ','
       << +p.L_TRACKCOND << ','
       << +p.M_PLATFORM << ','
       << +p.Q_PLATFORM << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
    

    return stream;
}

inline bool operator==(const Track_Condition_Station_Platforms_Core& a, const Track_Condition_Station_Platforms_Core& b)
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
    status = status && (a.D_TRACKCOND == b.D_TRACKCOND);
    status = status && (a.L_TRACKCOND == b.L_TRACKCOND);
    status = status && (a.M_PLATFORM == b.M_PLATFORM);
    status = status && (a.Q_PLATFORM == b.Q_PLATFORM);
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

inline bool operator!=(const Track_Condition_Station_Platforms_Core& a, const Track_Condition_Station_Platforms_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Track_Condition_Station_Platforms_Core Track_Condition_Station_Platforms_Core;

#define TRACK_CONDITION_STATION_PLATFORMS_CORE_BITSIZE 110

/*@
    logic integer BitSize{L}(Track_Condition_Station_Platforms_Core* p) = TRACK_CONDITION_STATION_PLATFORMS_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Track_Condition_Station_Platforms_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Track_Condition_Station_Platforms_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Track_Condition_Station_Platforms_Core* p) = \true;

    predicate ZeroInitialized(Track_Condition_Station_Platforms_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Track_Condition_Station_Platforms_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 18,  p->Q_TRACKINIT);

    predicate UpperBitsNotSet(Track_Condition_Station_Platforms_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_TRACKINIT,      1)   &&
      UpperBitsNotSet(p->N_ITER_1           5;

*/

#endif // TRACK_CONDITION_STATION_PLATFORMS_CORE_H_INCLUDED

