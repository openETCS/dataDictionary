
#ifndef INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_CORE_H_INCLUDED
#define INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "International_Static_Speed_Profile_Core_2_1.h"

struct International_Static_Speed_Profile_Core_2
{

    uint16_t  D_STATIC_k;       // # 15
    uint8_t   V_STATIC_k;       // # 7
    uint8_t   Q_FRONT_k;        // # 1
    uint8_t   N_ITER_2_1;       // # 5
    International_Static_Speed_Profile_Core_2_1   sub_2_1[31];
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const International_Static_Speed_Profile_Core_2& p)
{
    stream 
       << +p.D_STATIC_k << ','
       << +p.V_STATIC_k << ','
       << +p.Q_FRONT_k << ','
       << +p.N_ITER_2_1;
       for (uint32_t i = 0; i < p.N_ITER_2_1; ++i)
       {
           stream << ',' << p.sub_2_1[i];
       }
    

    return stream;
}

inline bool operator==(const International_Static_Speed_Profile_Core_2& a, const International_Static_Speed_Profile_Core_2& b)
{
    bool status = true;
    
    status = status && (a.D_STATIC_k == b.D_STATIC_k);
    status = status && (a.V_STATIC_k == b.V_STATIC_k);
    status = status && (a.Q_FRONT_k == b.Q_FRONT_k);
    status = status && (a.N_ITER_2_1 == b.N_ITER_2_1);
    if (a.N_ITER_2_1 == b.N_ITER_2_1)
    {
        for (uint32_t i = 0; i < a.N_ITER_2_1; ++i)
        {
            status = status && (a.sub_2_1[i] == b.sub_2_1[i]);
        }
    }
    else
    {
        status = false;
    }

    return status;
}

inline bool operator!=(const International_Static_Speed_Profile_Core_2& a, const International_Static_Speed_Profile_Core_2& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct International_Static_Speed_Profile_Core_2 International_Static_Speed_Profile_Core_2;

#define INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_CORE_BITSIZE 112

/*@
    logic integer BitSize{L}(International_Static_Speed_Profile_Core_2* p) = INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_CORE_BITSIZE;

    logic integer MaxBitSize{L}(International_Static_Speed_Profile_Core_2* p) = BitSize(p);

    predicate Separated(Bitstream* stream, International_Static_Speed_Profile_Core_2* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(International_Static_Speed_Profile_Core_2* p) = \true;

    predicate ZeroInitialized(International_Static_Speed_Profile_Core_2* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, International_Static_Speed_Profile_Core_2* p) =
      EqualBits(stream, pos + 67,  pos + 82,  p->D_STATIC_k)        &&
      EqualBits(stream, pos + 82,  pos + 89,  p->V_STATIC_k)        &&
      EqualBits(stream, pos + 89,  pos + 90,  p->Q_FRONT_k);

    predicate UpperBitsNotSet(International_Static_Speed_Profile_Core_2* p) =
      UpperBitsNotSet(p->D_STATIC_k,       15)  &&
      UpperBitsNotSet(p->V_STATIC_k,       7)   &&
      UpperBitsNotSet(p->Q_FRONT_k,        1)   &&
      UpperBitsNotSet(p->N_ITER_2_1         5;

*/

#endif // INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_CORE_H_INCLUDED

