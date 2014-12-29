
#ifndef ADHESION_FACTOR_H_INCLUDED
#define ADHESION_FACTOR_H_INCLUDED

#include "BitstreamInvariant.h"

struct Adhesion_Factor
{
    uint64_t ABC;  // 8
    uint64_t DEF;  // 3
    uint64_t GHI;  // 17
    // total: 28
};

typedef struct Adhesion_Factor Adhesion_Factor;

/*@
   predicate BitstreamEqual(Bitstream* stream, integer pos, Adhesion_Factor* p) =
      BitstreamEqual64(stream, pos, pos + 8, p->ABC) &&
      BitstreamEqual64(stream, pos + 8, pos + 11, p->DEF) &&
      BitstreamEqual64(stream, pos + 11, pos + 28, p->GHI);
*/

/*@
   predicate UpperBitsNotSet(Adhesion_Factor* p) =
      UpperBitsNotSet(p->ABC, 8) &&
      UpperBitsNotSet(p->DEF, 3) &&
      UpperBitsNotSet(p->GHI, 17);
*/

#endif // ADHESION_FACTOR_H_INCLUDED

