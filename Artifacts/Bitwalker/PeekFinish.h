#ifndef PEEK_FINISH_H
#define PEEK_FINISH_H

#include "Bitwalker.h"
#include "limits.h"

/*@
  requires \valid(bw);
  requires bw->Bitposition <= INT_MAX;

  assigns  \nothing;

  ensures  \result == bw->Bitposition;
*/
int Bitwalker_Peek_Finish(Bitwalker* bw);


#endif
