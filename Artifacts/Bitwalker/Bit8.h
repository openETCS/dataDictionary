

#ifndef Bit8_defined
#define Bit8_defined

#include "BitsFramaC.h"

/*@
    requires 0 <= left_index < 8;

    assigns \nothing;

    ensures (\result != 0) <==> LeftBit8(byte, left_index);
*/
static inline int PeekBit8(uint8_t byte, uint32_t left_index)
{
  uint8_t mask = ((uint8_t) 1) << (7u - left_index);
  uint8_t flag = byte & mask;

  return flag != 0;
}


/*@
    requires 0 <= left_index < 8;

    assigns \nothing;

    ensures \forall integer i; (0 <= i < left_index) ==>
              (LeftBit8(\result, i) <==> LeftBit8(byte, i));

    ensures LeftBit8(\result, left_index) <==> (flag != 0);

    ensures \forall integer i; (left_index < i < 8) ==>
              (LeftBit8(\result, i) <==> LeftBit8(byte, i));
*/
static inline uint8_t PokeBit8(uint8_t byte, uint32_t left_index, int flag)
{
  uint8_t mask = ((uint8_t) 1) << (7u - left_index);

  return (flag == 0) ? (byte & ~mask) : (byte | mask);
}

#endif

