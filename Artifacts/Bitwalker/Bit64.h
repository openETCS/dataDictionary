
#ifndef Bit64_defined
#define Bit64_defined

#include "BitsFramaC.h"

/*@
   requires 0 <= left_index < 64;

   assigns \nothing;

   ensures (\result != 0) <==> LeftBit64(value, left_index);
*/
static inline int PeekBit64(uint64_t value, uint32_t left_index)
{
  uint64_t mask = ((uint64_t) 1) << (63u - left_index);
  uint64_t flag = value & mask;
  //@ assert (flag != 0) <==> LeftBit64(value, left_index);

  return flag != 0u;
}


/*@
    requires left_index < 64;

    assigns \nothing;

    ensures \forall integer i; (0 <= i < left_index) ==>
                (LeftBit64(\result, i) <==> LeftBit64(value, i));

    ensures ((flag != 0)  <==>  LeftBit64(\result, left_index));

    ensures \forall integer i; (left_index < i < 64) ==>
                (LeftBit64(\result, i) <==> LeftBit64(value, i));
*/
static inline uint64_t PokeBit64(uint64_t value, uint32_t left_index, int flag)
{
  uint64_t mask = ((uint64_t) 1u) << (63 - left_index);

  return (flag == 0) ? (value & ~mask) : (value | mask);
}

#endif

