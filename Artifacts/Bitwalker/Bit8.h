

#ifndef BIT8_H_INCLUDED
#define BIT8_H_INCLUDED

#include "FramaCBits.h"

/*@
    requires pre: pos < 8;

    assigns \nothing;

    ensures set_bit: \result != 0 <==> LeftBit8(value, pos);
*/
int PeekBit8(uint8_t value, uint32_t pos);


/*@
    requires pre: pos < 8;

    assigns \nothing;

    ensures left:     LeftEqualBitRange(\result, value, 0,  pos);

    ensures set_bit:  LeftBit8(\result, pos) <==> (flag != 0);

    ensures right:    LeftEqualBitRange(\result, value, pos + 1,  8);
*/
uint8_t PokeBit8(uint8_t value, uint32_t pos, int flag);

#endif // BIT8_H_INCLUDED

