
#ifndef PACKAGE_FOO_H_INCLUDED
#define PACKAGE_FOO_H_INCLUDED

#include "Bitstream_Read.h"

struct Package_Foo
{
    uint64_t ABC;  // 8
    uint64_t DEF;  // 3
    uint64_t GHI;  // 17
                   // total: 28 
};

typedef struct Package_Foo Package_Foo;

//static inline uint32_t Package_Foo_Bits(const Package_Foo* p)
//{
 //   return 28;
//}

/*@
    requires \valid(p);

    assigns  *p;

    ensures  p->ABC == 0;
    ensures  p->DEF == 0;
    ensures  p->GHI == 0;
*/
void Package_Foo_Init(Package_Foo* p);

/*@
    requires \valid(stream);
    requires BitstreamInvariant(stream);
    requires stream->bitpos + 28 <= UINT32_MAX;
    requires \valid(p);
    requires \separated(stream, p);
    requires \separated(stream->addr + (0..stream->size-1), p);

    assigns stream->bitpos;
    assigns *p;

    behavior normal_case:
      assumes stream->bitpos + 28 <= 8 * stream->size;

      assigns stream->bitpos;
      assigns *p;

      ensures stream->bitpos == \old(stream->bitpos) + 28;
      ensures \result == 1;

    behavior error_case:
      assumes stream->bitpos + 28 > 8 * stream->size;

      assigns \nothing;

      ensures \result == 0;

    complete behaviors;
    disjoint behaviors;
*/
int Package_Foo_Decoder(Bitstream* stream, Package_Foo* p);


#endif // PACKAGE_FOO_H_INCLUDED
