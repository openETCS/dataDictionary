
#ifndef Bit8Array_defined
#define Bit8Array_defined

#include <limits.h>
#include <stdint.h>
#include "Bits.h"

/*@
    requires \valid_read(stream + (0..number_bytes-1));
    requires left_index < 8 * number_bytes;
    requires 8 * number_bytes < UINT_MAX;

    assigns \nothing;

    ensures (\result != 0) <==> LeftBitInStream(stream, left_index);
*/
int PeekBit8Array(uint8_t*      stream,
                  unsigned int  number_bytes,
                  unsigned int  left_index);



/*@
    requires 8 * BitstreamSize < UINT_MAX;
    requires \valid(Bitstream+(0..BitstreamSize-1));
    requires left_index < 8 * BitstreamSize;

    assigns Bitstream[0..BitstreamSize-1];

    ensures \forall integer i; (0 <= i < left_index/8) ==>
                (Bitstream[i] == \old(Bitstream[i]));

    ensures \forall integer i; (left_index/8 < i < BitstreamSize) ==>
                (Bitstream[i] == \old(Bitstream[i]));

    ensures \forall integer i; (0 <= i < left_index) ==>
                ((LeftBitInStream(Bitstream, i) <==> \old(LeftBitInStream(Bitstream, i))));

    ensures LeftBitInStream(Bitstream,left_index) <==> (flag != 0);

    ensures \forall integer i; (left_index < i < 8 * BitstreamSize) ==>
                ((LeftBitInStream(Bitstream, i) <==> \old(LeftBitInStream(Bitstream, i))));
*/
void PokeBit8Array(uint8_t* Bitstream,
                   unsigned int BitstreamSize,
                   unsigned int left_index,
                   int flag);

#endif

