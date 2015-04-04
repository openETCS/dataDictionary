
#include "Bitstream_Read.h"
#include "Bitstream_Write.h"

/*@
    requires valid:      Writeable(stream);
    requires invariant:  Invariant(stream, length);
    requires normal:     Normal(stream, length);
    requires upper:      UpperBitsNotSet(value, length);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;

    ensures result_value:  EqualBits64(\result, value);
*/
uint64_t Bitstream_WriteThenRead(Bitstream* stream, uint32_t length, uint64_t value)
{
    Bitstream_Write(stream, length, value);

    stream->bitpos -= length;

    uint64_t result = Bitstream_Read(stream, length);

    //@ assert partial_copy: EqualBitRange64(result, value, 0, length);
    //@ assert full_copy:    EqualBits64(result, value);

    return result;
}

