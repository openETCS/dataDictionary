
#include "Bit8Array.h"
#include "Bit8.h"

int PeekBit8Array(uint8_t*     stream,
                  unsigned int number_bytes,
                  unsigned int left_index)
{
  return PeekBit8(stream[left_index / 8], left_index % 8);
}


void PokeBit8Array(uint8_t* Bitstream,
                   unsigned int BitstreamSize,
                   unsigned int left_index,
                   int flag)
{
  unsigned int i = left_index / 8u;
  unsigned int k = left_index % 8u;

  Bitstream[i] = PokeBit8(Bitstream[i], k, flag);

  // The following two assertions claim that in byte with index "left_index/8"
  // the bits with indices different from "k" do not change
  /*@
    assert \forall integer j; 0 <= j < k ==>
      (LeftBit8(Bitstream[left_index/8], j) <==>
        \at(LeftBit8(Bitstream[left_index/8], j), Pre));
  */

  /*@
    assert \forall integer j; k < j < 8 ==>
      (LeftBit8(Bitstream[left_index/8], j) <==>
        \at(LeftBit8(Bitstream[left_index/8], j), Pre));
  */

  // The following two assertions claim that in every byte
  // with an index that is different from "left_index/8" no bit is changed.
  /*@
    assert \forall integer l, j;
      ((0 <= l < left_index/8) && (0 <= j < 8)) ==>
        (LeftBit8(Bitstream[l], j) <==> \at(LeftBit8(Bitstream[l], j), Pre));
  */

  /*@
    assert \forall integer l, j;
      ((left_index/8 < l < BitstreamSize) && (0 <= j < 8)) ==>
        (LeftBit8(Bitstream[l], j) <==> \at(LeftBit8(Bitstream[l], j), Pre));
  */
}

