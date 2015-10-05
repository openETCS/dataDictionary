
#ifndef VIRTUAL_BALISE_COVER_MARKER_H_INCLUDED
#define VIRTUAL_BALISE_COVER_MARKER_H_INCLUDED

#include "Bitstream.h"

struct Virtual_Balise_Cover_marker
{
    // TransmissionMedia=Balise
    // Indication to on-board that the telegram can be ignored according to
    // a VBC         
    // Packet Number = 0

    uint8_t   NID_VBCMK;        // # 6
};

typedef struct Virtual_Balise_Cover_marker Virtual_Balise_Cover_marker;

#define VIRTUAL_BALISE_COVER_MARKER_BITSIZE 6

/*@
    logic integer BitSize{L}(Virtual_Balise_Cover_marker* p) = VIRTUAL_BALISE_COVER_MARKER_BITSIZE;

    logic integer MaxBitSize{L}(Virtual_Balise_Cover_marker* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Virtual_Balise_Cover_marker* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Virtual_Balise_Cover_marker* p) =
      Invariant(p->NID_VBCMK);

    predicate ZeroInitialized(Virtual_Balise_Cover_marker* p) =
      ZeroInitialized(p->NID_VBCMK);

    predicate EqualBits(Bitstream* stream, integer pos, Virtual_Balise_Cover_marker* p) =
      EqualBits(stream, pos,       pos + 6,   p->NID_VBCMK);


    predicate UpperBitsNotSet(Virtual_Balise_Cover_marker* p) =
      UpperBitsNotSet(p->NID_VBCMK,        6);

*/

#endif // VIRTUAL_BALISE_COVER_MARKER_H_INCLUDED

