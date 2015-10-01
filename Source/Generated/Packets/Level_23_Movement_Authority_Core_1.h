
#ifndef LEVEL_23_MOVEMENT_AUTHORITY_CORE_1_CORE_H_INCLUDED
#define LEVEL_23_MOVEMENT_AUTHORITY_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"

struct Level_23_Movement_Authority_Core_1
{

    uint64_t  L_SECTION;        // # 15
    uint64_t   Q_SECTIONTIMER;   // # 1
    uint64_t  T_SECTIONTIMER;   // # 10
    uint64_t  D_SECTIONTIMERSTOPLOC;// # 15
};

typedef struct Level_23_Movement_Authority_Core_1 Level_23_Movement_Authority_Core_1;

#define LEVEL_23_MOVEMENT_AUTHORITY_CORE_1_CORE_BITSIZE 41

/*@
    logic integer BitSize{L}(Level_23_Movement_Authority_Core_1* p) = LEVEL_23_MOVEMENT_AUTHORITY_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Level_23_Movement_Authority_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level_23_Movement_Authority_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level_23_Movement_Authority_Core_1* p) =
      Invariant(p->L_SECTION)         &&
      Invariant(p->Q_SECTIONTIMER)    &&
      Invariant(p->T_SECTIONTIMER)    &&
      Invariant(p->D_SECTIONTIMERSTOPLOC);

    predicate ZeroInitialized(Level_23_Movement_Authority_Core_1* p) =
      ZeroInitialized(p->L_SECTION)         &&
      ZeroInitialized(p->Q_SECTIONTIMER)    &&
      ZeroInitialized(p->T_SECTIONTIMER)    &&
      ZeroInitialized(p->D_SECTIONTIMERSTOPLOC);

    predicate EqualBits(Bitstream* stream, integer pos, Level_23_Movement_Authority_Core_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->L_SECTION)         &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_SECTIONTIMER)    &&
      EqualBits(stream, pos + 16,  pos + 26,  p->T_SECTIONTIMER)    &&
      EqualBits(stream, pos + 26,  pos + 41,  p->D_SECTIONTIMERSTOPLOC);

    predicate UpperBitsNotSet(Level_23_Movement_Authority_Core_1* p) =
      UpperBitsNotSet(p->L_SECTION,        15)  &&
      UpperBitsNotSet(p->Q_SECTIONTIMER,   1)   &&
      UpperBitsNotSet(p->T_SECTIONTIMER,   10)  &&
      UpperBitsNotSet(p->D_SECTIONTIMERSTOPLOC,15);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Level_23_Movement_Authority_Core_1_UpperBitsNotSet(const Level_23_Movement_Authority_Core_1* p);

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
int Level_23_Movement_Authority_Core_1_Encode_Bit(Bitstream* stream, const Level_23_Movement_Authority_Core_1* p);

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
int Level_23_Movement_Authority_Core_1_Decode_Bit(Bitstream* stream, Level_23_Movement_Authority_Core_1* p);

int Level_23_Movement_Authority_Core_1_Encode_Int(PacketInfo* data, kcg_int* stream, const Level_23_Movement_Authority_Core_1* p);

int Level_23_Movement_Authority_Core_1_Decode_Int(PacketInfo* data, const kcg_int* stream, Level_23_Movement_Authority_Core_1* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Level_23_Movement_Authority_Core_1& p)
{
    stream
            << +p.L_SECTION << ','
            << +p.Q_SECTIONTIMER << ','
            << +p.T_SECTIONTIMER << ','
            << +p.D_SECTIONTIMERSTOPLOC;

    return stream;
}

inline bool operator==(const Level_23_Movement_Authority_Core_1& a, const Level_23_Movement_Authority_Core_1& b)
{
    bool status = true;

    status = status && (a.L_SECTION == b.L_SECTION);
    status = status && (a.Q_SECTIONTIMER == b.Q_SECTIONTIMER);
    status = status && (a.T_SECTIONTIMER == b.T_SECTIONTIMER);
    status = status && (a.D_SECTIONTIMERSTOPLOC == b.D_SECTIONTIMERSTOPLOC);

    return status;
}

inline bool operator!=(const Level_23_Movement_Authority_Core_1& a, const Level_23_Movement_Authority_Core_1& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Level_23_Movement_Authority_Core_1& p)
{
    return Level_23_Movement_Authority_Core_1_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, Level_23_Movement_Authority_Core_1& p)
{
    return Level_23_Movement_Authority_Core_1_Decode_Bit(&stream, &p);
}

inline int encode(PacketInfo& data, kcg_int* stream, const Level_23_Movement_Authority_Core_1& p)
{
    std::cerr << "encode int function not implemented for packet 15 yet." << std::endl;

    return Level_23_Movement_Authority_Core_1_Encode_Int(&data, stream, &p);
}

inline int decode(PacketInfo& data, const kcg_int* stream, Level_23_Movement_Authority_Core_1& p)
{
    std::cerr << "decode int function not implemented for packet 15 yet." << std::endl;

    return Level_23_Movement_Authority_Core_1_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // LEVEL_23_MOVEMENT_AUTHORITY_CORE_1_CORE_H_INCLUDED

