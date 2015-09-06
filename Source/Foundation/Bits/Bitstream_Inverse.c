
#include "Bitstream_Read.h"
#include "Bitstream_Write.h"

/*@
    requires valid:      Writeable(stream);
    requires invariant:  Invariant(stream, length);
    requires normal:     Normal(stream, length);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;

    ensures  unchanged:  Unchanged{Here,Old}(stream, 0, 8 * stream->size);
*/
void Bitstream_ReadThenWrite(Bitstream* stream, uint32_t length)
{
    //@ ghost uint32_t pos = stream->bitpos;
    uint64_t value = Bitstream_Read(stream, length);
    //@ assert equal:  EqualBits(stream, pos, pos+length, value);

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;

    Bitstream_Write(stream, length, value);
    //@ assert unchanged:  Unchanged{Here,Pre}(stream, pos, stream->bitpos);
}


/*@
    requires valid:      Writeable(stream);
    requires invariant:  Invariant(stream, length);
    requires normal:     Normal(stream, length);
    requires upper:      UpperBitsNotSet(value, length);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;

    ensures compare:     EqualBits64(\result, value, 0, 64);
*/
uint64_t Bitstream_WriteThenRead(Bitstream* stream, uint32_t length, uint64_t value)
{
    //@ ghost uint32_t pos = stream->bitpos;

    Bitstream_Write(stream, length, value);
    //@ assert equal:  EqualBits(stream, pos, pos+length, value);

    stream->bitpos -= length;
    //@ assert stream->bitpos == \at(stream->bitpos,Pre);

    uint64_t result = Bitstream_Read(stream, length);
    //@ assert equal_result: EqualBits(stream, pos, pos+length, result);
    //@ assert equal_value:  EqualBits(stream, pos, pos+length, value);
    //@ assert left:   EqualBits64(result, value, 64-length, 64);

    return result;
}

