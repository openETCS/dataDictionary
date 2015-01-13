
#ifndef POSITION_REPORT_PARAMETERS_H_INCLUDED
#define POSITION_REPORT_PARAMETERS_H_INCLUDED

#include "Bitstream.h"

struct Position_Report_Parameters
{
    // TransmissionMedia=RBC
    // This packet is intended to give parameters telling when and how often the position has to be reported.
    // Packet Number = 58

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  T_CYCLOC;         // # 8
    uint64_t  D_CYCLOC;         // # 15
    uint64_t  M_LOC;            // # 3
    uint64_t  N_ITER;           // # 5// # 15// # 1
};

typedef struct Position_Report_Parameters Position_Report_Parameters;

#define POSITION_REPORT_PARAMETERS_BITSIZE 72

/*@
    logic integer BitSize{L}(Position_Report_Parameters* p) = POSITION_REPORT_PARAMETERS_BITSIZE;

    logic integer MaxBitSize{L}(Position_Report_Parameters* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Position_Report_Parameters* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Position_Report_Parameters* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->T_CYCLOC)          &&
      Invariant(p->D_CYCLOC)          &&
      Invariant(p->M_LOC)             &&
      Invariant(p->N_ITER)            &&
      Invariant(p->D_LOC(k))          &&
      Invariant(p->Q_LGTLOC(k));

    predicate ZeroInitialized(Position_Report_Parameters* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->T_CYCLOC)          &&
      ZeroInitialized(p->D_CYCLOC)          &&
      ZeroInitialized(p->M_LOC)             &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->D_LOC(k))          &&
      ZeroInitialized(p->Q_LGTLOC(k));

    predicate EqualBits(Bitstream* stream, integer pos, Position_Report_Parameters* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 33,  p->T_CYCLOC)          &&
      EqualBits(stream, pos + 33,  pos + 48,  p->D_CYCLOC)          &&
      EqualBits(stream, pos + 48,  pos + 51,  p->M_LOC)             &&
      EqualBits(stream, pos + 51,  pos + 56,  p->N_ITER)            &&
      EqualBits(stream, pos + 56,  pos + 71,  p->D_LOC(k))          &&
      EqualBits(stream, pos + 71,  pos + 72,  p->Q_LGTLOC(k));


    predicate UpperBitsNotSet(Position_Report_Parameters* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->T_CYCLOC,         8)   &&
      UpperBitsNotSet(p->D_CYCLOC,         15)  &&
      UpperBitsNotSet(p->M_LOC,            3)   &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->D_LOC(k),         15)  &&
      UpperBitsNotSet(p->Q_LGTLOC(k),      1);

*/

#endif // POSITION_REPORT_PARAMETERS_H_INCLUDED

