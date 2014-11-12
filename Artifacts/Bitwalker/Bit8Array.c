
#include "Bit8Array.h"
#include "Bit8.h"

int PeekBit8Array(uint8_t*  addr, uint32_t size, uint32_t left)
{
  return PeekBit8(addr[left / 8], left % 8);
}


void PokeBit8Array(uint8_t* addr, uint32_t size, uint32_t left, int flag)
{
  uint32_t i = left / 8u;
  uint32_t k = left % 8u;

  addr[i] = PokeBit8(addr[i], k, flag);

  // The following two assertions claim that in byte with index "left/8"
  // the bits with indices different from "k" do not change
  /*@
    assert \forall integer j; 0 <= j < k ==>
      (LeftBit8(addr[left/8], j) <==> \at(LeftBit8(addr[left/8], j), Pre));
  */

  /*@
    assert \forall integer j; k < j < 8 ==>
      (LeftBit8(addr[left/8], j) <==> \at(LeftBit8(addr[left/8], j), Pre));
  */

  // The following two assertions claim that in every byte
  // with an index that is different from "left/8" no bit is changed.
  /*@
    assert \forall integer l, j;
      (0 <= l < left/8 && 0 <= j < 8) ==>
        (LeftBit8(addr[l], j) <==> \at(LeftBit8(addr[l], j), Pre));
  */

  /*@
    assert \forall integer l, j;
      ((left/8 < l < size) && (0 <= j < 8)) ==>
        (LeftBit8(addr[l], j) <==> \at(LeftBit8(addr[l], j), Pre));
  */
}

