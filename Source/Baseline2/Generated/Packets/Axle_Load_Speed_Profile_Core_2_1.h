
#ifndef AXLE_LOAD_SPEED_PROFILE_CORE_2_1_CORE_H_INCLUDED
#define AXLE_LOAD_SPEED_PROFILE_CORE_2_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"

struct Axle_Load_Speed_Profile_Core_2_1
{

    uint64_t   M_AXLELOAD;       // # 7
    uint64_t   V_AXLELOAD;       // # 7
};

typedef struct Axle_Load_Speed_Profile_Core_2_1 Axle_Load_Speed_Profile_Core_2_1;

#define AXLE_LOAD_SPEED_PROFILE_CORE_2_1_CORE_BITSIZE 14

/*@
    logic integer BitSize{L}(Axle_Load_Speed_Profile_Core_2_1* p) = AXLE_LOAD_SPEED_PROFILE_CORE_2_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Axle_Load_Speed_Profile_Core_2_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Axle_Load_Speed_Profile_Core_2_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Axle_Load_Speed_Profile_Core_2_1* p) =
      Invariant(p->M_AXLELOAD)        &&
      Invariant(p->V_AXLELOAD);

    predicate ZeroInitialized(Axle_Load_Speed_Profile_Core_2_1* p) =
      ZeroInitialized(p->M_AXLELOAD)        &&
      ZeroInitialized(p->V_AXLELOAD);

    predicate EqualBits(Bitstream* stream, integer pos, Axle_Load_Speed_Profile_Core_2_1* p) =
      EqualBits(stream, pos,       pos + 7,   p->M_AXLELOAD)        &&
      EqualBits(stream, pos + 7,   pos + 14,  p->V_AXLELOAD);

    predicate UpperBitsNotSet(Axle_Load_Speed_Profile_Core_2_1* p) =
      UpperBitsNotSet(p->M_AXLELOAD,       7)   &&
      UpperBitsNotSet(p->V_AXLELOAD,       7);

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
int Axle_Load_Speed_Profile_Core_2_1_Encode_Bit(Bitstream* stream, const Axle_Load_Speed_Profile_Core_2_1* p);

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
int Axle_Load_Speed_Profile_Core_2_1_Decode_Bit(Bitstream* stream, Axle_Load_Speed_Profile_Core_2_1* p);

int Axle_Load_Speed_Profile_Core_2_1_Encode_Int(PacketInfo* data, kcg_int* stream, const Axle_Load_Speed_Profile_Core_2_1* p);

int Axle_Load_Speed_Profile_Core_2_1_Decode_Int(PacketInfo* data, const kcg_int* stream, Axle_Load_Speed_Profile_Core_2_1* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Axle_Load_Speed_Profile_Core_2_1& p)
{
    stream
            << +p.M_AXLELOAD << ','
            << +p.V_AXLELOAD;

    return stream;
}

inline bool operator==(const Axle_Load_Speed_Profile_Core_2_1& a, const Axle_Load_Speed_Profile_Core_2_1& b)
{
    bool status = true;

    status = status && (a.M_AXLELOAD == b.M_AXLELOAD);
    status = status && (a.V_AXLELOAD == b.V_AXLELOAD);

    return status;
}

inline bool operator!=(const Axle_Load_Speed_Profile_Core_2_1& a, const Axle_Load_Speed_Profile_Core_2_1& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Axle_Load_Speed_Profile_Core_2_1& p)
{
    return Axle_Load_Speed_Profile_Core_2_1_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, Axle_Load_Speed_Profile_Core_2_1& p)
{
    return Axle_Load_Speed_Profile_Core_2_1_Decode_Bit(&stream, &p);
}

inline int encode(PacketInfo& data, kcg_int* stream, const Axle_Load_Speed_Profile_Core_2_1& p)
{
    std::cerr << "encode int function not implemented for packet 51 yet." << std::endl;

    return Axle_Load_Speed_Profile_Core_2_1_Encode_Int(&data, stream, &p);
}

inline int decode(PacketInfo& data, const kcg_int* stream, Axle_Load_Speed_Profile_Core_2_1& p)
{
    std::cerr << "decode int function not implemented for packet 51 yet." << std::endl;

    return Axle_Load_Speed_Profile_Core_2_1_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // AXLE_LOAD_SPEED_PROFILE_CORE_2_1_CORE_H_INCLUDED

