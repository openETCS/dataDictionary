
#ifndef ROUTE_SUITABILITY_DATA_CORE_1_CORE_H_INCLUDED
#define ROUTE_SUITABILITY_DATA_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"

struct Route_Suitability_Data_Core_1
{

    uint64_t  D_SUITABILITY;    // # 15
    uint64_t   Q_SUITABILITY;    // # 2
    uint64_t   M_LOADINGGAUGE;   // # 8
    uint64_t   M_AXLELOAD;       // # 7
    uint64_t   M_TRACTION;       // # 8
};

typedef struct Route_Suitability_Data_Core_1 Route_Suitability_Data_Core_1;

#define ROUTE_SUITABILITY_DATA_CORE_1_CORE_BITSIZE 17

/*@
    logic integer BitSize{L}(Route_Suitability_Data_Core_1* p) = ROUTE_SUITABILITY_DATA_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Route_Suitability_Data_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Route_Suitability_Data_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Route_Suitability_Data_Core_1* p) =
      Invariant(p->D_SUITABILITY)     &&
      Invariant(p->Q_SUITABILITY);

    predicate ZeroInitialized(Route_Suitability_Data_Core_1* p) =
      ZeroInitialized(p->D_SUITABILITY)     &&
      ZeroInitialized(p->Q_SUITABILITY);

    predicate EqualBits(Bitstream* stream, integer pos, Route_Suitability_Data_Core_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_SUITABILITY)     &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SUITABILITY);

    predicate UpperBitsNotSet(Route_Suitability_Data_Core_1* p) =
      UpperBitsNotSet(p->D_SUITABILITY,    15)  &&
      UpperBitsNotSet(p->Q_SUITABILITY,    2);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Route_Suitability_Data_Core_1_UpperBitsNotSet(const Route_Suitability_Data_Core_1* p);

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
int Route_Suitability_Data_Core_1_Encode_Bit(Bitstream* stream, const Route_Suitability_Data_Core_1* p);

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
int Route_Suitability_Data_Core_1_Decode_Bit(Bitstream* stream, Route_Suitability_Data_Core_1* p);

int Route_Suitability_Data_Core_1_Encode_Int(PacketInfo* data, kcg_int* stream, const Route_Suitability_Data_Core_1* p);

int Route_Suitability_Data_Core_1_Decode_Int(PacketInfo* data, const kcg_int* stream, Route_Suitability_Data_Core_1* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Route_Suitability_Data_Core_1& p)
{
    stream
            << +p.D_SUITABILITY << ','
            << +p.Q_SUITABILITY << ','
            << +p.M_LOADINGGAUGE << ','
            << +p.M_AXLELOAD << ','
            << +p.M_TRACTION;

    return stream;
}

inline bool operator==(const Route_Suitability_Data_Core_1& a, const Route_Suitability_Data_Core_1& b)
{
    bool status = true;

    status = status && (a.D_SUITABILITY == b.D_SUITABILITY);
    status = status && (a.Q_SUITABILITY == b.Q_SUITABILITY);

    if (a.Q_SUITABILITY == 0)
    {
        status = status && (a.M_LOADINGGAUGE == b.M_LOADINGGAUGE);
    }

    if (a.Q_SUITABILITY == 1)
    {
        status = status && (a.M_AXLELOAD == b.M_AXLELOAD);
    }

    if (a.Q_SUITABILITY == 2)
    {
        status = status && (a.M_TRACTION == b.M_TRACTION);
    }

    return status;
}

inline bool operator!=(const Route_Suitability_Data_Core_1& a, const Route_Suitability_Data_Core_1& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Route_Suitability_Data_Core_1& p)
{
    return Route_Suitability_Data_Core_1_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, Route_Suitability_Data_Core_1& p)
{
    return Route_Suitability_Data_Core_1_Decode_Bit(&stream, &p);
}

inline int encode(PacketInfo& data, kcg_int* stream, const Route_Suitability_Data_Core_1& p)
{
    std::cerr << "encode int function not implemented for packet 70 yet." << std::endl;

    return Route_Suitability_Data_Core_1_Encode_Int(&data, stream, &p);
}

inline int decode(PacketInfo& data, const kcg_int* stream, Route_Suitability_Data_Core_1& p)
{
    std::cerr << "decode int function not implemented for packet 70 yet." << std::endl;

    return Route_Suitability_Data_Core_1_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // ROUTE_SUITABILITY_DATA_CORE_1_CORE_H_INCLUDED

