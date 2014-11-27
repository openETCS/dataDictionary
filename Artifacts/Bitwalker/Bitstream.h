#ifndef BITWALKER_H
#define BITWALKER_H

#include "BitsFramaC.h"

struct Bitstream
{
  uint8_t*  addr;
  uint32_t  size;
  uint32_t  bitpos;
};

typedef struct Bitstream Bitstream;

#endif

