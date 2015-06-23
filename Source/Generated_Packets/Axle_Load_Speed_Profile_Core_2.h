
#ifndef AXLE_LOAD_SPEED_PROFILE_CORE_2_CORE_H_INCLUDED
#define AXLE_LOAD_SPEED_PROFILE_CORE_2_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "Axle_Load_Speed_Profile_Core_2_1.h"

struct Axle_Load_Speed_Profile_Core_2
{

    uint16_t  D_AXLELOAD_k;     // # 15
    uint16_t  L_AXLELOAD_k;     // # 15
    uint8_t   Q_FRONT_k;        // # 1
    uint8_t   N_ITER_2_1;       // # 5
    Axle_Load_Speed_Profile_Core_2_1   sub_2_1[31];
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Axle_Load_Speed_Profile_Core_2& p)
{
    stream 
       << +p.D_AXLELOAD_k << ','
       << +p.L_AXLELOAD_k << ','
       << +p.Q_FRONT_k << ','
       << +p.N_ITER_2_1;
       for (uint32_t i = 0; i < p.N_ITER_2_1; ++i)
       {
           stream << ',' << p.sub_2_1[i];
       }
    

    return stream;
}

inline bool operator==(const Axle_Load_Speed_Profile_Core_2& a, const Axle_Load_Speed_Profile_Core_2& b)
{
    bool status = true;
    
    status = status && (a.D_AXLELOAD_k == b.D_AXLELOAD_k);
    status = status && (a.L_AXLELOAD_k == b.L_AXLELOAD_k);
    status = status && (a.Q_FRONT_k == b.Q_FRONT_k);
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

inline bool operator!=(const Axle_Load_Speed_Profile_Core_2& a, const Axle_Load_Speed_Profile_Core_2& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Axle_Load_Speed_Profile_Core_2 Axle_Load_Speed_Profile_Core_2;

#define AXLE_LOAD_SPEED_PROFILE_CORE_2_CORE_BITSIZE 138

/*@
    logic integer BitSize{L}(Axle_Load_Speed_Profile_Core_2* p) = AXLE_LOAD_SPEED_PROFILE_CORE_2_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Axle_Load_Speed_Profile_Core_2* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Axle_Load_Speed_Profile_Core_2* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Axle_Load_Speed_Profile_Core_2* p) = \true;

    predicate ZeroInitialized(Axle_Load_Speed_Profile_Core_2* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Axle_Load_Speed_Profile_Core_2* p) = \true;

    predicate UpperBitsNotSet(Axle_Load_Speed_Profile_Core_2* p) = \true;

*/

#endif // AXLE_LOAD_SPEED_PROFILE_CORE_2_CORE_H_INCLUDED

