
#ifndef ADHESION_FACTOR_H_INCLUDED
#define ADHESION_FACTOR_H_INCLUDED

#include "BitstreamInvariant.h"

struct Adhesion_Factor
{
    // TransmissionMedia=Any
    // This packet is used when the trackside requests a change
    // of the adhesion factor to be used in the brake model.
    // Packet Number = 71

    uint64_t  NID_PACKET;  // # 8
    uint64_t  Q_DIR;       // # 2
    uint64_t  L_PACKET;    // # 13
    uint64_t  Q_SCALE;     // # 2
    uint64_t  D_ADHESION;  // # 15
    uint64_t  L_ADHESION;  // # 15
    uint64_t  M_ADHESION;  // # 1
};

typedef struct Adhesion_Factor Adhesion_Factor;

#define ADHESION_FACTOR_BITSIZE 56

/*@
    logic integer BitSize{L}(Adhesion_Factor* p) = ADHESION_FACTOR_BITSIZE;
*/

/*@
   predicate BitstreamEqual(Bitstream* stream, integer pos, Adhesion_Factor* p) =
      BitstreamEqual64(stream, pos,      pos + 8,  p->NID_PACKET)  &&
      BitstreamEqual64(stream, pos + 8,  pos + 10, p->Q_DIR)       &&
      BitstreamEqual64(stream, pos + 10, pos + 23, p->L_PACKET)    &&
      BitstreamEqual64(stream, pos + 23, pos + 25, p->Q_SCALE)     &&
      BitstreamEqual64(stream, pos + 25, pos + 40, p->D_ADHESION)  &&
      BitstreamEqual64(stream, pos + 40, pos + 55, p->L_ADHESION)  &&
      BitstreamEqual64(stream, pos + 55, pos + 56, p->M_ADHESION);
*/

/*@
   predicate UpperBitsNotSet(Adhesion_Factor* p) =
      UpperBitsNotSet(p->NID_PACKET, 8)   &&
      UpperBitsNotSet(p->Q_DIR,      2)   &&
      UpperBitsNotSet(p->L_PACKET,   13)  &&
      UpperBitsNotSet(p->Q_SCALE,    2)   &&
      UpperBitsNotSet(p->D_ADHESION, 15)  &&
      UpperBitsNotSet(p->L_ADHESION, 15)  &&
      UpperBitsNotSet(p->M_ADHESION, 1);
*/

#endif // ADHESION_FACTOR_H_INCLUDED

