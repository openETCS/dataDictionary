
#include "Bit8.h"

int PeekBit8(uint8_t byte, uint32_t left_index)
{
  uint8_t mask = ((uint8_t) 1) << (7u - left_index);
  uint8_t flag = byte & mask;

  return flag != 0;
}


uint8_t PokeBit8(uint8_t byte, uint32_t left_index, int flag)
{
  uint8_t mask = ((uint8_t) 1) << (7u - left_index);

  return (flag == 0) ? (byte & ~mask) : (byte | mask);
}

