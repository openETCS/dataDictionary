
#ifndef LIST_OF_BALISES_IN_SR_AUTHORITY_CORE_1_CORE_H_INCLUDED
#define LIST_OF_BALISES_IN_SR_AUTHORITY_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"

struct List_of_Balises_in_SR_Authority_Core_1
{

    uint64_t   Q_NEWCOUNTRY;     // # 1
    uint64_t  NID_C;            // # 10
    uint64_t  NID_BG;           // # 14
};

typedef struct List_of_Balises_in_SR_Authority_Core_1 List_of_Balises_in_SR_Authority_Core_1;

#define LIST_OF_BALISES_IN_SR_AUTHORITY_CORE_1_CORE_BITSIZE 15

/*@
    logic integer BitSize{L}(List_of_Balises_in_SR_Authority_Core_1* p) = LIST_OF_BALISES_IN_SR_AUTHORITY_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(List_of_Balises_in_SR_Authority_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, List_of_Balises_in_SR_Authority_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(List_of_Balises_in_SR_Authority_Core_1* p) =
      Invariant(p->Q_NEWCOUNTRY);

    predicate ZeroInitialized(List_of_Balises_in_SR_Authority_Core_1* p) =
      ZeroInitialized(p->Q_NEWCOUNTRY);

    predicate EqualBits(Bitstream* stream, integer pos, List_of_Balises_in_SR_Authority_Core_1* p) =
      EqualBits(stream, pos,       pos + 1,   p->Q_NEWCOUNTRY);

    predicate UpperBitsNotSet(List_of_Balises_in_SR_Authority_Core_1* p) =
      UpperBitsNotSet(p->Q_NEWCOUNTRY,     1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int List_of_Balises_in_SR_Authority_Core_1_UpperBitsNotSet(const List_of_Balises_in_SR_Authority_Core_1* p);

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
int List_of_Balises_in_SR_Authority_Core_1_Encoder(Bitstream* stream, const List_of_Balises_in_SR_Authority_Core_1* p);

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
int List_of_Balises_in_SR_Authority_Core_1_Decoder(Bitstream* stream, List_of_Balises_in_SR_Authority_Core_1* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const List_of_Balises_in_SR_Authority_Core_1& p)
{
    stream
            << +p.Q_NEWCOUNTRY << ','
            << +p.NID_C << ','
            << +p.NID_BG;

    return stream;
}

inline bool operator==(const List_of_Balises_in_SR_Authority_Core_1& a, const List_of_Balises_in_SR_Authority_Core_1& b)
{
    bool status = true;

    status = status && (a.Q_NEWCOUNTRY == b.Q_NEWCOUNTRY);

    if (a.Q_NEWCOUNTRY == 1)
    {
        status = status && (a.NID_C == b.NID_C);
    }
    status = status && (a.NID_BG == b.NID_BG);

    return status;
}

inline bool operator!=(const List_of_Balises_in_SR_Authority_Core_1& a, const List_of_Balises_in_SR_Authority_Core_1& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const List_of_Balises_in_SR_Authority_Core_1& p)
{
    return List_of_Balises_in_SR_Authority_Core_1_Encoder(&stream, &p);
}

inline int decode(Bitstream& stream, List_of_Balises_in_SR_Authority_Core_1& p)
{
    return List_of_Balises_in_SR_Authority_Core_1_Decoder(&stream, &p);
}

#endif // __cplusplus

#endif // LIST_OF_BALISES_IN_SR_AUTHORITY_CORE_1_CORE_H_INCLUDED

