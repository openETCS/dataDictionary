
#ifndef LEVEL_23_MOVEMENT_AUTHORITY_CORE_1_CORE_H_INCLUDED
#define LEVEL_23_MOVEMENT_AUTHORITY_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Level_23_Movement_Authority_Core_1
{

    uint16_t  L_SECTION_k;      // # 15
    uint8_t   Q_SECTIONTIMER_k; // # 1
    uint16_t  T_SECTIONTIMER_k; // # 10
    uint16_t  D_SECTIONTIMERSTOPLOC_k;// # 15
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Level_23_Movement_Authority_Core_1& p)
{
    stream 
       << +p.L_SECTION_k << ','
       << +p.Q_SECTIONTIMER_k << ','
       << +p.T_SECTIONTIMER_k << ','
       << +p.D_SECTIONTIMERSTOPLOC_k;

    return stream;
}

inline bool operator==(const Level_23_Movement_Authority_Core_1& a, const Level_23_Movement_Authority_Core_1& b)
{
    bool status = true;
    
    status = status && (a.L_SECTION_k == b.L_SECTION_k);
    status = status && (a.Q_SECTIONTIMER_k == b.Q_SECTIONTIMER_k);
    status = status && (a.T_SECTIONTIMER_k == b.T_SECTIONTIMER_k);
    status = status && (a.D_SECTIONTIMERSTOPLOC_k == b.D_SECTIONTIMERSTOPLOC_k);

    return status;
}

inline bool operator!=(const Level_23_Movement_Authority_Core_1& a, const Level_23_Movement_Authority_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Level_23_Movement_Authority_Core_1 Level_23_Movement_Authority_Core_1;

#define LEVEL_23_MOVEMENT_AUTHORITY_CORE_1_CORE_BITSIZE 80

/*@
    logic integer BitSize{L}(Level_23_Movement_Authority_Core_1* p) = LEVEL_23_MOVEMENT_AUTHORITY_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Level_23_Movement_Authority_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level_23_Movement_Authority_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level_23_Movement_Authority_Core_1* p) = \true;

    predicate ZeroInitialized(Level_23_Movement_Authority_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Level_23_Movement_Authority_Core_1* p) =
      EqualBits(stream, pos + 39,  pos + 54,  p->L_SECTION_k)       &&
      EqualBits(stream, pos + 54,  pos + 55,  p->Q_SECTIONTIMER_k)  &&
      EqualBits(stream, pos + 55,  pos + 65,  p->T_SECTIONTIMER_k)  &&
      EqualBits(stream, pos + 65,  pos + 80,  p->D_SECTIONTIMERSTOPLOC_k);

    predicate UpperBitsNotSet(Level_23_Movement_Authority_Core_1* p) =
      UpperBitsNotSet(p->L_SECTION_k,      15)  &&
      UpperBitsNotSet(p->Q_SECTIONTIMER_k, 1)   &&
      UpperBitsNotSet(p->T_SECTIONTIMER_k, 10)  &&
      UpperBitsNotSet(p->D_SECTIONTIMERSTOPLOC_k,15);

*/

#endif // LEVEL_23_MOVEMENT_AUTHORITY_CORE_1_CORE_H_INCLUDED

