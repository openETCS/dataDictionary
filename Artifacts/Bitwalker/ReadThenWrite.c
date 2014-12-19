
#include "Bitstream_Read.h"
#include "Bitstream_Write.h"

/*@
    requires valid_stream: \valid(stream);
    requires stream_inv:   BitstreamInvariant(stream);
    requires max_length:   length <= 64;
    requires max_pos:      NormalBitsequence(stream, length);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;

    ensures result_zero: \result == 0;
    ensures unchanged:   BitstreamUnchanged{Old}(stream, 0, 8 * stream->size);
*/
int ReadThenWrite(Bitstream* stream, uint32_t length)
{
  int result = 0;
  uint64_t value = Bitstream_Read(stream, length);

  //@ assert copied:  BitstreamEqual64(stream, \at(stream->bitpos, Pre), stream->bitpos, value);
  //@ assert not_set: LeftNotSet64(value, 64 - length);
  //@ assert value < (1 << length);
  result =  Bitstream_Write(stream, length, value);


  //@ assert unchanged_left:  BitstreamUnchanged{Pre}(stream, 0, \at(stream->bitpos, Pre));
  //@ assert copied:          BitstreamEqual64(stream, \at(stream->bitpos, Pre), stream->bitpos, value);
  //@ assert unchanged_right: BitstreamUnchanged{Pre}(stream, stream->bitpos, 8 * stream->size);
  //@ assert zero:            result == 0;

  return result;
}
