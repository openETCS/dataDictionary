
#ifndef PeekNext_included
#define PeekNext_included

#include "Locals.h"
#include "ValidIncrementalLocals.h"
#include "Bitwalker.h"

/*@
  requires \valid(Locals);
  requires Valid(Locals);
  requires 0 <= Length <= 64;
  requires Locals->CurrentBitposition + Length <= UINT_MAX;

  assigns  Locals->CurrentBitposition;

  behavior  invalid_bit_sequence:
    assumes (Locals->CurrentBitposition + Length)  > 8 * Locals->Length;
    assigns  Locals->CurrentBitposition;
    ensures \result == 0;

  behavior  normal_case:
    assumes (Locals->CurrentBitposition + Length) <= 8 * Locals->Length;
    assigns  Locals->CurrentBitposition;

    ensures \forall integer i; 0 <= i < Locals->Length ==>
    		(LeftBitInStream(Locals->Bitstream, Locals->CurrentBitposition+i) <==> LeftBit64(\result, 64 - Locals->Length + i));
	
    ensures \forall integer i; 0 <= i < 64 - Locals->Length ==> !LeftBit64(\result, i);

    ensures \old(Locals->CurrentBitposition) + \old(Locals->Length) == Locals->CurrentBitposition;

  complete behaviors;
  disjoint behaviors;
*/
uint64_t Bitwalker_IncrementalWalker_Peek_Next(
  T_Bitwalker_Incremental_Locals*  Locals,
  unsigned int                     Length);

#endif

