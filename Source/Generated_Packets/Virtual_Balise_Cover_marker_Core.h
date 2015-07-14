
#ifndef VIRTUAL_BALISE_COVER_MARKER_CORE_H_INCLUDED
#define VIRTUAL_BALISE_COVER_MARKER_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Virtual_Balise_Cover_marker_Core
{
    // TransmissionMedia=Balise
    // Indication to on-board that the telegram can be ignored according to
    // a VBC         
    // Packet Number = 0

    uint8_t   NID_VBCMK;        // # 6
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Virtual_Balise_Cover_marker_Core& p)
{
    stream 
       << +p.NID_VBCMK;

    return stream;
}

inline bool operator==(const Virtual_Balise_Cover_marker_Core& a, const Virtual_Balise_Cover_marker_Core& b)
{
    bool status = true;
    
    status = status && (a.NID_VBCMK == b.NID_VBCMK);

    return status;
}

inline bool operator!=(const Virtual_Balise_Cover_marker_Core& a, const Virtual_Balise_Cover_marker_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Virtual_Balise_Cover_marker_Core Virtual_Balise_Cover_marker_Core;

#define VIRTUAL_BALISE_COVER_MARKER_CORE_BITSIZE 6

/*@
    logic integer BitSize{L}(Virtual_Balise_Cover_marker_Core* p) = VIRTUAL_BALISE_COVER_MARKER_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Virtual_Balise_Cover_marker_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Virtual_Balise_Cover_marker_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Virtual_Balise_Cover_marker_Core* p) =
      Invariant(p->NID_VBCMK);

    predicate ZeroInitialized(Virtual_Balise_Cover_marker_Core* p) =
      ZeroInitialized(p->NID_VBCMK);

    predicate EqualBits(Bitstream* stream, integer pos, Virtual_Balise_Cover_marker_Core* p) =
      EqualBits(stream, pos,       pos + 6,   p->NID_VBCMK);

    predicate UpperBitsNotSet(Virtual_Balise_Cover_marker_Core* p) =
      UpperBitsNotSet(p->NID_VBCMK,        6);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Virtual_Balise_Cover_marker_UpperBitsNotSet(const Virtual_Balise_Cover_marker_Core* p);

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
int Virtual_Balise_Cover_marker_Encoder(Bitstream* stream, const Virtual_Balise_Cover_marker_Core* p);

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
int Virtual_Balise_Cover_marker_Decoder(Bitstream* stream, Virtual_Balise_Cover_marker_Core* p);

#endif // VIRTUAL_BALISE_COVER_MARKER_CORE_H_INCLUDED

