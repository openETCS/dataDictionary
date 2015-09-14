
#ifndef MODE_PROFILE_CORE_1_CORE_H_INCLUDED
#define MODE_PROFILE_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Compressed_Packets.h"

struct Mode_profile_Core_1
{

    uint64_t  D_MAMODE;         // # 15
    uint64_t   M_MAMODE;         // # 2
    uint64_t   V_MAMODE;         // # 7
    uint64_t  L_MAMODE;         // # 15
    uint64_t  L_ACKMAMODE;      // # 15
    uint64_t   Q_MAMODE;         // # 1
};

typedef struct Mode_profile_Core_1 Mode_profile_Core_1;

#define MODE_PROFILE_CORE_1_CORE_BITSIZE 55

/*@
    logic integer BitSize{L}(Mode_profile_Core_1* p) = MODE_PROFILE_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Mode_profile_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Mode_profile_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Mode_profile_Core_1* p) =
      Invariant(p->D_MAMODE)          &&
      Invariant(p->M_MAMODE)          &&
      Invariant(p->V_MAMODE)          &&
      Invariant(p->L_MAMODE)          &&
      Invariant(p->L_ACKMAMODE)       &&
      Invariant(p->Q_MAMODE);

    predicate ZeroInitialized(Mode_profile_Core_1* p) =
      ZeroInitialized(p->D_MAMODE)          &&
      ZeroInitialized(p->M_MAMODE)          &&
      ZeroInitialized(p->V_MAMODE)          &&
      ZeroInitialized(p->L_MAMODE)          &&
      ZeroInitialized(p->L_ACKMAMODE)       &&
      ZeroInitialized(p->Q_MAMODE);

    predicate EqualBits(Bitstream* stream, integer pos, Mode_profile_Core_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_MAMODE)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->M_MAMODE)          &&
      EqualBits(stream, pos + 17,  pos + 24,  p->V_MAMODE)          &&
      EqualBits(stream, pos + 24,  pos + 39,  p->L_MAMODE)          &&
      EqualBits(stream, pos + 39,  pos + 54,  p->L_ACKMAMODE)       &&
      EqualBits(stream, pos + 54,  pos + 55,  p->Q_MAMODE);

    predicate UpperBitsNotSet(Mode_profile_Core_1* p) =
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
int Mode_profile_Core_1_UpperBitsNotSet(const Mode_profile_Core_1* p);

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
int Mode_profile_Core_1_Encode_Bit(Bitstream* stream, const Mode_profile_Core_1* p);

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
int Mode_profile_Core_1_Decode_Bit(Bitstream* stream, Mode_profile_Core_1* p);

int Mode_profile_Core_1_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Mode_profile_Core_1* p);

int Mode_profile_Core_1_Decode_Int(const Packet_Info* data, const kcg_int* stream, Mode_profile_Core_1* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Mode_profile_Core_1& p)
{
    stream
            << +p.D_MAMODE << ','
            << +p.M_MAMODE << ','
            << +p.V_MAMODE << ','
            << +p.L_MAMODE << ','
            << +p.L_ACKMAMODE << ','
            << +p.Q_MAMODE;

    return stream;
}

inline bool operator==(const Mode_profile_Core_1& a, const Mode_profile_Core_1& b)
{
    bool status = true;

    status = status && (a.D_MAMODE == b.D_MAMODE);
    status = status && (a.M_MAMODE == b.M_MAMODE);
    status = status && (a.V_MAMODE == b.V_MAMODE);
    status = status && (a.L_MAMODE == b.L_MAMODE);
    status = status && (a.L_ACKMAMODE == b.L_ACKMAMODE);
    status = status && (a.Q_MAMODE == b.Q_MAMODE);

    return status;
}

inline bool operator!=(const Mode_profile_Core_1& a, const Mode_profile_Core_1& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Mode_profile_Core_1& p)
{
    return Mode_profile_Core_1_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, Mode_profile_Core_1& p)
{
    return Mode_profile_Core_1_Decode_Bit(&stream, &p);
}

inline int encode(Packet_Info& data, kcg_int* stream, kcg_int startAddress, const Mode_profile_Core_1& p)
{
    return Mode_profile_Core_1_Encode_Int(&data, stream, startAddress, &p);
}

inline int decode(const Packet_Info& data, const kcg_int* stream, Mode_profile_Core_1& p)
{
    return Mode_profile_Core_1_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // MODE_PROFILE_CORE_1_CORE_H_INCLUDED

