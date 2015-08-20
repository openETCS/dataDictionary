
#ifndef LINKING_CORE_1_CORE_H_INCLUDED
#define LINKING_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"

struct Linking_Core_1
{

    uint64_t  D_LINK_k;         // # 15
    uint64_t   Q_NEWCOUNTRY_k;   // # 1
    uint64_t  NID_C_k;          // # 10
    uint64_t  NID_BG_k;         // # 14
    uint64_t   Q_LINKORIENTATION_k;// # 1
    uint64_t   Q_LINKREACTION_k; // # 2
    uint64_t   Q_LOCACC_k;       // # 6
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Linking_Core_1& p)
{
    stream 
       << +p.D_LINK_k << ','
       << +p.Q_NEWCOUNTRY_k << ','
       << +p.NID_C_k << ','
       << +p.NID_BG_k << ','
       << +p.Q_LINKORIENTATION_k << ','
       << +p.Q_LINKREACTION_k << ','
       << +p.Q_LOCACC_k;

    return stream;
}

inline bool operator==(const Linking_Core_1& a, const Linking_Core_1& b)
{
    bool status = true;
    
    status = status && (a.D_LINK_k == b.D_LINK_k);
    status = status && (a.Q_NEWCOUNTRY_k == b.Q_NEWCOUNTRY_k);
    if (a.Q_NEWCOUNTRY_k == 1)
    {
    status = status && (a.NID_C_k == b.NID_C_k);
    }
    status = status && (a.NID_BG_k == b.NID_BG_k);
    status = status && (a.Q_LINKORIENTATION_k == b.Q_LINKORIENTATION_k);
    status = status && (a.Q_LINKREACTION_k == b.Q_LINKREACTION_k);
    status = status && (a.Q_LOCACC_k == b.Q_LOCACC_k);

    return status;
}

inline bool operator!=(const Linking_Core_1& a, const Linking_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Linking_Core_1 Linking_Core_1;

#define LINKING_CORE_1_CORE_BITSIZE 39

/*@
    logic integer BitSize{L}(Linking_Core_1* p) = LINKING_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Linking_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Linking_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Linking_Core_1* p) =
      Invariant(p->D_LINK_k)          &&
      Invariant(p->Q_NEWCOUNTRY_k);

    predicate ZeroInitialized(Linking_Core_1* p) =
      ZeroInitialized(p->D_LINK_k)          &&
      ZeroInitialized(p->Q_NEWCOUNTRY_k);

    predicate EqualBits(Bitstream* stream, integer pos, Linking_Core_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_LINK_k)          &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_NEWCOUNTRY_k);

    predicate UpperBitsNotSet(Linking_Core_1* p) =
      UpperBitsNotSet(p->D_LINK_k,         15)  &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY_k,   1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Linking_Core_1_UpperBitsNotSet(const Linking_Core_1* p);

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
int Linking_Core_1_Encoder(Bitstream* stream, const Linking_Core_1* p);

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
int Linking_Core_1_Decoder(Bitstream* stream, Linking_Core_1* p);

#endif // LINKING_CORE_1_CORE_H_INCLUDED

