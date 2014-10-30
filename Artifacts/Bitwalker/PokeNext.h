
#ifndef PokeNext_included
#define PokeNext_included

#include "Bitwalker.h"
#include "BitwalkerInvariant.h"

/*@
  requires \valid(bw);
  requires BitwalkerInvariant(bw);
  requires 0 <= Length <= 63;
  requires bw->Bitposition + Length <= UINT_MAX;

  assigns  bw->Bitstream[0..bw->Size - 1], bw->Bitposition;

  ensures \old(bw->Bitposition) + Length == bw->Bitposition;

  behavior  invalid_bit_sequence:
    assumes (bw->Bitposition + Length) > 8 * bw->Size;

    ensures \old(bw->Bitposition) + Length == bw->Bitposition;
    ensures \result == -1;

  behavior  value_too_big:
    assumes (1 << Length) <= Value && (bw->Bitposition + Length) <= 8 * bw->Size;

    ensures \old(bw->Bitposition) + Length == bw->Bitposition;
    ensures \result == -2;

  behavior  normal_case:
    assumes Value < (1 << Length) && (bw->Bitposition + Length) <= 8 * bw->Size;

    assigns  bw->Bitstream[0..bw->Size - 1], bw->Bitposition;

    ensures \forall integer i; 0 <= i < \old(bw->Bitposition) ==>
    		(LeftBitInStream(bw->Bitstream, i) <==> \old(LeftBitInStream(bw->Bitstream, i)));

    ensures \forall integer i; bw->Bitposition < i < 8 * bw->Size  ==>
    		(LeftBitInStream(bw->Bitstream, i) <==> \old(LeftBitInStream(bw->Bitstream, i)));

    ensures \forall integer i; 0 <= i < Length ==>
    		(LeftBitInStream(bw->Bitstream, \old(bw->Bitposition)+i) <==> LeftBit64(Value, (64-Length)+i));

    ensures \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
int  Bitwalker_Poke_Next(Bitwalker* bw, uint32_t Length, uint64_t Value);

#endif

