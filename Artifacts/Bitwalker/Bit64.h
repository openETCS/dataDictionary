
#ifndef Bit64_defined
#define Bit64_defined

#include "BitsFramaC.h"

/*@
   requires 0 <= left < 64;

   assigns \nothing;

   ensures \result != 0 <==> LeftBit64(value, left);
*/
static inline int PeekBit64(uint64_t value, uint32_t left)
{
  uint64_t mask = ((uint64_t) 1) << (63u - left);
  uint64_t flag = value & mask;
  //@ assert flag != 0 <==> LeftBit64(value, left);

  return flag != 0u;
}


/*@
    requires left < 64;

    assigns \nothing;

    ensures \forall integer i; (0 <= i < 64  &&  i != left) ==>
                (LeftBit64(\result, i) <==> LeftBit64(value, i));

    ensures flag != 0  <==>  LeftBit64(\result, left);
*/
static inline uint64_t PokeBit64(uint64_t value, uint32_t left, int flag)
{
  uint64_t mask = ((uint64_t) 1u) << (63 - left);

  return (flag == 0) ? (value & ~mask) : (value | mask);
}

#endif

