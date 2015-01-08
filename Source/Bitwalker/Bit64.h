
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

    ensures left:     LeftEqualBitRange(\result, value, 0,  pos);
    ensures set_bit:  flag != 0  <==>  LeftBit64(\result, pos);
    ensures right:    LeftEqualBitRange(\result, value, pos + 1,  64);
    ensures upper:    \forall integer i; i >= 64 - pos ==>
                         (UpperBitsNotSet(value, i) ==> UpperBitsNotSet(\result, i));
*/
static inline uint64_t PokeBit64(uint64_t value, uint32_t pos, int flag)
{
    uint64_t mask = ((uint64_t) 1u) << (63 - pos);

    return (flag == 0) ? (value & ~mask) : (value | mask);
}


/*@
    requires pre: length <= 64;

    assigns \nothing;

    ensures  not_set: \result <==> UpperBitsNotSet(value, length);
*/
static inline int UpperBitsNotSet64(uint64_t value, uint32_t length)
{
    if (length == 64)
    {
        return 1;
    }
    else
    {
        const uint64_t MaxValue = ((uint64_t) 1) << length;

        return (value >= MaxValue) ? 0 : 1;
    }
}




#endif  // BIT64_H_INCLUDED

