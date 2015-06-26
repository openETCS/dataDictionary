
#ifndef LEVEL_1_MOVEMENT_AUTHORITY_CORE_H_INCLUDED
#define LEVEL_1_MOVEMENT_AUTHORITY_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "Level_1_Movement_Authority_Core_1.h"

struct Level_1_Movement_Authority_Core
{
    // TransmissionMedia=Balise, Loop, RIU
    // Transmission of a movement authority for level 1.   
    // Packet Number = 12

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint8_t   V_MAIN;           // # 7
    uint8_t   V_LOA;            // # 7
    uint16_t  T_LOA;            // # 10
    uint8_t   N_ITER_1;         // # 5
    Level_1_Movement_Authority_Core_1   sub_1[31];
    uint16_t  L_ENDSECTION;     // # 15
    uint32_t  Q_SECTIONTIMER;   // # 1
    uint16_t  T_SECTIONTIMER;   // # 10
    uint16_t  D_SECTIONTIMERSTOPLOC;// # 15
    uint32_t  Q_ENDTIMER;       // # 1
    uint16_t  T_ENDTIMER;       // # 10
    uint16_t  D_ENDTIMERSTARTLOC;// # 15
    uint32_t  Q_DANGERPOINT;    // # 1
    uint16_t  D_DP;             // # 15
    uint8_t   V_RELEASEDP;      // # 7
    uint32_t  Q_OVERLAP;        // # 1
    uint16_t  D_STARTOL;        // # 15
    uint16_t  T_OL;             // # 10
    uint16_t  D_OL;             // # 15
    uint8_t   V_RELEASEOL;      // # 7
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Level_1_Movement_Authority_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.V_MAIN << ','
       << +p.V_LOA << ','
       << +p.T_LOA << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
    stream
       << +p.L_ENDSECTION << ','
       << +p.Q_SECTIONTIMER << ','
       << +p.T_SECTIONTIMER << ','
       << +p.D_SECTIONTIMERSTOPLOC << ','
       << +p.Q_ENDTIMER << ','
       << +p.T_ENDTIMER << ','
       << +p.D_ENDTIMERSTARTLOC << ','
       << +p.Q_DANGERPOINT << ','
       << +p.D_DP << ','
       << +p.V_RELEASEDP << ','
       << +p.Q_OVERLAP << ','
       << +p.D_STARTOL << ','
       << +p.T_OL << ','
       << +p.D_OL << ','
       << +p.V_RELEASEOL;

    return stream;
}

inline bool operator==(const Level_1_Movement_Authority_Core& a, const Level_1_Movement_Authority_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.V_MAIN == b.V_MAIN);
    status = status && (a.V_LOA == b.V_LOA);
    status = status && (a.T_LOA == b.T_LOA);
    status = status && (a.N_ITER_1 == b.N_ITER_1);
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
    status = status && (a.L_ENDSECTION == b.L_ENDSECTION);
    status = status && (a.Q_SECTIONTIMER == b.Q_SECTIONTIMER);
    status = status && (a.T_SECTIONTIMER == b.T_SECTIONTIMER);
    status = status && (a.D_SECTIONTIMERSTOPLOC == b.D_SECTIONTIMERSTOPLOC);
    status = status && (a.Q_ENDTIMER == b.Q_ENDTIMER);
    status = status && (a.T_ENDTIMER == b.T_ENDTIMER);
    status = status && (a.D_ENDTIMERSTARTLOC == b.D_ENDTIMERSTARTLOC);
    status = status && (a.Q_DANGERPOINT == b.Q_DANGERPOINT);
    status = status && (a.D_DP == b.D_DP);
    status = status && (a.V_RELEASEDP == b.V_RELEASEDP);
    status = status && (a.Q_OVERLAP == b.Q_OVERLAP);
    status = status && (a.D_STARTOL == b.D_STARTOL);
    status = status && (a.T_OL == b.T_OL);
    status = status && (a.D_OL == b.D_OL);
    status = status && (a.V_RELEASEOL == b.V_RELEASEOL);

    return status;
}

inline bool operator!=(const Level_1_Movement_Authority_Core& a, const Level_1_Movement_Authority_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Level_1_Movement_Authority_Core Level_1_Movement_Authority_Core;

#define LEVEL_1_MOVEMENT_AUTHORITY_CORE_BITSIZE 225

/*@
    logic integer BitSize{L}(Level_1_Movement_Authority_Core* p) = LEVEL_1_MOVEMENT_AUTHORITY_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Level_1_Movement_Authority_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level_1_Movement_Authority_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level_1_Movement_Authority_Core* p) = \true;

    predicate ZeroInitialized(Level_1_Movement_Authority_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Level_1_Movement_Authority_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 24,  p->V_MAIN)            &&
      EqualBits(stream, pos + 24,  pos + 31,  p->V_LOA)             &&
      EqualBits(stream, pos + 31,  pos + 41,  p->T_LOA)             &&
      EqualBits(stream, pos + 87,  pos + 102, p->L_ENDSECTION)      &&
      EqualBits(stream, pos + 102, pos + 103, p->Q_SECTIONTIMER)    &&
      EqualBits(stream, pos + 103, pos + 113, p->T_SECTIONTIMER)    &&
      EqualBits(stream, pos + 113, pos + 128, p->D_SECTIONTIMERSTOPLOC) &&
      EqualBits(stream, pos + 128, pos + 129, p->Q_ENDTIMER)        &&
      EqualBits(stream, pos + 129, pos + 139, p->T_ENDTIMER)        &&
      EqualBits(stream, pos + 139, pos + 154, p->D_ENDTIMERSTARTLOC) &&
      EqualBits(stream, pos + 154, pos + 155, p->Q_DANGERPOINT)     &&
      EqualBits(stream, pos + 155, pos + 170, p->D_DP)              &&
      EqualBits(stream, pos + 170, pos + 177, p->V_RELEASEDP)       &&
      EqualBits(stream, pos + 177, pos + 178, p->Q_OVERLAP)         &&
      EqualBits(stream, pos + 178, pos + 193, p->D_STARTOL)         &&
      EqualBits(stream, pos + 193, pos + 203, p->T_OL)              &&
      EqualBits(stream, pos + 203, pos + 218, p->D_OL)              &&
      EqualBits(stream, pos + 218, pos + 225, p->V_RELEASEOL);

    predicate UpperBitsNotSet(Level_1_Movement_Authority_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->V_MAIN,           7)   &&
      UpperBitsNotSet(p->V_LOA,            7)   &&
      UpperBitsNotSet(p->T_LOA,            10)  &&
      UpperBitsNotSet(p->N_ITER_1           5 &&
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

#endif // LEVEL_1_MOVEMENT_AUTHORITY_CORE_H_INCLUDED

