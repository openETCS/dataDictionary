
#ifndef PokeNext_included
#define PokeNext_included

#include "Locals.h"
#include "ValidIncrementalLocals.h"
#include "Bitwalker.h"

/*@
  requires \valid(Locals);
  requires Valid(Locals);
  requires 0 <= Length <= 63;
  requires Locals->CurrentBitposition + Length <= UINT_MAX;

  assigns  Locals->Bitstream[0..Locals->Length - 1], Locals->CurrentBitposition;

  ensures \old(Locals->CurrentBitposition) + Length == Locals->CurrentBitposition;

  behavior  invalid_bit_sequence:
    assumes (Locals->CurrentBitposition + Length) > 8 * Locals->Length;
    ensures \old(Locals->CurrentBitposition) + Length == Locals->CurrentBitposition;
    ensures \result == -1;

  behavior  value_too_big:
    assumes (1 << Length) <= Value &&
            (Locals->CurrentBitposition + Length) <= 8 * Locals->Length;
    ensures \old(Locals->CurrentBitposition) + Length == Locals->CurrentBitposition;
    ensures \result == -2;

  behavior  normal_case:
    assumes Value < (1 << Length) &&
            (Locals->CurrentBitposition + Length) <= 8 * Locals->Length;
    assigns  Locals->Bitstream[0..Locals->Length - 1], Locals->CurrentBitposition;

    ensures \forall integer i; 0 <= i < \old(Locals->CurrentBitposition) ==>
    		(LeftBitInStream(Locals->Bitstream, i) <==> \old(LeftBitInStream(Locals->Bitstream, i)));

    ensures \forall integer i; Locals->CurrentBitposition < i < 8*Locals->Length  ==>
    		(LeftBitInStream(Locals->Bitstream, i) <==> \old(LeftBitInStream(Locals->Bitstream, i)));

    ensures \forall integer i; 0 <= i < Length ==>
    		(LeftBitInStream(Locals->Bitstream, \old(Locals->CurrentBitposition)+i) <==> LeftBit64(Value, (64-Length)+i));

    ensures \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
int  Bitwalker_IncrementalWalker_Poke_Next(
  T_Bitwalker_Incremental_Locals*  Locals,
  unsigned int                     Length,
  uint64_t                         Value);

#endif

