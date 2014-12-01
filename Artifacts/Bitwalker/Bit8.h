

#ifndef Bit8_defined
#define Bit8_defined

#include "FramaCBits.h"

/*@
    requires pre: left < 8;

    assigns \nothing;

    ensures set_bit: \result != 0 <==> LeftBit8(byte, left);
*/
int PeekBit8(uint8_t byte, uint32_t left);


/*@
    requires left < 8;

    assigns \nothing;

    ensures unchanged_bits: \forall integer i; (0 <= i < 8  &&  i != left)  ==>
              (LeftBit8(\result, i) <==> LeftBit8(byte, i));

    ensures set_bit: LeftBit8(\result, left) <==> (flag != 0);
*/
uint8_t PokeBit8(uint8_t byte, uint32_t left, int flag);

#endif

