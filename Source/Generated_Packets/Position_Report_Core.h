
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
       << +p.V_TRAIN << ','
       << +p.Q_DIRTRAIN << ','
       << +p.M_MODE << ','
       << +p.M_LEVEL;

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
    status = status && (a.V_TRAIN == b.V_TRAIN);
    status = status && (a.Q_DIRTRAIN == b.Q_DIRTRAIN);
    status = status && (a.M_MODE == b.M_MODE);
    status = status && (a.M_LEVEL == b.M_LEVEL);

    return status;
}

inline bool operator!=(const Position_Report_Core& a, const Position_Report_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Position_Report_Core Position_Report_Core;

#define POSITION_REPORT_CORE_BITSIZE 129

/*@
    logic integer BitSize{L}(Position_Report_Core* p) = POSITION_REPORT_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Position_Report_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Position_Report_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Position_Report_Core* p) =
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->NID_LRBG)          &&
      Invariant(p->D_LRBG)            &&
      Invariant(p->Q_DIRLRBG)         &&
      Invariant(p->Q_DLRBG)           &&
      Invariant(p->L_DOUBTOVER)       &&
      Invariant(p->L_DOUBTUNDER)      &&
      Invariant(p->Q_LENGTH)          &&
      Invariant(p->V_TRAIN)           &&
      Invariant(p->Q_DIRTRAIN)        &&
      Invariant(p->M_MODE)            &&
      Invariant(p->M_LEVEL);

    predicate ZeroInitialized(Position_Report_Core* p) =
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->NID_LRBG)          &&
      ZeroInitialized(p->D_LRBG)            &&
      ZeroInitialized(p->Q_DIRLRBG)         &&
      ZeroInitialized(p->Q_DLRBG)           &&
      ZeroInitialized(p->L_DOUBTOVER)       &&
      ZeroInitialized(p->L_DOUBTUNDER)      &&
      ZeroInitialized(p->Q_LENGTH)          &&
      ZeroInitialized(p->V_TRAIN)           &&
      ZeroInitialized(p->Q_DIRTRAIN)        &&
      ZeroInitialized(p->M_MODE)            &&
      ZeroInitialized(p->M_LEVEL);

    predicate EqualBits(Bitstream* stream, integer pos, Position_Report_Core* p) =
      EqualBits(stream, pos,       pos + 13,  p->L_PACKET)          &&
      EqualBits(stream, pos + 13,  pos + 15,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 15,  pos + 39,  p->NID_LRBG)          &&
      EqualBits(stream, pos + 39,  pos + 54,  p->D_LRBG)            &&
      EqualBits(stream, pos + 54,  pos + 56,  p->Q_DIRLRBG)         &&
      EqualBits(stream, pos + 56,  pos + 58,  p->Q_DLRBG)           &&
      EqualBits(stream, pos + 58,  pos + 73,  p->L_DOUBTOVER)       &&
      EqualBits(stream, pos + 73,  pos + 88,  p->L_DOUBTUNDER)      &&
      EqualBits(stream, pos + 88,  pos + 90,  p->Q_LENGTH)          &&
      EqualBits(stream, pos + 105, pos + 112, p->V_TRAIN)           &&
      EqualBits(stream, pos + 112, pos + 114, p->Q_DIRTRAIN)        &&
      EqualBits(stream, pos + 114, pos + 118, p->M_MODE)            &&
      EqualBits(stream, pos + 118, pos + 121, p->M_LEVEL);

    predicate UpperBitsNotSet(Position_Report_Core* p) =
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->NID_LRBG,         24)  &&
      UpperBitsNotSet(p->D_LRBG,           15)  &&
      UpperBitsNotSet(p->Q_DIRLRBG,        2)   &&
      UpperBitsNotSet(p->Q_DLRBG,          2)   &&
      UpperBitsNotSet(p->L_DOUBTOVER,      15)  &&
      UpperBitsNotSet(p->L_DOUBTUNDER,     15)  &&
      UpperBitsNotSet(p->Q_LENGTH,         2)   &&
      UpperBitsNotSet(p->V_TRAIN,          7)   &&
      UpperBitsNotSet(p->Q_DIRTRAIN,       2)   &&
      UpperBitsNotSet(p->M_MODE,           4)   &&
      UpperBitsNotSet(p->M_LEVEL,          3);

*/

#endif // POSITION_REPORT_CORE_H_INCLUDED

