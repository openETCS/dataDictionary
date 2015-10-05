
#ifndef AXLE_LOAD_SPEED_PROFILE_CORE_2_CORE_H_INCLUDED
#define AXLE_LOAD_SPEED_PROFILE_CORE_2_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Axle_Load_Speed_Profile_Core_2_1.h"
#include "CompressedPackets.h"

struct Axle_Load_Speed_Profile_Core_2
{

    uint64_t  D_AXLELOAD;       // # 15
    uint64_t  L_AXLELOAD;       // # 15
    uint64_t   Q_FRONT;          // # 1
    uint64_t   N_ITER_2_1;       // # 5
    Axle_Load_Speed_Profile_Core_2_1   sub_2_1[31];
};

typedef struct Axle_Load_Speed_Profile_Core_2 Axle_Load_Speed_Profile_Core_2;

#define AXLE_LOAD_SPEED_PROFILE_CORE_2_CORE_BITSIZE 36

/*@
    logic integer BitSize{L}(Axle_Load_Speed_Profile_Core_2* p) = AXLE_LOAD_SPEED_PROFILE_CORE_2_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Axle_Load_Speed_Profile_Core_2* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Axle_Load_Speed_Profile_Core_2* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Axle_Load_Speed_Profile_Core_2* p) =
      Invariant(p->D_AXLELOAD)        &&
      Invariant(p->L_AXLELOAD)        &&
      Invariant(p->Q_FRONT);

    predicate ZeroInitialized(Axle_Load_Speed_Profile_Core_2* p) =
      ZeroInitialized(p->D_AXLELOAD)        &&
      ZeroInitialized(p->L_AXLELOAD)        &&
      ZeroInitialized(p->Q_FRONT);

    predicate EqualBits(Bitstream* stream, integer pos, Axle_Load_Speed_Profile_Core_2* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_AXLELOAD)        &&
      EqualBits(stream, pos + 15,  pos + 30,  p->L_AXLELOAD)        &&
      EqualBits(stream, pos + 30,  pos + 31,  p->Q_FRONT);

    predicate UpperBitsNotSet(Axle_Load_Speed_Profile_Core_2* p) =
      UpperBitsNotSet(p->D_AXLELOAD,       15)  &&
      UpperBitsNotSet(p->L_AXLELOAD,       15)  &&
      UpperBitsNotSet(p->Q_FRONT,          1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Axle_Load_Speed_Profile_Core_2_UpperBitsNotSet(const Axle_Load_Speed_Profile_Core_2* p);

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
int Axle_Load_Speed_Profile_Core_2_Encode_Bit(Bitstream* stream, const Axle_Load_Speed_Profile_Core_2* p);

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
int Axle_Load_Speed_Profile_Core_2_Decode_Bit(Bitstream* stream, Axle_Load_Speed_Profile_Core_2* p);

int Axle_Load_Speed_Profile_Core_2_Encode_Int(PacketInfo* data, kcg_int* stream, const Axle_Load_Speed_Profile_Core_2* p);

int Axle_Load_Speed_Profile_Core_2_Decode_Int(PacketInfo* data, const kcg_int* stream, Axle_Load_Speed_Profile_Core_2* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Axle_Load_Speed_Profile_Core_2& p)
{
    stream
            << +p.D_AXLELOAD << ','
            << +p.L_AXLELOAD << ','
            << +p.Q_FRONT << ','
            << +p.N_ITER_2_1;

    for (uint32_t i = 0; i < p.N_ITER_2_1; ++i)
    {
        stream << ',' << p.sub_2_1[i];
    }


    return stream;
}

inline bool operator==(const Axle_Load_Speed_Profile_Core_2& a, const Axle_Load_Speed_Profile_Core_2& b)
{
    bool status = true;

    status = status && (a.D_AXLELOAD == b.D_AXLELOAD);
    status = status && (a.L_AXLELOAD == b.L_AXLELOAD);
    status = status && (a.Q_FRONT == b.Q_FRONT);
    status = status && (a.N_ITER_2_1 == b.N_ITER_2_1);

    if (a.N_ITER_2_1 == b.N_ITER_2_1)
    {
        for (uint32_t i = 0; i < a.N_ITER_2_1; ++i)
        {
            status = status && (a.sub_2_1[i] == b.sub_2_1[i]);
        }
    }
    else
    {
        status = false;
    }

    return status;
}

inline bool operator!=(const Axle_Load_Speed_Profile_Core_2& a, const Axle_Load_Speed_Profile_Core_2& b)
{
    return !(a == b);
}

#endif // __cplusplus

#endif // AXLE_LOAD_SPEED_PROFILE_CORE_2_CORE_H_INCLUDED

