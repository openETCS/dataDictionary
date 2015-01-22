
#ifndef ADHESION_FACTOR_H_INCLUDED
#define ADHESION_FACTOR_H_INCLUDED

#include "TrackToTrain_Header.h"
#include "Bitstream.h"

struct Adhesion_Factor_Data {
    uint64_t  Q_SCALE;          // # 2
    uint64_t  D_ADHESION;       // # 15
    uint64_t  L_ADHESION;       // # 15
    uint64_t  M_ADHESION;       // # 1
};

typedef struct Adhesion_Factor_Data Adhesion_Factor_Data;

struct Adhesion_Factor
{
    // TransmissionMedia=Any
    // This packet is used when the trackside requests a change of the adhesion factor to be used in the brake model.
    // Packet Number = 71

    TrackToTrain_Header header;
    Adhesion_Factor_Data data;
};

typedef struct Adhesion_Factor Adhesion_Factor;

#define ADHESION_FACTOR_BITSIZE 33

/*@
    logic integer BitSize{L}(Adhesion_Factor* p) = ADHESION_FACTOR_BITSIZE;

    logic integer MaxBitSize{L}(Adhesion_Factor* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Adhesion_Factor* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Adhesion_Factor_Data* p) =
      Invariant(p->data.Q_SCALE)           &&
      Invariant(p->data.D_ADHESION)        &&
      Invariant(p->data.L_ADHESION)        &&
      Invariant(p->data.M_ADHESION);

    predicate ZeroInitialized(Adhesion_Factor_Data* p) =
      ZeroInitialized(p->data.Q_SCALE)           &&
      ZeroInitialized(p->data.D_ADHESION)        &&
      ZeroInitialized(p->data.L_ADHESION)        &&
      ZeroInitialized(p->data.M_ADHESION);

    predicate EqualBits(Bitstream* stream, integer pos, Adhesion_Factor_Data* p) =
      EqualBits(stream, pos,       pos +  2,  p->data.Q_SCALE)           &&
      EqualBits(stream, pos +  2,  pos + 17,  p->data.D_ADHESION)        &&
      EqualBits(stream, pos + 17,  pos + 32,  p->data.L_ADHESION)        &&
      EqualBits(stream, pos + 32,  pos + 33,  p->data.M_ADHESION);


    predicate UpperBitsNotSet(Adhesion_Factor_Data* p) =
      UpperBitsNotSet(p->data.Q_SCALE,          2)   &&
      UpperBitsNotSet(p->data.D_ADHESION,       15)  &&
      UpperBitsNotSet(p->data.L_ADHESION,       15)  &&
      UpperBitsNotSet(p->data.M_ADHESION,       1);

*/

#endif // ADHESION_FACTOR_H_INCLUDED

