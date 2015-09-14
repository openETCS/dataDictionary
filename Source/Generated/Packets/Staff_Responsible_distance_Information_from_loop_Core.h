
#ifndef STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_H_INCLUDED
#define STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Staff_Responsible_distance_Information_from_loop_Core_1.h"
#include "Compressed_Packets.h"

struct Staff_Responsible_distance_Information_from_loop_Core
{
    // TransmissionMedia=Loop
    // Information for trains in staff responsible mode
    // Packet Number = 13

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t   Q_NEWCOUNTRY_0;   // # 1
    uint64_t  NID_C_0;          // # 10
    uint64_t  NID_BG_0;         // # 14
    uint64_t   Q_NEWCOUNTRY_1;   // # 1
    uint64_t  NID_C_1;          // # 10
    uint64_t  NID_BG_1;         // # 14
    uint64_t  D_SR;             // # 15
    uint64_t   N_ITER_1;         // # 5
    Staff_Responsible_distance_Information_from_loop_Core_1   sub_1[31];
};

typedef struct Staff_Responsible_distance_Information_from_loop_Core Staff_Responsible_distance_Information_from_loop_Core;

#define STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_BITSIZE 67

/*@
    logic integer BitSize{L}(Staff_Responsible_distance_Information_from_loop_Core* p) = STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Staff_Responsible_distance_Information_from_loop_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Staff_Responsible_distance_Information_from_loop_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Staff_Responsible_distance_Information_from_loop_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_NEWCOUNTRY_0);

    predicate ZeroInitialized(Staff_Responsible_distance_Information_from_loop_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_NEWCOUNTRY_0);

    predicate EqualBits(Bitstream* stream, integer pos, Staff_Responsible_distance_Information_from_loop_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 18,  p->Q_NEWCOUNTRY_0);

    predicate UpperBitsNotSet(Staff_Responsible_distance_Information_from_loop_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY_0,   1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Staff_Responsible_distance_Information_from_loop_UpperBitsNotSet(const Staff_Responsible_distance_Information_from_loop_Core* p);

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
int Staff_Responsible_distance_Information_from_loop_Encode_Bit(Bitstream* stream, const Staff_Responsible_distance_Information_from_loop_Core* p);

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
int Staff_Responsible_distance_Information_from_loop_Decode_Bit(Bitstream* stream, Staff_Responsible_distance_Information_from_loop_Core* p);

int Staff_Responsible_distance_Information_from_loop_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Staff_Responsible_distance_Information_from_loop_Core* p);

int Staff_Responsible_distance_Information_from_loop_Decode_Int(const Packet_Info* data, const kcg_int* stream, Staff_Responsible_distance_Information_from_loop_Core* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Staff_Responsible_distance_Information_from_loop_Core& p)
{
    stream
            << +p.Q_DIR << ','
            << +p.L_PACKET << ','
            << +p.Q_SCALE << ','
            << +p.Q_NEWCOUNTRY_0 << ','
            << +p.NID_C_0 << ','
            << +p.NID_BG_0 << ','
            << +p.Q_NEWCOUNTRY_1 << ','
            << +p.NID_C_1 << ','
            << +p.NID_BG_1 << ','
            << +p.D_SR << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const Staff_Responsible_distance_Information_from_loop_Core& a, const Staff_Responsible_distance_Information_from_loop_Core& b)
{
    bool status = true;

    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.Q_NEWCOUNTRY_0 == b.Q_NEWCOUNTRY_0);

    if (a.Q_NEWCOUNTRY_0 == 1)
    {
        status = status && (a.NID_C_0 == b.NID_C_0);
    }
    status = status && (a.NID_BG_0 == b.NID_BG_0);
    status = status && (a.Q_NEWCOUNTRY_1 == b.Q_NEWCOUNTRY_1);

    if (a.Q_NEWCOUNTRY_1 == 1)
    {
        status = status && (a.NID_C_1 == b.NID_C_1);
    }
    status = status && (a.NID_BG_1 == b.NID_BG_1);
    status = status && (a.D_SR == b.D_SR);
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

inline bool operator!=(const Staff_Responsible_distance_Information_from_loop_Core& a, const Staff_Responsible_distance_Information_from_loop_Core& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Staff_Responsible_distance_Information_from_loop_Core& p)
{
    return Staff_Responsible_distance_Information_from_loop_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, Staff_Responsible_distance_Information_from_loop_Core& p)
{
    return Staff_Responsible_distance_Information_from_loop_Decode_Bit(&stream, &p);
}

inline int encode(Packet_Info& data, kcg_int* stream, kcg_int startAddress, const Staff_Responsible_distance_Information_from_loop_Core& p)
{
    return Staff_Responsible_distance_Information_from_loop_Encode_Int(&data, stream, startAddress, &p);
}

inline int decode(const Packet_Info& data, const kcg_int* stream, Staff_Responsible_distance_Information_from_loop_Core& p)
{
    return Staff_Responsible_distance_Information_from_loop_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_H_INCLUDED

