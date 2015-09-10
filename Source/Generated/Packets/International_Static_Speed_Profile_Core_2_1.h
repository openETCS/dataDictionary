
#ifndef INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_1_CORE_H_INCLUDED
#define INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_1_CORE_H_INCLUDED

#include "Bitstream.h"

struct International_Static_Speed_Profile_Core_2_1
{

    uint64_t   Q_DIFF;           // # 2
    uint64_t   NC_CDDIFF;        // # 4
    uint64_t   NC_DIFF;          // # 4
    uint64_t   V_DIFF;           // # 7
};

typedef struct International_Static_Speed_Profile_Core_2_1 International_Static_Speed_Profile_Core_2_1;

#define INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_1_CORE_BITSIZE 9

/*@
    logic integer BitSize{L}(International_Static_Speed_Profile_Core_2_1* p) = INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(International_Static_Speed_Profile_Core_2_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, International_Static_Speed_Profile_Core_2_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(International_Static_Speed_Profile_Core_2_1* p) =
      Invariant(p->Q_DIFF);

    predicate ZeroInitialized(International_Static_Speed_Profile_Core_2_1* p) =
      ZeroInitialized(p->Q_DIFF);

    predicate EqualBits(Bitstream* stream, integer pos, International_Static_Speed_Profile_Core_2_1* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIFF);

    predicate UpperBitsNotSet(International_Static_Speed_Profile_Core_2_1* p) =
      UpperBitsNotSet(p->Q_DIFF,           2);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int International_Static_Speed_Profile_Core_2_1_UpperBitsNotSet(const International_Static_Speed_Profile_Core_2_1* p);

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
int International_Static_Speed_Profile_Core_2_1_Encoder(Bitstream* stream, const International_Static_Speed_Profile_Core_2_1* p);

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
int International_Static_Speed_Profile_Core_2_1_Decoder(Bitstream* stream, International_Static_Speed_Profile_Core_2_1* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const International_Static_Speed_Profile_Core_2_1& p)
{
    stream
            << +p.Q_DIFF << ','
            << +p.NC_CDDIFF << ','
            << +p.NC_DIFF << ','
            << +p.V_DIFF;

    return stream;
}

inline bool operator==(const International_Static_Speed_Profile_Core_2_1& a, const International_Static_Speed_Profile_Core_2_1& b)
{
    bool status = true;

    status = status && (a.Q_DIFF == b.Q_DIFF);

    if (a.Q_DIFF == 0)
    {
        status = status && (a.NC_CDDIFF == b.NC_CDDIFF);
    }

    if ((a.Q_DIFF == 1) || (a.Q_DIFF == 2))
    {
        status = status && (a.NC_DIFF == b.NC_DIFF);
    }
    status = status && (a.V_DIFF == b.V_DIFF);

    return status;
}

inline bool operator!=(const International_Static_Speed_Profile_Core_2_1& a, const International_Static_Speed_Profile_Core_2_1& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const International_Static_Speed_Profile_Core_2_1& p)
{
    return International_Static_Speed_Profile_Core_2_1_Encoder(&stream, &p);
}

inline int decode(Bitstream& stream, International_Static_Speed_Profile_Core_2_1& p)
{
    return International_Static_Speed_Profile_Core_2_1_Decoder(&stream, &p);
}

#endif // __cplusplus

#endif // INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_1_CORE_H_INCLUDED

