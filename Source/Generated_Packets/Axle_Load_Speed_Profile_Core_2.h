
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

#define AXLE_LOAD_SPEED_PROFILE_CORE_2_CORE_BITSIZE 1919

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

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Axle_Load_Speed_Profile_Core_2_UpperBitsNotSet(const Axle_Load_Speed_Profile_Core_2* p);

/*@
    requires valid_stream:      Writeable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid_read(p);
    requires invariant:         Invariant(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns stream->addr[0..(stream->size-1)];

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && UpperBitsNotSet{Pre}(p);

      assigns stream->bitpos;
      assigns stream->addr[0..(stream->size-1)];

      ensures result:     \result == 1;
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures left:       Unchanged{Here,Old}(stream, 0, \old(stream->bitpos));
      ensures middle:     EqualBits(stream, \old(stream->bitpos), p);
      ensures right:      Unchanged{Here,Old}(stream, stream->bitpos, 8 * stream->size);

    behavior values_too_big:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && !UpperBitsNotSet{Pre}(p);

      assigns \nothing;

      ensures result:        \result == -2;

    behavior invalid_bit_sequence:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result:       \result == -1;

    complete behaviors;
    disjoint behaviors;
*/
int Axle_Load_Speed_Profile_Core_2_Encoder(Bitstream* stream, const Axle_Load_Speed_Profile_Core_2* p);

/*@
    requires valid_stream:      Readable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:          Unchanged{Here,Old}(stream, 0, 8*stream->size);

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p));

      assigns stream->bitpos;
      assigns *p;

      ensures invariant:  Invariant(p);
      ensures result:     \result == 1; 
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures equal:      EqualBits(stream, \old(stream->bitpos), p);
      ensures upper:      UpperBitsNotSet(p);

    behavior error_case:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result: \result == 0;

    complete behaviors;
    disjoint behaviors;
*/
int Axle_Load_Speed_Profile_Core_2_Decoder(Bitstream* stream, Axle_Load_Speed_Profile_Core_2* p);

#endif // AXLE_LOAD_SPEED_PROFILE_CORE_2_CORE_H_INCLUDED

