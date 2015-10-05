
#ifndef POSITION_REPORT_CORE_H_INCLUDED
#define POSITION_REPORT_CORE_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"

struct Position_Report_Core
{
    // TransmissionMedia=RBC, RIU
    // This packet is used to report the train position and speed
    // as well as some additional information (e.g. mode, level, etc.)
    // Packet Number = 0

    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t  NID_LRBG;         // # 24
    uint64_t  D_LRBG;           // # 15
    uint64_t   Q_DIRLRBG;        // # 2
    uint64_t   Q_DLRBG;          // # 2
    uint64_t  L_DOUBTOVER;      // # 15
    uint64_t  L_DOUBTUNDER;     // # 15
    uint64_t   Q_LENGTH;         // # 2
    uint64_t  L_TRAININT;       // # 15
    uint64_t   V_TRAIN;          // # 7
    uint64_t   Q_DIRTRAIN;       // # 2
    uint64_t   M_MODE;           // # 4
    uint64_t   M_LEVEL;          // # 3
    uint64_t   NID_NTC;          // # 8
};

typedef struct Position_Report_Core Position_Report_Core;

#define POSITION_REPORT_CORE_BITSIZE 106

/*@
    logic integer BitSize{L}(Position_Report_Core* p) = POSITION_REPORT_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Position_Report_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Position_Report_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Position_Report_Core* p) =
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->NID_LRBG)          &&
      Invariant(p->D_LRBG)            &&
      Invariant(p->Q_DIRLRBG)         &&
      Invariant(p->Q_DLRBG)           &&
      Invariant(p->L_DOUBTOVER)       &&
      Invariant(p->L_DOUBTUNDER)      &&
      Invariant(p->Q_LENGTH);

    predicate ZeroInitialized(Position_Report_Core* p) =
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->NID_LRBG)          &&
      ZeroInitialized(p->D_LRBG)            &&
      ZeroInitialized(p->Q_DIRLRBG)         &&
      ZeroInitialized(p->Q_DLRBG)           &&
      ZeroInitialized(p->L_DOUBTOVER)       &&
      ZeroInitialized(p->L_DOUBTUNDER)      &&
      ZeroInitialized(p->Q_LENGTH);

    predicate EqualBits(Bitstream* stream, integer pos, Position_Report_Core* p) =
      EqualBits(stream, pos,       pos + 13,  p->L_PACKET)          &&
      EqualBits(stream, pos + 13,  pos + 15,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 15,  pos + 39,  p->NID_LRBG)          &&
      EqualBits(stream, pos + 39,  pos + 54,  p->D_LRBG)            &&
      EqualBits(stream, pos + 54,  pos + 56,  p->Q_DIRLRBG)         &&
      EqualBits(stream, pos + 56,  pos + 58,  p->Q_DLRBG)           &&
      EqualBits(stream, pos + 58,  pos + 73,  p->L_DOUBTOVER)       &&
      EqualBits(stream, pos + 73,  pos + 88,  p->L_DOUBTUNDER)      &&
      EqualBits(stream, pos + 88,  pos + 90,  p->Q_LENGTH);

    predicate UpperBitsNotSet(Position_Report_Core* p) =
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->NID_LRBG,         24)  &&
      UpperBitsNotSet(p->D_LRBG,           15)  &&
      UpperBitsNotSet(p->Q_DIRLRBG,        2)   &&
      UpperBitsNotSet(p->Q_DLRBG,          2)   &&
      UpperBitsNotSet(p->L_DOUBTOVER,      15)  &&
      UpperBitsNotSet(p->L_DOUBTUNDER,     15)  &&
      UpperBitsNotSet(p->Q_LENGTH,         2);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Position_Report_UpperBitsNotSet(const Position_Report_Core* p);

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
int Position_Report_Encode_Bit(Bitstream* stream, const Position_Report_Core* p);

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
int Position_Report_Decode_Bit(Bitstream* stream, Position_Report_Core* p);

int Position_Report_Encode_Int(PacketInfo* data, kcg_int* stream, const Position_Report_Core* p);

int Position_Report_Decode_Int(PacketInfo* data, const kcg_int* stream, Position_Report_Core* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Position_Report_Core& p)
{
    stream
            << +p.L_PACKET << ','
            << +p.Q_SCALE << ','
            << +p.NID_LRBG << ','
            << +p.D_LRBG << ','
            << +p.Q_DIRLRBG << ','
            << +p.Q_DLRBG << ','
            << +p.L_DOUBTOVER << ','
            << +p.L_DOUBTUNDER << ','
            << +p.Q_LENGTH << ','
            << +p.L_TRAININT << ','
            << +p.V_TRAIN << ','
            << +p.Q_DIRTRAIN << ','
            << +p.M_MODE << ','
            << +p.M_LEVEL << ','
            << +p.NID_NTC;

    return stream;
}

inline bool operator==(const Position_Report_Core& a, const Position_Report_Core& b)
{
    bool status = true;

    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.NID_LRBG == b.NID_LRBG);
    status = status && (a.D_LRBG == b.D_LRBG);
    status = status && (a.Q_DIRLRBG == b.Q_DIRLRBG);
    status = status && (a.Q_DLRBG == b.Q_DLRBG);
    status = status && (a.L_DOUBTOVER == b.L_DOUBTOVER);
    status = status && (a.L_DOUBTUNDER == b.L_DOUBTUNDER);
    status = status && (a.Q_LENGTH == b.Q_LENGTH);

    if ((a.Q_LENGTH == 1) || (a.Q_LENGTH == 2))
    {
        status = status && (a.L_TRAININT == b.L_TRAININT);
    }

    status = status && (a.V_TRAIN == b.V_TRAIN);
    status = status && (a.Q_DIRTRAIN == b.Q_DIRTRAIN);
    status = status && (a.M_MODE == b.M_MODE);
    status = status && (a.M_LEVEL == b.M_LEVEL);

    if (a.M_LEVEL == 1)
    {
        status = status && (a.NID_NTC == b.NID_NTC);
    }

    return status;
}

inline bool operator!=(const Position_Report_Core& a, const Position_Report_Core& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Position_Report_Core& p)
{
    return Position_Report_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, Position_Report_Core& p)
{
    return Position_Report_Decode_Bit(&stream, &p);
}

inline int encode(PacketInfo& data, kcg_int* stream, const Position_Report_Core& p)
{
    return Position_Report_Encode_Int(&data, stream, &p);
}

inline int decode(PacketInfo& data, const kcg_int* stream, Position_Report_Core& p)
{
    return Position_Report_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // POSITION_REPORT_CORE_H_INCLUDED

