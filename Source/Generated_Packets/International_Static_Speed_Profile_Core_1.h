
#ifndef INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_1_CORE_H_INCLUDED
#define INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct International_Static_Speed_Profile_Core_1
{

    uint8_t   Q_DIFF_n;         // # 2
    uint8_t   NC_CDDIFF_n;      // # 4
    uint8_t   NC_DIFF_n;        // # 4
    uint8_t   V_DIFF_n;         // # 7
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const International_Static_Speed_Profile_Core_1& p)
{
    stream 
       << +p.Q_DIFF_n << ','
       << +p.NC_CDDIFF_n << ','
       << +p.NC_DIFF_n << ','
       << +p.V_DIFF_n;

    return stream;
}

inline bool operator==(const International_Static_Speed_Profile_Core_1& a, const International_Static_Speed_Profile_Core_1& b)
{
    bool status = true;
    
    status = status && (a.Q_DIFF_n == b.Q_DIFF_n);
    if (a.Q_DIFF_n == 0)
    {
    status = status && (a.NC_CDDIFF_n == b.NC_CDDIFF_n);
    }
    if ((a.Q_DIFF_n == 1) || (a.Q_DIFF_n == 2))
    {
    status = status && (a.NC_DIFF_n == b.NC_DIFF_n);
    }
    status = status && (a.V_DIFF_n == b.V_DIFF_n);

    return status;
}

inline bool operator!=(const International_Static_Speed_Profile_Core_1& a, const International_Static_Speed_Profile_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct International_Static_Speed_Profile_Core_1 International_Static_Speed_Profile_Core_1;

#define INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_1_CORE_BITSIZE 1283

/*@
    logic integer BitSize{L}(International_Static_Speed_Profile_Core_1* p) = INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(International_Static_Speed_Profile_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, International_Static_Speed_Profile_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(International_Static_Speed_Profile_Core_1* p) = \true;

    predicate ZeroInitialized(International_Static_Speed_Profile_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, International_Static_Speed_Profile_Core_1* p) = \true;

    predicate UpperBitsNotSet(International_Static_Speed_Profile_Core_1* p) = \true;

*/

#endif // INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_1_CORE_H_INCLUDED

