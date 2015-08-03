
#ifndef STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_1_CORE_H_INCLUDED
#define STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"

struct Staff_Responsible_distance_Information_from_loop_Core_1
{

    uint8_t   Q_NEWCOUNTRY_k;   // # 1
    uint16_t  NID_C_k;          // # 10
    uint16_t  NID_BG_k;         // # 14
    uint16_t  D_SR_k;           // # 15
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Staff_Responsible_distance_Information_from_loop_Core_1& p)
{
    stream 
       << +p.Q_NEWCOUNTRY_k << ','
       << +p.NID_C_k << ','
       << +p.NID_BG_k << ','
       << +p.D_SR_k;

    return stream;
}

inline bool operator==(const Staff_Responsible_distance_Information_from_loop_Core_1& a, const Staff_Responsible_distance_Information_from_loop_Core_1& b)
{
    bool status = true;
    
    status = status && (a.Q_NEWCOUNTRY_k == b.Q_NEWCOUNTRY_k);
    if (a.Q_NEWCOUNTRY_k == 1)
    {
    status = status && (a.NID_C_k == b.NID_C_k);
    }
    status = status && (a.NID_BG_k == b.NID_BG_k);
    status = status && (a.D_SR_k == b.D_SR_k);

    return status;
}

inline bool operator!=(const Staff_Responsible_distance_Information_from_loop_Core_1& a, const Staff_Responsible_distance_Information_from_loop_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Staff_Responsible_distance_Information_from_loop_Core_1 Staff_Responsible_distance_Information_from_loop_Core_1;

#define STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_1_CORE_BITSIZE 30

/*@
    logic integer BitSize{L}(Staff_Responsible_distance_Information_from_loop_Core_1* p) = STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Staff_Responsible_distance_Information_from_loop_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Staff_Responsible_distance_Information_from_loop_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Staff_Responsible_distance_Information_from_loop_Core_1* p) =
      Invariant(p->Q_NEWCOUNTRY_k);

    predicate ZeroInitialized(Staff_Responsible_distance_Information_from_loop_Core_1* p) =
      ZeroInitialized(p->Q_NEWCOUNTRY_k);

    predicate EqualBits(Bitstream* stream, integer pos, Staff_Responsible_distance_Information_from_loop_Core_1* p) =
      EqualBits(stream, pos,       pos + 1,   p->Q_NEWCOUNTRY_k);

    predicate UpperBitsNotSet(Staff_Responsible_distance_Information_from_loop_Core_1* p) =
      UpperBitsNotSet(p->Q_NEWCOUNTRY_k,   1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Staff_Responsible_distance_Information_from_loop_Core_1_UpperBitsNotSet(const Staff_Responsible_distance_Information_from_loop_Core_1* p);

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
int Staff_Responsible_distance_Information_from_loop_Core_1_Encoder(Bitstream* stream, const Staff_Responsible_distance_Information_from_loop_Core_1* p);

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
int Staff_Responsible_distance_Information_from_loop_Core_1_Decoder(Bitstream* stream, Staff_Responsible_distance_Information_from_loop_Core_1* p);

#endif // STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_1_CORE_H_INCLUDED

