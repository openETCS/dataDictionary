
#include "Bitstream.h"

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
    //@ ghost uint32_t old_pos = stream->bitpos;
    uint64_t value = Bitstream_Read(stream, length);
    //@ assert equal:  EqualBits(stream, old_pos, old_pos+length, value);

    stream->bitpos -= length;
    //@ assert stream->bitpos == old_pos;

    Bitstream_Write(stream, length, value);
    //@ assert unchanged:  Unchanged{Here,Pre}(stream, old_pos, stream->bitpos);
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
    //@ ghost uint32_t old_pos = stream->bitpos;

    Bitstream_Write(stream, length, value);
    //@ assert equal:  EqualBits(stream, old_pos, old_pos+length, value);

    /*@
        assigns stream->bitpos;
        ensures reset: stream->bitpos == \at(stream->bitpos,Pre);
    */
    stream->bitpos -= length;

    uint64_t result = Bitstream_Read(stream, length);
    //@ ghost uint32_t new_pos = stream->bitpos;
    //@ assert equal_result: EqualBits(stream, old_pos, new_pos, result);
    //@ assert equal_value:  EqualBits(stream, old_pos, new_pos, value);
    /*@ assert aux:          \forall integer k; old_pos <= k < new_pos ==> 
                               \let j = new_pos - 1 - k;
                               (BitTest(value,  j) <==> BitTest(result, j));
    */
    //@ assert left:   EqualBits64(result, value, 64-length, 64);

    return result;
}

