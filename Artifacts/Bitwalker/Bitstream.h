#ifndef BITWALKER_H
#define BITWALKER_H

#include "FramaCBits.h"

struct Bitstream
{
  uint8_t*  addr;
  uint32_t  size;
  uint32_t  bitpos;
};

typedef struct Bitstream Bitstream;

#endif

