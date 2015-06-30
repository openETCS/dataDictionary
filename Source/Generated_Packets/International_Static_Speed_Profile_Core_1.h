
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

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int International_Static_Speed_Profile_Core_1_UpperBitsNotSet(const International_Static_Speed_Profile_Core_1* p);

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
int International_Static_Speed_Profile_Core_1_Encoder(Bitstream* stream, const International_Static_Speed_Profile_Core_1* p);

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
int International_Static_Speed_Profile_Core_1_Decoder(Bitstream* stream, International_Static_Speed_Profile_Core_1* p);

#endif // INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_1_CORE_H_INCLUDED

