
#ifndef BITSTREAM_NORMAL_H_INCLUDED
#define BITSTREAM_NORMAL_H_INCLUDED

#include "Bitstream.h"

/*@
  requires valid:     Readable(stream);
  requires invariant: Invariant(stream, length);

  assigns \nothing;

  ensures  result:    \result <==> Normal(stream, length);
*/
int Bitstream_Normal(const Bitstream* stream, uint32_t length);

#endif // BITSTREAM_NORMAL_H_INCLUDED

