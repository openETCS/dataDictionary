
#ifndef REPOSITIONING_INFORMATION_CORE_H_INCLUDED
#define REPOSITIONING_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Repositioning_Information_Core
{
    // TransmissionMedia=Balise
    // Transmission of the update of the current distance   
    // Packet Number = 16

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint16_t  L_SECTION;        // # 15
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Repositioning_Information_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.L_SECTION;

    return stream;
}

inline bool operator==(const Repositioning_Information_Core& a, const Repositioning_Information_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.L_SECTION == b.L_SECTION);

    return status;
}

inline bool operator!=(const Repositioning_Information_Core& a, const Repositioning_Information_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Repositioning_Information_Core Repositioning_Information_Core;

#define REPOSITIONING_INFORMATION_CORE_BITSIZE 1151

/*@
    logic integer BitSize{L}(Repositioning_Information_Core* p) = REPOSITIONING_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Repositioning_Information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Repositioning_Information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Repositioning_Information_Core* p) = \true;

    predicate ZeroInitialized(Repositioning_Information_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Repositioning_Information_Core* p) = \true;

    predicate UpperBitsNotSet(Repositioning_Information_Core* p) = \true;

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Repositioning_Information_UpperBitsNotSet(const Repositioning_Information_Core* p);

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
int Repositioning_Information_Encoder(Bitstream* stream, const Repositioning_Information_Core* p);

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
int Repositioning_Information_Decoder(Bitstream* stream, Repositioning_Information_Core* p);

#endif // REPOSITIONING_INFORMATION_CORE_H_INCLUDED

