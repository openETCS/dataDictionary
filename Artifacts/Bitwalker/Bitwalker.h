#ifndef BITWALKER_H
#define BITWALKER_H

#include "BitsFramaC.h"

struct Bitwalker
{
  uint8_t*  Bitstream;
  uint32_t  Size;
  uint32_t  Bitposition;
};

typedef struct Bitwalker Bitwalker;

#endif

