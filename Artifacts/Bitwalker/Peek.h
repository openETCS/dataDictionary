
#ifndef Peek_defined
#define Peek_defined

#include "BitsFramaC.h"

/*@
  requires \valid_read(Bitstream + (0..BitstreamSize-1));
  requires 0 <= Length <= 64;
  requires Start + Length <= UINT_MAX;
  requires 8 * BitstreamSize <= UINT_MAX;

  assigns \nothing;

  behavior  invalid_bit_sequence:
    assumes (Start + Length) > 8 * BitstreamSize;
    assigns \nothing;
    ensures \result == 0;

  behavior  normal_case:
    assumes (Start + Length) <= 8 * BitstreamSize;
    assigns \nothing;

    ensures \forall integer i; 0 <= i < Length ==>
              (LeftBitInStream(Bitstream, Start+i) <==> LeftBit64(\result, 64-Length + i));

    ensures \forall integer i; 0 <= i < 64-Length ==> !LeftBit64(\result, i);

  complete behaviors;
  disjoint behaviors;
*/
uint64_t Bitwalker_Peek(uint32_t Start,
                        uint32_t Length,
                        uint8_t* Bitstream,
                        uint32_t BitstreamSize);

#endif
