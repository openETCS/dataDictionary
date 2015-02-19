
#ifndef DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_DATA_H_INCLUDED
#define DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_DATA_H_INCLUDED

#include "Bitstream.h"

struct Default_Gradient_for_Temporary_Speed_Restriction_Data
{
    // TransmissionMedia=Balise
    // It defines a default gradient to be used for TSR supervision when no gradient profile (packet 21) is available
    // Packet Number = 141

    uint32_t  Q_DIR;            // # 2
    uint32_t  Q_GDIR;           // # 1
    uint8_t   G_TSR;            // # 8
};

typedef struct Default_Gradient_for_Temporary_Speed_Restriction_Data Default_Gradient_for_Temporary_Speed_Restriction_Data;

#define DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_DATA_BITSIZE 24

/*@
    logic integer BitSize{L}(Default_Gradient_for_Temporary_Speed_Restriction_Data* p) = DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Default_Gradient_for_Temporary_Speed_Restriction_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Default_Gradient_for_Temporary_Speed_Restriction_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Default_Gradient_for_Temporary_Speed_Restriction_Data* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->Q_GDIR)            &&
      Invariant(p->G_TSR);

    predicate ZeroInitialized(Default_Gradient_for_Temporary_Speed_Restriction_Data* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->Q_GDIR)            &&
      ZeroInitialized(p->G_TSR);

    predicate EqualBits(Bitstream* stream, integer pos, Default_Gradient_for_Temporary_Speed_Restriction_Data* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR)            &&
      EqualBits(stream, pos + 16,  pos + 24,  p->G_TSR);


    predicate UpperBitsNotSet(Default_Gradient_for_Temporary_Speed_Restriction_Data* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->Q_GDIR,           1)   &&
      UpperBitsNotSet(p->G_TSR,            8);

*/

#endif // DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_DATA_H_INCLUDED

