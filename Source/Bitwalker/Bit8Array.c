
#include "Bit8Array.h"
#include "Bit8.h"

int PeekBit8Array(uint8_t*  addr, uint32_t size, uint32_t pos)
{
    return PeekBit8(addr[pos / 8], pos % 8);
}


void PokeBit8Array(uint8_t* addr, uint32_t size, uint32_t pos, int flag)
{
    uint32_t i = pos / 8u;
    uint32_t k = pos % 8u;

    addr[i] = PokeBit8(addr[i], k, flag);

    // The following assertion claims that in byte with index "pos/8"
    // the bits with indices different from "k" do not change
    /*@
      assert bits_in_byte:
        \forall integer j; (0 <= j < 8  && j != k) ==>
        (LeftBit8(addr[pos/8], j) <==> \at(LeftBit8(addr[pos/8], j), Pre));
    */

    // The following assertion claims that in every byte
    // with an index that is different from "pos/8" no bit is changed.

    /*@
        assert other_bytes:
        \forall integer l, j; (0 <= l < size  &&  l != pos/8  &&  0 <= j < 8) ==>
          (LeftBit8(addr[l], j) <==> \at(LeftBit8(addr[l], j), Pre));
    */

}

