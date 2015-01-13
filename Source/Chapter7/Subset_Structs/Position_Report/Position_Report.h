
#ifndef POSITION_REPORT_H_INCLUDED
#define POSITION_REPORT_H_INCLUDED

#include "Bitstream.h"

struct Position_Report
{
    // TransmissionMedia=RBC, RIU
    // This packet is used to report the train position and speed as well as some additional information (e.g. mode, level, etc.)
    // Packet Number = 0

    uint64_t  NID_PACKET;       // # 8
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  NID_LRBG;         // # 24
    uint64_t  D_LRBG;           // # 15
    uint64_t  Q_DIRLRBG;        // # 2
    uint64_t  Q_DLRBG;          // # 2
    uint64_t  L_DOUBTOVER;      // # 15
    uint64_t  L_DOUBTUNDER;     // # 15
    uint64_t  Q_LENGTH;         // # 2
    uint64_t  L_TRAININT;       // # 15
    uint64_t  V_TRAIN;          // # 7
    uint64_t  Q_DIRTRAIN;       // # 2
    uint64_t  M_MODE;           // # 4
    uint64_t  M_LEVEL;          // # 3
    uint64_t  NID_NTC;          // # 8
};

typedef struct Position_Report Position_Report;

#define POSITION_REPORT_BITSIZE 137

/*@
    logic integer BitSize{L}(Position_Report* p) = POSITION_REPORT_BITSIZE;

    logic integer MaxBitSize{L}(Position_Report* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Position_Report* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Position_Report* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->NID_LRBG)          &&
      Invariant(p->D_LRBG)            &&
      Invariant(p->Q_DIRLRBG)         &&
      Invariant(p->Q_DLRBG)           &&
      Invariant(p->L_DOUBTOVER)       &&
      Invariant(p->L_DOUBTUNDER)      &&
      Invariant(p->Q_LENGTH)          &&
      Invariant(p->L_TRAININT)        &&
      Invariant(p->V_TRAIN)           &&
      Invariant(p->Q_DIRTRAIN)        &&
      Invariant(p->M_MODE)            &&
      Invariant(p->M_LEVEL)           &&
      Invariant(p->NID_NTC);

    predicate ZeroInitialized(Position_Report* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->NID_LRBG)          &&
      ZeroInitialized(p->D_LRBG)            &&
      ZeroInitialized(p->Q_DIRLRBG)         &&
      ZeroInitialized(p->Q_DLRBG)           &&
      ZeroInitialized(p->L_DOUBTOVER)       &&
      ZeroInitialized(p->L_DOUBTUNDER)      &&
      ZeroInitialized(p->Q_LENGTH)          &&
      ZeroInitialized(p->L_TRAININT)        &&
      ZeroInitialized(p->V_TRAIN)           &&
      ZeroInitialized(p->Q_DIRTRAIN)        &&
      ZeroInitialized(p->M_MODE)            &&
      ZeroInitialized(p->M_LEVEL)           &&
      ZeroInitialized(p->NID_NTC);

    predicate EqualBits(Bitstream* stream, integer pos, Position_Report* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET)          &&
      EqualBits(stream, pos + 21,  pos + 23,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 23,  pos + 47,  p->NID_LRBG)          &&
      EqualBits(stream, pos + 47,  pos + 62,  p->D_LRBG)            &&
      EqualBits(stream, pos + 62,  pos + 64,  p->Q_DIRLRBG)         &&
      EqualBits(stream, pos + 64,  pos + 66,  p->Q_DLRBG)           &&
      EqualBits(stream, pos + 66,  pos + 81,  p->L_DOUBTOVER)       &&
      EqualBits(stream, pos + 81,  pos + 96,  p->L_DOUBTUNDER)      &&
      EqualBits(stream, pos + 96,  pos + 98,  p->Q_LENGTH)          &&
      EqualBits(stream, pos + 98,  pos + 113, p->L_TRAININT)        &&
      EqualBits(stream, pos + 113, pos + 120, p->V_TRAIN)           &&
      EqualBits(stream, pos + 120, pos + 122, p->Q_DIRTRAIN)        &&
      EqualBits(stream, pos + 122, pos + 126, p->M_MODE)            &&
      EqualBits(stream, pos + 126, pos + 129, p->M_LEVEL)           &&
      EqualBits(stream, pos + 129, pos + 137, p->NID_NTC);


    predicate UpperBitsNotSet(Position_Report* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->NID_LRBG,         24)  &&
      UpperBitsNotSet(p->D_LRBG,           15)  &&
      UpperBitsNotSet(p->Q_DIRLRBG,        2)   &&
      UpperBitsNotSet(p->Q_DLRBG,          2)   &&
      UpperBitsNotSet(p->L_DOUBTOVER,      15)  &&
      UpperBitsNotSet(p->L_DOUBTUNDER,     15)  &&
      UpperBitsNotSet(p->Q_LENGTH,         2)   &&
      UpperBitsNotSet(p->L_TRAININT,       15)  &&
      UpperBitsNotSet(p->V_TRAIN,          7)   &&
      UpperBitsNotSet(p->Q_DIRTRAIN,       2)   &&
      UpperBitsNotSet(p->M_MODE,           4)   &&
      UpperBitsNotSet(p->M_LEVEL,          3)   &&
      UpperBitsNotSet(p->NID_NTC,          8);

*/

#endif // POSITION_REPORT_H_INCLUDED

