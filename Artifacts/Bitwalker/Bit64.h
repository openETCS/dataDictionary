
#ifndef Bit64_defined
#define Bit64_defined

#include "FramaCBits.h"

/*@
   requires left < 64;

   assigns \nothing;

   ensures \result != 0 <==> LeftBit64(value, left);
*/
int PeekBit64(uint64_t value, uint32_t left);


/*@
    requires left < 64;

    assigns \nothing;

    ensures \forall integer i; (0 <= i < 64  &&  i != left) ==>
                (LeftBit64(\result, i) <==> LeftBit64(value, i));

    ensures flag != 0  <==>  LeftBit64(\result, left);
*/
uint64_t PokeBit64(uint64_t value, uint32_t left, int flag);

#endif

