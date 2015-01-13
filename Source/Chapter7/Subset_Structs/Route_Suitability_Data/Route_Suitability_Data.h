
#ifndef ROUTE_SUITABILITY_DATA_H_INCLUDED
#define ROUTE_SUITABILITY_DATA_H_INCLUDED

#include "Bitstream.h"

struct Route_Suitability_Data
{
    // TransmissionMedia=Any
    // The packet gives the characteristics needed to enter a route.
    // Packet Number = 70

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  Q_TRACKINIT;      // # 1
    uint64_t  D_TRACKINIT;      // # 15
    uint64_t  D_SUITABILITY;    // # 15
    uint64_t  Q_SUITABILITY;    // # 2
    uint64_t  M_LINEGAUGE;      // # 8
    uint64_t  M_AXLELOADCAT;    // # 7
    uint64_t  M_VOLTAGE;        // # 4
    uint64_t  NID_CTRACTION;    // # 10
    uint64_t  N_ITER;           // # 5// # 15// # 2// # 8// # 7// # 4// # 10
};

typedef struct Route_Suitability_Data Route_Suitability_Data;

#define ROUTE_SUITABILITY_DATA_BITSIZE 138

/*@
    logic integer BitSize{L}(Route_Suitability_Data* p) = ROUTE_SUITABILITY_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Route_Suitability_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Route_Suitability_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Route_Suitability_Data* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_TRACKINIT)       &&
      Invariant(p->D_TRACKINIT)       &&
      Invariant(p->D_SUITABILITY)     &&
      Invariant(p->Q_SUITABILITY)     &&
      Invariant(p->M_LINEGAUGE)       &&
      Invariant(p->M_AXLELOADCAT)     &&
      Invariant(p->M_VOLTAGE)         &&
      Invariant(p->NID_CTRACTION)     &&
      Invariant(p->N_ITER)            &&
      Invariant(p->D_SUITABILITY(k))  &&
      Invariant(p->Q_SUITABILITY(k))  &&
      Invariant(p->M_LINEGAUGE(k))    &&
      Invariant(p->M_AXLELOADCAT(k))  &&
      Invariant(p->M_VOLTAGE(k))      &&
      Invariant(p->NID_CTRACTION(k));

    predicate ZeroInitialized(Route_Suitability_Data* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_TRACKINIT)       &&
      ZeroInitialized(p->D_TRACKINIT)       &&
      ZeroInitialized(p->D_SUITABILITY)     &&
      ZeroInitialized(p->Q_SUITABILITY)     &&
      ZeroInitialized(p->M_LINEGAUGE)       &&
      ZeroInitialized(p->M_AXLELOADCAT)     &&
      ZeroInitialized(p->M_VOLTAGE)         &&
      ZeroInitialized(p->NID_CTRACTION)     &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->D_SUITABILITY(k))  &&
      ZeroInitialized(p->Q_SUITABILITY(k))  &&
      ZeroInitialized(p->M_LINEGAUGE(k))    &&
      ZeroInitialized(p->M_AXLELOADCAT(k))  &&
      ZeroInitialized(p->M_VOLTAGE(k))      &&
      ZeroInitialized(p->NID_CTRACTION(k));

    predicate EqualBits(Bitstream* stream, integer pos, Route_Suitability_Data* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 26,  p->Q_TRACKINIT)       &&
      EqualBits(stream, pos + 26,  pos + 41,  p->D_TRACKINIT)       &&
      EqualBits(stream, pos + 41,  pos + 56,  p->D_SUITABILITY)     &&
      EqualBits(stream, pos + 56,  pos + 58,  p->Q_SUITABILITY)     &&
      EqualBits(stream, pos + 58,  pos + 66,  p->M_LINEGAUGE)       &&
      EqualBits(stream, pos + 66,  pos + 73,  p->M_AXLELOADCAT)     &&
      EqualBits(stream, pos + 73,  pos + 77,  p->M_VOLTAGE)         &&
      EqualBits(stream, pos + 77,  pos + 87,  p->NID_CTRACTION)     &&
      EqualBits(stream, pos + 87,  pos + 92,  p->N_ITER)            &&
      EqualBits(stream, pos + 92,  pos + 107, p->D_SUITABILITY(k))  &&
      EqualBits(stream, pos + 107, pos + 109, p->Q_SUITABILITY(k))  &&
      EqualBits(stream, pos + 109, pos + 117, p->M_LINEGAUGE(k))    &&
      EqualBits(stream, pos + 117, pos + 124, p->M_AXLELOADCAT(k))  &&
      EqualBits(stream, pos + 124, pos + 128, p->M_VOLTAGE(k))      &&
      EqualBits(stream, pos + 128, pos + 138, p->NID_CTRACTION(k));


    predicate UpperBitsNotSet(Route_Suitability_Data* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_TRACKINIT,      1)   &&
      UpperBitsNotSet(p->D_TRACKINIT,      15)  &&
      UpperBitsNotSet(p->D_SUITABILITY,    15)  &&
      UpperBitsNotSet(p->Q_SUITABILITY,    2)   &&
      UpperBitsNotSet(p->M_LINEGAUGE,      8)   &&
      UpperBitsNotSet(p->M_AXLELOADCAT,    7)   &&
      UpperBitsNotSet(p->M_VOLTAGE,        4)   &&
      UpperBitsNotSet(p->NID_CTRACTION,    10)  &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->D_SUITABILITY(k), 15)  &&
      UpperBitsNotSet(p->Q_SUITABILITY(k), 2)   &&
      UpperBitsNotSet(p->M_LINEGAUGE(k),   8)   &&
      UpperBitsNotSet(p->M_AXLELOADCAT(k), 7)   &&
      UpperBitsNotSet(p->M_VOLTAGE(k),     4)   &&
      UpperBitsNotSet(p->NID_CTRACTION(k), 10);

*/

#endif // ROUTE_SUITABILITY_DATA_H_INCLUDED

