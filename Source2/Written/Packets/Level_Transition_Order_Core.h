
#ifndef LEVEL_TRANSITION_ORDER_CORE_H_INCLUDED
#define LEVEL_TRANSITION_ORDER_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Level_Transition_Order_Core_1.h"
#include "CompressedPackets.h"

struct Level_Transition_Order_Core
{
    // TransmissionMedia=Any
    // Packet to identify where a level transition shall take place. In
    // case of mixed levels, the successive M_LEVELTR go from the highest
    // priority level to the lowest one.
    // Packet Number = 41

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t  D_LEVELTR;        // # 15
    uint64_t   M_LEVELTR;        // # 3
    uint64_t   NID_NTC;          // # 8
    uint64_t  L_ACKLEVELTR;     // # 15
    uint64_t   N_ITER_1;         // # 5
    Level_Transition_Order_Core_1   sub_1[31];
};

typedef struct Level_Transition_Order_Core Level_Transition_Order_Core;

#define LEVEL_TRANSITION_ORDER_CORE_BITSIZE 55

/*@
    logic integer BitSize{L}(Level_Transition_Order_Core* p) = LEVEL_TRANSITION_ORDER_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Level_Transition_Order_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level_Transition_Order_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level_Transition_Order_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_LEVELTR)         &&
      Invariant(p->M_LEVELTR);

    predicate ZeroInitialized(Level_Transition_Order_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_LEVELTR)         &&
      ZeroInitialized(p->M_LEVELTR);

    predicate EqualBits(Bitstream* stream, integer pos, Level_Transition_Order_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_LEVELTR)         &&
      EqualBits(stream, pos + 32,  pos + 35,  p->M_LEVELTR);

    predicate UpperBitsNotSet(Level_Transition_Order_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_LEVELTR,        15)  &&
      UpperBitsNotSet(p->M_LEVELTR,        3);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Level_Transition_Order_UpperBitsNotSet(const Level_Transition_Order_Core* p);

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
int Level_Transition_Order_Encode_Bit(Bitstream* stream, const Level_Transition_Order_Core* p);

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
int Level_Transition_Order_Decode_Bit(Bitstream* stream, Level_Transition_Order_Core* p);

int Level_Transition_Order_Encode_Int(PacketInfo* data, kcg_int* stream, const Level_Transition_Order_Core* p);

int Level_Transition_Order_Decode_Int(PacketInfo* data, const kcg_int* stream, Level_Transition_Order_Core* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Level_Transition_Order_Core& p)
{
    stream
            << +p.Q_DIR << ','
            << +p.L_PACKET << ','
            << +p.Q_SCALE << ','
            << +p.D_LEVELTR << ','
            << +p.M_LEVELTR << ','
            << +p.NID_NTC << ','
            << +p.L_ACKLEVELTR << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const Level_Transition_Order_Core& a, const Level_Transition_Order_Core& b)
{
    bool status = true;

    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_LEVELTR == b.D_LEVELTR);
    status = status && (a.M_LEVELTR == b.M_LEVELTR);

    if (a.M_LEVELTR == 1)
    {
        status = status && (a.NID_NTC == b.NID_NTC);
    }
    status = status && (a.L_ACKLEVELTR == b.L_ACKLEVELTR);
    status = status && (a.N_ITER_1 == b.N_ITER_1);
    if (a.N_ITER_1 == b.N_ITER_1)
    {
        for (uint32_t i = 0; i < a.N_ITER_1; ++i)
        {
            status = status && (a.sub_1[i] == b.sub_1[i]);
        }
    }
    else
    {
        status = false;
    }

    return status;
}

inline bool operator!=(const Level_Transition_Order_Core& a, const Level_Transition_Order_Core& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Level_Transition_Order_Core& p)
{
    return Level_Transition_Order_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, Level_Transition_Order_Core& p)
{
    return Level_Transition_Order_Decode_Bit(&stream, &p);
}

inline int encode(PacketInfo& data, kcg_int* stream, const Level_Transition_Order_Core& p)
{
    return Level_Transition_Order_Encode_Int(&data, stream, &p);
}

inline int decode(PacketInfo& data, const kcg_int* stream, Level_Transition_Order_Core& p)
{
    return Level_Transition_Order_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // LEVEL_TRANSITION_ORDER_CORE_H_INCLUDED

