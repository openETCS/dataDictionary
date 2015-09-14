
#ifndef GRADIENT_PROFILE_CORE_1_CORE_H_INCLUDED
#define GRADIENT_PROFILE_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Compressed_Packets.h"

struct Gradient_Profile_Core_1
{

    uint64_t  D_GRADIENT;       // # 15
    uint64_t   Q_GDIR;           // # 1
    uint64_t   G_A;              // # 8
};

typedef struct Gradient_Profile_Core_1 Gradient_Profile_Core_1;

#define GRADIENT_PROFILE_CORE_1_CORE_BITSIZE 24

/*@
    logic integer BitSize{L}(Gradient_Profile_Core_1* p) = GRADIENT_PROFILE_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Gradient_Profile_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Gradient_Profile_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Gradient_Profile_Core_1* p) =
      Invariant(p->D_GRADIENT)        &&
      Invariant(p->Q_GDIR)            &&
      Invariant(p->G_A);

    predicate ZeroInitialized(Gradient_Profile_Core_1* p) =
      ZeroInitialized(p->D_GRADIENT)        &&
      ZeroInitialized(p->Q_GDIR)            &&
      ZeroInitialized(p->G_A);

    predicate EqualBits(Bitstream* stream, integer pos, Gradient_Profile_Core_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_GRADIENT)        &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR)            &&
      EqualBits(stream, pos + 16,  pos + 24,  p->G_A);

    predicate UpperBitsNotSet(Gradient_Profile_Core_1* p) =
      UpperBitsNotSet(p->D_GRADIENT,       15)  &&
      UpperBitsNotSet(p->Q_GDIR,           1)   &&
      UpperBitsNotSet(p->G_A,              8);

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
int Gradient_Profile_Core_1_Encode_Bit(Bitstream* stream, const Gradient_Profile_Core_1* p);

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
int Gradient_Profile_Core_1_Decode_Bit(Bitstream* stream, Gradient_Profile_Core_1* p);

int Gradient_Profile_Core_1_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Gradient_Profile_Core_1* p);

int Gradient_Profile_Core_1_Decode_Int(const Packet_Info* data, const kcg_int* stream, Gradient_Profile_Core_1* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Gradient_Profile_Core_1& p)
{
    stream
            << +p.D_GRADIENT << ','
            << +p.Q_GDIR << ','
            << +p.G_A;

    return stream;
}

inline bool operator==(const Gradient_Profile_Core_1& a, const Gradient_Profile_Core_1& b)
{
    bool status = true;

    status = status && (a.D_GRADIENT == b.D_GRADIENT);
    status = status && (a.Q_GDIR == b.Q_GDIR);
    status = status && (a.G_A == b.G_A);

    return status;
}

inline bool operator!=(const Gradient_Profile_Core_1& a, const Gradient_Profile_Core_1& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Gradient_Profile_Core_1& p)
{
    return Gradient_Profile_Core_1_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, Gradient_Profile_Core_1& p)
{
    return Gradient_Profile_Core_1_Decode_Bit(&stream, &p);
}

inline int encode(Packet_Info& data, kcg_int* stream, kcg_int startAddress, const Gradient_Profile_Core_1& p)
{
    return Gradient_Profile_Core_1_Encode_Int(&data, stream, startAddress, &p);
}

inline int decode(const Packet_Info& data, const kcg_int* stream, Gradient_Profile_Core_1& p)
{
    return Gradient_Profile_Core_1_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // GRADIENT_PROFILE_CORE_1_CORE_H_INCLUDED

