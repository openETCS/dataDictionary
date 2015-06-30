
#ifndef SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_CORE_H_INCLUDED
#define SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Session_Management_with_neighbouring_Radio_Infill_Unit_Core
{
    // TransmissionMedia=RIU
    // Packet to give the identity and telephone number of the neighbouring
    // Radio Infill Unit with which a session shall be established or
    // terminated.          
    // Packet Number = 143

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_RIU;            // # 1
    uint16_t  NID_C;            // # 10
    uint16_t  NID_RIU;          // # 14
    uint64_t  NID_RADIO;        // # 64
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Session_Management_with_neighbouring_Radio_Infill_Unit_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_RIU << ','
       << +p.NID_C << ','
       << +p.NID_RIU << ','
       << +p.NID_RADIO;

    return stream;
}

inline bool operator==(const Session_Management_with_neighbouring_Radio_Infill_Unit_Core& a, const Session_Management_with_neighbouring_Radio_Infill_Unit_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_RIU == b.Q_RIU);
    status = status && (a.NID_C == b.NID_C);
    status = status && (a.NID_RIU == b.NID_RIU);
    status = status && (a.NID_RADIO == b.NID_RADIO);

    return status;
}

inline bool operator!=(const Session_Management_with_neighbouring_Radio_Infill_Unit_Core& a, const Session_Management_with_neighbouring_Radio_Infill_Unit_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Session_Management_with_neighbouring_Radio_Infill_Unit_Core Session_Management_with_neighbouring_Radio_Infill_Unit_Core;

#define SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_CORE_BITSIZE 4143

/*@
    logic integer BitSize{L}(Session_Management_with_neighbouring_Radio_Infill_Unit_Core* p) = SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Session_Management_with_neighbouring_Radio_Infill_Unit_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Session_Management_with_neighbouring_Radio_Infill_Unit_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Session_Management_with_neighbouring_Radio_Infill_Unit_Core* p) = \true;

    predicate ZeroInitialized(Session_Management_with_neighbouring_Radio_Infill_Unit_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Session_Management_with_neighbouring_Radio_Infill_Unit_Core* p) = \true;

    predicate UpperBitsNotSet(Session_Management_with_neighbouring_Radio_Infill_Unit_Core* p) = \true;

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Session_Management_with_neighbouring_Radio_Infill_Unit_UpperBitsNotSet(const Session_Management_with_neighbouring_Radio_Infill_Unit_Core* p);

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
int Session_Management_with_neighbouring_Radio_Infill_Unit_Encoder(Bitstream* stream, const Session_Management_with_neighbouring_Radio_Infill_Unit_Core* p);

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
int Session_Management_with_neighbouring_Radio_Infill_Unit_Decoder(Bitstream* stream, Session_Management_with_neighbouring_Radio_Infill_Unit_Core* p);

#endif // SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_CORE_H_INCLUDED

