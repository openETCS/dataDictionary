
#ifndef DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_H_INCLUDED
#define DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_H_INCLUDED

#include "Bitstream.h"

struct Default_Gradient_for_Temporary_Speed_Restriction
{
    // TransmissionMedia=Balise
    // It defines a default gradient to be used for TSR supervision when no gradient profile (packet 21) is available
    // Packet Number = 141

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_GDIR;           // # 1
    uint64_t  G_TSR;            // # 8
};

typedef struct Default_Gradient_for_Temporary_Speed_Restriction Default_Gradient_for_Temporary_Speed_Restriction;

#define DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_BITSIZE 32

/*@
    logic integer BitSize{L}(Default_Gradient_for_Temporary_Speed_Restriction* p) = DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_BITSIZE;

    logic integer MaxBitSize{L}(Default_Gradient_for_Temporary_Speed_Restriction* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Default_Gradient_for_Temporary_Speed_Restriction* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Default_Gradient_for_Temporary_Speed_Restriction* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_GDIR)            &&
      Invariant(p->G_TSR);

    predicate ZeroInitialized(Default_Gradient_for_Temporary_Speed_Restriction* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_GDIR)            &&
      ZeroInitialized(p->G_TSR);

    predicate EqualBits(Bitstream* stream, integer pos, Default_Gradient_for_Temporary_Speed_Restriction* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 24,  p->Q_GDIR)            &&
      EqualBits(stream, pos + 24,  pos + 32,  p->G_TSR);


    predicate UpperBitsNotSet(Default_Gradient_for_Temporary_Speed_Restriction* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_GDIR,           1)   &&
      UpperBitsNotSet(p->G_TSR,            8);

*/

#endif // DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_H_INCLUDED

