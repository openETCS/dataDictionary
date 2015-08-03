
#ifndef LEVEL_23_TRANSITION_INFORMATION_CORE_H_INCLUDED
#define LEVEL_23_TRANSITION_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"

struct Level_23_transition_information_Core
{
    // TransmissionMedia=RBC
    // Identity of the level 2/3 transition balise group   
    // Packet Number = 9

    uint16_t  L_PACKET;         // # 13
    uint32_t  NID_LTRBG;        // # 24
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Level_23_transition_information_Core& p)
{
    stream 
       << +p.L_PACKET << ','
       << +p.NID_LTRBG;

    return stream;
}

inline bool operator==(const Level_23_transition_information_Core& a, const Level_23_transition_information_Core& b)
{
    bool status = true;
    
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.NID_LTRBG == b.NID_LTRBG);

    return status;
}

inline bool operator!=(const Level_23_transition_information_Core& a, const Level_23_transition_information_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Level_23_transition_information_Core Level_23_transition_information_Core;

#define LEVEL_23_TRANSITION_INFORMATION_CORE_BITSIZE 37

/*@
    logic integer BitSize{L}(Level_23_transition_information_Core* p) = LEVEL_23_TRANSITION_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Level_23_transition_information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level_23_transition_information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level_23_transition_information_Core* p) =
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_LTRBG);

    predicate ZeroInitialized(Level_23_transition_information_Core* p) =
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_LTRBG);

    predicate EqualBits(Bitstream* stream, integer pos, Level_23_transition_information_Core* p) =
      EqualBits(stream, pos,       pos + 13,  p->L_PACKET)          &&
      EqualBits(stream, pos + 13,  pos + 37,  p->NID_LTRBG);

    predicate UpperBitsNotSet(Level_23_transition_information_Core* p) =
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_LTRBG,        24);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Level_23_transition_information_UpperBitsNotSet(const Level_23_transition_information_Core* p);

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
int Level_23_transition_information_Encoder(Bitstream* stream, const Level_23_transition_information_Core* p);

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
int Level_23_transition_information_Decoder(Bitstream* stream, Level_23_transition_information_Core* p);

#endif // LEVEL_23_TRANSITION_INFORMATION_CORE_H_INCLUDED

