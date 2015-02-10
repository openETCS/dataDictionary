
#ifndef ADHESION_FACTOR_H_INCLUDED
#define ADHESION_FACTOR_H_INCLUDED

#include "TrackToTrain_Header.h"
#include "Adhesion_Factor_Data.h"

struct Adhesion_Factor {
    // TransmissionMedia=Any
    // This packet is used when the trackside requests a change of the adhesion factor to be used in the brake model.
    // Packet Number = 71

    TrackToTrain_Header header;
    Adhesion_Factor_Data data;
};

typedef struct Adhesion_Factor Adhesion_Factor;

/*@
    logic integer BitSize{L}(Adhesion_Factor* p) = BitSize(&p->header) + BitSize(&p->data);

    logic integer MaxBitSize{L}(Adhesion_Factor* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Adhesion_Factor* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Adhesion_Factor* p) =
      Invariant(&p->header)  &&
      Invariant(&p->data);

    predicate ZeroInitialized(Adhesion_Factor* p) =
      ZeroInitialized(&p->header)  &&
      ZeroInitialized(&p->data);

    predicate EqualBits(Bitstream* stream, integer pos, Adhesion_Factor* p) =
      EqualBits(stream, pos, &p->header)                        &&
      EqualBits(stream, pos + BitSize(&p->header), &p->data); 


    predicate UpperBitsNotSet(Adhesion_Factor* p) =
      UpperBitsNotSet(&p->header)                    &&
      UpperBitsNotSet(&p->data);

*/

#endif // ADHESION_FACTOR_H_INCLUDED

