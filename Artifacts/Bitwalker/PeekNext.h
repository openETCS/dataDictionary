
#ifndef PeekNext_included
#define PeekNext_included

#include "Bitwalker.h"
#include "BitwalkerInvariant.h"

/*@
  requires \valid(bw);
  requires BitwalkerInvariant(bw);
  requires 0 <= Length <= 64;
  requires bw->Bitposition + Length <= UINT_MAX;

  assigns  bw->Bitposition;

  ensures \old(bw->Bitposition) + Length == bw->Bitposition;

  behavior  invalid_bit_sequence:
    assumes (bw->Bitposition + Length)  > 8 * bw->Size;
    assigns  bw->Bitposition;

    ensures \result == 0;

  behavior  normal_case:
    assumes (bw->Bitposition + Length) <= 8 * bw->Size;
    assigns  bw->Bitposition;

    ensures \forall integer i; 0 <= i < Length ==>
    		(LeftBitInStream(\old(bw->Bitstream), \old(bw->Bitposition)+i) <==> LeftBit64(\result, 64-Length + i));

    ensures \forall integer i; 0 <= i < 64-Length ==> !LeftBit64(\result, i);

    ensures \result < (1 << Length);

  complete behaviors;
  disjoint behaviors;
*/
uint64_t Bitwalker_Peek_Next(Bitwalker* bw, uint32_t Length);

#endif

