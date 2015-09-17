
#ifndef BIT64_H_INCLUDED
#define BIT64_H_INCLUDED

#include "BitPredicates.h"

/*@
   requires pre: pos < 64;

   assigns \nothing;

   ensures set_bit: \result != 0 <==> Bit64(value, pos);
*/
static inline int TestBit64(uint64_t value, uint32_t pos)
{
    uint64_t mask = ((uint64_t) 1) << (63u - pos);
    uint64_t flag = value & mask;

    return flag != 0u;
}


/*@
    requires pre: pos < 64;

    assigns \nothing;

    ensures left:     EqualBits64(\result, value, 0,  pos);
    ensures set_bit:  flag != 0  <==>  Bit64(\result, pos);
    ensures right:    EqualBits64(\result, value, pos + 1,  64);
    ensures upper:    \forall integer i; i >= 64 - pos ==>
                         (UpperBitsNotSet(value, i) ==> UpperBitsNotSet(\result, i));
*/
static inline uint64_t SetBit64(uint64_t value, uint32_t pos, int flag)
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
        // assert equiv: UpperBitsNotSet(value, length) <==> value < MaxValue;

        return value < MaxValue;
    }
}


#endif  // BIT64_H_INCLUDED

