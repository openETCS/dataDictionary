
#ifndef RADIO_INFILL_AREA_INFORMATION_CORE_H_INCLUDED
#define RADIO_INFILL_AREA_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Radio_infill_area_information_Core
{
    // TransmissionMedia=Balise
    // Packet Number = 133

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint32_t  Q_RIU;            // # 1
    uint16_t  NID_C;            // # 10
    uint16_t  NID_RIU;          // # 14
    uint64_t  NID_RADIO;        // # 64
    uint16_t  D_INFILL;         // # 15
    uint16_t  NID_BG;           // # 14
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Radio_infill_area_information_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.Q_RIU << ','
       << +p.NID_C << ','
       << +p.NID_RIU << ','
       << +p.NID_RADIO << ','
       << +p.D_INFILL << ','
       << +p.NID_BG;

    return stream;
}

inline bool operator==(const Radio_infill_area_information_Core& a, const Radio_infill_area_information_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.Q_RIU == b.Q_RIU);
    status = status && (a.NID_C == b.NID_C);
    status = status && (a.NID_RIU == b.NID_RIU);
    status = status && (a.NID_RADIO == b.NID_RADIO);
    status = status && (a.D_INFILL == b.D_INFILL);
    status = status && (a.NID_BG == b.NID_BG);

    return status;
}

inline bool operator!=(const Radio_infill_area_information_Core& a, const Radio_infill_area_information_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Radio_infill_area_information_Core Radio_infill_area_information_Core;

#define RADIO_INFILL_AREA_INFORMATION_CORE_BITSIZE 3745

/*@
    logic integer BitSize{L}(Radio_infill_area_information_Core* p) = RADIO_INFILL_AREA_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Radio_infill_area_information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Radio_infill_area_information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Radio_infill_area_information_Core* p) = \true;

    predicate ZeroInitialized(Radio_infill_area_information_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Radio_infill_area_information_Core* p) = \true;

    predicate UpperBitsNotSet(Radio_infill_area_information_Core* p) = \true;

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Radio_infill_area_information_UpperBitsNotSet(const Radio_infill_area_information_Core* p);

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
int Radio_infill_area_information_Encoder(Bitstream* stream, const Radio_infill_area_information_Core* p);

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
int Radio_infill_area_information_Decoder(Bitstream* stream, Radio_infill_area_information_Core* p);

#endif // RADIO_INFILL_AREA_INFORMATION_CORE_H_INCLUDED

