
#ifndef LEVEL_CROSSING_INFORMATION_H_INCLUDED
#define LEVEL_CROSSING_INFORMATION_H_INCLUDED

#include "Bitstream.h"

struct Level_Crossing_information
{
    // TransmissionMedia=Any
    // Level Crossing information
    // Packet Number = 88

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  NID_LX;           // # 8
    uint64_t  D_LX;             // # 15
    uint64_t  L_LX;             // # 15
    uint64_t  Q_LXSTATUS;       // # 1
    uint64_t  V_LX;             // # 7
    uint64_t  Q_STOPLX;         // # 1
    uint64_t  L_STOPLX;         // # 15
};

typedef struct Level_Crossing_information Level_Crossing_information;

#define LEVEL_CROSSING_INFORMATION_BITSIZE 87

/*@
    logic integer BitSize{L}(Level_Crossing_information* p) = LEVEL_CROSSING_INFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(Level_Crossing_information* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level_Crossing_information* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level_Crossing_information* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->NID_LX)            &&
      Invariant(p->D_LX)              &&
      Invariant(p->L_LX)              &&
      Invariant(p->Q_LXSTATUS)        &&
      Invariant(p->V_LX)              &&
      Invariant(p->Q_STOPLX)          &&
      Invariant(p->L_STOPLX);

    predicate ZeroInitialized(Level_Crossing_information* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->NID_LX)            &&
      ZeroInitialized(p->D_LX)              &&
      ZeroInitialized(p->L_LX)              &&
      ZeroInitialized(p->Q_LXSTATUS)        &&
      ZeroInitialized(p->V_LX)              &&
      ZeroInitialized(p->Q_STOPLX)          &&
      ZeroInitialized(p->L_STOPLX);

    predicate EqualBits(Bitstream* stream, integer pos, Level_Crossing_information* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 33,  p->NID_LX)            &&
      EqualBits(stream, pos + 33,  pos + 48,  p->D_LX)              &&
      EqualBits(stream, pos + 48,  pos + 63,  p->L_LX)              &&
      EqualBits(stream, pos + 63,  pos + 64,  p->Q_LXSTATUS)        &&
      EqualBits(stream, pos + 64,  pos + 71,  p->V_LX)              &&
      EqualBits(stream, pos + 71,  pos + 72,  p->Q_STOPLX)          &&
      EqualBits(stream, pos + 72,  pos + 87,  p->L_STOPLX);


    predicate UpperBitsNotSet(Level_Crossing_information* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->NID_LX,           8)   &&
      UpperBitsNotSet(p->D_LX,             15)  &&
      UpperBitsNotSet(p->L_LX,             15)  &&
      UpperBitsNotSet(p->Q_LXSTATUS,       1)   &&
      UpperBitsNotSet(p->V_LX,             7)   &&
      UpperBitsNotSet(p->Q_STOPLX,         1)   &&
      UpperBitsNotSet(p->L_STOPLX,         15);

*/

#endif // LEVEL_CROSSING_INFORMATION_H_INCLUDED

