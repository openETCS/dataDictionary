
#ifndef PACKET_HEADER_H_INCLUDED
#define PACKET_HEADER_H_INCLUDED

#include "Bitstream.h"

struct Packet_Header
{
    uint8_t  NID_PACKET;         // # 8
};

typedef struct Packet_Header Packet_Header;

#define PACKET_HEADER_BITSIZE 8

/*@
    logic integer BitSize{L}(Packet_Header* p) = HEADER_BITSIZE;

    logic integer MaxBitSize{L}(Packet_Header* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Packet_Header* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Packet_Header* p) =
      Invariant(p->NID_PACKET);

    predicate ZeroInitialized(Packet_Header* p) =
      ZeroInitialized(p->NID_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, Packet_Header* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);


    predicate UpperBitsNotSet(Packet_Header* p) =
      UpperBitsNotSet(p->NID_PACKET,  8);

*/


#endif // PACKET_HEADER_H_INCLUDED

