
#ifndef PACKAGE_FOO_DECODER_H_INCLUDED
#define PACKAGE_FOO_DECODER_H_INCLUDED

#include "Package_Foo.h"

/*@
    requires \valid(stream);
    requires BitstreamInvariant(stream);
    requires stream->bitpos + 28 <= UINT32_MAX;
    requires \valid(p);
    requires \separated(stream, p);
    requires \separated(stream->addr + (0..stream->size-1), p);

    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:    BitstreamUnchanged{Here,Old}(stream, 0, 8*stream->size);

    behavior normal_case:
      assumes NormalBitsequence(stream, 28);

      assigns stream->bitpos;
      assigns *p;

      ensures \result == 1;
      ensures stream->bitpos == \old(stream->bitpos) + 28;
      ensures BitstreamEqual(stream, \old(stream->bitpos), p);
      ensures UpperBitsNotSet(p);

    behavior error_case:
      assumes !NormalBitsequence(stream, 28);

      assigns \nothing;

      ensures \result == 0;

    complete behaviors;
    disjoint behaviors;
*/
int Package_Foo_Decoder(Bitstream* stream, Package_Foo* p);


#endif // PACKAGE_FOO_DECODER_H_INCLUDED
