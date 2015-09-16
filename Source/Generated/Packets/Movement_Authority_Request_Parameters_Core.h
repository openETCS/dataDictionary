
#ifndef MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_CORE_H_INCLUDED
#define MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Compressed_Packets.h"

struct Movement_Authority_Request_Parameters_Core
{
    // TransmissionMedia=RBC
    // This packet is intended to give parameters telling when and how
    // often the train has to ask for a movement authority.
    // Packet Number = 57

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   T_MAR;            // # 8
    uint64_t  T_TIMEOUTRQST;    // # 10
    uint64_t   T_CYCRQST;        // # 8
};

typedef struct Movement_Authority_Request_Parameters_Core Movement_Authority_Request_Parameters_Core;

#define MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_CORE_BITSIZE 41

/*@
    logic integer BitSize{L}(Movement_Authority_Request_Parameters_Core* p) = MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Movement_Authority_Request_Parameters_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Movement_Authority_Request_Parameters_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Movement_Authority_Request_Parameters_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->T_MAR)             &&
      Invariant(p->T_TIMEOUTRQST)     &&
      Invariant(p->T_CYCRQST);

    predicate ZeroInitialized(Movement_Authority_Request_Parameters_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->T_MAR)             &&
      ZeroInitialized(p->T_TIMEOUTRQST)     &&
      ZeroInitialized(p->T_CYCRQST);

    predicate EqualBits(Bitstream* stream, integer pos, Movement_Authority_Request_Parameters_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 23,  p->T_MAR)             &&
      EqualBits(stream, pos + 23,  pos + 33,  p->T_TIMEOUTRQST)     &&
      EqualBits(stream, pos + 33,  pos + 41,  p->T_CYCRQST);

    predicate UpperBitsNotSet(Movement_Authority_Request_Parameters_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->T_MAR,            8)   &&
      UpperBitsNotSet(p->T_TIMEOUTRQST,    10)  &&
      UpperBitsNotSet(p->T_CYCRQST,        8);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Movement_Authority_Request_Parameters_UpperBitsNotSet(const Movement_Authority_Request_Parameters_Core* p);

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
int Movement_Authority_Request_Parameters_Encode_Bit(Bitstream* stream, const Movement_Authority_Request_Parameters_Core* p);

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
int Movement_Authority_Request_Parameters_Decode_Bit(Bitstream* stream, Movement_Authority_Request_Parameters_Core* p);

int Movement_Authority_Request_Parameters_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Movement_Authority_Request_Parameters_Core* p);

int Movement_Authority_Request_Parameters_Decode_Int(const Packet_Info* data, const kcg_int* stream, Movement_Authority_Request_Parameters_Core* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Movement_Authority_Request_Parameters_Core& p)
{
    stream
            << +p.Q_DIR << ','
            << +p.L_PACKET << ','
            << +p.T_MAR << ','
            << +p.T_TIMEOUTRQST << ','
            << +p.T_CYCRQST;

    return stream;
}

inline bool operator==(const Movement_Authority_Request_Parameters_Core& a, const Movement_Authority_Request_Parameters_Core& b)
{
    bool status = true;

    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.T_MAR == b.T_MAR);
    status = status && (a.T_TIMEOUTRQST == b.T_TIMEOUTRQST);
    status = status && (a.T_CYCRQST == b.T_CYCRQST);

    return status;
}

inline bool operator!=(const Movement_Authority_Request_Parameters_Core& a, const Movement_Authority_Request_Parameters_Core& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Movement_Authority_Request_Parameters_Core& p)
{
    return Movement_Authority_Request_Parameters_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, Movement_Authority_Request_Parameters_Core& p)
{
    return Movement_Authority_Request_Parameters_Decode_Bit(&stream, &p);
}

inline int encode(Packet_Info& data, kcg_int* stream, kcg_int startAddress, const Movement_Authority_Request_Parameters_Core& p)
{
    return Movement_Authority_Request_Parameters_Encode_Int(&data, stream, startAddress, &p);
}

inline int decode(const Packet_Info& data, const kcg_int* stream, Movement_Authority_Request_Parameters_Core& p)
{
    return Movement_Authority_Request_Parameters_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_CORE_H_INCLUDED

