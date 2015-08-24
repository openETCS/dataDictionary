
#ifndef MESSAGE_HEADER_H_INCLUDED
#define MESSAGE_HEADER_H_INCLUDED

#include "Bitstream.h"

struct Message_Header
{
    uint8_t  NID_MESSAGE;         // # 8
};

typedef struct Message_Header Message_Header;

#define MESSAGE_HEADER_BITSIZE 8

/*@
    logic integer BitSize{L}(Message_Header* p) = MESSAGE_HEADER_BITSIZE;

    logic integer MaxBitSize{L}(Message_Header* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Message_Header* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Message_Header* p) =
      Invariant(p->NID_MESSAGE);

    predicate ZeroInitialized(Message_Header* p) =
      ZeroInitialized(p->NID_MESSAGE);

    predicate EqualBits(Bitstream* stream, integer pos, Message_Header* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_MESSAGE);


    predicate UpperBitsNotSet(Message_Header* p) =
      UpperBitsNotSet(p->NID_MESSAGE,  8);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Message_Header_UpperBitsNotSet(const Message_Header* p);

/*@
    requires valid_stream:      Writeable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid_read(p);
    requires invariant:         Invariant(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns stream->addr[0..(stream->size-1)];

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && UpperBitsNotSet{Pre}(p);

      assigns stream->bitpos;
      assigns stream->addr[0..(stream->size-1)];

      ensures result:     \result == 1;
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures left:       Unchanged{Here,Old}(stream, 0, \old(stream->bitpos));
      ensures middle:     EqualBits(stream, \old(stream->bitpos), p);
      ensures right:      Unchanged{Here,Old}(stream, stream->bitpos, 8 * stream->size);

    behavior values_too_big:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && !UpperBitsNotSet{Pre}(p);

      assigns \nothing;

      ensures result:        \result == -2;

    behavior invalid_bit_sequence:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result:       \result == -1;

    complete behaviors;
    disjoint behaviors;
*/
int Message_Header_Encoder(Bitstream* stream, const Message_Header* p);

/*@
    requires valid_stream:      Readable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:          Unchanged{Here,Old}(stream, 0, 8*stream->size);

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p));

      assigns stream->bitpos;
      assigns *p;

      ensures invariant:  Invariant(p);
      ensures result:     \result == 1; 
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures equal:      EqualBits(stream, \old(stream->bitpos), p);
      ensures upper:      UpperBitsNotSet(p);

    behavior error_case:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result: \result == 0;

    complete behaviors;
    disjoint behaviors;
*/
int Message_Header_Decoder(Bitstream* stream, Message_Header* p);

#endif // MESSAGE_HEADER_H_INCLUDED

