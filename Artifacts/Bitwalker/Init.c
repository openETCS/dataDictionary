#include "Init.h"

void
Bitwalker_Init(Bitwalker* bw, uint8_t* Bitstream, uint32_t Size, uint32_t Bitposition)
{
  bw->Bitstream    = Bitstream;
  bw->Size         = Size;
  bw->Bitposition  = Bitposition;
}

