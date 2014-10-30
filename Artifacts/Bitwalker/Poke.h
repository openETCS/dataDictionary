#ifndef Poke_defined
#define Poke_defined

#include "BitsFramaC.h"

/*@
  requires writeable_bitstream:
           \valid(Bitstream + (0..BitstreamSize-1));
  requires valid_length: 0 <= Length < 64;
  requires no_overflow_1: Start + Length <= UINT_MAX;
  requires no_overflow_2: 8 * BitstreamSize <= UINT_MAX;

  assigns Bitstream[0..BitstreamSize - 1];

  behavior  invalid_bit_sequence:
    assumes (Start + Length)  > 8 * BitstreamSize;
    assigns \nothing;
    ensures \result == -1;

  behavior  value_too_big:
    assumes (1 << Length) <= Value &&
            (Start + Length) <= 8 * BitstreamSize;
    assigns \nothing;
    ensures \result == -2;

  behavior  normal_case:
    assumes Value < (1 << Length) && (Start + Length) <= 8 * BitstreamSize;
    assigns Bitstream[0..BitstreamSize - 1];

    ensures \forall integer i; 0 <= i < Start ==>
             (LeftBitInStream(Bitstream, i) <==> \old(LeftBitInStream(Bitstream, i)));

    ensures \forall integer i; 0 <= i < Length ==>
             (LeftBitInStream(Bitstream, Start+i) <==> LeftBit64(Value,(64-Length)+i));

    ensures \forall integer i; Start+Length <= i < 8*BitstreamSize ==>
             (LeftBitInStream(Bitstream, i) <==> \old(LeftBitInStream(Bitstream, i)));

    ensures \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
int Bitwalker_Poke (uint32_t Start, uint32_t Length,
                    uint8_t* Bitstream, uint32_t BitstreamSize, uint64_t Value);

#endif
