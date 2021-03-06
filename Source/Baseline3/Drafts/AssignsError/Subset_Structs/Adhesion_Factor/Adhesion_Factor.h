
#ifndef ADHESION_FACTOR_H_INCLUDED
#define ADHESION_FACTOR_H_INCLUDED

#include "Bitstream.h"

struct Adhesion_Factor
{
    // TransmissionMedia=Any
    // This packet is used when the trackside requests a change of
    // the adhesion factor to be used in the brake model. 
    // Packet Number = 71

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint16_t  D_ADHESION;       // # 15
    uint16_t  L_ADHESION;       // # 15
    uint32_t  M_ADHESION;       // # 1
};

typedef struct Adhesion_Factor Adhesion_Factor;

#define ADHESION_FACTOR_BITSIZE 48

/*@
    logic integer BitSize{L}(Adhesion_Factor* p) = ADHESION_FACTOR_BITSIZE;

    logic integer MaxBitSize{L}(Adhesion_Factor* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Adhesion_Factor* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Adhesion_Factor* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_ADHESION)        &&
      Invariant(p->L_ADHESION)        &&
      Invariant(p->M_ADHESION);

    predicate ZeroInitialized(Adhesion_Factor* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_ADHESION)        &&
      ZeroInitialized(p->L_ADHESION)        &&
      ZeroInitialized(p->M_ADHESION);

    predicate EqualBits(Bitstream* stream, integer pos, Adhesion_Factor* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_ADHESION)        &&
      EqualBits(stream, pos + 32,  pos + 47,  p->L_ADHESION)        &&
      EqualBits(stream, pos + 47,  pos + 48,  p->M_ADHESION);


    predicate UpperBitsNotSet(Adhesion_Factor* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_ADHESION,       15)  &&
      UpperBitsNotSet(p->L_ADHESION,       15)  &&
      UpperBitsNotSet(p->M_ADHESION,       1);

*/

#endif // ADHESION_FACTOR_H_INCLUDED

