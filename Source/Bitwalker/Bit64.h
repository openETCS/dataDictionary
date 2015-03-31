
#ifndef BIT64_H_INCLUDED
#define BIT64_H_INCLUDED

#include "FramaCBits.h"

/*@
   requires pre: pos < 64;

   assigns \nothing;

   ensures set_bit: \result != 0 <==> LeftBit64(value, pos);
*/
static inline int PeekBit64(uint64_t value, uint32_t pos)
{
    uint64_t mask = ((uint64_t) 1) << (63u - pos);
    uint64_t flag = value & mask;

    return flag != 0u;
}


/*@
    requires pre: pos < 64;

    assigns \nothing;

    ensures left:     LeftEqualBitRange64(\result, value, 0,  pos);
    ensures set_bit:  flag != 0  <==>  LeftBit64(\result, pos);
    ensures right:    LeftEqualBitRange64(\result, value, pos + 1,  64);
    ensures upper:    \forall integer i; i >= 64 - pos ==>
                         (UpperBitsNotSet(value, i) ==> UpperBitsNotSet(\result, i));
*/
static inline uint64_t PokeBit64(uint64_t value, uint32_t pos, int flag)
{
    uint64_t mask = ((uint64_t) 1u) << (63 - pos);

    return (flag == 0) ? (value & ~mask) : (value | mask);
}

#endif  // BIT64_H_INCLUDED

