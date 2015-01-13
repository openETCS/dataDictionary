
#ifndef LEVEL_1_MOVEMENT_AUTHORITY_H_INCLUDED
#define LEVEL_1_MOVEMENT_AUTHORITY_H_INCLUDED

#include "Bitstream.h"

struct Level_1_Movement_Authority
{
    // TransmissionMedia=Balise, Loop, RIU
    // Transmission of a movement authority for level 1.
    // Packet Number = 12

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  V_MAIN;           // # 7
    uint64_t  V_LOA;            // # 7
    uint64_t  T_LOA;            // # 10
    uint64_t  N_ITER;           // # 5// # 15// # 1// # 10// # 15
    uint64_t  L_ENDSECTION;     // # 15
    uint64_t  Q_SECTIONTIMER;   // # 1
    uint64_t  T_SECTIONTIMER;   // # 10
    uint64_t  D_SECTIONTIMERSTOPLOC;// # 15
    uint64_t  Q_ENDTIMER;       // # 1
    uint64_t  T_ENDTIMER;       // # 10
    uint64_t  D_ENDTIMERSTARTLOC;// # 15
    uint64_t  Q_DANGERPOINT;    // # 1
    uint64_t  D_DP;             // # 15
    uint64_t  V_RELEASEDP;      // # 7
    uint64_t  Q_OVERLAP;        // # 1
    uint64_t  D_STARTOL;        // # 15
    uint64_t  T_OL;             // # 10
    uint64_t  D_OL;             // # 15
    uint64_t  V_RELEASEOL;      // # 7
};

typedef struct Level_1_Movement_Authority Level_1_Movement_Authority;

#define LEVEL_1_MOVEMENT_AUTHORITY_BITSIZE 233

/*@
    logic integer BitSize{L}(Level_1_Movement_Authority* p) = LEVEL_1_MOVEMENT_AUTHORITY_BITSIZE;

    logic integer MaxBitSize{L}(Level_1_Movement_Authority* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level_1_Movement_Authority* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level_1_Movement_Authority* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->V_MAIN)            &&
      Invariant(p->V_LOA)             &&
      Invariant(p->T_LOA)             &&
      Invariant(p->N_ITER)            &&
      Invariant(p->L_SECTION(k))      &&
      Invariant(p->Q_SECTIONTIMER(k)) &&
      Invariant(p->T_SECTIONTIMER(k)) &&
      Invariant(p->D_SECTIONTIMERSTOPLOC(k)) &&
      Invariant(p->L_ENDSECTION)      &&
      Invariant(p->Q_SECTIONTIMER)    &&
      Invariant(p->T_SECTIONTIMER)    &&
      Invariant(p->D_SECTIONTIMERSTOPLOC) &&
      Invariant(p->Q_ENDTIMER)        &&
      Invariant(p->T_ENDTIMER)        &&
      Invariant(p->D_ENDTIMERSTARTLOC) &&
      Invariant(p->Q_DANGERPOINT)     &&
      Invariant(p->D_DP)              &&
      Invariant(p->V_RELEASEDP)       &&
      Invariant(p->Q_OVERLAP)         &&
      Invariant(p->D_STARTOL)         &&
      Invariant(p->T_OL)              &&
      Invariant(p->D_OL)              &&
      Invariant(p->V_RELEASEOL);

    predicate ZeroInitialized(Level_1_Movement_Authority* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->V_MAIN)            &&
      ZeroInitialized(p->V_LOA)             &&
      ZeroInitialized(p->T_LOA)             &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->L_SECTION(k))      &&
      ZeroInitialized(p->Q_SECTIONTIMER(k)) &&
      ZeroInitialized(p->T_SECTIONTIMER(k)) &&
      ZeroInitialized(p->D_SECTIONTIMERSTOPLOC(k)) &&
      ZeroInitialized(p->L_ENDSECTION)      &&
      ZeroInitialized(p->Q_SECTIONTIMER)    &&
      ZeroInitialized(p->T_SECTIONTIMER)    &&
      ZeroInitialized(p->D_SECTIONTIMERSTOPLOC) &&
      ZeroInitialized(p->Q_ENDTIMER)        &&
      ZeroInitialized(p->T_ENDTIMER)        &&
      ZeroInitialized(p->D_ENDTIMERSTARTLOC) &&
      ZeroInitialized(p->Q_DANGERPOINT)     &&
      ZeroInitialized(p->D_DP)              &&
      ZeroInitialized(p->V_RELEASEDP)       &&
      ZeroInitialized(p->Q_OVERLAP)         &&
      ZeroInitialized(p->D_STARTOL)         &&
      ZeroInitialized(p->T_OL)              &&
      ZeroInitialized(p->D_OL)              &&
      ZeroInitialized(p->V_RELEASEOL);

    predicate EqualBits(Bitstream* stream, integer pos, Level_1_Movement_Authority* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 32,  p->V_MAIN)            &&
      EqualBits(stream, pos + 32,  pos + 39,  p->V_LOA)             &&
      EqualBits(stream, pos + 39,  pos + 49,  p->T_LOA)             &&
      EqualBits(stream, pos + 49,  pos + 54,  p->N_ITER)            &&
      EqualBits(stream, pos + 54,  pos + 69,  p->L_SECTION(k))      &&
      EqualBits(stream, pos + 69,  pos + 70,  p->Q_SECTIONTIMER(k)) &&
      EqualBits(stream, pos + 70,  pos + 80,  p->T_SECTIONTIMER(k)) &&
      EqualBits(stream, pos + 80,  pos + 95,  p->D_SECTIONTIMERSTOPLOC(k)) &&
      EqualBits(stream, pos + 95,  pos + 110, p->L_ENDSECTION)      &&
      EqualBits(stream, pos + 110, pos + 111, p->Q_SECTIONTIMER)    &&
      EqualBits(stream, pos + 111, pos + 121, p->T_SECTIONTIMER)    &&
      EqualBits(stream, pos + 121, pos + 136, p->D_SECTIONTIMERSTOPLOC) &&
      EqualBits(stream, pos + 136, pos + 137, p->Q_ENDTIMER)        &&
      EqualBits(stream, pos + 137, pos + 147, p->T_ENDTIMER)        &&
      EqualBits(stream, pos + 147, pos + 162, p->D_ENDTIMERSTARTLOC) &&
      EqualBits(stream, pos + 162, pos + 163, p->Q_DANGERPOINT)     &&
      EqualBits(stream, pos + 163, pos + 178, p->D_DP)              &&
      EqualBits(stream, pos + 178, pos + 185, p->V_RELEASEDP)       &&
      EqualBits(stream, pos + 185, pos + 186, p->Q_OVERLAP)         &&
      EqualBits(stream, pos + 186, pos + 201, p->D_STARTOL)         &&
      EqualBits(stream, pos + 201, pos + 211, p->T_OL)              &&
      EqualBits(stream, pos + 211, pos + 226, p->D_OL)              &&
      EqualBits(stream, pos + 226, pos + 233, p->V_RELEASEOL);


    predicate UpperBitsNotSet(Level_1_Movement_Authority* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->V_MAIN,           7)   &&
      UpperBitsNotSet(p->V_LOA,            7)   &&
      UpperBitsNotSet(p->T_LOA,            10)  &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->L_SECTION(k),     15)  &&
      UpperBitsNotSet(p->Q_SECTIONTIMER(k),1)   &&
      UpperBitsNotSet(p->T_SECTIONTIMER(k),10)  &&
      UpperBitsNotSet(p->D_SECTIONTIMERSTOPLOC(k),15)  &&
      UpperBitsNotSet(p->L_ENDSECTION,     15)  &&
      UpperBitsNotSet(p->Q_SECTIONTIMER,   1)   &&
      UpperBitsNotSet(p->T_SECTIONTIMER,   10)  &&
      UpperBitsNotSet(p->D_SECTIONTIMERSTOPLOC,15)  &&
      UpperBitsNotSet(p->Q_ENDTIMER,       1)   &&
      UpperBitsNotSet(p->T_ENDTIMER,       10)  &&
      UpperBitsNotSet(p->D_ENDTIMERSTARTLOC,15)  &&
      UpperBitsNotSet(p->Q_DANGERPOINT,    1)   &&
      UpperBitsNotSet(p->D_DP,             15)  &&
      UpperBitsNotSet(p->V_RELEASEDP,      7)   &&
      UpperBitsNotSet(p->Q_OVERLAP,        1)   &&
      UpperBitsNotSet(p->D_STARTOL,        15)  &&
      UpperBitsNotSet(p->T_OL,             10)  &&
      UpperBitsNotSet(p->D_OL,             15)  &&
      UpperBitsNotSet(p->V_RELEASEOL,      7);

*/

#endif // LEVEL_1_MOVEMENT_AUTHORITY_H_INCLUDED

