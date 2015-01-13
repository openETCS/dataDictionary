
#ifndef TRAIN_RUNNING_53_H_INCLUDED
#define TRAIN_RUNNING_53_H_INCLUDED

#include "Bitstream.h"

struct Train_running_number
{
    // TransmissionMedia=RBC
    // Train running number
    // Packet Number = 5

    uint64_t  NID_PACKET;       // # 8
    uint64_t  L_PACKET;         // # 13
    uint64_t  NID_OPERATIONAL;  // # 32
};

typedef struct Train_running_number Train_running_number;

#define TRAIN_RUNNING_53_BITSIZE 53

/*@
    logic integer BitSize{L}(Train_running_number* p) = TRAIN_RUNNING_53_BITSIZE;

    logic integer MaxBitSize{L}(Train_running_number* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Train_running_number* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Train_running_number* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_OPERATIONAL);

    predicate ZeroInitialized(Train_running_number* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_OPERATIONAL);

    predicate EqualBits(Bitstream* stream, integer pos, Train_running_number* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET)          &&
      EqualBits(stream, pos + 21,  pos + 53,  p->NID_OPERATIONAL);


    predicate UpperBitsNotSet(Train_running_number* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_OPERATIONAL,  32);

*/

#endif // TRAIN_RUNNING_53_H_INCLUDED

