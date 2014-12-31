

#ifndef BIT8_H_INCLUDED
#define BIT8_H_INCLUDED

#include "FramaCBits.h"

/*@
    requires pre: pos < 8;

    assigns \nothing;

    ensures set_bit: \result != 0 <==> LeftBit8(byte, pos);
*/
int PeekBit8(uint8_t byte, uint32_t pos);


/*@
    requires pre: pos < 8;

    assigns \nothing;

    ensures left: \forall integer i; 0 <= i < pos  ==> (LeftBit8(\result, i) <==> LeftBit8(byte, i));

    ensures set_bit: LeftBit8(\result, pos) <==> (flag != 0);

    ensures right: \forall integer i; pos < i < 8  ==> (LeftBit8(\result, i) <==> LeftBit8(byte, i));
*/
uint8_t PokeBit8(uint8_t byte, uint32_t pos, int flag);

#endif // BIT8_H_INCLUDED

