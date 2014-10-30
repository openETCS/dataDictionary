
#ifndef BitwalkerInvariant_h
#define BitwalkerInvariant_h

#include "Bitwalker.h"

/*@
    predicate BitwalkerInvariant(Bitwalker* bw) =
        \valid(bw->Bitstream + (0..bw->Size-1))  &&
        8 * bw->Size <= UINT_MAX                 &&
        \separated(bw->Bitstream + (0..bw->Size-1), bw);
*/

#endif

