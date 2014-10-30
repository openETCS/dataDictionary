#ifndef INIT_H
#define INIT_H

#include "Bitwalker.h"
#include "BitwalkerInvariant.h"

/*@
  requires \valid(bw);
  requires \valid(Bitstream + (0..Size-1));
  requires 8 * Size <= UINT_MAX;
  requires Bitposition <= 8 * Size;
  requires \separated(Bitstream + (0..Size-1), bw);

  assigns  bw->Bitstream;
  assigns  bw->Size;
  assigns  bw->Bitposition;

  ensures  bw->Bitstream == Bitstream;
  ensures  bw->Size == Size;
  ensures  bw->Bitposition == Bitposition;
  ensures  BitwalkerInvariant(bw);
*/
void Bitwalker_Init(Bitwalker*  bw, uint8_t* Bitstream, uint32_t Size, uint32_t Bitposition);

#endif

