
#ifndef GRADIENT_PROFILE_CORE_1_CORE_H_INCLUDED
#define GRADIENT_PROFILE_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Gradient_Profile_Core_1
{

    uint16_t  D_GRADIENT_k;     // # 15
    uint8_t   Q_GDIR_k;         // # 1
    uint8_t   G_A_k;            // # 8
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Gradient_Profile_Core_1& p)
{
    stream 
       << +p.D_GRADIENT_k << ','
       << +p.Q_GDIR_k << ','
       << +p.G_A_k;

    return stream;
}

inline bool operator==(const Gradient_Profile_Core_1& a, const Gradient_Profile_Core_1& b)
{
    bool status = true;
    
    status = status && (a.D_GRADIENT_k == b.D_GRADIENT_k);
    status = status && (a.Q_GDIR_k == b.Q_GDIR_k);
    status = status && (a.G_A_k == b.G_A_k);

    return status;
}

inline bool operator!=(const Gradient_Profile_Core_1& a, const Gradient_Profile_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Gradient_Profile_Core_1 Gradient_Profile_Core_1;

#define GRADIENT_PROFILE_CORE_1_CORE_BITSIZE 1221

/*@
    logic integer BitSize{L}(Gradient_Profile_Core_1* p) = GRADIENT_PROFILE_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Gradient_Profile_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Gradient_Profile_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Gradient_Profile_Core_1* p) = \true;

    predicate ZeroInitialized(Gradient_Profile_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Gradient_Profile_Core_1* p) = \true;

    predicate UpperBitsNotSet(Gradient_Profile_Core_1* p) = \true;

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Gradient_Profile_Core_1_UpperBitsNotSet(const Gradient_Profile_Core_1* p);

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
int Gradient_Profile_Core_1_Encoder(Bitstream* stream, const Gradient_Profile_Core_1* p);

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
int Gradient_Profile_Core_1_Decoder(Bitstream* stream, Gradient_Profile_Core_1* p);

#endif // GRADIENT_PROFILE_CORE_1_CORE_H_INCLUDED

