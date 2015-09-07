
#ifndef MESSAGE_HEADER_H_INCLUDED
#define MESSAGE_HEADER_H_INCLUDED

#include "Bitstream.h"

struct MessageHeader
{
    uint8_t  NID_MESSAGE;         // # 8
};

typedef struct MessageHeader MessageHeader;

#define MESSAGE_HEADER_BITSIZE 8

/*@
    logic integer BitSize{L}(MessageHeader* p) = MESSAGE_HEADER_BITSIZE;

    logic integer MaxBitSize{L}(MessageHeader* p) = BitSize(p);

    predicate Separated(Bitstream* stream, MessageHeader* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(MessageHeader* p) =
      Invariant(p->NID_MESSAGE);

    predicate ZeroInitialized(MessageHeader* p) =
      ZeroInitialized(p->NID_MESSAGE);

    predicate EqualBits(Bitstream* stream, integer pos, MessageHeader* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_MESSAGE);


    predicate UpperBitsNotSet(MessageHeader* p) =
      UpperBitsNotSet(p->NID_MESSAGE,  8);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int MessageHeader_UpperBitsNotSet(const MessageHeader* p);

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
int MessageHeader_Encoder(Bitstream* stream, const MessageHeader* p);

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
int MessageHeader_Decoder(Bitstream* stream, MessageHeader* p);

#endif // MESSAGE_HEADER_H_INCLUDED

