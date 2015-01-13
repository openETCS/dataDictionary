
#ifndef REVERSING_AREA_INFORMATION_H_INCLUDED
#define REVERSING_AREA_INFORMATION_H_INCLUDED

#include "Bitstream.h"

struct Reversing_area_information
{
    // TransmissionMedia=Any
    // Used to send start and length of reversing area to the on-board
    // Packet Number = 138

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  D_STARTREVERSE;   // # 15
    uint64_t  L_REVERSEAREA;    // # 15
};

typedef struct Reversing_area_information Reversing_area_information;

#define REVERSING_AREA_INFORMATION_BITSIZE 55

/*@
    logic integer BitSize{L}(Reversing_area_information* p) = REVERSING_AREA_INFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(Reversing_area_information* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Reversing_area_information* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Reversing_area_information* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_STARTREVERSE)    &&
      Invariant(p->L_REVERSEAREA);

    predicate ZeroInitialized(Reversing_area_information* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_STARTREVERSE)    &&
      ZeroInitialized(p->L_REVERSEAREA);

    predicate EqualBits(Bitstream* stream, integer pos, Reversing_area_information* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_STARTREVERSE)    &&
      EqualBits(stream, pos + 40,  pos + 55,  p->L_REVERSEAREA);


    predicate UpperBitsNotSet(Reversing_area_information* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_STARTREVERSE,   15)  &&
      UpperBitsNotSet(p->L_REVERSEAREA,    15);

*/

#endif // REVERSING_AREA_INFORMATION_H_INCLUDED

