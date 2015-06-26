
#ifndef AXLE_LOAD_SPEED_PROFILE_CORE_H_INCLUDED
#define AXLE_LOAD_SPEED_PROFILE_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "Axle_Load_Speed_Profile_Core_1.h"
#include "Axle_Load_Speed_Profile_Core_2.h"

struct Axle_Load_Speed_Profile_Core
{
    // TransmissionMedia=Any
    // This packet gives the speed restrictions for trains with axle load
    // category higher than or equal to the specified value for the
    // speed restriction         
    // Packet Number = 51

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint32_t  Q_TRACKINIT;      // # 1
    uint16_t  D_TRACKINIT;      // # 15
    uint16_t  D_AXLELOAD;       // # 15
    uint16_t  L_AXLELOAD;       // # 15
    uint32_t  Q_FRONT;          // # 1
    uint8_t   N_ITER_1;         // # 5
    Axle_Load_Speed_Profile_Core_1   sub_1[31];
    uint8_t   N_ITER_2;         // # 5
    Axle_Load_Speed_Profile_Core_2   sub_2[31];
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Axle_Load_Speed_Profile_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.Q_TRACKINIT << ','
       << +p.D_TRACKINIT << ','
       << +p.D_AXLELOAD << ','
       << +p.L_AXLELOAD << ','
       << +p.Q_FRONT << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
    stream
       << +p.N_ITER_2;
       for (uint32_t i = 0; i < p.N_ITER_2; ++i)
       {
           stream << ',' << p.sub_2[i];
       }
    

    return stream;
}

inline bool operator==(const Axle_Load_Speed_Profile_Core& a, const Axle_Load_Speed_Profile_Core& b)
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
    status = status && (a.D_AXLELOAD == b.D_AXLELOAD);
    status = status && (a.L_AXLELOAD == b.L_AXLELOAD);
    status = status && (a.Q_FRONT == b.Q_FRONT);
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
    if (a.N_ITER_2 == b.N_ITER_2)
    {
        for (uint32_t i = 0; i < a.N_ITER_2; ++i)
        {
            status = status && (a.sub_2[i] == b.sub_2[i]);
        }
    }
    else
    {
        status = false;
    }
    }

    return status;
}

inline bool operator!=(const Axle_Load_Speed_Profile_Core& a, const Axle_Load_Speed_Profile_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Axle_Load_Speed_Profile_Core Axle_Load_Speed_Profile_Core;

#define AXLE_LOAD_SPEED_PROFILE_CORE_BITSIZE 138

/*@
    logic integer BitSize{L}(Axle_Load_Speed_Profile_Core* p) = AXLE_LOAD_SPEED_PROFILE_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Axle_Load_Speed_Profile_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Axle_Load_Speed_Profile_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Axle_Load_Speed_Profile_Core* p) = \true;

    predicate ZeroInitialized(Axle_Load_Speed_Profile_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Axle_Load_Speed_Profile_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 18,  p->Q_TRACKINIT);

    predicate UpperBitsNotSet(Axle_Load_Speed_Profile_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_TRACKINIT,      1)   &&
      UpperBitsNotSet(p->N_ITER_1           5 &&
      UpperBitsNotSet(p->N_ITER_2           5;

*/

#endif // AXLE_LOAD_SPEED_PROFILE_CORE_H_INCLUDED

