
#ifndef REVERSING_SUPERVISION_INFORMATION_CORE_H_INCLUDED
#define REVERSING_SUPERVISION_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Reversing_supervision_information_Core
{
    // TransmissionMedia=Any
    // Used to send supervision parameters (distance to run, speed) of reversing
    // area to the on-board       
    // Packet Number = 139

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint16_t  D_REVERSE;        // # 15
    uint8_t   V_REVERSE;        // # 7
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Reversing_supervision_information_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.D_REVERSE << ','
       << +p.V_REVERSE;

    return stream;
}

inline bool operator==(const Reversing_supervision_information_Core& a, const Reversing_supervision_information_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_REVERSE == b.D_REVERSE);
    status = status && (a.V_REVERSE == b.V_REVERSE);

    return status;
}

inline bool operator!=(const Reversing_supervision_information_Core& a, const Reversing_supervision_information_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Reversing_supervision_information_Core Reversing_supervision_information_Core;

#define REVERSING_SUPERVISION_INFORMATION_CORE_BITSIZE 3968

/*@
    logic integer BitSize{L}(Reversing_supervision_information_Core* p) = REVERSING_SUPERVISION_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Reversing_supervision_information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Reversing_supervision_information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Reversing_supervision_information_Core* p) = \true;

    predicate ZeroInitialized(Reversing_supervision_information_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Reversing_supervision_information_Core* p) = \true;

    predicate UpperBitsNotSet(Reversing_supervision_information_Core* p) = \true;

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Reversing_supervision_information_UpperBitsNotSet(const Reversing_supervision_information_Core* p);

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
int Reversing_supervision_information_Encoder(Bitstream* stream, const Reversing_supervision_information_Core* p);

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
int Reversing_supervision_information_Decoder(Bitstream* stream, Reversing_supervision_information_Core* p);

#endif // REVERSING_SUPERVISION_INFORMATION_CORE_H_INCLUDED

