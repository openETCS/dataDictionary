

#include "Bitwalker.h"
#include "Bitwalker_Peek_Normal.h"
#include "Bitwalker_Poke_Normal.h"

/*@
    requires valid:      Writeable(addr, size);
    requires invariant:  BitwalkerInvariant(size, bitpos, length);
    requires normal:     NormalBitwalker(size, bitpos, length);

    assigns addr[0..size-1];

    ensures  unchanged:  Unchanged{Here,Old}(addr, 0, 8*size);
*/
void PeekThenPoke(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length)
{
    uint64_t value = Bitwalker_Peek_Normal(addr, size, bitpos, length);
    //@ assert equal:  EqualBits(addr, bitpos, bitpos + length, value);

    Bitwalker_Poke_Normal(addr, size, bitpos, length, value);
    //@ assert unchanged:  Unchanged{Here,Pre}(addr, bitpos, bitpos + length);
}

