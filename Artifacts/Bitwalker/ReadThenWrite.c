
#include "Bitstream_Read.h"
#include "Bitstream_Write.h"

/*@
    requires valid_stream: \valid(stream);
    requires stream_inv:   BitstreamInvariant(stream);
    requires max_length:   length <= 64;
    requires max_pos:      stream->bitpos + length <= UINT32_MAX;
    requires max_pos:      NormalBitsequence(stream, 2*length);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;

    ensures result_zero: \result == 0;
    ensures unchanged:   BitstreamUnchanged{Old}(stream, 0, 8 * stream->size);
    ensures pos:         stream->bitpos == 2 * \old(stream->bitpos);
*/
int ReadThenWrite(Bitstream* stream, uint32_t length)
{
  /*@
     requires valid_stream:     \valid(stream);
     requires stream_invariant: BitstreamInvariant(stream);
     requires max_length:       length <= 64;
     requires max_pos:          stream->bitpos + length <= UINT32_MAX;
     requires max_pos:          NormalBitsequence(stream, length);

     assigns  stream->bitpos;
     assigns  value;

     ensures increment:     stream->bitpos == \old(stream->bitpos) + length;
     ensures copied:        BitstreamEqual64(stream, \old(stream->bitpos), stream->bitpos, value);
     ensures not_set:       LeftNotSet64(value, 64 - length);
     ensures unchanged:     BitstreamUnchanged{Old}(stream, 0, 8*stream->size);
     ensures valid_result:  value < (1 << length);
  */
  uint64_t value = Bitstream_Read(stream, length);

   // assert copied:  BitstreamEqual64(stream, \at(stream->bitpos, Pre), stream->bitpos, value);
   // assert not_set: LeftNotSet64(value, 64 - length);
   // assert value < (1 << length);
   // assert stream->bitpos == \at(stream->bitpos, Pre) + length;

  /*@
      requires \valid(stream);
      requires BitstreamInvariant(stream);
      requires length <= 64;
      requires NormalBitsequence(stream, length);
      requires value < (1 << length) || length == 64;

      assigns stream->addr[0..stream->size-1];
      assigns stream->bitpos;
      assigns result;

      ensures stream->bitpos == \old(stream->bitpos) + length;
      ensures result == 0;
  */
  int result =  Bitstream_Write(stream, length, value);

  //@ assert unchanged_left:  BitstreamUnchanged{Pre}(stream, 0, \at(stream->bitpos, Pre));
  //@ assert copied:          BitstreamEqual64(stream, \at(stream->bitpos, Pre), stream->bitpos, value);
  //@ assert unchanged_right: BitstreamUnchanged{Pre}(stream, stream->bitpos, 8 * stream->size);
  //@ assert zero:            result == 0;

  return result;
}
