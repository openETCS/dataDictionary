
#ifndef DANGER_FOR_SHUNTING_INFORMATION_CORE_H_INCLUDED
#define DANGER_FOR_SHUNTING_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"

struct Danger_for_Shunting_information_Core
{
    // TransmissionMedia=Balise
    // Transmission of the aspect of a shunting signal   
    // Packet Number = 132

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_ASPECT;         // # 1
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Danger_for_Shunting_information_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_ASPECT;

    return stream;
}

inline bool operator==(const Danger_for_Shunting_information_Core& a, const Danger_for_Shunting_information_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_ASPECT == b.Q_ASPECT);

    return status;
}

inline bool operator!=(const Danger_for_Shunting_information_Core& a, const Danger_for_Shunting_information_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Danger_for_Shunting_information_Core Danger_for_Shunting_information_Core;

#define DANGER_FOR_SHUNTING_INFORMATION_CORE_BITSIZE 16

/*@
    logic integer BitSize{L}(Danger_for_Shunting_information_Core* p) = DANGER_FOR_SHUNTING_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Danger_for_Shunting_information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Danger_for_Shunting_information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Danger_for_Shunting_information_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_ASPECT);

    predicate ZeroInitialized(Danger_for_Shunting_information_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_ASPECT);

    predicate EqualBits(Bitstream* stream, integer pos, Danger_for_Shunting_information_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_ASPECT);

    predicate UpperBitsNotSet(Danger_for_Shunting_information_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_ASPECT,         1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Danger_for_Shunting_information_UpperBitsNotSet(const Danger_for_Shunting_information_Core* p);

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
int Danger_for_Shunting_information_Encoder(Bitstream* stream, const Danger_for_Shunting_information_Core* p);

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
int Danger_for_Shunting_information_Decoder(Bitstream* stream, Danger_for_Shunting_information_Core* p);

#endif // DANGER_FOR_SHUNTING_INFORMATION_CORE_H_INCLUDED

