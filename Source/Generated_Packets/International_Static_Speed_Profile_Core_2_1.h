
#ifndef INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_1_CORE_H_INCLUDED
#define INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct International_Static_Speed_Profile_Core_2_1
{

    uint8_t   Q_DIFF_k_m;       // # 2
    uint8_t   NC_CDDIFF_k_m;    // # 4
    uint8_t   NC_DIFF_k_m;      // # 4
    uint8_t   V_DIFF_k_m;       // # 7
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const International_Static_Speed_Profile_Core_2_1& p)
{
    stream 
       << +p.Q_DIFF_k_m << ','
       << +p.NC_CDDIFF_k_m << ','
       << +p.NC_DIFF_k_m << ','
       << +p.V_DIFF_k_m;

    return stream;
}

inline bool operator==(const International_Static_Speed_Profile_Core_2_1& a, const International_Static_Speed_Profile_Core_2_1& b)
{
    bool status = true;
    
    status = status && (a.Q_DIFF_k_m == b.Q_DIFF_k_m);
    if (a.Q_DIFF_k_m == 0)
    {
    status = status && (a.NC_CDDIFF_k_m == b.NC_CDDIFF_k_m);
    }
    if ((a.Q_DIFF_k_m == 1) || (a.Q_DIFF_k_m == 2))
    {
    status = status && (a.NC_DIFF_k_m == b.NC_DIFF_k_m);
    }
    status = status && (a.V_DIFF_k_m == b.V_DIFF_k_m);

    return status;
}

inline bool operator!=(const International_Static_Speed_Profile_Core_2_1& a, const International_Static_Speed_Profile_Core_2_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct International_Static_Speed_Profile_Core_2_1 International_Static_Speed_Profile_Core_2_1;

#define INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_1_CORE_BITSIZE 112

/*@
    logic integer BitSize{L}(International_Static_Speed_Profile_Core_2_1* p) = INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(International_Static_Speed_Profile_Core_2_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, International_Static_Speed_Profile_Core_2_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(International_Static_Speed_Profile_Core_2_1* p) = \true;

    predicate ZeroInitialized(International_Static_Speed_Profile_Core_2_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, International_Static_Speed_Profile_Core_2_1* p) =
      EqualBits(stream, pos + 95,  pos + 97,  p->Q_DIFF_k_m)        &&
      EqualBits(stream, pos + 105, pos + 112, p->V_DIFF_k_m);

    predicate UpperBitsNotSet(International_Static_Speed_Profile_Core_2_1* p) =
      UpperBitsNotSet(p->Q_DIFF_k_m,       2)   &&
      UpperBitsNotSet(p->V_DIFF_k_m,       7);

*/

#endif // INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_1_CORE_H_INCLUDED

