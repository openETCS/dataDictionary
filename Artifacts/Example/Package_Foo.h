
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

/*@
   predicate UpperBitsNotSet(Package_Foo* p) =
      UpperBitsNotSet(p->ABC, 8) &&
      UpperBitsNotSet(p->DEF, 3) &&
      UpperBitsNotSet(p->GHI, 17);
*/


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

    ensures unchanged:    BitstreamUnchanged{Old}(stream, 0, 8*stream->size);

    behavior normal_case:
      assumes NormalBitsequence(stream, 28);

      assigns stream->bitpos;
      assigns *p;

      ensures BitstreamEqual(stream, \old(stream->bitpos), p);
      ensures UpperBitsNotSet(p);
      ensures \result == 1;

    behavior error_case:
      assumes !NormalBitsequence(stream, 28);

      assigns \nothing;

      ensures \result == 0;

    complete behaviors;
    disjoint behaviors;
*/
int Package_Foo_Decoder(Bitstream* stream, Package_Foo* p);


/*@
    requires \valid(stream);
    requires BitstreamInvariant(stream);
    requires stream->bitpos + 28 <= UINT32_MAX;
    requires \valid_read(p);
    requires \separated(stream, p);
    requires \separated(stream->addr + (0..stream->size-1), p);

    assigns stream->bitpos;
    assigns stream->addr[0..(stream->size-1)];

    behavior invalid_bit_sequence:
      assumes !NormalBitsequence(stream, 28);

      assigns \nothing;

      ensures \result == -1;

    behavior values_too_big:
      assumes NormalBitsequence(stream, 28) && !UpperBitsNotSet(p);

      assigns \nothing;

      ensures \result == -2;

    behavior normal_case:
      assumes NormalBitsequence(stream, 28) && UpperBitsNotSet(p);

      assigns stream->bitpos;
      assigns stream->addr[0..(stream->size-1)];

      ensures BitstreamEqual(stream, \old(stream->bitpos), p);
      ensures \result == 1;

    complete behaviors;
    disjoint behaviors;
*/
int Package_Foo_Encoder(Bitstream* stream, const Package_Foo* p);





#endif // PACKAGE_FOO_H_INCLUDED
