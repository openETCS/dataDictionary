
#ifndef POKE_FINISH_H
#define POKE_FINISH_H

#include "Bitwalker.h"

/*@
  requires  \valid(bw);
  requires  bw->Bitposition <= INT_MAX;

  assigns   \nothing;

  ensures \result == bw->Bitposition;
*/
int Bitwalker_Poke_Finish(Bitwalker* bw);

#endif

