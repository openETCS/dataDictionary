
#ifndef TRAIN_RUNNING_55_FROM_RBC_H_INCLUDED
#define TRAIN_RUNNING_55_FROM_RBC_H_INCLUDED

#include "Bitstream.h"

struct Train_running_number_from_RBC
{
    // TransmissionMedia=RBC
    // Train running number from RBC
    // Packet Number = 140

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  NID_OPERATIONAL;  // # 32
};

typedef struct Train_running_number_from_RBC Train_running_number_from_RBC;

#define TRAIN_RUNNING_55_FROM_RBC_BITSIZE 55

/*@
    logic integer BitSize{L}(Train_running_number_from_RBC* p) = TRAIN_RUNNING_55_FROM_RBC_BITSIZE;

    logic integer MaxBitSize{L}(Train_running_number_from_RBC* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Train_running_number_from_RBC* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Train_running_number_from_RBC* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_OPERATIONAL);

    predicate ZeroInitialized(Train_running_number_from_RBC* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_OPERATIONAL);

    predicate EqualBits(Bitstream* stream, integer pos, Train_running_number_from_RBC* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 55,  p->NID_OPERATIONAL);


    predicate UpperBitsNotSet(Train_running_number_from_RBC* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_OPERATIONAL,  32);

*/

#endif // TRAIN_RUNNING_55_FROM_RBC_H_INCLUDED

