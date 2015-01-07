
#ifndef PACKAGE_FOO_H_INCLUDED
#define PACKAGE_FOO_H_INCLUDED

#include "Bitstream.h"

struct Package_Foo
{
    uint64_t ABC;  // 8
    uint64_t DEF;  // 3
    uint64_t GHI;  // 17
    // total: 28
};

typedef struct Package_Foo Package_Foo;

/*@
    logic integer BitSize{L}(Package_Foo* p) = 28;
*/

/*@
    predicate Separated(Bitstream* stream, Package_Foo* p) =
     \separated(stream, p) &&
     \separated(stream->addr + (0..stream->size-1), p);


     predicate EqualBits(Bitstream* stream, integer pos, Package_Foo* p) =
      EqualBits(stream, pos, pos + 8, p->ABC) &&
      EqualBits(stream, pos + 8, pos + 11, p->DEF) &&
      EqualBits(stream, pos + 11, pos + 28, p->GHI);


   predicate UpperBitsNotSet(Package_Foo* p) =
      UpperBitsNotSet(p->ABC, 8) &&
      UpperBitsNotSet(p->DEF, 3) &&
      UpperBitsNotSet(p->GHI, 17);
*/

#endif // PACKAGE_FOO_H_INCLUDED

