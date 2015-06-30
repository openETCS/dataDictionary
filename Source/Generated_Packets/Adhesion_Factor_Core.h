
#ifndef ADHESION_FACTOR_CORE_H_INCLUDED
#define ADHESION_FACTOR_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Adhesion_Factor_Core
{
    // TransmissionMedia=Any
    // This packet is used when the trackside requests a change of
    // the adhesion factor to be used in the brake model. 
    // Packet Number = 71

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint16_t  D_ADHESION;       // # 15
    uint16_t  L_ADHESION;       // # 15
    uint32_t  M_ADHESION;       // # 1
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Adhesion_Factor_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.D_ADHESION << ','
       << +p.L_ADHESION << ','
       << +p.M_ADHESION;

    return stream;
}

inline bool operator==(const Adhesion_Factor_Core& a, const Adhesion_Factor_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_ADHESION == b.D_ADHESION);
    status = status && (a.L_ADHESION == b.L_ADHESION);
    status = status && (a.M_ADHESION == b.M_ADHESION);

    return status;
}

inline bool operator!=(const Adhesion_Factor_Core& a, const Adhesion_Factor_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Adhesion_Factor_Core Adhesion_Factor_Core;

#define ADHESION_FACTOR_CORE_BITSIZE 2794

/*@
    logic integer BitSize{L}(Adhesion_Factor_Core* p) = ADHESION_FACTOR_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Adhesion_Factor_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Adhesion_Factor_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Adhesion_Factor_Core* p) = \true;

    predicate ZeroInitialized(Adhesion_Factor_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Adhesion_Factor_Core* p) = \true;

    predicate UpperBitsNotSet(Adhesion_Factor_Core* p) = \true;

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Adhesion_Factor_UpperBitsNotSet(const Adhesion_Factor_Core* p);

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
int Adhesion_Factor_Encoder(Bitstream* stream, const Adhesion_Factor_Core* p);

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
int Adhesion_Factor_Decoder(Bitstream* stream, Adhesion_Factor_Core* p);

#endif // ADHESION_FACTOR_CORE_H_INCLUDED

