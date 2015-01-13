
#ifndef END_OF_INFORMATION_H_INCLUDED
#define END_OF_INFORMATION_H_INCLUDED

#include "Bitstream.h"

struct End_of_Information
{
    // TransmissionMedia=Balise, Loop
    // This packet consists only of NID_PACKET containing 8 bit 1sIt acts as a finish flag; the receiver will stop reading the remaining part of the message/telegram when receiving eight bits set to one in the NID_PACKET field.
    // Packet Number = 255

    uint64_t  NID_PACKET;       // # 8
};

typedef struct End_of_Information End_of_Information;

#define END_OF_INFORMATION_BITSIZE 8

/*@
    logic integer BitSize{L}(End_of_Information* p) = END_OF_INFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(End_of_Information* p) = BitSize(p);

    predicate Separated(Bitstream* stream, End_of_Information* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(End_of_Information* p) =
      Invariant(p->NID_PACKET);

    predicate ZeroInitialized(End_of_Information* p) =
      ZeroInitialized(p->NID_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, End_of_Information* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);


    predicate UpperBitsNotSet(End_of_Information* p) =
      UpperBitsNotSet(p->NID_PACKET,       8);

*/

#endif // END_OF_INFORMATION_H_INCLUDED

