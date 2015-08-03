
#ifndef GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_CORE_H_INCLUDED
#define GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"

struct Geographical_Position_Information_Core_1
{

    uint8_t   Q_NEWCOUNTRY_k;   // # 1
    uint16_t  NID_C_k;          // # 10
    uint16_t  NID_BG_k;         // # 14
    uint16_t  D_POSOFF_k;       // # 15
    uint8_t   Q_MPOSITION_k;    // # 1
    uint32_t  M_POSITION_k;     // # 24
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Geographical_Position_Information_Core_1& p)
{
    stream 
       << +p.Q_NEWCOUNTRY_k << ','
       << +p.NID_C_k << ','
       << +p.NID_BG_k << ','
       << +p.D_POSOFF_k << ','
       << +p.Q_MPOSITION_k << ','
       << +p.M_POSITION_k;

    return stream;
}

inline bool operator==(const Geographical_Position_Information_Core_1& a, const Geographical_Position_Information_Core_1& b)
{
    bool status = true;
    
    status = status && (a.Q_NEWCOUNTRY_k == b.Q_NEWCOUNTRY_k);
    if (a.Q_NEWCOUNTRY_k == 1)
    {
    status = status && (a.NID_C_k == b.NID_C_k);
    }
    status = status && (a.NID_BG_k == b.NID_BG_k);
    status = status && (a.D_POSOFF_k == b.D_POSOFF_k);
    status = status && (a.Q_MPOSITION_k == b.Q_MPOSITION_k);
    status = status && (a.M_POSITION_k == b.M_POSITION_k);

    return status;
}

inline bool operator!=(const Geographical_Position_Information_Core_1& a, const Geographical_Position_Information_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Geographical_Position_Information_Core_1 Geographical_Position_Information_Core_1;

#define GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_CORE_BITSIZE 55

/*@
    logic integer BitSize{L}(Geographical_Position_Information_Core_1* p) = GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Geographical_Position_Information_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Geographical_Position_Information_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Geographical_Position_Information_Core_1* p) =
      Invariant(p->Q_NEWCOUNTRY_k);

    predicate ZeroInitialized(Geographical_Position_Information_Core_1* p) =
      ZeroInitialized(p->Q_NEWCOUNTRY_k);

    predicate EqualBits(Bitstream* stream, integer pos, Geographical_Position_Information_Core_1* p) =
      EqualBits(stream, pos,       pos + 1,   p->Q_NEWCOUNTRY_k);

    predicate UpperBitsNotSet(Geographical_Position_Information_Core_1* p) =
      UpperBitsNotSet(p->Q_NEWCOUNTRY_k,   1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Geographical_Position_Information_Core_1_UpperBitsNotSet(const Geographical_Position_Information_Core_1* p);

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
int Geographical_Position_Information_Core_1_Encoder(Bitstream* stream, const Geographical_Position_Information_Core_1* p);

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
int Geographical_Position_Information_Core_1_Decoder(Bitstream* stream, Geographical_Position_Information_Core_1* p);

#endif // GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_CORE_H_INCLUDED

