
#ifndef DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_H_INCLUDED
#define DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_H_INCLUDED

#include "Bitstream.h"

struct Default_Gradient_for_Temporary_Speed_Restriction
{
    // TransmissionMedia=Balise
    // It defines a default gradient to be used for TSR supervision
    // when no gradient profile (packet 21) is available   
    // Packet Number = 141

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_GDIR;           // # 1
    uint8_t   G_TSR;            // # 8
};

typedef struct Default_Gradient_for_Temporary_Speed_Restriction Default_Gradient_for_Temporary_Speed_Restriction;

#define DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_BITSIZE 24

/*@
    logic integer BitSize{L}(Default_Gradient_for_Temporary_Speed_Restriction* p) = DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_BITSIZE;

    logic integer MaxBitSize{L}(Default_Gradient_for_Temporary_Speed_Restriction* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Default_Gradient_for_Temporary_Speed_Restriction* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Default_Gradient_for_Temporary_Speed_Restriction* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_GDIR)            &&
      Invariant(p->G_TSR);

    predicate ZeroInitialized(Default_Gradient_for_Temporary_Speed_Restriction* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_GDIR)            &&
      ZeroInitialized(p->G_TSR);

    predicate EqualBits(Bitstream* stream, integer pos, Default_Gradient_for_Temporary_Speed_Restriction* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR)            &&
      EqualBits(stream, pos + 16,  pos + 24,  p->G_TSR);


    predicate UpperBitsNotSet(Default_Gradient_for_Temporary_Speed_Restriction* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_GDIR,           1)   &&
      UpperBitsNotSet(p->G_TSR,            8);

*/

#endif // DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_H_INCLUDED

