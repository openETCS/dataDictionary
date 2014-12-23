
#ifndef PACKAGE_FOO_H_INCLUDED
#define PACKAGE_FOO_H_INCLUDED

#include "BitstreamInvariant.h"

struct Package_Foo
{
    uint64_t ABC;  // 8
    uint64_t DEF;  // 3
    uint64_t GHI;  // 17
    // total: 28
};

typedef struct Package_Foo Package_Foo;

/*@
   predicate BitstreamEqual(Bitstream* stream, integer pos, Package_Foo* p) =
      BitstreamEqual64(stream, pos, pos + 8, p->ABC) &&
      BitstreamEqual64(stream, pos + 8, pos + 11, p->DEF) &&
      BitstreamEqual64(stream, pos + 11, pos + 28, p->GHI);
*/


/*@ lemma BitstreamEqualLemma:
      \forall Bitstream* stream, integer pos, Package_Foo* p; 
         BitstreamEqual64(stream, pos, pos + 8, p->ABC) ==>
         BitstreamEqual64(stream, pos + 8, pos + 11, p->DEF) ==>
         BitstreamEqual64(stream, pos + 11, pos + 28, p->GHI) ==>
         BitstreamEqual(stream, pos, p);
*/

/*@
   predicate UpperBitsNotSet(Package_Foo* p) =
      UpperBitsNotSet(p->ABC, 8) &&
      UpperBitsNotSet(p->DEF, 3) &&
      UpperBitsNotSet(p->GHI, 17);
*/

#endif // PACKAGE_FOO_H_INCLUDED

