
#include "Bitstream_ReadInt32.h"
#include "Bitstream_Read.h"

int32_t Bitstream_ReadInt32(Bitstream* stream, uint32_t length)
{
  // plausibility check is done when reading the bits
  uint64_t a = Bitstream_Read(stream, length);

  return int32_t(a);
}

