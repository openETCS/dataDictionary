
#ifndef LEVEL_1_MOVEMENT_AUTHORITY_CORE_1_CORE_H_INCLUDED
#define LEVEL_1_MOVEMENT_AUTHORITY_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Level_1_Movement_Authority_Core_1
{

    uint16_t  L_SECTION_k;      // # 15
    uint8_t   Q_SECTIONTIMER_k; // # 1
    uint16_t  T_SECTIONTIMER_k; // # 10
    uint16_t  D_SECTIONTIMERSTOPLOC_k;// # 15
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Level_1_Movement_Authority_Core_1& p)
{
    stream 
       << +p.L_SECTION_k << ','
       << +p.Q_SECTIONTIMER_k << ','
       << +p.T_SECTIONTIMER_k << ','
       << +p.D_SECTIONTIMERSTOPLOC_k;

    return stream;
}

inline bool operator==(const Level_1_Movement_Authority_Core_1& a, const Level_1_Movement_Authority_Core_1& b)
{
    bool status = true;
    
    status = status && (a.L_SECTION_k == b.L_SECTION_k);
    status = status && (a.Q_SECTIONTIMER_k == b.Q_SECTIONTIMER_k);
    status = status && (a.T_SECTIONTIMER_k == b.T_SECTIONTIMER_k);
    status = status && (a.D_SECTIONTIMERSTOPLOC_k == b.D_SECTIONTIMERSTOPLOC_k);

    return status;
}

inline bool operator!=(const Level_1_Movement_Authority_Core_1& a, const Level_1_Movement_Authority_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Level_1_Movement_Authority_Core_1 Level_1_Movement_Authority_Core_1;

#define LEVEL_1_MOVEMENT_AUTHORITY_CORE_1_CORE_BITSIZE 636

/*@
    logic integer BitSize{L}(Level_1_Movement_Authority_Core_1* p) = LEVEL_1_MOVEMENT_AUTHORITY_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Level_1_Movement_Authority_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level_1_Movement_Authority_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level_1_Movement_Authority_Core_1* p) = \true;

    predicate ZeroInitialized(Level_1_Movement_Authority_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Level_1_Movement_Authority_Core_1* p) = \true;

    predicate UpperBitsNotSet(Level_1_Movement_Authority_Core_1* p) = \true;

*/

#endif // LEVEL_1_MOVEMENT_AUTHORITY_CORE_1_CORE_H_INCLUDED

