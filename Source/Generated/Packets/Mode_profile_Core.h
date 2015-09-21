
#ifndef MODE_PROFILE_CORE_H_INCLUDED
#define MODE_PROFILE_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Mode_profile_Core_1.h"
#include "Compressed_Packets.h"

struct Mode_profile_Core
{
    // TransmissionMedia=Any
    // Mode profile associated to an MA
    // Packet Number = 80

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t  D_MAMODE;         // # 15
    uint64_t   M_MAMODE;         // # 2
    uint64_t   V_MAMODE;         // # 7
    uint64_t  L_MAMODE;         // # 15
    uint64_t  L_ACKMAMODE;      // # 15
    uint64_t   Q_MAMODE;         // # 1
    uint64_t   N_ITER_1;         // # 5
    Mode_profile_Core_1   sub_1[31];
};

typedef struct Mode_profile_Core Mode_profile_Core;

#define MODE_PROFILE_CORE_BITSIZE 77

/*@
    logic integer BitSize{L}(Mode_profile_Core* p) = MODE_PROFILE_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Mode_profile_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Mode_profile_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Mode_profile_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_MAMODE)          &&
      Invariant(p->M_MAMODE)          &&
      Invariant(p->V_MAMODE)          &&
      Invariant(p->L_MAMODE)          &&
      Invariant(p->L_ACKMAMODE)       &&
      Invariant(p->Q_MAMODE);

    predicate ZeroInitialized(Mode_profile_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_MAMODE)          &&
      ZeroInitialized(p->M_MAMODE)          &&
      ZeroInitialized(p->V_MAMODE)          &&
      ZeroInitialized(p->L_MAMODE)          &&
      ZeroInitialized(p->L_ACKMAMODE)       &&
      ZeroInitialized(p->Q_MAMODE);

    predicate EqualBits(Bitstream* stream, integer pos, Mode_profile_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_MAMODE)          &&
      EqualBits(stream, pos + 32,  pos + 34,  p->M_MAMODE)          &&
      EqualBits(stream, pos + 34,  pos + 41,  p->V_MAMODE)          &&
      EqualBits(stream, pos + 41,  pos + 56,  p->L_MAMODE)          &&
      EqualBits(stream, pos + 56,  pos + 71,  p->L_ACKMAMODE)       &&
      EqualBits(stream, pos + 71,  pos + 72,  p->Q_MAMODE);

    predicate UpperBitsNotSet(Mode_profile_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_MAMODE,         15)  &&
      UpperBitsNotSet(p->M_MAMODE,         2)   &&
      UpperBitsNotSet(p->V_MAMODE,         7)   &&
      UpperBitsNotSet(p->L_MAMODE,         15)  &&
      UpperBitsNotSet(p->L_ACKMAMODE,      15)  &&
      UpperBitsNotSet(p->Q_MAMODE,         1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Mode_profile_UpperBitsNotSet(const Mode_profile_Core* p);

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
int Mode_profile_Encode_Bit(Bitstream* stream, const Mode_profile_Core* p);

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
int Mode_profile_Decode_Bit(Bitstream* stream, Mode_profile_Core* p);

int Mode_profile_Encode_Int(Packet_Info* data, kcg_int* stream, const Mode_profile_Core* p);

int Mode_profile_Decode_Int(Packet_Info* data, const kcg_int* stream, Mode_profile_Core* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Mode_profile_Core& p)
{
    stream
            << +p.Q_DIR << ','
            << +p.L_PACKET << ','
            << +p.Q_SCALE << ','
            << +p.D_MAMODE << ','
            << +p.M_MAMODE << ','
            << +p.V_MAMODE << ','
            << +p.L_MAMODE << ','
            << +p.L_ACKMAMODE << ','
            << +p.Q_MAMODE << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const Mode_profile_Core& a, const Mode_profile_Core& b)
{
    bool status = true;

    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_MAMODE == b.D_MAMODE);
    status = status && (a.M_MAMODE == b.M_MAMODE);
    status = status && (a.V_MAMODE == b.V_MAMODE);
    status = status && (a.L_MAMODE == b.L_MAMODE);
    status = status && (a.L_ACKMAMODE == b.L_ACKMAMODE);
    status = status && (a.Q_MAMODE == b.Q_MAMODE);
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

inline bool operator!=(const Mode_profile_Core& a, const Mode_profile_Core& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Mode_profile_Core& p)
{
    return Mode_profile_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, Mode_profile_Core& p)
{
    return Mode_profile_Decode_Bit(&stream, &p);
}

inline int encode(Packet_Info& data, kcg_int* stream, const Mode_profile_Core& p)
{
    std::cerr << "encode int function not implemented for packet 80 yet." << std::endl;

    return Mode_profile_Encode_Int(&data, stream, &p);
}

inline int decode(Packet_Info& data, const kcg_int* stream, Mode_profile_Core& p)
{
    std::cerr << "decode int function not implemented for packet 80 yet." << std::endl;

    return Mode_profile_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // MODE_PROFILE_CORE_H_INCLUDED

