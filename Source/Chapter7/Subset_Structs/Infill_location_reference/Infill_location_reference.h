
#ifndef INFILL_LOCATION_REFERENCE_H_INCLUDED
#define INFILL_LOCATION_REFERENCE_H_INCLUDED

#include "Bitstream.h"

struct Infill_location_reference
{
    // TransmissionMedia=Balise, Loop, RIU
    // Defines location reference for all data contained in the same radio message or balise/loop telegram respectively, following this packet.
    // Packet Number = 136

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_NEWCOUNTRY;     // # 1
    uint64_t  NID_C;            // # 10
    uint64_t  NID_BG;           // # 14
};

typedef struct Infill_location_reference Infill_location_reference;

#define INFILL_LOCATION_REFERENCE_BITSIZE 48

/*@
    logic integer BitSize{L}(Infill_location_reference* p) = INFILL_LOCATION_REFERENCE_BITSIZE;

    logic integer MaxBitSize{L}(Infill_location_reference* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Infill_location_reference* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Infill_location_reference* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_NEWCOUNTRY)      &&
      Invariant(p->NID_C)             &&
      Invariant(p->NID_BG);

    predicate ZeroInitialized(Infill_location_reference* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_NEWCOUNTRY)      &&
      ZeroInitialized(p->NID_C)             &&
      ZeroInitialized(p->NID_BG);

    predicate EqualBits(Bitstream* stream, integer pos, Infill_location_reference* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 24,  p->Q_NEWCOUNTRY)      &&
      EqualBits(stream, pos + 24,  pos + 34,  p->NID_C)             &&
      EqualBits(stream, pos + 34,  pos + 48,  p->NID_BG);


    predicate UpperBitsNotSet(Infill_location_reference* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY,     1)   &&
      UpperBitsNotSet(p->NID_C,            10)  &&
      UpperBitsNotSet(p->NID_BG,           14);

*/

#endif // INFILL_LOCATION_REFERENCE_H_INCLUDED

