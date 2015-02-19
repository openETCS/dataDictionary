
#ifndef TRAIN_RUNNING_NUMBER_DATA_H_INCLUDED
#define TRAIN_RUNNING_NUMBER_DATA_H_INCLUDED

#include "Bitstream.h"

struct Train_running_number_Data
{
    // TransmissionMedia=RBC
    // Train running number
    // Packet Number = 5

    uint32_t  NID_OPERATIONAL;  // # 32
};

typedef struct Train_running_number_Data Train_running_number_Data;

#define TRAIN_RUNNING_NUMBER_DATA_BITSIZE 32

/*@
    logic integer BitSize{L}(Train_running_number_Data* p) = TRAIN_RUNNING_NUMBER_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Train_running_number_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Train_running_number_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Train_running_number_Data* p) =
      Invariant(p->NID_OPERATIONAL);

    predicate ZeroInitialized(Train_running_number_Data* p) =
      ZeroInitialized(p->NID_OPERATIONAL);

    predicate EqualBits(Bitstream* stream, integer pos, Train_running_number_Data* p) =
      EqualBits(stream, pos,       pos + 32,  p->NID_OPERATIONAL);


    predicate UpperBitsNotSet(Train_running_number_Data* p) =
      UpperBitsNotSet(p->NID_OPERATIONAL,  32);

*/

#endif // TRAIN_RUNNING_NUMBER_DATA_H_INCLUDED

