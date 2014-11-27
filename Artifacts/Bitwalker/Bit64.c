
#include "Bit64.h"

int PeekBit64(uint64_t value, uint32_t left)
{
  uint64_t mask = ((uint64_t) 1) << (63u - left);
  uint64_t flag = value & mask;
  //@ assert flag != 0 <==> LeftBit64(value, left);

  return flag != 0u;
}


uint64_t PokeBit64(uint64_t value, uint32_t left, int flag)
{
  uint64_t mask = ((uint64_t) 1u) << (63 - left);

  return (flag == 0) ? (value & ~mask) : (value | mask);
}


