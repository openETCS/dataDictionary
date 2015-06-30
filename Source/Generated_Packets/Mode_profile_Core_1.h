
#ifndef MODE_PROFILE_CORE_1_CORE_H_INCLUDED
#define MODE_PROFILE_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Mode_profile_Core_1
{

    uint16_t  D_MAMODE_k;       // # 15
    uint8_t   M_MAMODE_k;       // # 2
    uint8_t   V_MAMODE_k;       // # 7
    uint16_t  L_MAMODE_k;       // # 15
    uint16_t  L_ACKMAMODE_k;    // # 15
    uint8_t   Q_MAMODE_k;       // # 1
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Mode_profile_Core_1& p)
{
    stream 
       << +p.D_MAMODE_k << ','
       << +p.M_MAMODE_k << ','
       << +p.V_MAMODE_k << ','
       << +p.L_MAMODE_k << ','
       << +p.L_ACKMAMODE_k << ','
       << +p.Q_MAMODE_k;

    return stream;
}

inline bool operator==(const Mode_profile_Core_1& a, const Mode_profile_Core_1& b)
{
    bool status = true;
    
    status = status && (a.D_MAMODE_k == b.D_MAMODE_k);
    status = status && (a.M_MAMODE_k == b.M_MAMODE_k);
    status = status && (a.V_MAMODE_k == b.V_MAMODE_k);
    status = status && (a.L_MAMODE_k == b.L_MAMODE_k);
    status = status && (a.L_ACKMAMODE_k == b.L_ACKMAMODE_k);
    status = status && (a.Q_MAMODE_k == b.Q_MAMODE_k);

    return status;
}

inline bool operator!=(const Mode_profile_Core_1& a, const Mode_profile_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Mode_profile_Core_1 Mode_profile_Core_1;

#define MODE_PROFILE_CORE_1_CORE_BITSIZE 3354

/*@
    logic integer BitSize{L}(Mode_profile_Core_1* p) = MODE_PROFILE_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Mode_profile_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Mode_profile_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Mode_profile_Core_1* p) = \true;

    predicate ZeroInitialized(Mode_profile_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Mode_profile_Core_1* p) = \true;

    predicate UpperBitsNotSet(Mode_profile_Core_1* p) = \true;

*/

#endif // MODE_PROFILE_CORE_1_CORE_H_INCLUDED

