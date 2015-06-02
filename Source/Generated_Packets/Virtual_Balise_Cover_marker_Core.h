
#ifndef VIRTUAL_BALISE_COVER_MARKER_CORE_H_INCLUDED
#define VIRTUAL_BALISE_COVER_MARKER_CORE_H_INCLUDED

#include "Bitstream.h"

struct Virtual_Balise_Cover_marker_Core
{
    // TransmissionMedia=Balise
    // Indication to on-board that the telegram can be ignored according to
    // a VBC         
    // Packet Number = 0

    uint8_t   NID_VBCMK;        // # 6
};

#ifdef __cplusplus

inline bool operator==(const Virtual_Balise_Cover_marker_Core& a, const Virtual_Balise_Cover_marker_Core& b)
{
    return
        (a.NID_VBCMK == b.NID_VBCMK);
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

#endif // VIRTUAL_BALISE_COVER_MARKER_CORE_H_INCLUDED

