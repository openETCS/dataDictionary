
#ifndef PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_H_INCLUDED
#define PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"

struct Permitted_Braking_Distance_Information_Core_1
{

    uint64_t  D_PBD;            // # 15
    uint64_t   Q_GDIR;           // # 1
    uint64_t   G_PBDSR;          // # 8
    uint64_t   Q_PBDSR;          // # 1
    uint64_t  D_PBDSR;          // # 15
    uint64_t  L_PBDSR;          // # 15
};

typedef struct Permitted_Braking_Distance_Information_Core_1 Permitted_Braking_Distance_Information_Core_1;

#define PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_BITSIZE 55

/*@
    logic integer BitSize{L}(Permitted_Braking_Distance_Information_Core_1* p) = PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Permitted_Braking_Distance_Information_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Permitted_Braking_Distance_Information_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Permitted_Braking_Distance_Information_Core_1* p) =
      Invariant(p->D_PBD)             &&
      Invariant(p->Q_GDIR)            &&
      Invariant(p->G_PBDSR)           &&
      Invariant(p->Q_PBDSR)           &&
      Invariant(p->D_PBDSR)           &&
      Invariant(p->L_PBDSR);

    predicate ZeroInitialized(Permitted_Braking_Distance_Information_Core_1* p) =
      ZeroInitialized(p->D_PBD)             &&
      ZeroInitialized(p->Q_GDIR)            &&
      ZeroInitialized(p->G_PBDSR)           &&
      ZeroInitialized(p->Q_PBDSR)           &&
      ZeroInitialized(p->D_PBDSR)           &&
      ZeroInitialized(p->L_PBDSR);

    predicate EqualBits(Bitstream* stream, integer pos, Permitted_Braking_Distance_Information_Core_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_PBD)             &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR)            &&
      EqualBits(stream, pos + 16,  pos + 24,  p->G_PBDSR)           &&
      EqualBits(stream, pos + 24,  pos + 25,  p->Q_PBDSR)           &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_PBDSR)           &&
      EqualBits(stream, pos + 40,  pos + 55,  p->L_PBDSR);

    predicate UpperBitsNotSet(Permitted_Braking_Distance_Information_Core_1* p) =
      UpperBitsNotSet(p->D_PBD,            15)  &&
      UpperBitsNotSet(p->Q_GDIR,           1)   &&
      UpperBitsNotSet(p->G_PBDSR,          8)   &&
      UpperBitsNotSet(p->Q_PBDSR,          1)   &&
      UpperBitsNotSet(p->D_PBDSR,          15)  &&
      UpperBitsNotSet(p->L_PBDSR,          15);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Permitted_Braking_Distance_Information_Core_1_UpperBitsNotSet(const Permitted_Braking_Distance_Information_Core_1* p);

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
int Permitted_Braking_Distance_Information_Core_1_Encode_Bit(Bitstream* stream, const Permitted_Braking_Distance_Information_Core_1* p);

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
int Permitted_Braking_Distance_Information_Core_1_Decode_Bit(Bitstream* stream, Permitted_Braking_Distance_Information_Core_1* p);

int Permitted_Braking_Distance_Information_Core_1_Encode_Int(PacketInfo* data, kcg_int* stream, const Permitted_Braking_Distance_Information_Core_1* p);

int Permitted_Braking_Distance_Information_Core_1_Decode_Int(PacketInfo* data, const kcg_int* stream, Permitted_Braking_Distance_Information_Core_1* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Permitted_Braking_Distance_Information_Core_1& p)
{
    stream
            << +p.D_PBD << ','
            << +p.Q_GDIR << ','
            << +p.G_PBDSR << ','
            << +p.Q_PBDSR << ','
            << +p.D_PBDSR << ','
            << +p.L_PBDSR;

    return stream;
}

inline bool operator==(const Permitted_Braking_Distance_Information_Core_1& a, const Permitted_Braking_Distance_Information_Core_1& b)
{
    bool status = true;

    status = status && (a.D_PBD == b.D_PBD);
    status = status && (a.Q_GDIR == b.Q_GDIR);
    status = status && (a.G_PBDSR == b.G_PBDSR);
    status = status && (a.Q_PBDSR == b.Q_PBDSR);
    status = status && (a.D_PBDSR == b.D_PBDSR);
    status = status && (a.L_PBDSR == b.L_PBDSR);

    return status;
}

inline bool operator!=(const Permitted_Braking_Distance_Information_Core_1& a, const Permitted_Braking_Distance_Information_Core_1& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Permitted_Braking_Distance_Information_Core_1& p)
{
    return Permitted_Braking_Distance_Information_Core_1_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, Permitted_Braking_Distance_Information_Core_1& p)
{
    return Permitted_Braking_Distance_Information_Core_1_Decode_Bit(&stream, &p);
}

inline int encode(PacketInfo& data, kcg_int* stream, const Permitted_Braking_Distance_Information_Core_1& p)
{
    std::cerr << "encode int function not implemented for packet 52 yet." << std::endl;

    return Permitted_Braking_Distance_Information_Core_1_Encode_Int(&data, stream, &p);
}

inline int decode(PacketInfo& data, const kcg_int* stream, Permitted_Braking_Distance_Information_Core_1& p)
{
    std::cerr << "decode int function not implemented for packet 52 yet." << std::endl;

    return Permitted_Braking_Distance_Information_Core_1_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_H_INCLUDED

