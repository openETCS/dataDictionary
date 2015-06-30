
#ifndef POSITION_REPORT_CORE_H_INCLUDED
#define POSITION_REPORT_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Position_Report_Core
{
    // TransmissionMedia=RBC, RIU
    // This packet is used to report the train position and speed
    // as well as some additional information (e.g. mode, level, etc.) 
    // Packet Number = 0

    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint32_t  NID_LRBG;         // # 24
    uint16_t  D_LRBG;           // # 15
    uint32_t  Q_DIRLRBG;        // # 2
    uint32_t  Q_DLRBG;          // # 2
    uint16_t  L_DOUBTOVER;      // # 15
    uint16_t  L_DOUBTUNDER;     // # 15
    uint32_t  Q_LENGTH;         // # 2
    uint16_t  L_TRAININT;       // # 15
    uint8_t   V_TRAIN;          // # 7
    uint32_t  Q_DIRTRAIN;       // # 2
    uint32_t  M_MODE;           // # 4
    uint32_t  M_LEVEL;          // # 3
    uint8_t   NID_NTC;          // # 8
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Position_Report_Core& p)
{
    stream 
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.NID_LRBG << ','
       << +p.D_LRBG << ','
       << +p.Q_DIRLRBG << ','
       << +p.Q_DLRBG << ','
       << +p.L_DOUBTOVER << ','
       << +p.L_DOUBTUNDER << ','
       << +p.Q_LENGTH << ','
       << +p.L_TRAININT << ','
       << +p.V_TRAIN << ','
       << +p.Q_DIRTRAIN << ','
       << +p.M_MODE << ','
       << +p.M_LEVEL << ','
       << +p.NID_NTC;

    return stream;
}

inline bool operator==(const Position_Report_Core& a, const Position_Report_Core& b)
{
    bool status = true;
    
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.NID_LRBG == b.NID_LRBG);
    status = status && (a.D_LRBG == b.D_LRBG);
    status = status && (a.Q_DIRLRBG == b.Q_DIRLRBG);
    status = status && (a.Q_DLRBG == b.Q_DLRBG);
    status = status && (a.L_DOUBTOVER == b.L_DOUBTOVER);
    status = status && (a.L_DOUBTUNDER == b.L_DOUBTUNDER);
    status = status && (a.Q_LENGTH == b.Q_LENGTH);
    if ((a.Q_LENGTH == 1) || (a.Q_LENGTH == 2))
    {
    status = status && (a.L_TRAININT == b.L_TRAININT);
    }
    status = status && (a.V_TRAIN == b.V_TRAIN);
    status = status && (a.Q_DIRTRAIN == b.Q_DIRTRAIN);
    status = status && (a.M_MODE == b.M_MODE);
    status = status && (a.M_LEVEL == b.M_LEVEL);
    if (a.M_LEVEL == 1)
    {
    status = status && (a.NID_NTC == b.NID_NTC);
    }

    return status;
}

inline bool operator!=(const Position_Report_Core& a, const Position_Report_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Position_Report_Core Position_Report_Core;

#define POSITION_REPORT_CORE_BITSIZE 4302

/*@
    logic integer BitSize{L}(Position_Report_Core* p) = POSITION_REPORT_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Position_Report_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Position_Report_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Position_Report_Core* p) = \true;

    predicate ZeroInitialized(Position_Report_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Position_Report_Core* p) = \true;

    predicate UpperBitsNotSet(Position_Report_Core* p) = \true;

*/

#endif // POSITION_REPORT_CORE_H_INCLUDED

