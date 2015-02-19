
#ifndef TRAIN_RUNNING_NUMBER_FROM_RBC_DATA_H_INCLUDED
#define TRAIN_RUNNING_NUMBER_FROM_RBC_DATA_H_INCLUDED

#include "Bitstream.h"

struct Train_running_number_from_RBC_Data
{
    // TransmissionMedia=RBC
    // Train running number from RBC
    // Packet Number = 140

    uint32_t  Q_DIR;            // # 2
    uint32_t  NID_OPERATIONAL;  // # 32
};

typedef struct Train_running_number_from_RBC_Data Train_running_number_from_RBC_Data;

#define TRAIN_RUNNING_NUMBER_FROM_RBC_DATA_BITSIZE 47

/*@
    logic integer BitSize{L}(Train_running_number_from_RBC_Data* p) = TRAIN_RUNNING_NUMBER_FROM_RBC_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Train_running_number_from_RBC_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Train_running_number_from_RBC_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Train_running_number_from_RBC_Data* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->NID_OPERATIONAL);

    predicate ZeroInitialized(Train_running_number_from_RBC_Data* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->NID_OPERATIONAL);

    predicate EqualBits(Bitstream* stream, integer pos, Train_running_number_from_RBC_Data* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 15,  pos + 47,  p->NID_OPERATIONAL);


    predicate UpperBitsNotSet(Train_running_number_from_RBC_Data* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->NID_OPERATIONAL,  32);

*/

#endif // TRAIN_RUNNING_NUMBER_FROM_RBC_DATA_H_INCLUDED

