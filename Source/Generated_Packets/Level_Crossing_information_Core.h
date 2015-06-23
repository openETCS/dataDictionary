
#ifndef LEVEL_CROSSING_INFORMATION_CORE_H_INCLUDED
#define LEVEL_CROSSING_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Level_Crossing_information_Core
{
    // TransmissionMedia=Any
    // Level Crossing information        
    // Packet Number = 88

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint8_t   NID_LX;           // # 8
    uint16_t  D_LX;             // # 15
    uint16_t  L_LX;             // # 15
    uint32_t  Q_LXSTATUS;       // # 1
    uint8_t   V_LX;             // # 7
    uint32_t  Q_STOPLX;         // # 1
    uint16_t  L_STOPLX;         // # 15
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Level_Crossing_information_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.NID_LX << ','
       << +p.D_LX << ','
       << +p.L_LX << ','
       << +p.Q_LXSTATUS << ','
       << +p.V_LX << ','
       << +p.Q_STOPLX << ','
       << +p.L_STOPLX;

    return stream;
}

inline bool operator==(const Level_Crossing_information_Core& a, const Level_Crossing_information_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.NID_LX == b.NID_LX);
    status = status && (a.D_LX == b.D_LX);
    status = status && (a.L_LX == b.L_LX);
    status = status && (a.Q_LXSTATUS == b.Q_LXSTATUS);
    if (a.Q_LXSTATUS == 1)
    {
    status = status && (a.V_LX == b.V_LX);
    status = status && (a.Q_STOPLX == b.Q_STOPLX);
    }
    if (a.Q_STOPLX == 1)
    {
    status = status && (a.L_STOPLX == b.L_STOPLX);
    }

    return status;
}

inline bool operator!=(const Level_Crossing_information_Core& a, const Level_Crossing_information_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Level_Crossing_information_Core Level_Crossing_information_Core;

#define LEVEL_CROSSING_INFORMATION_CORE_BITSIZE 79

/*@
    logic integer BitSize{L}(Level_Crossing_information_Core* p) = LEVEL_CROSSING_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Level_Crossing_information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level_Crossing_information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level_Crossing_information_Core* p) = \true;

    predicate ZeroInitialized(Level_Crossing_information_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Level_Crossing_information_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 25,  p->NID_LX)            &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_LX)              &&
      EqualBits(stream, pos + 40,  pos + 55,  p->L_LX)              &&
      EqualBits(stream, pos + 55,  pos + 56,  p->Q_LXSTATUS);

    predicate UpperBitsNotSet(Level_Crossing_information_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->NID_LX,           8)   &&
      UpperBitsNotSet(p->D_LX,             15)  &&
      UpperBitsNotSet(p->L_LX,             15)  &&
      UpperBitsNotSet(p->Q_LXSTATUS,       1);

*/

#endif // LEVEL_CROSSING_INFORMATION_CORE_H_INCLUDED

