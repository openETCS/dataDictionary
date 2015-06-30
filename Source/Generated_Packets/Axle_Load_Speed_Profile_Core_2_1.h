
#ifndef AXLE_LOAD_SPEED_PROFILE_CORE_2_1_CORE_H_INCLUDED
#define AXLE_LOAD_SPEED_PROFILE_CORE_2_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Axle_Load_Speed_Profile_Core_2_1
{

    uint8_t   M_AXLELOADCAT_k_m;// # 7
    uint8_t   V_AXLELOAD_k_m;   // # 7
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Axle_Load_Speed_Profile_Core_2_1& p)
{
    stream 
       << +p.M_AXLELOADCAT_k_m << ','
       << +p.V_AXLELOAD_k_m;

    return stream;
}

inline bool operator==(const Axle_Load_Speed_Profile_Core_2_1& a, const Axle_Load_Speed_Profile_Core_2_1& b)
{
    bool status = true;
    
    status = status && (a.M_AXLELOADCAT_k_m == b.M_AXLELOADCAT_k_m);
    status = status && (a.V_AXLELOAD_k_m == b.V_AXLELOAD_k_m);

    return status;
}

inline bool operator!=(const Axle_Load_Speed_Profile_Core_2_1& a, const Axle_Load_Speed_Profile_Core_2_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Axle_Load_Speed_Profile_Core_2_1 Axle_Load_Speed_Profile_Core_2_1;

#define AXLE_LOAD_SPEED_PROFILE_CORE_2_1_CORE_BITSIZE 1919

/*@
    logic integer BitSize{L}(Axle_Load_Speed_Profile_Core_2_1* p) = AXLE_LOAD_SPEED_PROFILE_CORE_2_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Axle_Load_Speed_Profile_Core_2_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Axle_Load_Speed_Profile_Core_2_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Axle_Load_Speed_Profile_Core_2_1* p) = \true;

    predicate ZeroInitialized(Axle_Load_Speed_Profile_Core_2_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Axle_Load_Speed_Profile_Core_2_1* p) = \true;

    predicate UpperBitsNotSet(Axle_Load_Speed_Profile_Core_2_1* p) = \true;

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Axle_Load_Speed_Profile_Core_2_1_UpperBitsNotSet(const Axle_Load_Speed_Profile_Core_2_1* p);

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
int Axle_Load_Speed_Profile_Core_2_1_Encoder(Bitstream* stream, const Axle_Load_Speed_Profile_Core_2_1* p);

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
int Axle_Load_Speed_Profile_Core_2_1_Decoder(Bitstream* stream, Axle_Load_Speed_Profile_Core_2_1* p);

#endif // AXLE_LOAD_SPEED_PROFILE_CORE_2_1_CORE_H_INCLUDED

