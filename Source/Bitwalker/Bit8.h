
#ifndef BIT8_H_INCLUDED
#define BIT8_H_INCLUDED

#include "FramaCBits.h"

/*@
    requires pre:  pos < 8;

    assigns \nothing;

    ensures pos:  \result != 0 <==> LeftBit8(value, pos);
*/
static inline int PeekBit8(uint8_t value, uint32_t pos)
{
    uint8_t mask = ((uint8_t) 1) << (7u - pos);
    uint8_t flag = value & mask;

    return flag != 0;
}


/*@
    requires pre: pos < 8;

    assigns \nothing;

    ensures left:   LeftEqualBitRange(\result, value, 0,  pos);
    ensures pos:    LeftBit8(\result, pos) <==> (flag != 0);
    ensures right:  LeftEqualBitRange(\result, value, pos + 1,  8);
*/
static inline uint8_t PokeBit8(uint8_t value, uint32_t pos, int flag)
{
    uint8_t mask = ((uint8_t) 1) << (7u - pos);

    return (flag == 0) ? (value & ~mask) : (value | mask);
}

#endif // BIT8_H_INCLUDED

