
#ifndef BitstreamInvariant_h
#define BitstreamInvariant_h

#include "Bitstream.h"

/*@
  predicate BitstreamInvariant(Bitstream* stream) =
     \valid(stream->addr + (0..stream->size-1))  &&
     8 * stream->size <= UINT32_MAX     &&
     \separated(stream->addr + (0..stream->size-1), stream);
*/

#endif

