
#ifndef INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_H_INCLUDED
#define INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_H_INCLUDED

#include "Bitstream.h"
#include "International_Static_Speed_Profile_Core_1.h"
#include "International_Static_Speed_Profile_Core_2.h"
#include "Compressed_Packets.h"

struct International_Static_Speed_Profile_Core
{
    // TransmissionMedia=Any
    // Static speed profile and optionally speed limits depending on the international
    // train category.
    // Packet Number = 27

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t  D_STATIC;         // # 15
    uint64_t   V_STATIC;         // # 7
    uint64_t   Q_FRONT;          // # 1
    uint64_t   N_ITER_1;         // # 5
    International_Static_Speed_Profile_Core_1   sub_1[31];
    uint64_t   N_ITER_2;         // # 5
    International_Static_Speed_Profile_Core_2   sub_2[31];
};

typedef struct International_Static_Speed_Profile_Core International_Static_Speed_Profile_Core;

#define INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_BITSIZE 50

/*@
    logic integer BitSize{L}(International_Static_Speed_Profile_Core* p) = INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_BITSIZE;

    logic integer MaxBitSize{L}(International_Static_Speed_Profile_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, International_Static_Speed_Profile_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(International_Static_Speed_Profile_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_STATIC)          &&
      Invariant(p->V_STATIC)          &&
      Invariant(p->Q_FRONT);

    predicate ZeroInitialized(International_Static_Speed_Profile_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_STATIC)          &&
      ZeroInitialized(p->V_STATIC)          &&
      ZeroInitialized(p->Q_FRONT);

    predicate EqualBits(Bitstream* stream, integer pos, International_Static_Speed_Profile_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_STATIC)          &&
      EqualBits(stream, pos + 32,  pos + 39,  p->V_STATIC)          &&
      EqualBits(stream, pos + 39,  pos + 40,  p->Q_FRONT);

    predicate UpperBitsNotSet(International_Static_Speed_Profile_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_STATIC,         15)  &&
      UpperBitsNotSet(p->V_STATIC,         7)   &&
      UpperBitsNotSet(p->Q_FRONT,          1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int International_Static_Speed_Profile_UpperBitsNotSet(const International_Static_Speed_Profile_Core* p);

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
int International_Static_Speed_Profile_Encode_Bit(Bitstream* stream, const International_Static_Speed_Profile_Core* p);

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
int International_Static_Speed_Profile_Decode_Bit(Bitstream* stream, International_Static_Speed_Profile_Core* p);

int International_Static_Speed_Profile_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const International_Static_Speed_Profile_Core* p);

int International_Static_Speed_Profile_Decode_Int(const Packet_Info* data, const kcg_int* stream, International_Static_Speed_Profile_Core* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const International_Static_Speed_Profile_Core& p)
{
    stream
            << +p.Q_DIR << ','
            << +p.L_PACKET << ','
            << +p.Q_SCALE << ','
            << +p.D_STATIC << ','
            << +p.V_STATIC << ','
            << +p.Q_FRONT << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
    stream << ','
       << +p.N_ITER_2;
       for (uint32_t i = 0; i < p.N_ITER_2; ++i)
       {
           stream << ',' << p.sub_2[i];
       }
   

    return stream;
}

inline bool operator==(const International_Static_Speed_Profile_Core& a, const International_Static_Speed_Profile_Core& b)
{
    bool status = true;

    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_STATIC == b.D_STATIC);
    status = status && (a.V_STATIC == b.V_STATIC);
    status = status && (a.Q_FRONT == b.Q_FRONT);
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
    status = status && (a.N_ITER_2 == b.N_ITER_2);
    if (a.N_ITER_2 == b.N_ITER_2)
    {
        for (uint32_t i = 0; i < a.N_ITER_2; ++i)
        {
            status = status && (a.sub_2[i] == b.sub_2[i]);
        }
    }
    else
    {
        status = false;
    }

    return status;
}

inline bool operator!=(const International_Static_Speed_Profile_Core& a, const International_Static_Speed_Profile_Core& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const International_Static_Speed_Profile_Core& p)
{
    return International_Static_Speed_Profile_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, International_Static_Speed_Profile_Core& p)
{
    return International_Static_Speed_Profile_Decode_Bit(&stream, &p);
}

inline int encode(Packet_Info& data, kcg_int* stream, kcg_int startAddress, const International_Static_Speed_Profile_Core& p)
{
    std::cerr << "encode int function not implemented for packet 27 yet." << std::endl;

    return International_Static_Speed_Profile_Encode_Int(&data, stream, startAddress, &p);
}

inline int decode(const Packet_Info& data, const kcg_int* stream, International_Static_Speed_Profile_Core& p)
{
    std::cerr << "decode int function not implemented for packet 27 yet." << std::endl;

    return International_Static_Speed_Profile_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_H_INCLUDED

